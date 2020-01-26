//
// Created by Vathanan on 14/01/2020.
//

#ifndef AOW_UNIT_H
#define AOW_UNIT_H

#include "Battlefield.h"
#include <iostream>
#include <sstream>

class Unit{
protected :
    int pos; //position dans le tableau de case
    int hp; //points de vie actuel
    int price; //prix de d'achat de l'unité
    int attackDmg; //dégats d'attaque de l'unité
    int rangeMin;//portée minimale
    int rangeMax; //portée maximale
    Battlefield* plateau;
    bool team; //appartenance à l'équipe, true pour bleu, false pour rouge
    bool act=false; // bool renvoyant si l'action 1 a été effectuée ou non
    std::string nom; //nom de l'unité
    static int id;// identifiant unique des unités, utilisés pour créer le nom


public:
    Unit(int p,int hp, int price, int attackDmg, int rangeMin, int rangeMax, Battlefield *plateau, bool team);

    Unit(int p);

    //getters and setters
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

    void doDmg(Unit *u, int i); //inflige des degats i à une unité u

    void doDmg(Fort *f, int i);//inflige des degats i à un fort f

    void attack(int position);//essaye d'attaquer le contenu de la case d'indice position

    void move(int position);//essaye de se déplacer dans la case d'indice position

    void takeDmg(int i); //subit des dégats d'un montant i

    bool isDead();//vérifie si décédé

    virtual void action1() = 0;//Forcer les classe filles a les definir + transformation en class abstraites
    virtual void action2() = 0;
    virtual void action3() = 0;
    virtual void promote() = 0;//promote si tue une unité, utile que dans fantassin
    virtual std::string print() = 0 ;
    virtual ~Unit();//destructeur

    void setI(int j);

    const std::string &getNom() const;

    void setNom(const std::string &nom);
};


#endif //AOW_UNIT_H
