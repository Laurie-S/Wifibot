#include "MaFenetre.h"
#include <QLabel>
#include <QMessageBox>
#include <QInputDialog>
#include <QString>
#include <QFontMetrics>
#include <QLineEdit>
#include <QPicture>
#include <vector>
#include <QDebug>
#include "item.h"

// adresse des fichiers
QString adresse = "C:/Users/Utilisateur/Documents/Dossier perso Celine/Cours3A/Projet Jeu Choix/test";
//QString adresse = "D:/Documents/_COURS_/3A/Corona/Projet/wifibot";"
//QString adresse = "C:/Users/Laurie/Downloads/Wifibot-master/Wifibot-master";

std::vector<int> arriere;
int a = 0

MaFenetre::MaFenetre() : QWidget()
{
    longueur = 900;
    largeur = 600;
    bouton_larg = 50;
    bouton_long = bouton_larg*3;


    setFixedSize(longueur, largeur);
     Ennemi ennemi;
     int health =100;
     hero.setHealth(health);
     hero.setNamePersonnage("Aventurier");
     Item invent(0, "Inventaire", 0, 0, "/bag.png");
     hero.addItem(invent);
     Item sword(5, "épée", 0, 0, "/epee.png");
     hero.addItem(sword);

     arriere.push_back(1);
     arriere.push_back(1);
     Situation sit = charger_sit(1,adresse,arriere);
     setSituationActuelle(sit);

    Image = new QLabel(this);
    Image->setPixmap(QPixmap(adresse+"/Main_Menu.jpg"));
    Image->setVisible(false);


    m_texte = new QLabel(this); // Création de l"objet
    m_texte->setStyleSheet("QLabel { font : Arial ; background-color : none; color : white; font: 24pt;  }");
    m_texte->setVisible(false);

    m_texte2 = new QLabel(this); // Création de l"objet
    m_texte2->setStyleSheet("QLabel { font : Arial ; background-color : none; color : white; font: 24pt;  }");
    m_texte2->setVisible(false);

    m_texte3 = new QLabel(this); // Création de l"objet
    m_texte3->setStyleSheet("QLabel { font : Arial ; background-color : none; color : white; font: 24pt;  }");
    m_texte3->setVisible(false);

    m_texte4 = new QLabel(this); // Création de l"objet
    m_texte4->setStyleSheet("QLabel { font : Arial ; background-color : none; color : white; font: 24pt;  }");
    m_texte4->setVisible(false);

    Texte(" MENU PRINCIPAL");

    // Construction des boutons
    m_bouton_newGame = new QPushButton("Nouvelle partie", this);
    m_bouton_newGame->setCursor(Qt::PointingHandCursor);
    m_bouton_newGame->setGeometry(longueur/2-bouton_long/2, largeur/3, bouton_long, bouton_larg);
    QObject::connect(m_bouton_newGame, SIGNAL(clicked()), this, SLOT(Nouvelle_partie()));
    m_bouton_newGame->setVisible(false);

    m_bouton_saved = new QPushButton("Partie Sauvegardée", this);
    m_bouton_saved->setCursor(Qt::PointingHandCursor);
    m_bouton_saved->setGeometry(longueur/2-bouton_long/2, largeur/3+bouton_larg+10, bouton_long, bouton_larg);
    QObject::connect(m_bouton_saved, SIGNAL(clicked()), this, SLOT(charger()));
    m_bouton_saved->setVisible(false);


    m_bouton_quitter = new QPushButton("Quitter", this);
    m_bouton_quitter->setCursor(Qt::PointingHandCursor);
    m_bouton_quitter->setGeometry(longueur/2-bouton_long/2,  largeur/3+(2*bouton_larg)+20, bouton_long, bouton_larg);
    QObject::connect(m_bouton_quitter, SIGNAL(clicked()), qApp, SLOT(quit()));
    m_bouton_quitter->setVisible(false);

    m_bouton_Retour_Menu = new QPushButton("Retour", this);
    m_bouton_Retour_Menu->setCursor(Qt::PointingHandCursor);
    m_bouton_Retour_Menu->setGeometry(longueur/2-bouton_long/2, largeur/3+bouton_larg+10, bouton_long, bouton_larg);
    QObject::connect(m_bouton_Retour_Menu, SIGNAL(clicked()), this, SLOT(Menu()));
    m_bouton_Retour_Menu->setVisible(false);


    m_bouton_start= new QPushButton("Commencer", this);
    m_bouton_start->setCursor(Qt::PointingHandCursor);
    m_bouton_start->setGeometry(longueur/2-bouton_long/2, largeur/3, bouton_long, bouton_larg);
    QObject::connect(m_bouton_start, SIGNAL(clicked()), this, SLOT(Situ()));
    m_bouton_start->setVisible(false);

    /////////////////////////////////////////////////////////////////////////////////////////////
    // boutons pour les situations
    // bouton pour sauvegarder et quitter pendant les situations
    m_bouton_sauvegarder= new QPushButton("Sauv", this);
    m_bouton_sauvegarder->setCursor(Qt::PointingHandCursor);
    m_bouton_sauvegarder->setGeometry(0, 0, 30, 30);
    QObject::connect(m_bouton_sauvegarder, SIGNAL(clicked()), this, SLOT(SauvegarderEtQuitter()));
    m_bouton_sauvegarder->setVisible(false);


    // bouton pour continuer pendant les situations
    m_bouton_continuer = new QPushButton("Continuer", this);
    m_bouton_continuer->setCursor(Qt::PointingHandCursor);
    m_bouton_continuer->setGeometry(longueur-bouton_long, largeur-bouton_larg, bouton_long, bouton_larg);
    QObject::connect(m_bouton_continuer, SIGNAL(clicked()), this, SLOT(loadChoix()));
    m_bouton_continuer->setVisible(false);


    // boutons pour les choix des situations
    m_bouton_choix1= new QPushButton("", this);
    m_bouton_choix1->setCursor(Qt::PointingHandCursor);
    QObject::connect(m_bouton_choix1, SIGNAL(clicked()), this, SLOT(Choix1()));
    m_bouton_choix1->setVisible(false);

    m_bouton_choix2= new QPushButton("", this);
    m_bouton_choix2->setCursor(Qt::PointingHandCursor);
    QObject::connect(m_bouton_choix2, SIGNAL(clicked()), this, SLOT());
    m_bouton_choix2->setVisible(false);

    m_bouton_choix3= new QPushButton("", this);
    m_bouton_choix3->setCursor(Qt::PointingHandCursor);
    QObject::connect(m_bouton_choix3, SIGNAL(clicked()), this, SLOT());
    m_bouton_choix3->setVisible(false);

    m_bouton_choix4= new QPushButton("", this);
    m_bouton_choix4->setCursor(Qt::PointingHandCursor);
    QObject::connect(m_bouton_choix4, SIGNAL(clicked()), this, SLOT());
    m_bouton_choix4->setVisible(false);

//inventaire
    m_bouton_item1= new QPushButton("", this);
    m_bouton_item1->setGeometry(10, 250, 60, 50);
    m_bouton_item1->setVisible(false);

    m_bouton_item2= new QPushButton("", this);
    m_bouton_item2->setGeometry(15, 300, 50, 50);
    m_bouton_item2->setVisible(false);

    m_bouton_item3= new QPushButton("", this);
    m_bouton_item3->setGeometry(15, 350, 50, 50);
    m_bouton_item3->setVisible(false);

    m_bouton_item4= new QPushButton("", this);
    m_bouton_item4->setGeometry(15, 400, 50, 50);
    m_bouton_item4->setVisible(false);

    m_bouton_item5= new QPushButton("", this);
    m_bouton_item5->setGeometry(15, 450, 50, 50);
    m_bouton_item5->setVisible(false);

    m_bouton_item6= new QPushButton("", this);
    m_bouton_item6->setGeometry(15, 500, 50, 50);
    m_bouton_item6->setVisible(false);




//barre de vie
    barre_vie = new QProgressBar(this);
    barre_vie->setMaximum(health);
    barre_vie->setValue(health);

    barre_vie->setGeometry(761, 20, 170, 15);


    barre_vie->setVisible(false);






   // Menu();


}

