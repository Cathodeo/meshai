#include "mainui.h"
#include "database.h"
#include "battleui.h"
#include <QApplication>
#include <QFile>
#include <QtSql>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsView>
#include <QPixmap>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    if (!createConnection())
        return EXIT_FAILURE;
    mainUI w1;
    battleui w2;
    QFile styleSheet ("/home/tmmartin/meshai/resources/style/cyber.qss");
    styleSheet.open(QFile::ReadOnly);
    QString styles = QLatin1String(styleSheet.readAll());
    a.setStyleSheet(styles);
    w2.show();
    return a.exec();
}
