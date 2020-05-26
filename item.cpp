#include "item.h"
#include <QApplication>


//constructeur
Item::Item(){ }

//constructeur
Item::Item(QString p_name, int p_damage, int p_heal, QString p_path){
        name = p_name;
        damage = p_damage;
        heal = p_heal ;
        path = p_path;
}
// getters et setteurs

QString Item ::getNameItem(){
    return name;
}

int Item::getDamage(){
    return damage;
}


int Item::getHeal(){
    return heal;
}

QString Item::getPathItem(){
    return path;
}


void Item::setNameItem(QString p_name){
    name = p_name;
}


void Item::setDamage(int p_damage){
    damage = p_damage;
}

void Item::setHeal(int p_heal){
    heal = p_heal;
}

void Item::setPathItem(QString p_path){
    path = p_path;
}

Item::~Item(){}