void MaFenetre::Menu(){

    Texte("MENU PRINCIPAL"); // Définition du texte
    m_texte->setGeometry(900/2-(taille_texte("MENU PRINCIPAL")/2),600/3-50,taille_texte("MENU PRINCIPAL") , 30);


    Image->setVisible(true);
    m_texte->setVisible(true);
    m_bouton_newGame->setVisible(true);
    m_bouton_saved->setVisible(true);
    m_bouton_quitter->setVisible(true);
    m_bouton_Retour_Menu->setVisible(false);
    m_bouton_start->setVisible(false);

    Image->setPixmap(QPixmap(adresse+"/Main_Menu.jpg"));



    //QVBoxLayout *layout = new QVBoxLayout;


}


void MaFenetre::Nouvelle_partie(){
    m_bouton_newGame->setVisible(false);
    m_bouton_saved->setVisible(false);
    m_bouton_quitter->setVisible(false);
    m_bouton_Retour_Menu->setVisible(true);


    Texte("NOUVELLE PARTIE");

   Image->setPixmap(QPixmap(adresse+"/feat-1800x0-c-center.jpg"));


    m_bouton_start->setVisible(true);


}

QPushButton* MaFenetre::getBoutonChoix1(){
    return m_bouton_choix1;
}

QPushButton* MaFenetre::getBoutonChoix2(){
    return m_bouton_choix2;
}

