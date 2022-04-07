#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <QString>
#include<QSqlQuery>
#include<QSqlQueryModel>

class Employee
{
    int id;
    QString mail, nom, prenom, poste,chaine;
public:

    Employee(){}
    Employee(int,QString,QString,QString,QString);
    int getid(){return id;}
    QString getmail(){return mail;}
    QString getnom(){return nom;}
    QString getprenom(){return prenom;}
    QString getposte(){return poste;}
    void setid(int id){this->id=id;}
    void setmail(QString ml){this->mail=ml;}
    void setnom(QString nm){nom=nm;}
    void setprenom(QString pm){prenom=pm;}
    void setposte(QString ps){poste=ps;}
    QSqlQueryModel * afficher(QString, int);
    QSqlQueryModel * afficher2();
    bool ajouter();
    bool modify(int);
    bool supprimer(int);
    bool ChaineValide(QString chaine);
    QSqlQueryModel * show_Desc_name();
QSqlQueryModel * show_Asc_name();

};

#endif // EMPLOYEE_H
