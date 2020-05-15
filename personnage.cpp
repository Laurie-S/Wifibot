#include "personnage.h"
#include <QApplication>
#include "item.h"
#include "personnage.h"

//constructeur
Personnage::Personnage(){}

Personnage::Personnage(QString p_name, int p_health){
   name = p_name;
   health = p_health;
   size = 5;
}


QString Personnage::getNamePersonnage(){
    return name;
}

int Personnage::getHealth(){
    return health;
}

QList<Item *> Personnage::getInventory(){
    return inventory;
}
int Personnage::getSize(){
    return size;
}

void Personnage::setNamePersonnage(QString p_name){
    name = p_name;
}

void Personnage::setHealth(int p_health){
    health= p_health;
}

void Personnage::setInventory(QList<Item *> p_inventory){
    inventory = p_inventory;
}

void Personnage::setSize(int p_size){
    size = p_size;
}

void Personnage::removeItem(Item *objet){
    for(int i =0; i< inventory.size(); i++){
        if((*objet).getIdItem() == (*inventory[i]).getIdItem()){
            inventory.removeAt(i);
        }
    }
}

QString Personnage::addItem(Item *objet){
    QString message;
            if(inventory.size() == size){
                message ="Impossible de prendre l'objet, votre inventaire est plein";
            }
            else{
                inventory << objet;
                message ="Ajouter à votre inventaire !";
            }
    return message;
}



Personnage::~Personnage(){}


