//
// Created by Vathanan on 14/01/2020.
//

#ifndef AOW_CATAPULTE_H
#define AOW_CATAPULTE_H

#include <ostream>
#include "Unit.h"

class Catapulte : public Unit{
protected:

public:
    Catapulte(int p,int hp, int price, int attackDmg, int rangeMin, int rangeMax, Battlefield *plateau, bool t);

    friend std::ostream &operator<<(std::ostream &os, const Catapulte &catapulte);

    void action1() override;
    void action2() override;
    void action3() override;

    void promote() override ;
    std::string print() override;
};


#endif //AOW_CATAPULTE_H
