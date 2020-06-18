#ifndef DEF_MAFENETRE
#define DEF_MAFENETRE

#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QTextEdit>   // Nous allons tout de même afficher le contenu du fichier ^^
#include <QFile>       // Pour utiliser le fichier
#include <QString>     // Stocke le contenu du fichier
#include <QTextStream> // Flux sortant du fichier
#include <QSlider>
#include <QLineEdit>
#include <QTextBrowser>
#include <QVBoxLayout>
#include <QObject>
#include <QLabel>
#include <QProgressBar>
#include "situation.h"
#include "personnage.h"
#include "chargement_sit.h"


class MaFenetre : public QWidget // On hérite de QWidget (IMPORTANT)
{
    Q_OBJECT // pour utiliser mes slots

    public:
    MaFenetre();
    int taille_texte(QString txt);
    QPushButton* getBoutonChoix1();
    QPushButton* getBoutonChoix2();
    QPushButton* getBoutonChoix3();
    QPushButton* getBoutonChoix4();
    QPushButton* getBoutonItem1();
    QPushButton* getBoutonItem2();
    QPushButton* getBoutonItem3();
    QPushButton* getBoutonItem4();
    QPushButton* getBoutonItem5();
    QPushButton* getBoutonContinuer();
    QLabel* getImage();
    QLabel* getText();
    Situation getSituationActuelle();
    void setSituationActuelle(Situation situation);
    void setNextPath(int path);
    int getNextPath();
    Personnage getPersonnage();
    void affichageInventaire();
    QString soin();
    void Texte(QString message);




    public slots:
    void charger();
    void Nouvelle_partie();
    void Menu();
    void Situ();
    void SauvegarderEtQuitter();
    void loadChoix();
    void Choix1();
    void Choix2();
    void Choix3();
    void Choix4();


    private:
    QPushButton *m_bouton_newGame;
    QPushButton *m_bouton_saved;
    QPushButton *m_bouton_quitter;
    QPushButton *m_bouton_Retour_Menu;
    QPushButton *m_bouton_start;
    QPushButton *m_bouton_sauvegarder;
    QPushButton *m_bouton_continuer;
    QPushButton *m_bouton_choix1;
    QPushButton *m_bouton_choix2;
    QPushButton *m_bouton_choix3;
    QPushButton *m_bouton_choix4;
    QPushButton *m_bouton_item1;
    QPushButton *m_bouton_item2;
    QPushButton *m_bouton_item3;
    QPushButton *m_bouton_item4;
    QPushButton *m_bouton_item5;
    QPushButton *m_bouton_item6;
    int largeur;
    int longueur;
    int bouton_larg;
    int bouton_long;
    QLabel *Image;
    QLabel *m_texte;
    QLabel *m_texte2;
    QLabel *m_texte3;
    QLabel *m_texte4;
    QLineEdit *m_pseudo;
    Situation situation_actuelle;
    int next_path;
    Personnage hero;
    QProgressBar *barre_vie;

};

#endif
