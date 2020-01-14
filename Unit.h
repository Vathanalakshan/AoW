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
public :
    int m_price;
    int m_attackDmg;
    int m_rangeMin;
    int m_rangeMax;
    Battlefield* Plateau;
    Player* Joueur;



public:

    Unit(int price,int health,bool t,int p,int ad,int rangemin,int rangemax,Battlefield& bf,Player& P);
    int getPrice();

    int getAttackDmg() const;

    int getRangeMax() const;

    int getRangeMin() const;

    int getPrice() const;

    void Move();
    void Attack();

    virtual void action1() = 0;//Forcer les classe filles a les definir + transformation en class abstraites
    virtual void action2() = 0;
    virtual void action3() = 0;

    void toString();

    void SuperSaiyan();//Promote


    ~Unit();

};


#endif //AOW_UNIT_H
