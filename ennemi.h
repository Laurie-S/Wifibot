#ifndef ENNEMI_H
#define ENNEMI_H
#include <QApplication>

class Ennemi{

private :
    int id;
    QString name;
    int attack;

public:
    Ennemi();
    Ennemi(int p_id, QString p_name, int p_attack);
    ~Ennemi();

    QString getNameEnnemi();
    int getIdEnnemi();
    int getAttack();

    void setNameEnnemi(QString p_name);
    void setIdEnnemi(int p_id);
    void setAttack(int p_attack);

};

#endif // ENNEMI_H
