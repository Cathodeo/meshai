#ifndef MAINUI_H
#define MAINUI_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QtSql>

QT_BEGIN_NAMESPACE
namespace Ui { class mainUI; }
QT_END_NAMESPACE

class mainUI : public QMainWindow
{
    Q_OBJECT

public:
    mainUI(QWidget *parent = nullptr);
    ~mainUI();

private:
    Ui::mainUI *ui;
    QGraphicsScene *scene;
    QGraphicsScene *portrait;

private slots:
    void selectoption(int);
    void rollnext();

};
#endif // MAINUI_H
