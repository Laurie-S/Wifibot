#ifndef PERSONNAGE_H
#define PERSONNAGE_H
#include <QApplication>
#include "item.h"


class Personnage{

private:
    QString name;
    int health;
    QList<Item> inventory;
    int size = 5;

public:
    Personnage();
    Personnage(QString p_name, int p_health);
    ~Personnage();

    QString getNamePersonnage();
    int getHealth();
    QList<Item> getInventory();
    int getSize();

    void setNamePersonnage(QString p_name);
    void setHealth(int p_health);
    void setInventory(QList<Item> p_inventory);
    void setSize(int p_size);

    QString utiliserPotion();
    void removeItem(Item objet);
    QString addItem(Item objet);

};

#endif // PERSONNAGE_H
