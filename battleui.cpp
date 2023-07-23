#include "battleui.h"
#include "ui_battleui.h"
#include <QWidget>
#include <QtSql>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsView>
#include <QPixmap>

battleui::battleui(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::battleui)
{
    ui->setupUi(this);
    initialPopulate();
}

battleui::~battleui()
{
    delete ui;
}

void battleui::initialPopulate() {
    QSqlQuery alliesPresent ("select actor_instance.actor_id, actor.actor_name, actor_currenthp, actor_isalive, actor_currenten from actor_instance left join actor on actor_instance.actor_id=actor.actor_id where actor_instance.actor_id < 100");
    QSqlQuery enemiesPresent ("select actor_instance.actor_id, actor.actor_name, actor_currenthp, actor_isalive, actor_currenten from actor_instance left join actor on actor_instance.actor_id=actor.actor_id where actor_instance.actor_id > 100");
    QSqlQuery alliesMoves("select ACTOR_INSTANCE.ACTOR_ID, MOVE1, MOVE2, MOVE3, MOVE4 from actor_instance left join actor_moves on ACTOR_INSTANCE.ACTOR_ID=actor_moves.ACTOR_ID where actor_instance.actor_id < 100");
    alliesPresent.first();
    enemiesPresent.first();
    alliesMoves.first();

    //Prepare test ally
    ui->Ally_hp->setValue(alliesPresent.value(2).toInt());
    ui->Ally_energy->setValue(alliesPresent.value(4).toInt());
    ui->Ally_name->setText(alliesPresent.value(1).toString());
    //Prepare attacks, to be replaced with for loop and array
    ui->Attack1->setText(alliesMoves.value(1).toString());
    //Prepare test enemy
    ui->Enemy1_hp->setValue(enemiesPresent.value(2).toInt());
    ui->Enemy1_name->setText(enemiesPresent.value(1).toString());

}