QPushButton* MaFenetre::getBoutonChoix3(){
    return m_bouton_choix3;
}
QPushButton* MaFenetre::getBoutonChoix4(){
    return m_bouton_choix4;
}
QPushButton* MaFenetre::getBoutonContinuer(){
    return m_bouton_continuer;
}
QLabel* MaFenetre::getImage(){
    return Image;
}
QLabel* MaFenetre::getText(){
    return m_texte;
}

Situation MaFenetre::getSituationActuelle(){
    return situation_actuelle;

}

Personnage MaFenetre::getPersonnage(){
    return hero;
}

void MaFenetre::setSituationActuelle(Situation situation){
    situation_actuelle = situation;
    a=0;
}

void MaFenetre::setNextPath(int path){
    next_path = path;
}
int MaFenetre::getNextPath(){
    return next_path;
}

QString MaFenetre::soin(){
    bool id1 = false;
    bool id2 = false;
    bool id3 = false;
    bool id4 = false;
    QList<Item> inventaire = hero.getInventory();
    for(int i = 0; i< inventaire.size(); i++){
        if(inventaire[i].getIdItem() == 1){
            id1 = true;
        }
        if(inventaire[i].getIdItem() == 2){
            id2 = true;
        }
        if(inventaire[i].getIdItem() == 3){
            id3 = true;
        }
        if(inventaire[i].getIdItem() == 4){
            id4 = true;
        }
    }
    QString message = QString::fromUtf8("");

    if(hero.getHealth()<=50 && hero.getHealth()>0 && id1 == true){
        message = message + hero.utiliserSoin(1);
        int vie = hero.getHealth();
        barre_vie->setValue(vie);
    }
    if(hero.getHealth()<=80 && hero.getHealth()>50 && id2 == true){
        message = message + hero.utiliserSoin(2);
        int vie = hero.getHealth();
        barre_vie->setValue(vie);
    }
    if(hero.getHealth()<=90 && hero.getHealth()>80 && id3 == true){
        message = message + hero.utiliserSoin(3);
        int vie = hero.getHealth();
        barre_vie->setValue(vie);
    }
    if(hero.getHealth()<=95 && hero.getHealth()>90 && id4 == true){
        message = message + hero.utiliserSoin(4);
        int vie = hero.getHealth();
        barre_vie->setValue(vie);
    }
    return message;
}


