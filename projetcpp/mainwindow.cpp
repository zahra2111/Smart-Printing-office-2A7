#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "commande.h"
#include <QMessageBox>
#include <QIntValidator>
#include <QDebug>
#include <QDateTimeEdit>
#include <QComboBox>
#include <QSqlQuery>
#include <QModelIndex>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
ui->id->setValidator(new QIntValidator(0,9999999,this));
ui->tabcommande->setModel(c.afficher());
QDateTimeEdit *dateEdit = new QDateTimeEdit(QDate::currentDate());
  dateEdit->setMinimumDate(QDate::currentDate().addDays(-365));
  dateEdit->setMaximumDate(QDate::currentDate().addDays(365));
  dateEdit->setDisplayFormat("yyyy.MM.dd");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    int IDcommande=ui->id->text().toInt();
    QString mailClient=ui->mail->text();
    QString description=ui->desc->toPlainText();
     QDate date=ui->date->date();
    QString etat=ui->etat->text();

    commande c(IDcommande,mailClient,description,date,etat);

    bool test=c.ajouter();
    if (test)
    {
        QMessageBox::information(nullptr,QObject::tr("OK"),
                QObject::tr("ajout effectue"),
                QMessageBox::Cancel);
         ui->tabcommande->setModel(c.afficher());
    }
    else{
        QMessageBox::critical(nullptr,QObject::tr("NOT OK"),
                QObject::tr("ajout non effectue"),
                QMessageBox::Cancel);

    }

}


void MainWindow::on_supprimer_clicked()
{
    commande c;
    c.setIDcommande(ui->idsup->text().toInt());
    bool test=c.supprimer(c.getIDcommande());
    QMessageBox msgBox;
    if(test)
        {msgBox.setText("suppression avec succes.");
    ui->tabcommande->setModel(c.afficher());
    }
    else
        msgBox.setText("Echec de suppression");
    msgBox.exec();
}




void MainWindow::on_modifier_clicked()
{
    commande c;
    int IDcommande=ui->idc->text().toInt();
      c.setMailClient(ui->ma->text());
       c.setDescription(ui->de->toPlainText());
        c.setEtat(ui->et->text());

 bool test=c.modifier(IDcommande);
    if (test)
    {
        QMessageBox::information(nullptr,QObject::tr("OK"),
                QObject::tr("Modifié avec succes"),
                QMessageBox::Cancel);
         ui->tabcommande->setModel(c.afficher());
    }
    else{
        QMessageBox::critical(nullptr,QObject::tr("NOT OK"),
                QObject::tr("Echec"),
                QMessageBox::Cancel);

    }
}

void MainWindow::on_tabcommande_activated(const QModelIndex &index)
{
    QString val=ui->tabcommande->model()->data(index).toString();
    QSqlQuery qry;
    qry.prepare("select * from commandes where IDcommande='"+val+"'");
   if (qry.exec())
   {
       while(qry.next())
       {
          ui->idc->setText(qry.value(0).toString());
           ui->idsup->setText(qry.value(0).toString());
          ui->ma->setText(qry.value(1).toString());
          ui->de->setText(qry.value(2).toString());
           ui->dat->setDate(qry.value(3).toDate());
           ui->et->setText(qry.value(4).toString());

       }
   }
   else
   {
       QMessageBox::critical(nullptr,QObject::tr("NOT OK"),
               QObject::tr("Echec"),
               QMessageBox::Cancel);
   }
}

void MainWindow::on_com_selec_clicked()
{
    if (ui->tabWidget->count() > 1) {
          ui->tabWidget->setCurrentIndex( (ui->tabWidget->currentIndex()+3) % ui->tabWidget->count() );
       }
}

void MainWindow::on_com_retour_clicked()
{
    if (ui->tabWidget->count() > 1) {
          ui->tabWidget->setCurrentIndex( (ui->tabWidget->currentIndex()-3) % ui->tabWidget->count() );
       }
}



void MainWindow::on_com_sup_clicked()
{
    if (ui->tabWidget->count() > 1) {
          ui->tabWidget->setCurrentIndex( (ui->tabWidget->currentIndex()+2) % ui->tabWidget->count() );
       }

}

void MainWindow::on_sup_tt_clicked()
{
    QSqlQuery qry;
    qry.prepare("truncate table commandes");
    if (qry.exec())
    {
        QMessageBox::information(nullptr,QObject::tr("OK"),
                QObject::tr("Suppression effectuée"),
                QMessageBox::Cancel);
        ui->tabcommande->setModel(c.afficher());
    }
    else
    {
        QMessageBox::critical(nullptr,QObject::tr("NOT OK"),
                QObject::tr("Echec"),
                QMessageBox::Cancel);
    }
}

void MainWindow::on_com_retour_3_clicked()
{
    if (ui->tabWidget->count() > 1) {
          ui->tabWidget->setCurrentIndex( (ui->tabWidget->currentIndex()-1) % ui->tabWidget->count() );
       }
}

void MainWindow::on_com_retour_2_clicked()
{
    if (ui->tabWidget->count() > 1) {
          ui->tabWidget->setCurrentIndex( (ui->tabWidget->currentIndex()-2) % ui->tabWidget->count() );
       }
}
