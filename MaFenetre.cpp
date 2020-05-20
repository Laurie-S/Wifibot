#include "MaFenetre.h"
#include <QLabel>
#include <QMessageBox>
#include <QInputDialog>
#include <QString>
#include <QFontMetrics>
#include <QLineEdit>
#include <QPicture>

MaFenetre::MaFenetre() : QWidget()
{
    longueur = 900;
    largeur = 600;
    bouton_larg = 50;
    bouton_long = bouton_larg*3;


    setFixedSize(longueur, largeur);

     Situation sit(1, 0, 0, 4, "C:/Users/Utilisateur/Documents/Dossier perso Celine/Cours3A/Projet Jeu Choix/test/Main_Menu.jpg", "Choississez le chemin à prendre dans la forêt", "chemin actuel", " gauche", "droite", "retour en arrière", "", "GAUCHE !", "DROITE !", "", "");
    setSituationActuelle(sit);
    Image = new QLabel(this);
    Image->setPixmap(QPixmap("C:/Users/Utilisateur/Documents/Dossier perso Celine/Cours3A/Projet Jeu Choix/test/Main_Menu.jpg"));
    Image->setVisible(false);


    m_texte = new QLabel(this); // Création de l"objet
    m_texte->setText("MENU PRINCIPAL"); // Définition du texte
    m_texte->setStyleSheet("QLabel { font : Arial ; background-color : none; color : white; font: 18pt;  }");
    m_texte->setGeometry(900/2-(taille_texte("MENU PRINCIPAL")/2),600/3-50,taille_texte("MENU PRINCIPAL") , 30);
    m_texte->setVisible(false);



    // Construction des boutons
    m_bouton_newGame = new QPushButton("Nouvelle partie", this);
    m_bouton_newGame->setCursor(Qt::PointingHandCursor);
    m_bouton_newGame->setGeometry(longueur/2-bouton_long/2, largeur/3, bouton_long, bouton_larg);
    QObject::connect(m_bouton_newGame, SIGNAL(clicked()), this, SLOT(Nouvelle_partie()));
    m_bouton_newGame->setVisible(false);

    m_bouton_saved = new QPushButton("Partie Sauvegardée", this);
    m_bouton_saved->setCursor(Qt::PointingHandCursor);
    m_bouton_saved->setGeometry(longueur/2-bouton_long/2, largeur/3+bouton_larg+10, bouton_long, bouton_larg);
    QObject::connect(m_bouton_saved, SIGNAL(clicked()), this, SLOT(charger()));
    m_bouton_saved->setVisible(false);


    m_bouton_quitter = new QPushButton("Quitter", this);
    m_bouton_quitter->setCursor(Qt::PointingHandCursor);
    m_bouton_quitter->setGeometry(longueur/2-bouton_long/2,  largeur/3+(2*bouton_larg)+20, bouton_long, bouton_larg);
    QObject::connect(m_bouton_quitter, SIGNAL(clicked()), qApp, SLOT(quit()));
    m_bouton_quitter->setVisible(false);

    m_bouton_Retour_Menu = new QPushButton("Retour", this);
    m_bouton_Retour_Menu->setCursor(Qt::PointingHandCursor);
    m_bouton_Retour_Menu->setGeometry(longueur/2-bouton_long/2, largeur/3+bouton_larg+10, bouton_long, bouton_larg);
    QObject::connect(m_bouton_Retour_Menu, SIGNAL(clicked()), this, SLOT(Menu()));
    m_bouton_Retour_Menu->setVisible(false);


    m_bouton_start= new QPushButton("Commencer", this);
    m_bouton_start->setCursor(Qt::PointingHandCursor);
    m_bouton_start->setGeometry(longueur/2-bouton_long/2, largeur/3, bouton_long, bouton_larg);
    QObject::connect(m_bouton_start, SIGNAL(clicked()), this, SLOT(Situ()));
    m_bouton_start->setVisible(false);

    /////////////////////////////////////////////////////////////////////////////////////////////
    // boutons pour les situations
    // bouton pour sauvegarder et quitter pendant les situations
    m_bouton_sauvegarder= new QPushButton("Sauv", this);
    m_bouton_sauvegarder->setCursor(Qt::PointingHandCursor);
    m_bouton_sauvegarder->setGeometry(0, 0, 30, 30);
    QObject::connect(m_bouton_sauvegarder, SIGNAL(clicked()), this, SLOT(SauvegarderEtQuitter()));
    m_bouton_sauvegarder->setVisible(false);


    // bouton pour continuer pendant les situations
    m_bouton_continuer = new QPushButton("Continuer", this);
    m_bouton_continuer->setCursor(Qt::PointingHandCursor);
    m_bouton_continuer->setGeometry(longueur-bouton_long, largeur-bouton_larg, bouton_long, bouton_larg);
    QObject::connect(m_bouton_continuer, SIGNAL(clicked()), this, SLOT());
    m_bouton_continuer->setVisible(false);


    // boutons pour les choix des situations
    m_bouton_choix1= new QPushButton("", this);
    m_bouton_choix1->setCursor(Qt::PointingHandCursor);
    QObject::connect(m_bouton_choix1, SIGNAL(clicked()), this, SLOT());
    m_bouton_choix1->setVisible(false);

    m_bouton_choix2= new QPushButton("", this);
    m_bouton_choix2->setCursor(Qt::PointingHandCursor);
    QObject::connect(m_bouton_choix2, SIGNAL(clicked()), this, SLOT());
    m_bouton_choix2->setVisible(false);

    m_bouton_choix3= new QPushButton("", this);
    m_bouton_choix3->setCursor(Qt::PointingHandCursor);
    QObject::connect(m_bouton_choix3, SIGNAL(clicked()), this, SLOT());
    m_bouton_choix3->setVisible(false);

    m_bouton_choix4= new QPushButton("", this);
    m_bouton_choix4->setCursor(Qt::PointingHandCursor);
    QObject::connect(m_bouton_choix4, SIGNAL(clicked()), this, SLOT());
    m_bouton_choix4->setVisible(false);


    Menu();


}

