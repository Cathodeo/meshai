#include "mainui.h"
#include "ui_mainui.h"


mainUI::mainUI(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::mainUI)
{
    ui->setupUi(this);
    connect (ui->optionWidget, &optionButtons::optionNumber,
             this, &mainUI::showme);
}

mainUI::~mainUI()
{
    delete ui;
}

void mainUI::showme(int index) {
    QString indexFormatted = QString::number(index);
    ui->textBox->setText("selected option: " + indexFormatted );
}

