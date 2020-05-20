#ifndef DEF_MAFENETRE
#define DEF_MAFENETRE

#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QSlider>
#include <QLineEdit>
#include <QTextBrowser>
#include <QVBoxLayout>
#include <QObject>
#include <QLabel>
#include "situation.h"

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
    QPushButton* getBoutonContinuer();
    QLabel* getImage();
    QLabel* getText();
    Situation getSituationActuelle();
    void setSituationActuelle(Situation situation);
    void setNextPath(QString path);
    QString getNextPath();




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
    int largeur;
    int longueur;
    int bouton_larg;
    int bouton_long;
    QLabel *Image;
    QLabel *m_texte;
    QLineEdit *m_pseudo;
    Situation situtation_actuelle;
    QString next_path;

};

#endif
