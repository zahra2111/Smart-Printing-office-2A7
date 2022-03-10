#include "employee.h"
#include <QDebug>

Employee::Employee(int id,QString mail,QString nom,QString prenom,QString poste)
{
    this->id=id;
    this->mail=mail;
    this->nom=nom;
    this->prenom=prenom;
    this->poste=poste;
}

QSqlQueryModel * Employee::afficher(QString rech, int ord)
{
QSqlQueryModel * model=new QSqlQueryModel();
model->setQuery("select * from Employee where lower(nom) LIKE lower('%" + rech + "%')");
model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));

model->setHeaderData(1,Qt::Horizontal,QObject::tr("MAIL"));

model->setHeaderData(2,Qt::Horizontal,QObject::tr("NOM"));

model->setHeaderData(3,Qt::Horizontal,QObject::tr("PRENOM"));
model->setHeaderData(4,Qt::Horizontal,QObject::tr("POSTE"));
return model;
}
QSqlQueryModel * Employee::afficher2()
{
QSqlQueryModel * model=new QSqlQueryModel();
model->setQuery("select * from Employee");
model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));

model->setHeaderData(1,Qt::Horizontal,QObject::tr("MAIL"));

model->setHeaderData(2,Qt::Horizontal,QObject::tr("NOM"));

model->setHeaderData(3,Qt::Horizontal,QObject::tr("PRENOM"));
model->setHeaderData(4,Qt::Horizontal,QObject::tr("POSTE"));
return model;
}
bool Employee::ajouter()
{
    QSqlQuery query;
    QString res = QString::number(id);
    QString res2 = mail;
    query.prepare("insert into Employee (id,mail,nom,prenom,poste) ""values(:id,:mail,:nom,:prenom,:poste)");
   query.bindValue(":id",res);
   query.bindValue(":mail",res2);
   query.bindValue(":nom",nom);
   query.bindValue(":prenom",prenom);
   query.bindValue(":poste",poste);
   return query.exec();
}
bool Employee::modify(int id){
    QSqlQuery query;
    query.prepare("UPDATE Employee SET mail=:mail, nom=:nom,  prenom=:prenom, poste=:poste WHERE id=:id");
    query.bindValue(":id",id);
    query.bindValue(":mail",mail);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":poste",poste);
    return query.exec();
}
bool Employee::supprimer(int id)
{
QSqlQuery query;
QString res = QString::number(id);
query.prepare("Delete from Employee where id=:id");
query.bindValue(":id",res);
return query.exec();
}
