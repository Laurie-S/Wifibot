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

class MaFenetre : public QWidget // On hérite de QWidget (IMPORTANT)
{
    Q_OBJECT // pour utiliser mes slots

    public:
    MaFenetre();
    int taille_texte(QString txt);

    public slots:
    void charger();
    void Nouvelle_partie();
    void Menu();

    private:
    QPushButton *m_bouton_newGame;
    QPushButton *m_bouton_saved;
    QPushButton *m_bouton_quitter;
    QPushButton *m_bouton_Retour_Menu;
    QPushButton *m_bouton_start;

    int largeur;
    int longueur;
    int bouton_larg;
    int bouton_long;
    QLabel *Image;
    QLabel *m_texte;
    QString *pseudo;
    QLineEdit *m_pseudo;

};

#endif
