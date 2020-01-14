//
// Created by Vathanan on 14/01/2020.
//
#include "Fantassin.h"

Fantassin::Fantassin(int price,int health,bool t,int p,int ad,int rangemin,int rangemax,Battlefield& bf,Player& P):Unit(price,health,t,p,ad,rangemin,rangemax,bf,P)

{

}
Fantassin::~Fantassin() {};

void Fantassin::action1(){

};//Forcer les classe filles a les definir + transformation en class abstraites
void Fantassin::action2(){

};
void Fantassin::action3(){

};
