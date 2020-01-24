//
// Created by Vathanan on 14/01/2020.
//
#ifndef AOW_FORT_H
#define AOW_FORT_H

#include <ostream>

class Battlefield;
class Player;


class Fort{
protected:
    int hp;
    Battlefield* Plateau;
    bool team;
public:

    Fort(int pos,int hp, Battlefield *plateau, bool team);

    friend std::ostream &operator<<(std::ostream &os, const Fort &fort);

    int getHp() const;

    void setHp(int hp);

    Battlefield *getPlateau() const;

    void setPlateau(Battlefield *plateau);

    bool isTeam() const;

    void setTeam(bool team);
};

#endif //AOW_FORT_H
