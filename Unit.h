//
// Created by Vathanan on 14/01/2020.
//

#ifndef AOW_UNIT_H
#define AOW_UNIT_H
#include "Player.h"
#include "Battlefield.h"
#include <iostream>
#include <sstream>

class Unit{
protected :
    int pos;
    int hp;
    int price;
    int attackDmg;
    int rangeMin;
    int rangeMax;
    Battlefield* plateau;
    bool team;
    bool action1=false;

public:
    Unit(int p,int hp, int price, int attackDmg, int rangeMin, int rangeMax, Battlefield *plateau, bool team);

    Unit(int p);

    int getHp() const;

    void setHp(int hp);

    int getact() const;

    void setact(bool act);

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

    int getPos() const;

    void setPos(int pos);

    bool isTeam() const;

    bool sameTeam(Unit *u);

    void setTeam(bool team);

    bool doDmg(Unit *u, int i);

    void doDmg(Fort *f, int i);

    void attack(int position);

    void move(int position);

    void takeDmg(int i);

    bool isDead();

    virtual void action1() = 0;//Forcer les classe filles a les definir + transformation en class abstraites
    virtual void action2() = 0;
    virtual void action3() = 0;
};


#endif //AOW_UNIT_H