void MaFenetre::Menu(){

    m_texte->setText("MENU PRINCIPAL"); // Définition du texte
    m_texte->setGeometry(900/2-(taille_texte("MENU PRINCIPAL")/2),600/3-50,taille_texte("MENU PRINCIPAL") , 30);


    Image->setVisible(true);
    m_texte->setVisible(true);
    m_bouton_newGame->setVisible(true);
    m_bouton_saved->setVisible(true);
    m_bouton_quitter->setVisible(true);
    m_bouton_Retour_Menu->setVisible(false);

    Image->setPixmap(QPixmap("C:/Users/Utilisateur/Documents/Dossier perso Celine/Cours3A/Projet Jeu Choix/test/Main_Menu.jpg"));



    //QVBoxLayout *layout = new QVBoxLayout;


}

void MaFenetre::charger(){

}

void MaFenetre::Nouvelle_partie(){
    m_bouton_newGame->setVisible(false);
    m_bouton_saved->setVisible(false);
    m_bouton_quitter->setVisible(false);
    m_bouton_Retour_Menu->setVisible(true);

    m_texte->setText("NOUVELLE PARTIE");
    m_texte->setGeometry(longueur/2-(taille_texte("NOUVELLE PARTIE")/2),largeur/3-50, taille_texte("NOUVELLE PARTIE") , 30);

   Image->setPixmap(QPixmap("C:/Users/Utilisateur/Documents/Dossier perso Celine/Cours3A/Projet Jeu Choix/test/feat-1800x0-c-center.jpg"));


    m_bouton_start->setVisible(true);


}

QPushButton* MaFenetre::getBoutonChoix1(){
    return m_bouton_choix1;
}

QPushButton* MaFenetre::getBoutonChoix2(){
    return m_bouton_choix2;
}

QPushButton* MaFenetre::getBoutonChoix3(){
    return m_bouton_choix3;
}
QPushButton* MaFenetre::getBoutonChoix4(){
    return m_bouton_choix4;
}
QPushButton* MaFenetre::getBoutonContinuer(){
    return m_bouton_continuer;
}
QLabel* MaFenetre::getImage(){
    return Image;
}
QLabel* MaFenetre::getText(){
    return m_texte;
}

Situation MaFenetre::getSituationActuelle(){
    return situtation_actuelle;

}
void MaFenetre::setSituationActuelle(Situation situation){
    situtation_actuelle = situation;
}

