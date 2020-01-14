//
// Created by Vathanan on 14/01/2020.
//

#include "Archer.h"
Archer::Archer(int price,int health,bool t,int p,int ad,int rangemin,int rangemax,Battlefield& bf,Player& P):Unit(price,health,t,p,ad,rangemin,rangemax,bf,P)

{

}
Archer::~Archer() = default;;

void Archer::action1(){

};//Forcer les classe filles a les definir + transformation en class abstraites
void Archer::action2(){

};
void Archer::action3(){

}

void Archer::attack() {

};


