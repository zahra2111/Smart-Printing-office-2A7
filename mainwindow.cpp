#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QMessageBox>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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

void MainWindow::on_Ajouteraff_clicked()
{
    ui->idajout->setText("");
    ui->mailajout->setText("");
    ui->nomajout->setText("");
    ui->prenomajout->setText("");
    ui->posteajout->setText("");

    ui->stackedWidget->setCurrentIndex(3);

}

void MainWindow::on_confirmerajout_clicked()
{
    Employee * emp = new Employee(ui->idajout->text().toInt(), ui->mailajout->text(), ui->nomajout->text(), ui->prenomajout->text() , ui->posteajout->text());
    emp->ajouter();
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
