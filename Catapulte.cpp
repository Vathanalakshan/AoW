//
// Created by Vathanan on 14/01/2020.
//

#include "Catapulte.h"

Catapulte::Catapulte(int p,int hp, int price, int attackDmg, int rangeMin, int rangeMax, Battlefield *plateau, Player *joueur)
        : Unit(p,hp, price, attackDmg, rangeMin, rangeMax, plateau, joueur) {}

std::ostream &operator<<(std::ostream &os, const Catapulte &catapulte) {
    os << static_cast<const Unit &>(catapulte);
    return os;
}
void Catapulte::action1(){
    std::cout<< "1 " << std::endl;
};
void Catapulte::action2(){
    std::cout<< "1 " << std::endl;

};
void Catapulte::action3(){
    std::cout<< "1 " << std::endl;
};