void MaFenetre::affichageInventaire(){
    QList<Item> inventaire;
    QString image[4];
    image[0] = "/potion.png";
    image[1] = "/baies.png";
    image[2] = "/fleurs.png";
    image[3] = "/champignon.png";

    QString objet1;
    QString objet2;
    QString objet3;
    QString objet4;
    QString objet5;
    QString objet6;
    QString nom_objet1;
    QString nom_objet2;
    QString nom_objet3;
    QString nom_objet4;
    QString nom_objet5;
    QString nom_objet6;

    inventaire = hero.getInventory();
    int taille = inventaire.size();

    switch(taille){
        case 1 :
            objet1 = inventaire[0].getPathItem();
            m_bouton_item1->setIcon(QIcon (adresse+objet1));
            nom_objet1 = inventaire[0].getNameItem();
            m_bouton_item1->setToolTip(nom_objet1);
          break;
        case 2 :
            objet1 = inventaire[0].getPathItem();
            m_bouton_item1->setIcon(QIcon (adresse+objet1));
            nom_objet1 = inventaire[0].getNameItem();
            m_bouton_item1->setToolTip(nom_objet1);
            objet2 = inventaire[1].getPathItem();
            m_bouton_item2->setIcon(QIcon (adresse+objet2));
            nom_objet2 = inventaire[1].getNameItem();
            m_bouton_item2->setToolTip(nom_objet2);
          break;
        case 3 :
            objet1 = inventaire[0].getPathItem();
            m_bouton_item1->setIcon(QIcon (adresse+objet1));
            nom_objet1 = inventaire[0].getNameItem();
            m_bouton_item1->setToolTip(nom_objet1);
            objet2 = inventaire[1].getPathItem();
            m_bouton_item2->setIcon(QIcon (adresse+objet2));
            nom_objet2 = inventaire[1].getNameItem();
            m_bouton_item2->setToolTip(nom_objet2);
            objet3 = image[inventaire[2].getIdItem()-1];
            m_bouton_item3->setIcon(QIcon (adresse+objet3));
            nom_objet3 = inventaire[2].getNameItem();
            m_bouton_item3->setToolTip(nom_objet3);
          break;
        case 4 :
            objet1 = inventaire[0].getPathItem();
            m_bouton_item1->setIcon(QIcon (adresse+objet1));
            nom_objet1 = inventaire[0].getNameItem();
            m_bouton_item1->setToolTip(nom_objet1);
            objet2 = inventaire[1].getPathItem();
            m_bouton_item2->setIcon(QIcon (adresse+objet2));
            nom_objet2 = inventaire[1].getNameItem();
            m_bouton_item2->setToolTip(nom_objet2);
            objet3 =image[inventaire[2].getIdItem()-1];
            m_bouton_item3->setIcon(QIcon (adresse+objet3));
            nom_objet3 = inventaire[2].getNameItem();
            m_bouton_item3->setToolTip(nom_objet3);
            objet4 = image[inventaire[3].getIdItem()-1];
            m_bouton_item4->setIcon(QIcon (adresse+objet4));
            nom_objet4 = inventaire[3].getNameItem();
            m_bouton_item4->setToolTip(nom_objet4);
          break;
        case 5 :
            objet1 = inventaire[0].getPathItem();
            m_bouton_item1->setIcon(QIcon (adresse+objet1));
            nom_objet1 = inventaire[0].getNameItem();
            m_bouton_item1->setToolTip(nom_objet1);
            objet2 = inventaire[1].getPathItem();
            m_bouton_item2->setIcon(QIcon (adresse+objet2));
            nom_objet2 = inventaire[1].getNameItem();
            m_bouton_item2->setToolTip(nom_objet2);
            objet3 = image[inventaire[2].getIdItem()-1];
            m_bouton_item3->setIcon(QIcon (adresse+objet3));
            nom_objet3 = inventaire[2].getNameItem();
            m_bouton_item3->setToolTip(nom_objet3);
            objet4 = image[inventaire[3].getIdItem()-1];
            m_bouton_item4->setIcon(QIcon (adresse+objet4));
            nom_objet4 = inventaire[3].getNameItem();
            m_bouton_item4->setToolTip(nom_objet4);
            objet5 = image[inventaire[4].getIdItem()-1];
            m_bouton_item5->setIcon(QIcon (adresse+objet5));
            nom_objet5 = inventaire[4].getNameItem();
            m_bouton_item5->setToolTip(nom_objet5);
        break;
    case 6 :
        objet1 = inventaire[0].getPathItem();
        m_bouton_item1->setIcon(QIcon (adresse+objet1));
        nom_objet1 = inventaire[0].getNameItem();
        m_bouton_item1->setToolTip(nom_objet1);
        objet2 = inventaire[1].getPathItem();
        m_bouton_item2->setIcon(QIcon (adresse+objet2));
        nom_objet2 = inventaire[1].getNameItem();
        m_bouton_item2->setToolTip(nom_objet2);
        objet3 = image[inventaire[2].getIdItem()-1];
        m_bouton_item3->setIcon(QIcon (adresse+objet3));
        nom_objet3 = inventaire[2].getNameItem();
        m_bouton_item3->setToolTip(nom_objet3);
        objet4 = image[inventaire[3].getIdItem()-1];
        m_bouton_item4->setIcon(QIcon (adresse+objet4));
        nom_objet4 = inventaire[3].getNameItem();
        m_bouton_item4->setToolTip(nom_objet4);
        objet5 = image[inventaire[4].getIdItem()-1];
        m_bouton_item5->setIcon(QIcon (adresse+objet5));
        nom_objet5 = inventaire[4].getNameItem();
        m_bouton_item5->setToolTip(nom_objet5);
        objet6 = image[inventaire[5].getIdItem()-1];
        m_bouton_item6->setIcon(QIcon (adresse+objet6));
        nom_objet6 = inventaire[5].getNameItem();
        m_bouton_item6->setToolTip(nom_objet6);
          break;
      }

    m_bouton_item1->setVisible(true);
    m_bouton_item2->setVisible(true);
    m_bouton_item3->setVisible(true);
    m_bouton_item4->setVisible(true);
    m_bouton_item5->setVisible(true);
    m_bouton_item6->setVisible(true);

}

