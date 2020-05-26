#include "ennemi.h"

    //constructeur
    Ennemi::Ennemi(){ }

    //constructeur
    Ennemi::Ennemi(QString p_name, int p_attack){
            name = p_name;
            attack = p_attack;

    }
    // getters et setteurs

    QString Ennemi::getNameEnnemi(){
        return name;
    }


    int Ennemi::getAttack(){
        return attack;
    }

    void Ennemi::setNameEnnemi(QString p_name){
        name = p_name;
    }

    void Ennemi::setAttack(int p_attack){
        attack = p_attack;
    }

    Ennemi::~Ennemi(){}

