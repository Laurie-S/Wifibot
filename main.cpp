#include <QApplication>
#include <QPushButton>
#include <QHBoxLayout>
#include "item.h"
#include "ennemi.h"
#include <QLabel>
#include <QMessageBox>
#include <QInputDialog>
#include <QString>
#include "personnage.h"
#include "situation.h"
#include "MaFenetre.h"
#include <QTranslator>
#include <QLocale>
#include <QLibraryInfo>



int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MaFenetre fenetre;
    fenetre.Menu();


    fenetre.show();

    return app.exec();
}
