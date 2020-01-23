//
// Created by Vathanan on 14/01/2020.
//
#ifndef AOW_FORT_H
#define AOW_FORT_H

#include <ostream>
#include "Elements.h"

class Battlefield;
class Player;


class Fort : public Elements
{
protected:
    int hp;
    Battlefield* Plateau;
    Player* Joueur;
public:

    Fort(int pos,int hp, Battlefield *plateau, Player *joueur);

    friend std::ostream &operator<<(std::ostream &os, const Fort &fort);
};

#endif //AOW_FORT_H