void MaFenetre::Situ(){
    int nombre_choix;
    QString message;
    QString image;
    QString objet;

    affichageInventaire();

    barre_vie->setVisible(true);

    nombre_choix = situation_actuelle.getNbChoix();
    message = situation_actuelle.getMessage();
    image = situation_actuelle.getPathImage();
    Image->setPixmap(QPixmap(image));

    m_bouton_choix1->setGeometry(longueur/2-bouton_long, largeur-2*bouton_larg, bouton_long, bouton_larg);
    m_bouton_choix2->setGeometry(longueur/2, largeur-2*bouton_larg, bouton_long, bouton_larg);
    m_bouton_choix3->setGeometry(longueur/2-bouton_long, largeur-bouton_larg, bouton_long, bouton_larg);
    m_bouton_choix4->setGeometry(longueur/2, largeur-bouton_larg, bouton_long, bouton_larg);

    Texte(message);

    m_bouton_newGame->setVisible(false);
    m_bouton_saved->setVisible(false);
    m_bouton_quitter->setVisible(false);
    m_bouton_Retour_Menu->setVisible(false);
    m_bouton_start->setVisible(false);
    m_bouton_sauvegarder->setVisible(true);
    m_bouton_continuer->setVisible(false);

    m_bouton_choix1->setVisible(true);
    m_bouton_choix1->setText(situation_actuelle.getChoix1());
    //QObject::connect(m_bouton_choix1, SIGNAL(clicked()), this, SLOT(Choix1()));

    m_bouton_choix2->setVisible(true);
    m_bouton_choix2->setText(situation_actuelle.getChoix2());
    QObject::connect(m_bouton_choix2, SIGNAL(clicked()), this, SLOT(Choix2()));

    m_bouton_choix3->setVisible(false);

    if(nombre_choix == 3 || nombre_choix ==4){
        m_bouton_choix3->setText(situation_actuelle.getChoix3());
        m_bouton_choix3->setVisible(true);
        QObject::connect(m_bouton_choix3, SIGNAL(clicked()), this, SLOT(Choix3()));
    }

    m_bouton_choix4->setVisible(false);

    if(nombre_choix ==4){
        m_bouton_choix4->setText(situation_actuelle.getChoix4());
        m_bouton_choix4->setVisible(true);
        QObject::connect(m_bouton_choix4, SIGNAL(clicked()), this, SLOT(Choix4()));
    }

}


