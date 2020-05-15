#include "MaFenetre.h"
#include <QLabel>
#include <QMessageBox>
#include <QInputDialog>
#include <QString>
#include <QFontMetrics>
#include <QLineEdit>

MaFenetre::MaFenetre() : QWidget()
{
    longueur = 900;
    largeur = 600;
    bouton_larg = 50;
    bouton_long = bouton_larg*3;


    setFixedSize(longueur, largeur);

    Image = new QLabel(this);
    Image->setPixmap(QPixmap("C:/Users/Laurie/Documents/_COURS_/3A/Corona/Projet/wifibot/Main_Menu.jpg"));
    Image->setVisible(false);


    m_texte = new QLabel(this); // Création de l"objet
    m_texte->setText("MENU PRINCIPAL"); // Définition du texte
    m_texte->setStyleSheet("QLabel { font : Arial ; background-color : none; color : white; font: 18pt;  }");
    m_texte->setGeometry(900/2-(taille_texte("MENU PRINCIPAL")/2),600/3-50,taille_texte("MENU PRINCIPAL") , 30);
    m_texte->setVisible(false);

    m_pseudo = new QLineEdit;


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
    m_bouton_Retour_Menu->setGeometry(longueur/2-bouton_long/2,  largeur/3+(2*bouton_larg)+20, bouton_long, bouton_larg);
    QObject::connect(m_bouton_Retour_Menu, SIGNAL(clicked()), this, SLOT(Menu()));
    m_bouton_Retour_Menu->setVisible(false);

    m_bouton_start= new QPushButton("", this);

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

   // m_pseudo->setEchoMode();



}

int MaFenetre::taille_texte(QString txt){
    //pour placer le texte au bon endroit
    QFont myFont("Arial", 18);;
    QFontMetrics fm(myFont);
    int width=fm.horizontalAdvance(txt);
    return width;
}
