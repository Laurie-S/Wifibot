#ifndef ITEM_H
#define ITEM_H
#include <QApplication>

class Item {

private :
   int id;
   QString name;
   int damage;
   int heal;
   QString path;

public:
    Item();
    Item(int p_id, QString p_name, int p_damage, int p_healt, QString p_path);
    ~Item();

    QString getNameItem();
    int getIdItem();
    int getDamage();
    int getHeal();
    QString getPathItem();

    void setNameItem(QString p_name);
    void setIdItem(int p_id);
    void setDamage(int p_damage);
    void setHeal(int p_heal);
    void setPathItem(QString p_path);

};

#endif // Item_H
