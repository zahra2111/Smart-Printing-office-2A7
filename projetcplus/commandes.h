#ifndef COMMANDES_H
#define COMMANDES_H

#include <QDeclarativeItem>
#include <QMainWindow>
#include <QObject>
#include <QQuickItem>
#include <QSharedDataPointer>
#include <QWidget>

class commandesData;

class commandes
{
    Q_OBJECT
public:
    commandes();
    commandes(const commandes &);
    commandes &operator=(const commandes &);
    ~commandes();

private:
    QSharedDataPointer<commandesData> data;
};

#endif // COMMANDES_H
