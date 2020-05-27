#ifndef SITUATION_H
#define SITUATION_H

#include <QApplication>
#include "item.h"
#include "ennemi.h"
#include <QWidget>
#include <QPushButton>



class Situation{

private:
    int id; // 0 = normale, 1 = ennemi present et situation mortelle, 2= situation victoire
    int nb_choix;
    QString path_image;
    QString path_actuel;
    int path_next1;
    int path_next2;
    int path_next3;
    int path_next4;
    QString message;
    QString message_choix;
    QString choix1;
    QString choix2;
    QString choix3;
    QString choix4;
    Ennemi monstre;

public:
    Situation();
    Situation(int p_id, int p_nb_choix, QString p_path_image, QString message, QString p_path_actuel, QString p_choix1, QString p_choix2, QString p_choix3, QString p_choix4, int p_path_next1, int p_path_next2, int p_path_next3, int p_path_next4, Ennemi p_monstre);
    ~Situation();

    int getIdSituation();
    int getNbChoix();
    QString getPathSituation();
    QString getPathImage();
    QString getMessage();
    QString getPathNext();
    QString getMessageChoix();
    QString getChoix1();
    QString getChoix2();
    QString getChoix3();
    QString getChoix4();
    int getPathNext1();
    int getPathNext2();
    int getPathNext3();
    int getPathNext4();
    Ennemi getEnnemi();

    void setIdSituation(int p_id);
    void setPathSituation(QString p_path);
    void setMessage(QString p_message);
    void setPathImage(QString p_path_image);
    void setPathNext(QString p_path_next);
    void setMessageChoix(QString p_message);


};

#endif // SITUATION_H
