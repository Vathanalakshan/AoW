#include <iostream>
#include "Player.h"
#include "Fantassin.h"
#include "Battlefield.h"
#include "Archer.h"
#include "Catapulte.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    Battlefield b;
    Player p;
    Archer *a= new Archer(5,500,10,78,45,45,&b,&p);
    Fantassin*f= new Fantassin(6,500,10,78,45,45,&b,&p);
    Catapulte *c= new Catapulte(3,500,10,78,45,45,&b,&p);
    b.Generer();
    b.addUnit(a,a->getPos());
    b.addUnit(f,f->getPos());
    b.addUnit(c,c->getPos());
    std::cout<<b;

    //b.removeUnit(6);

    b.moveUnit(3,2);
    std::cout<<b;

    return 0;
}
