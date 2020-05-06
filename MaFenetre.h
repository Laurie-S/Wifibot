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

class MaFenetre : public QWidget // On hérite de QWidget (IMPORTANT)
{
    Q_OBJECT // pour utiliser mes slots

    public:
    MaFenetre();

public slots:
    void changer_back();
    void Nouvelle_partie();
    void Menu();

    private:
    QPushButton *m_bouton_newGame;
    QPushButton *m_bouton_saved;
    QPushButton *m_bouton;
    int largeur;
    int longueur;
};

#endif
