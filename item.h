#ifndef ITEM_H
#define ITEM_H
#include <QApplication>

class Item {

private :
   QString name;
   int damage;
   int heal;
   QString path;

public:
    Item();
    Item(QString p_name, int p_damage, int p_healt, QString p_path);
    ~Item();

    QString getNameItem();
    int getDamage();
    int getHeal();
    QString getPathItem();

    void setNameItem(QString p_name);
    void setDamage(int p_damage);
    void setHeal(int p_heal);
    void setPathItem(QString p_path);

};

#endif // Item_H
