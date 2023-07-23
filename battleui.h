#ifndef BATTLEUI_H
#define BATTLEUI_H

#include <QWidget>
#include <QtSql>

namespace Ui {
class battleui;
}

class battleui : public QWidget
{
    Q_OBJECT

public:
    explicit battleui(QWidget *parent = nullptr);
    ~battleui();
    void initialPopulate();

private:
    Ui::battleui *ui;
};

#endif // BATTLEUI_H
