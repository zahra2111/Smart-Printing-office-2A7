#ifndef CONNECTION_H
#define CONNECTION_H
#include <QSqlDatabase>

class Connection
{
    QSqlDatabase db;
public:
    Connection();
    bool createconnect();
    void closeconnection();
};

#endif // CONNECTION_H
