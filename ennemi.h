#ifndef ENNEMI_H
#define ENNEMI_H
#include <QApplication>

class Ennemi{

private :
    QString name;
    int attack;

public:
    Ennemi();
    Ennemi(QString p_name, int p_attack);
    ~Ennemi();

    QString getNameEnnemi();
    int getAttack();

    void setNameEnnemi(QString p_name);
    void setAttack(int p_attack);

};

#endif // ENNEMI_H
