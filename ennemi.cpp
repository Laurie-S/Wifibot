#include "ennemi.h"

    //constructeur
    Ennemi::Ennemi(){ }

    //constructeur
    Ennemi::Ennemi(int p_id, QString p_name, int p_attack){
            id = p_id;
            name = p_name;
            attack = p_attack;

    }
    // getters et setteurs

    QString Ennemi::getNameEnnemi(){
        return name;
    }


    int Ennemi::getIdEnnemi(){
        return id;
    }


    int Ennemi::getAttack(){
        return attack;
    }





    void Ennemi::setNameEnnemi(QString p_name){
        name = p_name;
    }

    void Ennemi::setIdEnnemi(int p_id){
        id = p_id;
    }

    void Ennemi::setAttack(int p_attack){
        attack = p_attack;
    }

    Ennemi::~Ennemi(){}

