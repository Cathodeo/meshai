#include "mainui.h"
#include "database.h"
#include <QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    if (!createConnection())
        return EXIT_FAILURE;
    mainUI w;
    QFile styleSheet ("/home/tmmartin/meshai/resources/style/cyber.qss");
    styleSheet.open(QFile::ReadOnly);
    QString styles = QLatin1String(styleSheet.readAll());
    a.setStyleSheet(styles);
    w.show();
    return a.exec();
}
