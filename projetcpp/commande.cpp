#include "commande.h"
#include<QSqlQuery>
#include <QDebug>
#include <QObject>
commande::commande()
{
    IDcommande=0;
    mailClient="";
    description="";
    datep.currentDate();
    etat="";
}
commande::commande(int IDcommande ,QString mailClient,QString description, QDate datep,QString etat)
{
this->IDcommande=IDcommande;
this->mailClient=mailClient;
this->description=description;
this->datep=datep;
this->etat=etat;
}
//getters
QString commande::getMailClient(){return mailClient ;}
QString commande::getDescription(){return description;}
QDate commande::getDate(){return datep;}
QString commande::getEtat(){return etat;}
int commande::getIDcommande(){return IDcommande;}
//setters
void commande::setIDcommande(int IDcommande){this->IDcommande=IDcommande;}
void commande::setMailClient(QString mailClient){this->mailClient=mailClient;}
void commande::setDescription(QString description){this->description=description;}
void commande::setDate( QDate datep){this->datep=datep;}
void commande::setEtat(QString etat){this->etat=etat;}

bool commande::ajouter()
{
QSqlQuery query;
   QString res = QString::number(IDcommande);
   query.prepare("INSERT INTO commandes (IDcommande,mailClient,description,datep,etat)" "values(:IDcommande,:mailClient,:description,:datep,:etat)");
query.bindValue(":IDcommande",res);
   query.bindValue(":mailClient",mailClient);
    query.bindValue(":description",description);
     query.bindValue(":datep",datep);
      query.bindValue(":etat",etat);
      return query.exec();
}
QSqlQueryModel* commande::afficher()
{
  QSqlQueryModel* model=new QSqlQueryModel;

       model->setQuery("SELECT * FROM commandes");
       model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant"));
       model->setHeaderData(1, Qt::Horizontal, QObject::tr("Mail du client"));
       model->setHeaderData(2, Qt::Horizontal, QObject::tr("Description"));
       model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date de passage"));
       model->setHeaderData(4, Qt::Horizontal, QObject::tr("Etat"));

return model;
}
bool commande::supprimer(int IDcommande)
{
    QSqlQuery query;
    QString res = QString::number(IDcommande);
    query.prepare("delete from commandes where IDcommande=:id");
    query.bindValue(0,IDcommande);
    return query.exec();
}
bool commande::modifier(int IDcommande)
{

QSqlQuery query;
query.prepare("UPDATE  commandes SET mailClient=:mailClient, description=:description, etat=:etat WHERE IDcommande=:IDcommande");

query.bindValue(":IDcommande",IDcommande);
query.bindValue(":mailClient",mailClient);
query.bindValue(":description",description);
query.bindValue(":etat",etat);
return query.exec();
}

