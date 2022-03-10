#include "commandes.h"

class commandesData : public QSharedData
{
public:

};

commandes::commandes() : data(new commandesData)
{

}

commandes::commandes(const commandes &rhs) : data(rhs.data)
{

}

commandes &commandes::operator=(const commandes &rhs)
{
    if (this != &rhs)
        data.operator=(rhs.data);
    return *this;
}

commandes::~commandes()
{

}
