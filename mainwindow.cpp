#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employee.h"
#include <QDebug>
#include <QMessageBox>
#include "QIntValidator"
#include <QDateEdit>
#include <QPlainTextEdit>
#include <QPrinter>
//#include <QPrinterInfo>
//#include <QPrintDialog>
#include <QTextStream>
#include <QPainter>
#include <QTextStream>
#include <QFileDialog>
#include <QTextDocument>
#include <QtPrintSupport/QPrinter>
#include <QFileDialog>
#include <QTextDocument>
#include <strstream>
#include <QSystemTrayIcon>
#include <QRegExpValidator>
#include <QDesktopServices>
#include <QUrl>
#include <QGuiApplication>
//#include <QQmlApplicationEngine>
#include <QTcpSocket>
//#include <QQuickItem>
#include <QSystemTrayIcon>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //chat
    mSocket=new QTcpSocket(this);
        mSocket->connectToHost("localhost",2000);
        if (mSocket->waitForConnected(3000))
        {
            ui->plainTextEdit->appendPlainText("se connecter correctement");
        }
        else
        {
            ui->plainTextEdit->appendPlainText("connected");
        }
        connect(mSocket,SIGNAL(readyRead()),this,SLOT(leer()));
        // fin chat
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    qDebug() << "pushed";
    ui->tableView->setModel(emp.afficher(ui->lineEditAff->text(), 0));
//    ui->tableView->setItemDelegateForColumn(4,new TailButtonsDelegate(ui->tableView));
}

void MainWindow::on_annulerajout_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);

}
/*ui->idajout->setText("");
ui->mailajout->setText("");
ui->nomajout->setText("");
ui->prenomajout->setText("");
ui->posteajout->setText("");*/
void MainWindow::on_Ajouteraff_clicked()
{
    ui->idajout->setText("");
    ui->mailajout->setText("");
    ui->nomajout->setText("");
    ui->prenomajout->setText("");
    ui->posteajout->setText("");

    /*QString Nom=ui->nomajout->text();
        QString prenom=ui->prenomajout->text();
        QString poste=ui->posteajout->text();



        int erreur=0;
            if(!emp.ChaineValide(Nom))
            erreur=1;
            if(!emp.ChaineValide(prenom))
            erreur=2;
            if(!emp.ChaineValide(poste))
            erreur=3;
            switch(erreur)
            {
            case 1:
                QMessageBox::critical(nullptr, QObject::tr("invalide"),
                            QObject::tr("Le nom doit être composé seulement par des lettres !"), QMessageBox::Cancel);
            break;

            case 2:
                QMessageBox::critical(nullptr, QObject::tr("invalide"),
                            QObject::tr("Le prenom doit être composé seulement par des lettres !"), QMessageBox::Cancel);        break;

            case 3:
                QMessageBox::critical(nullptr, QObject::tr("invalide"),
                            QObject::tr("La poste doit être composé seulement par des lettres !"), QMessageBox::Cancel);        break;

        }
        if(erreur==0)
        {
            bool test=emp.ajouter();
            if(test)
            {QMessageBox::information(nullptr, QObject::tr("ajouter is open"),
                                      QObject::tr("successful.\n"
                                                  "Click Cancel to exit."), QMessageBox::Cancel);
                  ui->nomajout->clear();
                  ui->prenomajout->clear();
                  ui->posteajout->clear();

            }
            else
                QMessageBox::critical(nullptr, QObject::tr("ajouter is not working"),
                            QObject::tr("failed.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);

        }


        int id=ui->idajout->text().toInt();
             QString mail=ui->mailajout->text();
            Employee emp(id,mail,Nom,prenom,poste);
            bool Employee=emp.ajouter();
            ui->tableView->setModel(emp.afficher(ui->lineEditAff->text(), 0));
            if(Employee)
            {
                QMessageBox::information(nullptr, QObject::tr("ajouter is open"),
                            QObject::tr("successful.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);

        }
            else{
                QMessageBox::critical(nullptr, QObject::tr("ajouter is not working"),
                            QObject::tr("failed.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
        }*/


    ui->stackedWidget->setCurrentIndex(3);

}

void MainWindow::on_confirmerajout_clicked()
{
    Employee * emp = new Employee(ui->idajout->text().toInt(), ui->mailajout->text(), ui->nomajout->text(), ui->prenomajout->text() , ui->posteajout->text());
    emp->ajouter();
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
            notifyIcon->show();


           notifyIcon->showMessage("Ajouter ","Ajouter valide",QSystemTrayIcon::Information,15000);
    ui->stackedWidget->setCurrentIndex(2);

}

void MainWindow::on_quittermodif_clicked()
{
    QCoreApplication::quit();

}

void MainWindow::on_Quitteraff_clicked()
{
    QCoreApplication::quit();

}

void MainWindow::on_quitterajout_clicked()
{
    QCoreApplication::quit();

}

void MainWindow::on_annulermodif_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_Ajouteraff_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

}

void MainWindow::on_confirmermodif_clicked()
{
    int ID = ui->idmodif->text().toInt();
    QString MAIL= ui->mailmodif->text();
    QString NOM= ui->nommodif->text();
    QString PRENOM= ui->prenommodif->text();
    QString POSTE=ui->postemodif->text();

     /*bool test=emp.modify(ID);
     if (test)
         QMessageBox::information(nullptr, QObject::tr("success"),
                     QObject::tr(""), QMessageBox::Cancel);
     else
         QMessageBox::information(nullptr, QObject::tr("error"),
                     QObject::tr(""), QMessageBox::Cancel);
    ui->stackedWidget->setCurrentIndex(2);
    ui->tableView->setModel(emp.afficher(ui->lineEditAff->text(), 0));*/

    Employee * emp = new Employee(ID, MAIL, NOM,PRENOM,POSTE);
    emp->modify(ID);
    ui->stackedWidget->setCurrentIndex(2);
    ui->tableView->setModel(emp->afficher(ui->lineEditAff->text(), 0));

}

