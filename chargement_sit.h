#include <QApplication>
#include <QPushButton>
#include <QHBoxLayout>
#include "ennemi.h"
#include "item.h"
#include <QLabel>
#include <QMessageBox>
#include <QInputDialog>
#include <QString>
#include "situation.h"
#include <QTranslator>
#include <QLocale>
#include <QLibraryInfo>
#include <QFile>
#include <QTextStream>


#ifndef CHARGEMENT_SIT_H
#define CHARGEMENT_SIT_H

Situation charger_sit(int nbr, QString adresse, std::vector<int> arriere);

bool sauvegarder(QString adresse);

bool charger_partie(QString adresse);


#endif // CHARGEMENT_SIT_H
