//
// Created by Vathanan on 14/01/2020.
//

#include "Catapulte.h"

Catapulte::Catapulte(int p,int hp, int price, int attackDmg, int rangeMin, int rangeMax, Battlefield *plateau, bool t)
        : Unit(p,hp, price, attackDmg, rangeMin, rangeMax, plateau, t) {
    id++;
    nom = " Cata-" + std::to_string(id);
}


void Catapulte::action1(){//attaque de zone selon portée
    for (int i=rangeMin; i<rangeMax;i++){
        if (!act) {//si pas déjà attaquer, essaye d'attaquer ennemi selon la portée
            if (isTeam()) {

                attack(pos + i);
                attack(pos+i+1);
            } else {
                attack(pos - i);
                attack(pos - i-1);
            }
        }
    }
    if(!act){//si pas déjà attaqué, et qu'un ennemi est sur la portée maximale, attaque et peut toucher un soldat allier
        if(isTeam()){
                attack(pos + rangeMax);

                Case c = plateau->getCase(pos + rangeMax - 1);
                if(c.getE()!=nullptr) {
                    doDmg(c.getE(), attackDmg);
                }

        }
        else{
                attack(pos - rangeMax);
                Case c = plateau->getCase(pos - rangeMax + 1);
            if(c.getE()!=nullptr) {
                doDmg(c.getE(), attackDmg);
            }
        }
    }

};

void Catapulte::action2(){


};
void Catapulte::action3(){//se déplace si pas attaquer, limité par taille du plateau+portée max
    if(!getact()){
        if (isTeam()){
            if (pos < 7) {
                move(pos + 1);
            }
        }
        else{
            if (pos > 4) {
                move(pos-1);
            }
        }
    }
    act=false;
}

void Catapulte::promote() {

}

std::ostream &operator<<(std::ostream &os, const Catapulte &catapulte) {
    os << catapulte.getNom() <<" "<<catapulte.getHp() <<" Hp";
    return os;
}

std::string Catapulte::print() {
    return getNom()+ " " + std::to_string(getHp())+ "Hp";
}

Catapulte::~Catapulte() {
    std::cout<< nom << " meurt." << std::endl;
}