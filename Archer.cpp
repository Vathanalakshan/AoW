//
// Created by Vathanan on 14/01/2020.
//

#include "Archer.h"
Archer::Archer(int p,int hp, int price, int attackDmg, int rangeMin, int rangeMax, Battlefield *plateau, bool t)
        : Unit(p,hp, price, attackDmg, rangeMin, rangeMax, plateau, t) {
    id = i;
    i = i++;
    if (team) {
        nom = "Archer " + id;
        nom = nom + " bleu";
    } else {
        nom = "Archer " + id;
        nom = nom + " rouge";
    }

}

void Archer::action1(){
    for (i=rangeMin; i<rangeMax+1;i++){
        if (!act) {
            if (isTeam()) {
                attack(pos + i);
            } else {
                attack(pos - i);
            }
        }
    }

    std::cout<< "1 " << std::endl;
};
void Archer::action2(){
    if (isTeam()){
        move(pos+1);
    }
    else{
        move(pos-1);
    }
    std::cout<< "1 " << std::endl;

};
void Archer::action3(){
    std::cout<< "1 " << std::endl;
};