#ifndef COMMANDE_H
#define COMMANDE_H

#include <QDate>
#include <QString>
#include <qsqlquerymodel.h>
class commande
{

public:
    commande();
    commande(int,QString,QString,QDate,QString);
    //getters
    QString getMailClient();
    QString getDescription();
     QDate getDate();
    QString getEtat();
    int getIDcommande();
    //setters
    void setMailClient(QString);
    void setDescription(QString );
    void setDate( QDate);
     void setEtat(QString );
   void setIDcommande(int);
bool ajouter();
QSqlQueryModel* afficher();
bool supprimer(int );
bool modifier(int );
private:
     int IDcommande;
     QDate datep ;
     QString mailClient,description,etat;
};

#endif // COMMANDE_H
