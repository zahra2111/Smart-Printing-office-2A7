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
model->setQuery("select * from Employee where lower(nom) LIKE lower('%" + rech + "%') OR lower(prenom) LIKE lower('%" + rech + "%') OR lower(poste) LIKE lower('%" + rech + "%')");
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
    query.prepare("Delete from Employee where id= :id");
    query.bindValue(":id",res);
    return query.exec();
//QSqlQuery query;
//QString res = QString::number(id);
//query.prepare("Delete from Employee where id=:id");
//query.bindValue(":id",res);
//return query.exec();
}

QSqlQueryModel * Employee::show_Desc_name()
{
    QSqlQueryModel* model = new QSqlQueryModel();
     model->setQuery("select * from Employee ORDER BY ID DESC ");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("MAIL"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("NOM"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("PRENOM"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("POSTE"));
     return model;
}
QSqlQueryModel * Employee::show_Asc_name()
{
    QSqlQueryModel* model = new QSqlQueryModel();
     model->setQuery("select * from Employee ORDER BY ID ASC ");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("MAIL"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("NOM"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("PRENOM"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("POSTE"));
     return model;
}

bool Employee::ChaineValide(QString chaine)
    {
        int i=0;
        while(i<chaine.size())
        {
            if(chaine[i]=='&' || chaine[i]=='~' || chaine[i]=='"' || chaine[i]=='#' || chaine[i]=='r'||chaine[i]=='='||chaine[i]==':' ||
                    chaine[i]=='-' || chaine[i]=='[' || chaine[i]=='|' ||chaine[i]=='_'||chaine[i]=='/'||chaine[i]=='!'||chaine[i]=='+'||
                    chaine[i]=='1' ||chaine[i]=='2' ||chaine[i]=='3' ||chaine[i]=='4' ||chaine[i]=='5' ||chaine[i]=='6' ||chaine[i]==']'||
                    chaine[i]=='7' ||chaine[i]=='8' ||chaine[i]=='9' ||chaine[i]=='0' ||chaine[i]=='@' ||chaine[i]==')' ||chaine[i]=='}'||
                    chaine[i]=='%' ||chaine[i]=='*' ||chaine[i]=='?' ||chaine[i]==',' ||chaine[i]==';' ||chaine[i]=='.')
            {
                return false;
                break;
            }
            i++;
        }

        return true;
    }