void MaFenetre::setNextPath(QString path){
    next_path = path;
}
QString MaFenetre::getNextPath(){
    return next_path;
}

void MaFenetre::Situ(){
    Situation situation;
    int nombre_choix;
    QString message;
    QString image;
   // Situation sit(1, 0, 0, 4, "C:/Users/Utilisateur/Documents/Dossier perso Celine/Cours3A/Projet Jeu Choix/test/Main_Menu.jpg", "Choississez le chemin à prendre dans la forêt", "chemin actuel", " gauche", "droite", "retour en arrière", "", "GAUCHE !", "DROITE !", "", "");
   // setSituationActuelle(sit);
    situation = getSituationActuelle();
    nombre_choix = situation.getNbChoix();
    message = situation.getMessage();
    image = situation.getPathImage();
    Image->setPixmap(QPixmap(image));

    m_bouton_choix1->setGeometry(longueur/2-bouton_long, largeur-2*bouton_larg, bouton_long, bouton_larg);
    m_bouton_choix2->setGeometry(longueur/2, largeur-2*bouton_larg, bouton_long, bouton_larg);
    m_bouton_choix3->setGeometry(longueur/2-bouton_long, largeur-bouton_larg, bouton_long, bouton_larg);
    m_bouton_choix4->setGeometry(longueur/2, largeur-bouton_larg, bouton_long, bouton_larg);
    m_texte->setText(message);
    m_texte->setGeometry(900/2-(taille_texte(message)/2),600/3-50,taille_texte(message) , 30);
    m_texte->setVisible(true);
    m_bouton_newGame->setVisible(false);
    m_bouton_saved->setVisible(false);
    m_bouton_quitter->setVisible(false);
    m_bouton_Retour_Menu->setVisible(false);
    m_bouton_start->setVisible(false);
    m_bouton_sauvegarder->setVisible(true);
    m_bouton_continuer->setVisible(false);

    m_bouton_choix1->setVisible(true);
    m_bouton_choix1->setText(situation.getChoix1());
    QObject::connect(m_bouton_choix1, SIGNAL(clicked()), this, SLOT(Choix1()));

    m_bouton_choix2->setVisible(true);
    m_bouton_choix2->setText(situation.getChoix2());
    QObject::connect(m_bouton_choix2, SIGNAL(clicked()), this, SLOT(Choix2()));

    m_bouton_choix3->setText(situation.getChoix3());
    m_bouton_choix3->setVisible(true);
    QObject::connect(m_bouton_choix3, SIGNAL(clicked()), this, SLOT(Choix3()));
    m_bouton_choix4->setVisible(false);

    if(nombre_choix ==4){
    m_bouton_choix4->setText(situation.getChoix4());
    m_bouton_choix4->setVisible(true);
    QObject::connect(m_bouton_choix4, SIGNAL(clicked()), this, SLOT(Choix4()));
    }

/*
    if(nombre_choix == 4){
        m_bouton_choix1->setGeometry(longueur/2-bouton_long, largeur-2*bouton_larg, bouton_long, bouton_larg);
        m_bouton_choix2->setGeometry(longueur/2, largeur-2*bouton_larg, bouton_long, bouton_larg);
        m_bouton_choix3->setGeometry(longueur/2-bouton_long, largeur-bouton_larg, bouton_long, bouton_larg);
        m_bouton_choix4->setGeometry(longueur/2, largeur-bouton_larg, bouton_long, bouton_larg);

    }

    if(nombre_choix == 3){
        m_bouton_choix1->setGeometry(longueur/2-bouton_long/2, largeur-2*bouton_larg, bouton_long, bouton_larg);
        m_bouton_choix2->setGeometry(longueur/2-bouton_long, largeur-bouton_larg, bouton_long, bouton_larg);
        m_bouton_choix3->setGeometry(longueur/2, largeur-bouton_larg, bouton_long, bouton_larg);

    }
    if(nombre_choix == 2){
        m_bouton_choix1->setGeometry(longueur/2-bouton_long, largeur-bouton_larg, bouton_long, bouton_larg);
        m_bouton_choix2->setGeometry(longueur/2, largeur-bouton_larg, bouton_long, bouton_larg);

    }*/

}

