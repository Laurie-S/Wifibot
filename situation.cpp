#include "situation.h"

Situation::Situation(){}


 Situation::Situation(int p_id, int p_nb_choix, QString p_path_image, QString p_message, QString p_path_actuel, QString p_choix1, QString p_choix2, QString p_choix3, QString p_choix4, int p_path_next1, int p_path_next2, int p_path_next3, int p_path_next4, Ennemi p_monstre, Item p_item){
    id = p_id;
    nb_choix = p_nb_choix;
    path_image = p_path_image;
    message = p_message;
    path_actuel = p_path_actuel;
    choix1 = p_choix1;
    choix2 = p_choix2;
    choix3 = p_choix3;
    choix4 = p_choix4;
    path_next1 = p_path_next1;
    path_next2 = p_path_next2;
    path_next3 = p_path_next3;
    path_next4 = p_path_next4;
    monstre = p_monstre;
    item = p_item;

}


int Situation::getIdSituation(){
    return id;
}


int Situation::getNbChoix(){
    return nb_choix;
}

QString Situation::getPathSituation(){
    return path_actuel;
}


QString Situation::getMessage(){
    return message;
}

QString Situation::getChoix1(){
    return choix1;
}

QString Situation::getChoix2(){
    return choix2;
}

QString Situation::getChoix3(){
    return choix3;
}
QString Situation::getChoix4(){
    return choix4;
}

int Situation::getPathNext1(){
    return path_next1;
}

int Situation::getPathNext2(){
    return path_next2;
}

int Situation::getPathNext3(){
    return path_next3;
}

int Situation::getPathNext4(){
    return path_next4;
}

QString Situation::getPathImage(){
    return path_image;
}

Ennemi Situation::getEnnemi(){
    return monstre;
}

Item Situation::getItem(){
    return item;
}

void Situation::setIdSituation(int p_id){
    id = p_id;
}

void Situation::setPathSituation(QString p_path){
    path_actuel =p_path;
}

void Situation::setMessage(QString p_message){
    message = p_message;
}


Situation::~Situation(){}
