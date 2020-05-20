#include "test_titre.h"

test_titre::test_titre() : QWidget()
{
    setFixedSize(300, 150);

    // Construction du bouton
    m_bouton = new QPushButton("Quitter", this);

    m_bouton->setFont(QFont("Comic Sans MS", 14));
    m_bouton->setCursor(Qt::PointingHandCursor);
    //m_bouton->setIcon(QIcon("smile.png"));
    m_bouton->move(50, 110);

    // Connexion du clic du bouton à la fermeture de l'application
        QObject::connect(m_bouton, SIGNAL(clicked()), qApp, SLOT(quit()));
}