void MaFenetre::loadChoix(){
       QString path;
       path = getNextPath();
       QString message;
       Situation nouvelle;
       message = "chargement de la nouvelle situation : " + path;
    //faire le chargement et récupérer la situation voulue avec un nouvelle = ?

    Situation sit(1, 0, 0, 3, "C:/Users/Utilisateur/Documents/Dossier perso Celine/Cours3A/Projet Jeu Choix/test/forest-chemin.jpg", "Choississez le chemin à prendre dans la forêt", "chemin actuel", " obscur", "lumineux", "retour en arrière", "", "Vie", "Mort !", "", "");
    setSituationActuelle(nouvelle);
    m_texte->setText(message);
    m_texte->setGeometry(900/2-(taille_texte(message)/2),600/3-50,taille_texte(message) , 30);
    m_texte->setVisible(true);
    Situ();
}

void MaFenetre::Choix1(){
    Situation situation;
    situation = getSituationActuelle();
    QString message;
    message = " Vous avez choisit  : ' " + situation.getChoix1() + " ' ";
    m_texte->setText(message);
     m_texte->setGeometry(900/2-(taille_texte(message)/2),600/3-50,taille_texte(message) , 30);
    m_texte->setVisible(true);
    QString path = situation.getPathNext1();
    setNextPath(path);
    m_bouton_choix1->setVisible(false);
    m_bouton_choix2->setVisible(false);
    m_bouton_choix3->setVisible(false);
    m_bouton_choix4->setVisible(false);
    m_bouton_continuer->setVisible(true);
    QObject::connect(m_bouton_continuer, SIGNAL(clicked()), this, SLOT(loadChoix()));
}

void MaFenetre::Choix2(){
    Situation situation;
    situation = getSituationActuelle();
    QString message;
    message = " Vous avez choisit  : ' " + situation.getChoix2() + " ' ";
    m_texte->setText(message);
     m_texte->setGeometry(900/2-(taille_texte(message)/2),600/3-50,taille_texte(message) , 30);
    m_texte->setVisible(true);
    QString path = situation.getPathNext2();
    setNextPath(path);
    m_bouton_choix1->setVisible(false);
    m_bouton_choix2->setVisible(false);
    m_bouton_choix3->setVisible(false);
    m_bouton_choix4->setVisible(false);
    m_bouton_continuer->setVisible(true);
    QObject::connect(m_bouton_continuer, SIGNAL(clicked()), this, SLOT(loadChoix()));
}
void MaFenetre::Choix3(){
    Situation situation;
    situation = getSituationActuelle();
    QString message;
    message = " Vous avez choisit  : ' " + situation.getChoix3() + " ' ";
    m_texte->setText(message);
     m_texte->setGeometry(900/2-(taille_texte(message)/2),600/3-50,taille_texte(message) , 30);
    m_texte->setVisible(true);
    QString path = situation.getPathNext3();
    setNextPath(path);
    m_bouton_choix1->setVisible(false);
    m_bouton_choix2->setVisible(false);
    m_bouton_choix3->setVisible(false);
    m_bouton_choix4->setVisible(false);
    m_bouton_continuer->setVisible(true);
    QObject::connect(m_bouton_continuer, SIGNAL(clicked()), this, SLOT(loadChoix()));
}
void MaFenetre::Choix4(){
    Situation situation;
    situation = getSituationActuelle();
    QString message;
    message = " Vous avez choisit  : ' " + situation.getChoix4() + " ' ";
    m_texte->setText(message);
     m_texte->setGeometry(900/2-(taille_texte(message)/2),600/3-50,taille_texte(message) , 30);
    m_texte->setVisible(true);
    QString path = situation.getPathNext4();
    setNextPath(path);
    m_bouton_choix1->setVisible(false);
    m_bouton_choix2->setVisible(false);
    m_bouton_choix3->setVisible(false);
    m_bouton_choix4->setVisible(false);
    m_bouton_continuer->setVisible(true);
    QObject::connect(m_bouton_continuer, SIGNAL(clicked()), this, SLOT(loadChoix()));
}

void MaFenetre::SauvegarderEtQuitter(){

}

int MaFenetre::taille_texte(QString txt){
    //pour placer le texte au bon endroit
    QFont myFont("Arial", 18);;
    QFontMetrics fm(myFont);
    int width=fm.horizontalAdvance(txt);
    return width;
}

