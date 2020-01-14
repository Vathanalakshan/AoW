//
// Created by Vathanan on 14/01/2020.
//

#ifndef AOW_ELEMENTS_H
#define AOW_ELEMENTS_H

#include <string>
class Elements
{
protected:
    int m_pos;//Ses position
    bool m_team;//L'equipe
    int m_currentHealth;


public:
    Elements(){};
    ~Elements();

    int getPos() const;
    bool getTeam() const;
    int getCurrentHealth() const;
    virtual void toString() =0;//Rendre abstact la classe

};

#endif //AOW_ELEMENTS_H
