#include "MaFenetre.h"
#include <QLabel>
#include <QMessageBox>
#include <QInputDialog>
#include <QString>

MaFenetre::MaFenetre() : QWidget()
{
    longueur = 900;
    largeur = 600;


    setFixedSize(longueur, largeur);

    Menu();


}

void MaFenetre::Menu(){

    int bouton_larg = 50;
    int bouton_long = bouton_larg*3;

    QLabel *Image = new QLabel(this);
            Image->setPixmap(QPixmap("C:/Users/Laurie/Documents/_COURS_/3A/Corona/Projet/wifibot/Main_Menu.jpg"));

    QLabel *m_texte = new QLabel(this); // Création de l"objet
            m_texte->setText("MENU PRINCIPAL"); // Définition du texte
            m_texte->setStyleSheet("QLabel { background-color : none; color : white; font: 18pt;  }");
            m_texte->setGeometry(900/2-95,600/3-50,190 , 30);

    // Construction des boutons
    m_bouton_newGame = new QPushButton("Nouvelle partie", this);
    m_bouton_newGame->setCursor(Qt::PointingHandCursor);
    m_bouton_newGame->setGeometry(longueur/2-bouton_long/2, largeur/3, bouton_long, bouton_larg);
    QObject::connect(m_bouton_newGame, SIGNAL(clicked()), this, SLOT(Nouvelle_partie()));

    m_bouton_saved = new QPushButton("Partie Sauvegardée", this);
    m_bouton_saved->setCursor(Qt::PointingHandCursor);
    m_bouton_saved->setGeometry(longueur/2-bouton_long/2, largeur/3+bouton_larg+10, bouton_long, bouton_larg);
    QObject::connect(m_bouton_saved, SIGNAL(clicked()), this, SLOT(changer_back()));

    m_bouton = new QPushButton("Quitter", this);
    m_bouton->setCursor(Qt::PointingHandCursor);
    m_bouton->setGeometry(longueur/2-bouton_long/2,  largeur/3+(2*bouton_larg)+20, bouton_long, bouton_larg);
    QObject::connect(m_bouton, SIGNAL(clicked()), qApp, SLOT(quit()));
}

void MaFenetre::changer_back(){
    setFixedSize(200, 100);
}

void MaFenetre::Nouvelle_partie(){


}