void MainWindow::on_tableView_clicked(const QModelIndex &iindex)
{
    QPoint mousePos = QCursor::pos();
    QPoint localPos = ui->tableView->mapFromGlobal( mousePos );
    qDebug() << " mouse positions  global= " << mousePos << "local = " << localPos;
    QModelIndex index=ui->tableView->selectionModel()->currentIndex();
    QVariant value=index.sibling(index.row(),0).data();
}

void MainWindow::on_stackedWidget_currentChanged(int arg1)
{
    if(arg1==2)
    {
        ui->tableView->setModel(emp.afficher("", 0));
    }else if(arg1==1)
    {
        QModelIndex index=ui->tableView->selectionModel()->currentIndex();
        QVariant value=index.sibling(index.row(),0).data();
        ui->idmodif->setText(value.toString());

        value=index.sibling(index.row(),1).data();
        ui->mailmodif->setText(value.toString());


        value = index.sibling(index.row(), 2).data();
        ui->nommodif->setText(value.toString());

        value = index.sibling(index.row(), 3).data();
        ui->prenommodif->setText(value.toString());

        value = index.sibling(index.row(), 4).data();
        ui->postemodif->setText(value.toString());



    }

}

void MainWindow::on_quitterajout_2_clicked()
{
    QCoreApplication::quit();
}



void MainWindow::on_confirsupp_clicked()
{


  emp.getid();
emp.setid(ui->idsupp->text().toInt());
    emp.supprimer(mref);
    ui->stackedWidget->setCurrentIndex(2);
    //int id=ui->idsupp->text().toInt();
   // bool test=emp.supprimer(id);
   // QMessageBox msgBox;
    //if(test)
    //{
    //    msgBox.setText("supprimer");
    //    ui->tableView->setModel(emp.afficher2());
    //}

}


void MainWindow::on_Suppaff_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

}

void MainWindow::on_tri_asc_clicked()
{
    //ui->tableview->setModel(Emp.afficher_tri_ID());
    ui->tableView->setModel(emp.afficher(ui->lineEditAff->text(), 0));

}

void MainWindow::on_tri_desc_clicked()
{
    //ui->tableview->setModel(Emp.afficher_tri_ID());
    //ui->tableView->setModel(emp.afficher(ui->lineEditAff->text(), 0));
    ui->tableView->setModel(emp.show_Desc_name());
}

void MainWindow::on_lineEditAff_textChanged(const QString &arg1)
{
    ui->tableView->setModel(emp.afficher(ui->lineEditAff->text(), 0));
    //ui->tableView->setItemDelegateForColumn(4,new TailButtonsDelegate(ui->tableView));
}

void MainWindow::on_lineEditAff_textEdited(const QString &arg1)
{
    ui->tableView->setModel(emp.afficher(ui->lineEditAff->text(), 0));
}

// go to chat boutton
void MainWindow::on_pushButton_3_clicked()
{
   ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_CHAT_clicked()
{

    mSocket->write(ui->lineEdit->text().toLatin1().data(),ui->lineEdit->text().size());

    ui->plainTextEdit->appendPlainText(ui->lineEdit->text());

    ui->lineEdit->clear();
}

/*void MainWindow::on_pushButton_2_clicked()
{
    QString strStream;
        QTextStream out(&strStream);
        const int rowCount = ui->tableView->model()->rowCount();
        const int columnCount = ui->tableView->model()->columnCount();
        out <<  "<html>\n"
            "<head>\n"
            "<meta Content=\"Text/html; charset=Windows-1251\">\n"
            <<  QString("<title>%1</title>\n").arg("strTitle")
            <<  "</head>\n"
            "<body bgcolor=#ffffff link=#5000A0>\n"
            //     "<align='right'> " << datefich << "</align>"
            "<center> <H1>Liste RH </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";
        // headers
        out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
        for (int column = 0; column < columnCount; column++)

            if (!ui->tableView->isColumnHidden(column))

                out << QString("<th>%1</th>").arg(ui->tableView->model()->headerData(column, Qt::Horizontal).toString());

        out << "</tr></thead>\n";
        // data table

        for (int row = 0; row < rowCount; row++)
        {
            out << "<tr> <td bkcolor=0>" << row + 1 << "</td>";
            for (int column = 0; column < columnCount; column++)
            {
                if (!ui->tableView->isColumnHidden(column))
                {
                    QString data = ui->tableView->model()->data(ui->tableView->model()->index(row, column)).toString().simplified();
                    out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                }
            }
            out << "</tr>\n";
        }
        out <<  "</table> </center>\n"

            "</body>\n"

            "</html>\n";

        QString fileName = QFileDialog::getSaveFileName((QWidget * )0, "Sauvegarder en PDF", QString(), "*.pdf");

        if (QFileInfo(fileName).suffix().isEmpty())

        {

            fileName.append(".pdf");

        }

         QPrinter printer (QPrinter::PrinterResolution);
         printer.setOutputFormat(QPrinter::PdfFormat);
         printer.setPaperSize(QPrinter::A4);
         printer.setOutputFileName(fileName);
         QTextDocument doc;
         doc.setHtml(strStream);
         doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
         doc.print(&printer);
}*/

void MainWindow::on_notifi_clicked()
{
    // notifi
}
