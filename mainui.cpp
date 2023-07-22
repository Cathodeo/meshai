#include "mainui.h"
#include "ui_mainui.h"
#include <QtSql>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsView>
#include <QPixmap>


mainUI::mainUI(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::mainUI)
{

    ui->setupUi(this);

    connect (ui->nextButton,
             &QPushButton::clicked,
             this,
             &mainUI::rollnext);
    ////SQL THINGIES//////////////////
    //////////////////////////////////
    /// //////////////////////////////
    ////STARTING UP DUMMY GRAPHICS////
    ///TO MOVE TO A DIFFERENT FILE///
    scene = new QGraphicsScene(this);
    portrait = new QGraphicsScene(this);
    QImage background01("/home/tmmartin/meshai/resources/charas/possesioner02.png");
    QImage chara01("/home/tmmartin/meshai/resources/charas/possesioner01.png");
    QImage portrait01("/home/tmmartin/meshai/resources/charas/possesioner03");
    QGraphicsPixmapItem *background = new QGraphicsPixmapItem(QPixmap::fromImage(background01));
    QGraphicsPixmapItem *character = new QGraphicsPixmapItem(QPixmap::fromImage(chara01));
    QGraphicsPixmapItem *portraitres = new QGraphicsPixmapItem(QPixmap::fromImage(portrait01));
    character->setPos(200,0);
    character->setScale(2);
    portraitres->setScale(2);
    scene->addItem(background);
    scene->addItem(character);
    portrait->addItem(portraitres);
    ui->mainView->setScene(scene);
    ui->charaView->setScene(portrait);
    ui->mainView->show();
    ui->charaView->show();

}

mainUI::~mainUI()
{
    delete ui;
}

void mainUI::rollnext() {
      QSqlQuery initialSession ("select current_sequence from sessions where session_id = 1");
      initialSession.first();
      int sequenceNow = initialSession.value(0).toInt();
      QSqlQuery fetchText;
      fetchText.prepare("select textbox from sequence_text where sequence_no = :sequenceNow");
      fetchText.bindValue(":sequenceNow", sequenceNow);
      fetchText.exec();
      fetchText.first();
      ui->textBox->setText(fetchText.value(0).toString());
      QSqlQuery increase;
      increase.prepare("update sessions set current_sequence = :sequenceNext");
      increase.bindValue(":sequenceNext" , sequenceNow + 1);
      increase.exec();
      connect
               (ui->optionWidget,
               &optionButtons::optionNumber,
               this,
               &mainUI::selectoption);
}

void mainUI::selectoption(int index) {
    QString indexFormatted = QString::number(index);
    ui->textBox->setText("selected option: " + indexFormatted );
}



