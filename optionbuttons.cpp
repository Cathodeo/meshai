#include "optionbuttons.h"

optionButtons::optionButtons(QWidget *parent):
    QWidget(parent)
{
 QVBoxLayout*hLayout = new QVBoxLayout(this);
 QSignalMapper *mapper = new QSignalMapper(this);


 //Create 5 options with a vertical layout//
 for (int row = 0; row < 5; ++row) {
     //Identify each option with its row number
     QString numberito = QString::number(row + 1);
     QPushButton *option = new QPushButton("Option " + numberito);
     hLayout->addWidget(option,row);
     opt_column.append(option);
     mapper->setMapping(option, opt_column.count());
     connect(option, SIGNAL(clicked()), mapper, SLOT(map()));
 }
 connect(mapper, SIGNAL(mapped(int)),
         this, SLOT(optionChosen(int)));
}

void optionButtons::optionChosen(int index)
{
    if(index < 0 || index > opt_column.size()){
        return;
    }
    QPushButton *option = opt_column[index - 1];
    emit optionNumber(index);
}

