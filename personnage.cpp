#include "personnage.h"
#include <QApplication>
#include "item.h"
#include "personnage.h"

//constructeur
Personnage::Personnage(){}

Personnage::Personnage(QString p_name, int p_health){
   name = p_name;
   health = p_health;
   size = 6;
}


QString Personnage::getNamePersonnage(){
    return name;
}

int Personnage::getHealth(){
    return health;
}

QList<Item> Personnage::getInventory(){
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

void Personnage::setInventory(QList<Item> p_inventory){
    inventory = p_inventory;
}

void Personnage::setSize(int p_size){
    size = p_size;
}

void Personnage::removeItem(Item objet){
    for(int i =0; i< inventory.size(); i++){
        if((objet).getNameItem() == (inventory[i]).getNameItem()){
            inventory.removeAt(i);
        }
    }
}

QString Personnage::addItem(Item objet){
    bool find = false;
    QString message;
    for(int i =0; i<inventory.size(); i++){
        if(inventory[i].getIdItem() == objet.getIdItem()){
            find = true;
        }
    }
    if(find == true){
        message ="\n Vous possédez déjà cet objet dans votre inventaire";
    }
    else{

        if(inventory.size() == 6){
            message ="\n Impossible de prendre l'objet, votre inventaire est plein";
         }

         else if(inventory.size() <6){
            inventory << objet;
             message ="\n Ajouté à votre inventaire !";
          }
    }

    return message;
}

QString Personnage::utiliserSoin(int id){
    QString message;
    for(int i=0; i<inventory.size(); i++){
      if((inventory[i]).getIdItem() == id){
            setHealth(health +( inventory[i]).getHeal());
            message = "\n Utilisation de l'objet "+ (inventory[i]).getNameItem();
            inventory.removeAt(i);
      }
    }
    return message;
}



Personnage::~Personnage(){}


