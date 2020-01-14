//
// Created by Vathanan on 14/01/2020.
//

#ifndef AOW_FANTASSIN_H
#define AOW_FANTASSIN_H
#include "Unit.h"

class Fantassin : public Unit{

public:

    Fantassin(int price,int health,bool t,int p,int ad,int rangemin,int rangemax,Battlefield& bf,Player& P);
    ~Fantassin();

    void Action();

    void attack();

    void action1();
    void action2();
    void action3();


};

#endif //AOW_FANTASSIN_H
