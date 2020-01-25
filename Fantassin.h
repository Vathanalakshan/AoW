//
// Created by Vathanan on 14/01/2020.
//

#ifndef AOW_FANTASSIN_H
#define AOW_FANTASSIN_H

#include <ostream>
#include "Unit.h"

class Fantassin : public Unit{

private:
    bool superSoldat=false;

public:
    Fantassin(int pos,int hp, int price, int attackDmg, int rangeMin, int rangeMax, Battlefield *plateau, Player *joueur);

    friend std::ostream &operator<<(std::ostream &os, const Fantassin &fantassin);


    void action1() override;
    void action2() override;
    void action3() override;
    void promote() override;

};

#endif //AOW_FANTASSIN_H
