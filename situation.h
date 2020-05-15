#ifndef SITUATION_H
#define SITUATION_H
#include <QApplication>
#include "item.h"
#include "ennemi.h"
#include "fen_principale.h"


class Situation{

private:
    int id;
    int ennemi;
    int item;
    QString path;

public:
    Situation();
    Situation(int p_id, int p_ennemi, int p_item, QString p_path);
    ~Situation();

    int getIdSituation();
    int getEnnemi();
    int getItem();
    QString getPathSituation();

    void setIdSituation(int p_id);
    void setEnnemi(int p_ennemi);
    void setItem(int p_item);
    void setPathSituation(QString p_path);

    QList <QPushButton *> TwoChoice(QString choix1, QString choix2,  QWidget *zoneCentrale);
    QList <QPushButton> ThreeChoice(QString choix1, QString choix2, QString choix3,  QWidget *zoneCentrale);
    QList <QPushButton> FourChoice(QString choix1, QString choix2, QString choix3, QString choix4,  QWidget *zoneCentrale);


};

#endif // SITUATION_H
