//
// Created by Vathanan on 14/01/2020.
//
#include "Unit.h"

Unit::Unit(int price,int health,bool t,int p,int ad,int rangemin,int rangemax,Battlefield& bf,Player& P)
{
    m_price=price;
    m_currentHealth=health;
    m_team=t;
    m_pos=p;
    m_attackDmg=ad;
    m_rangeMax=rangemax;
    m_rangeMin=rangemin;
    Plateau=&bf;
    Joueur=&P;
}

int Unit::getPrice() const{
    return m_price;
}

void Unit::Move()
{
}

void Unit::Attack()
{
}

void Unit::toString(){
    std::cout << m_price;
    std::cout << "Hello world!" << std::endl;

}

void Unit::SuperSaiyan()
{
}

Unit::~Unit()
{
}

int Unit::getAttackDmg() const{
    return m_attackDmg;

}

int Unit::getRangeMax() const{
    return m_rangeMax;
}

int Unit::getRangeMin() const{
    return m_rangeMin;
}

