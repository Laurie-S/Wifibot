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
             QString a = QString::fromUtf8("");
             a += list[16];
             Item obj(list[15].toInt(),a,list[17].toInt(),list[18].toInt(),adresse+list[19]);

             Ennemi ennemi(list[13], list[14].toInt());
            QString b[4];
                 for(int j = 0; j<4; j++){
                     if(list[9+j].toInt()==arriere.at((arriere.size()-2))){
                        list[5+j]="retour en arrière";
                     }
                    b[j] = QString::fromUtf8("");
                    b[j] += list[5+j];
             }
                 qDebug() << arriere.at((arriere.size())-1);
                 qDebug() << arriere.at((arriere.size())-2) << "\n";



             Situation sit(list[0].toInt(),list[1].toInt(),adresse+list[2],list[3],list[4],b[0],b[1],b[2],b[3],list[9].toInt(),list[10].toInt(),list[11].toInt(),list[12].toInt(), ennemi, obj);
             return sit;
         }
         i++;
    }
}