void MaFenetre::loadChoix(){
       int path;
       path = getNextPath();
       arriere.push_back(path);
       QString message;
       Situation nouvelle;
       Ennemi ennemi("monstre", 10);
       int vie;
       vie = hero.getHealth();

        if(vie <= 0 || path == 0){
            Situation sit = charger_sit(0, adresse, arriere);
            setSituationActuelle(sit);
            message = QString::fromUtf8("Vous êtes mort");
            Texte(message);
            Image->setPixmap(QPixmap(adresse+"/Mort.jpg"));
            m_bouton_quitter->setVisible(true);
            m_bouton_continuer->setVisible(false);
            barre_vie->setVisible(false);
            m_bouton_item1->setVisible(false);
            m_bouton_item2->setVisible(false);
            m_bouton_item3->setVisible(false);
            m_bouton_item4->setVisible(false);
            m_bouton_item5->setVisible(false);
            m_bouton_item6->setVisible(false);

        }
        else{
            Situation sit = charger_sit(path, adresse, arriere);
            setSituationActuelle(sit);

            if(situation_actuelle.getIdSituation()== 3){
                arriere.pop_back();
            }

            if(situation_actuelle.getIdSituation()== 2){ // situation victoire ?
                message = QString::fromUtf8("Félicitation vous avez trouvé le trésor");
                Texte(message);
                Image->setPixmap(QPixmap(adresse+"/victoire.jpg"));
                m_bouton_quitter->setVisible(true);
                m_bouton_continuer->setVisible(false);
                barre_vie->setVisible(false);
                m_bouton_item1->setVisible(false);
                m_bouton_item2->setVisible(false);
                m_bouton_item3->setVisible(false);
                m_bouton_item4->setVisible(false);
                m_bouton_item5->setVisible(false);
                m_bouton_item6->setVisible(false);
            }
            else{
              Texte(message);
              Situ();
            }


        }
}

void MaFenetre::Choix1(){
    QString message;
    message = QString::fromUtf8(" Vous avez choisit  : ' ");
    message+= situation_actuelle.getChoix1() + " ' ";

    if(situation_actuelle.getIdSituation() == 1 && a == 0){
        a++;
        int chance;
         Ennemi ennemi;
         int degat;
         int vie;
         qsrand(time(NULL));
         ennemi = situation_actuelle.getEnnemi();
         degat = ennemi.getAttack();
         vie = hero.getHealth();
         chance = (rand() % (degat - 0 + 1)) + 0;
         vie = vie - chance;
         hero.setHealth(vie);
         if(vie<= 0){
             barre_vie->setValue(0);
         }
         else{
            barre_vie->setValue(vie);
         }
         if(chance==0){
           message = message + "\n Quelle chance ! Aucune blesssure subie ";
         }
         else{
         message = message + "\n Vous avez reçu une blessures ";
        }
    }

    if(situation_actuelle.getIdSituation()==3){
        Item item;
        int degat;
        int vie;
        vie = hero.getHealth();
        item = situation_actuelle.getItem();
        degat = item.getDamage();
        message = message +"\n Objet ramassé :" +item.getNameItem();
        if(degat !=0){
            vie = vie - degat;
            message = message + "\n c'est empoisonné !";
        }
        else{
            message = message + hero.addItem(item);
        }
    }
    message = message + soin();

    Texte(message);
    int path = situation_actuelle.getPathNext1();
    setNextPath(path);

    if(path==arriere.at((arriere.size())-1) && arriere.size()!=1){
        std::vector<int> vect = arriere;
        arriere.clear();
        int n = 0;
        while (vect.at(n)!=path) {
            arriere.push_back(vect.at(n));
            n++;
        }



    }

    m_bouton_choix1->setVisible(false);
    m_bouton_choix2->setVisible(false);
    m_bouton_choix3->setVisible(false);
    m_bouton_choix4->setVisible(false);
    m_bouton_continuer->setVisible(true);

}

