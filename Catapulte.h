//
// Created by Vathanan on 14/01/2020.
//

#ifndef AOW_CATAPULTE_H
#define AOW_CATAPULTE_H

#include "Unit.h"

class Catapulte : public Unit{
private:
    /* data */
public:
    Catapulte(int price,int health,bool t,int p,int ad,int rangemin,int rangemax,Battlefield& bf,Player& P);
    ~Catapulte();
};


Catapulte::~Catapulte()
{
}

#endif //AOW_CATAPULTE_H
