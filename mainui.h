#ifndef MAINUI_H
#define MAINUI_H

#include <QMainWindow>

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

private slots:
    void showme(int);


};
#endif // MAINUI_H
