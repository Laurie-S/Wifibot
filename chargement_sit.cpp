#include "chargement_sit.h"


Situation charger_sit(int nbr, QString adresse){

    QFile file(adresse+"/Situation.csv");


    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        throw std::logic_error("Impossible de lire le fichier");
    }

    QTextStream stream(&file);
    int i = 0;

    while (!stream.atEnd() && i<=nbr )
    {
         QString line = stream.readLine();
         QStringList list = line.split(";");
         if(i==nbr){ // on est a la situation voulue

             Ennemi ennemi(list[13], list[14].toInt());
             Situation sit(list[0].toInt(),list[1].toInt(),adresse+list[2],list[3],list[4],list[5],list[6],list[7],list[8],list[9].toInt(),list[10].toInt(),list[11].toInt(),list[12].toInt(), ennemi);
             return sit;
         }
         i++;
    }
}