void MaFenetre::Choix2(){
    QString message;
    message = " Vous avez choisit  : ' " + situation_actuelle.getChoix2() + " ' ";
    Ennemi ennemi;
    int degat;
    ennemi = situation_actuelle.getEnnemi();
    degat = ennemi.getAttack();
    if(situation_actuelle.getIdSituation() == 1 && degat != 100 && a==0){

         int vie;
         int chance;
         qsrand(time(NULL));

         vie = hero.getHealth();
         chance = (rand() % ((2*degat) - 0 + 1)) + 0;
         vie = vie - chance;
         hero.setHealth(vie);
         if(vie<= 0){
             barre_vie->setValue(0);
         }
         else{
            barre_vie->setValue(vie);
         }
         if(chance==0){
           message = message + "\n Quelle chance ! Aucune blesssure subie ";
         }
         else{
         message = message + "\n Ce n'était pas une bonne idée ! Vous avez reçu une blessures ";
        }
    }
     message = message + soin();
    Texte(message);
    int path = situation_actuelle.getPathNext2();
    setNextPath(path);

    if(path==arriere.at((arriere.size())-2)&& arriere.size()!=1){
        std::vector<int> vect = arriere;
        arriere.clear();
        int n = 0;
        while (vect.at(n)!=path) {
            arriere.push_back(vect.at(n));
            n++;
        }
    }

    m_bouton_choix1->setVisible(false);
    m_bouton_choix2->setVisible(false);
    m_bouton_choix3->setVisible(false);
    m_bouton_choix4->setVisible(false);
    m_bouton_continuer->setVisible(true);
}
void MaFenetre::Choix3(){
    QString message;
    message = " Vous avez choisit  : ' " + situation_actuelle.getChoix3() + " ' ";
    Texte(message);
    int path = situation_actuelle.getPathNext3();
    setNextPath(path);

    if(path==arriere.at((arriere.size())-2)&& arriere.size()!=1){
        std::vector<int> vect = arriere;
        arriere.clear();
        int n = 0;
        while (vect.at(n)!=path) {
            arriere.push_back(vect.at(n));
            n++;
        }
    }

    m_bouton_choix1->setVisible(false);
    m_bouton_choix2->setVisible(false);
    m_bouton_choix3->setVisible(false);
    m_bouton_choix4->setVisible(false);
    m_bouton_continuer->setVisible(true);

}
void MaFenetre::Choix4(){
    QString message;
    message = " Vous avez choisit  : ' " + situation_actuelle.getChoix4() + " ' ";
    Texte(message);
    int path = situation_actuelle.getPathNext4();
    setNextPath(path);

    if(path==arriere.at((arriere.size())-2)&& arriere.size()!=1){
        std::vector<int> vect = arriere;
        arriere.clear();
        int n = 0;
        while (vect.at(n)!=path) {
            arriere.push_back(vect.at(n));
            n++;
        }
    }

    m_bouton_choix1->setVisible(false);
    m_bouton_choix2->setVisible(false);
    m_bouton_choix3->setVisible(false);
    m_bouton_choix4->setVisible(false);
    m_bouton_continuer->setVisible(true);
}

int MaFenetre::taille_texte(QString txt){
    //pour placer le texte au bon endroit
    QFont myFont("Arial", 24);
    QFontMetrics fm(myFont);
    int width=fm.horizontalAdvance(txt);
    return width;
}

void MaFenetre::charger(){
    QFile file(adresse+"/Save.csv");


    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        throw std::logic_error("Impossible de lire le fichier");
    }

    QTextStream stream(&file);

    while (!stream.atEnd())
    {
        QString line = stream.readLine();
        QStringList list = line.split(";");

        hero.setHealth(list[0].toInt());
        int nbr = list[1].toInt()+2;
        QList<Item> inventory;
        for (int i = 2;i<nbr;i++) {
            if(list[i].toInt()==0){
                Item Obj(0,"Inventaire",0,0,"/bag.png");
                inventory.push_back(Obj);
            }
            if(list[i].toInt()==1){
                Item Obj(1,"Elixir de soin",0,50,"/potion.png");
                inventory.push_back(Obj);
            }
            if(list[i].toInt()==2){
                Item Obj(2,"Baies Soin",0,20,"/baies.png");
                inventory.push_back(Obj);
            }
            if(list[i].toInt()==3){
                Item Obj(3,"Fleurs Soin",0,10,"/fleurs.png");
                inventory.push_back(Obj);
            }
            if(list[i].toInt()==4){
                Item Obj(4,"champignon soin",0,5,"/champignon.png");
                inventory.push_back(Obj);
            }
            if(list[i].toInt()==5){
                Item Obj(5,"Epée",0,0,"/epee.png");
                inventory.push_back(Obj);
            }
        }

        hero.setInventory(inventory);
        setNextPath(list[nbr].toInt());

        int nbr2= nbr +list[nbr+1].toInt();
        for (int i = nbr;i<=nbr2;i++) {
            arriere.push_back(list[i].toInt());
        }
        qDebug() << "test" << arriere.at(arriere.size()-2);
    loadChoix();
    }
}

