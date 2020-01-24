//
// Created by Vathanan on 14/01/2020.
//


#ifndef AOW_ARCHER_H
#define AOW_ARCHER_H

#include <ostream>
#include "Unit.h"

class Archer : public Unit{

public:
    Archer(int p,int hp, int price, int attackDmg, int rangeMin, int rangeMax, Battlefield *plateau, Player *joueur);


    void action1() override;
    void action2() override;
    void action3() override;


};


#endif //AOW_ARCHER_H
