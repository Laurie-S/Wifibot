#include "situation.h"

Situation::Situation(){}


Situation::Situation(int p_id, int p_ennemi, int p_item, QString p_path){
    id = p_id;
    ennemi = p_ennemi;
    item = p_item;
    path = p_path;

}


int Situation::getIdSituation(){
    return id;
}

int Situation::getEnnemi(){
    return ennemi;
}

int Situation::getItem(){
    return item;
}

QString Situation::getPathSituation(){
    return path;
}

void Situation::setIdSituation(int p_id){
    id = p_id;
}

void Situation::setEnnemi(int p_ennemi){
    ennemi = p_ennemi;
}

void Situation::setItem(int p_item){
    item = p_item;
}

void Situation::setPathSituation(QString p_path){
    path =p_path;
}


QList <QPushButton *> TwoChoice(QString choix1, QString choix2,  QWidget *zoneCentrale){
    QPushButton *bouton1 = new QPushButton(choix1);
    bouton1->setGeometry(800,600, 50, 15);
    QPushButton *bouton2 = new QPushButton(choix2);
    bouton1->setGeometry(800, 610, 50, 15);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(bouton1);
    layout->addWidget(bouton2);

    QList <QPushButton *> listButton;
   listButton << bouton1 << bouton2;

    zoneCentrale->setLayout(layout);
    return listButton;
}

QList <QPushButton> ThreeChoice(QString choix1, QString choix2, QString choix3,  QWidget zoneCentrale);
QList <QPushButton> FourChoice(QString choix1, QString choix2, QString choix3, QString choix4,  QWidget zoneCentrale);

Situation::~Situation(){}
