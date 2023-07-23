#ifndef DATABASE_H
#define DATABASE_H

#endif // DATABASE_H


#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

static bool createConnection()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/home/tmmartin/meshai/meshai.db");
    if (!db.open()) {
        QMessageBox::critical(nullptr, QObject::tr("Cannot open database"),
            QObject::tr("Unable to establish a database connection.\n"
                        "This example needs SQLite support. Please read "
                        "the Qt SQL driver documentation for information how "
                        "to build it.\n\n"
                        "Click Cancel to exit."), QMessageBox::Cancel);
        return false;
    }
    QSqlQuery startFromZero_1 ("delete from sessions");
    QSqlQuery startFromZero_b1 ("delete from actor_instance");
    QSqlQuery startFromZero_2 ("insert into sessions values (1, 1, 0)");
    QSqlQuery startFromZero_b2 ("insert into actor_instance values (1, 100, 1, 100), (101, 100, 1, 100)");
    return true;
    }
