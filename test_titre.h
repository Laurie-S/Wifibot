#ifndef TEST_TITRE_H
#define TEST_TITRE_H

#include <QApplication>
#include <QWidget>
#include <QPushButton>


class test_titre : public QWidget // On hérite de QWidget (IMPORTANT)
{
    public:
    test_titre();

    private:
    QPushButton *m_bouton;

};

#endif // TEST_TITRE_H
