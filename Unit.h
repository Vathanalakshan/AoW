//
// Created by Vathanan on 14/01/2020.
//

#ifndef AOW_UNIT_H
#define AOW_UNIT_H
#include "Elements.h"
#include "Player.h"
#include "Battlefield.h"
#include <iostream>
#include <sstream>

class Unit :public Elements{
protected :
    int hp;
    int price;
    int attackDmg;
    int rangeMin;
    int rangeMax;
    Battlefield* Plateau;
    Player* Joueur;

public:
    Unit(int p,int hp, int price, int attackDmg, int rangeMin, int rangeMax, Battlefield *plateau, Player *joueur);

    int getHp() const;

    void setHp(int hp);

    int getPrice() const;

    void setPrice(int price);

    int getAttackDmg() const;

    void setAttackDmg(int attackDmg);

    int getRangeMin() const;

    void setRangeMin(int rangeMin);

    int getRangeMax() const;

    void setRangeMax(int rangeMax);

    Battlefield *getPlateau() const;

    void setPlateau(Battlefield *plateau);

    Player *getJoueur() const;

    void setJoueur(Player *joueur);

    virtual void action1() = 0;//Forcer les classe filles a les definir + transformation en class abstraites
    virtual void action2() = 0;
    virtual void action3() = 0;

};


#endif //AOW_UNIT_H
