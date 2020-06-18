#include "chargement_sit.h"
#include <vector>
#include <QDebug>


Situation charger_sit(int nbr, QString adresse, std::vector<int> arriere){

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
             Item obj(list[15].toInt(),list[16],list[17].toInt(),list[18].toInt(),adresse+list[19]);
             Ennemi ennemi(list[13], list[14].toInt());

             /*if(list[0].toInt()==3){
                 arriere.pop_back();
                 qDebug() << "TEST";
             }*/

                 for(int j = 0; j<4; j++){
                     if(list[10+j].toInt()==arriere.at((arriere.size()-2))){
                        list[6+j]="retour en arriere";
                     }

             }
                 qDebug() << arriere.at((arriere.size())-1);
                 qDebug() << arriere.at((arriere.size())-2) << "\n";



             Situation sit(list[0].toInt(),list[1].toInt(),adresse+list[2],list[3],list[4],list[5],list[6],list[7],list[8],list[9].toInt(),list[10].toInt(),list[11].toInt(),list[12].toInt(), ennemi, obj);
             return sit;
         }
         i++;
    }
}


