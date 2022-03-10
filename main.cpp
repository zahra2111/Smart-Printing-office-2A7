#include "mainwindow.h"
#include "connexion.h"
#include "employee.h"


#include <QMessageBox>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
     Connection c;

     bool test=c.createconnect();

     if(test)
     {
         QMessageBox::information(nullptr, QObject::tr("database is open"),
                     QObject::tr("connection successful"), QMessageBox::Cancel);
         w.show();
     }
     else
         QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                     QObject::tr("connection failed"), QMessageBox::Cancel);
    w.show();
    return a.exec();
}