void MaFenetre::SauvegarderEtQuitter(){
    QFile file(adresse+"/Save.csv");


    if(!file.open(QIODevice::WriteOnly | QIODevice::ReadOnly | QIODevice::Text)){
        throw std::logic_error("Impossible de lire le fichier");
    }

    QTextStream stream(&file);

    QList<Item> inventory = hero.getInventory();


    stream << hero.getHealth() << ";" << inventory.size() << ";";
    for (int i = 0;i<inventory.size();i++) {
        Item obj = inventory.at(i);
        stream << obj.getIdItem() << ";";
    }

    stream << arriere.at(arriere.size()-1) << ";" ;
    stream << arriere.size() << ";";
    for (int i = 0;i<arriere.size();i++) {
        stream << arriere.at(i) << ";";
    }
    stream << ";" << ";" << ";";
    m_bouton_choix1->setVisible(false);
    m_bouton_choix2->setVisible(false);
    m_bouton_choix3->setVisible(false);
    m_bouton_choix4->setVisible(false);

    m_bouton_quitter->setVisible(true);
}

void MaFenetre::Texte(QString message){
    QStringList list = message.split("\n");


    if(list.size()==1){
        m_texte->setGeometry(900/2-((taille_texte(list[0])+5)/2),600/3-100,taille_texte(list[0])+5 , 40);
        m_texte->setText(list[0]);
        m_texte->setVisible(true);
        m_texte2->setVisible(false);
        m_texte3->setVisible(false);
        m_texte4->setVisible(false);
    }
    if(list.size()==2){
        m_texte->setGeometry(900/2-((taille_texte(list[0])+5)/2),600/3-100,taille_texte(list[0])+5 , 40);
        m_texte2->setGeometry(900/2-((taille_texte(list[1])+5)/2),600/3-50,taille_texte(list[1])+5 , 40);
        m_texte->setText(list[0]);
        m_texte2->setText(list[1]);
        m_texte->setVisible(true);
        m_texte2->setVisible(true);
        m_texte3->setVisible(false);
        m_texte4->setVisible(false);
    }
    if(list.size()==3){
        m_texte->setGeometry(900/2-((taille_texte(list[0])+5)/2),600/3-100,taille_texte(list[0])+5 , 40);
        m_texte2->setGeometry(900/2-((taille_texte(list[1])+5)/2),600/3-50,taille_texte(list[1])+5 , 40);
        m_texte3->setGeometry(900/2-((taille_texte(list[2])+5)/2),600/3,taille_texte(list[2]+5) , 40);
        m_texte->setText(list[0]);
        m_texte2->setText(list[1]);
        m_texte3->setText(list[2]);
        m_texte->setVisible(true);
        m_texte2->setVisible(true);
        m_texte3->setVisible(true);
        m_texte4->setVisible(false);
    }
    if(list.size()==4){
        m_texte->setGeometry(900/2-((taille_texte(list[0])+5)/2),600/3-100,taille_texte(list[0])+5 , 40);
        m_texte2->setGeometry(900/2-((taille_texte(list[1])+5)/2),600/3-50,taille_texte(list[1])+5 , 40);
        m_texte3->setGeometry(900/2-((taille_texte(list[2])+5)/2),600/3,taille_texte(list[2]+5) , 40);
        m_texte4->setGeometry(900/2-((taille_texte(list[3])+5)/2),600/3+50,taille_texte(list[3])+5 , 40);
        m_texte->setText(list[0]);
        m_texte2->setText(list[1]);
        m_texte3->setText(list[2]);
        m_texte4->setText(list[3]);
        m_texte->setVisible(true);
        m_texte2->setVisible(true);
        m_texte3->setVisible(true);
        m_texte4->setVisible(true);
    }

}


