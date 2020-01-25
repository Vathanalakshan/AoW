//
// Created by Vathanan on 14/01/2020.
//

#include "Archer.h"
Archer::Archer(int p,int hp, int price, int attackDmg, int rangeMin, int rangeMax, Battlefield *plateau, bool t)
        : Unit(p,hp, price, attackDmg, rangeMin, rangeMax, plateau, t) {}


void Archer::action1(){
    std::cout<< "1 " << std::endl;
};
void Archer::action2(){
    std::cout<< "1 " << std::endl;

};
void Archer::action3(){
    std::cout<< "1 " << std::endl;
};