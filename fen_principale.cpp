
#include "fen_principale.h"
#include <QApplication>
#include <QPushButton>
#include "situation.h"

Fen_principale::Fen_principale(){
      QWidget *zoneCentrale = new QWidget;
       int longueur = 900;
       int largeur = 600;


        zoneCentrale->setFixedSize(longueur, largeur);

        int bouton_larg = 50;
        int bouton_long = bouton_larg*3;

        QLabel *Image = new QLabel(zoneCentrale);
                Image->setPixmap(QPixmap("C:/Users/Utilisateur/Documents/test2/Main_Menu.jpg"));

        QLabel *m_texte = new QLabel(zoneCentrale); // Création de l"objet
                m_texte->setText("MENU PRINCIPAL"); // Définition du texte
                m_texte->setStyleSheet("QLabel { background-color : none; color : white; font: 18pt;  }");
                m_texte->setGeometry(900/2-95,600/3-50,190 , 30);

        // Construction des boutons
         QPushButton *m_bouton_newGame = new QPushButton("Nouvelle partie", zoneCentrale);
        m_bouton_newGame->setCursor(Qt::PointingHandCursor);
        m_bouton_newGame->setGeometry(longueur/2-bouton_long/2, largeur/3, bouton_long, bouton_larg);
        QObject::connect(m_bouton_newGame, SIGNAL(clicked()), zoneCentrale, SLOT(Nouvelle_partie()));

         QPushButton *m_bouton_saved = new QPushButton("Partie Sauvegardée", zoneCentrale);
        m_bouton_saved->setCursor(Qt::PointingHandCursor);
        m_bouton_saved->setGeometry(longueur/2-bouton_long/2, largeur/3+bouton_larg+10, bouton_long, bouton_larg);
        //QObject::connect(m_bouton_saved, SIGNAL(clicked()), zoneCentrale, SLOT(changer_back()));

         QPushButton *m_bouton = new QPushButton("Quitter", zoneCentrale);
        m_bouton->setCursor(Qt::PointingHandCursor);
        m_bouton->setGeometry(longueur/2-bouton_long/2,  largeur/3+(2*bouton_larg)+20, bouton_long, bouton_larg);
        QObject::connect(m_bouton, SIGNAL(clicked()), qApp, SLOT(quit()));

        setCentralWidget(zoneCentrale);
}

void Fen_principale::Nouvelle_partie(){
    this->takeCentralWidget();
    QList<QPushButton *> listbouton;
    Situation nouvelle(2, 0, 0, "C:/Users/Utilisateur/Documents/Dossier perso Celine/Cours3A/Projet Jeu Choix/test/vi-1549367232326-vi34.png");
    QWidget *zoneCentrale = new QWidget;
    QLabel *Image = new QLabel(this);
            Image->setPixmap(QPixmap( "C:/Users/Utilisateur/Documents/Dossier perso Celine/Cours3A/Projet Jeu Choix/test/vi-1549367232326-vi34.png"));
            QPushButton *bouton1 = new QPushButton("test");
            bouton1->setGeometry(800,600, 50, 15);
   //nouvelle.TwoChoice("Epee", "Carte", zoneCentrale);
    this->setCentralWidget(zoneCentrale);
}


