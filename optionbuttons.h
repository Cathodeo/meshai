#ifndef OPTIONBUTTONS_H
#define OPTIONBUTTONS_H
#include <QWidget>
#include <QPushButton>
#include <QLayout>
#include <QSignalMapper>

class optionButtons:public QWidget
{
   Q_OBJECT
public:
    optionButtons(QWidget *parent = nullptr);
public slots:
    void optionChosen(int index);
private:
    QVector<QPushButton*>opt_column;
signals:
    void optionNumber(int);



};

#endif // OPTIONBUTTONS_H
