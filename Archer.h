//
// Created by Vathanan on 14/01/2020.
//

#include "Unit.h"

#ifndef AOW_ARCHER_H
#define AOW_ARCHER_H

class Archer : public Unit{

public:

    Archer(int price,int health,bool t,int p,int ad,int rangemin,int rangemax,Battlefield& bf,Player& P);
    ~Archer();

    void Action();

    void attack();

    void action1();
    void action2();
    void action3();


};


#endif //AOW_ARCHER_H
