#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <random>
#include <ctime>
#include <cstdio>

#include "geometrie/vague.h"
#include "geometrie/Palmier.h"
#include "geometrie/Paysage.h"
#include "geometrie/transformation.h"
#include "graphisme/couleur.h"
#include "svg/svgfile.h"
#include "util/util.h"
#include "geometrie/Plan.h"
#include "geometrie/Paysage.h"
#include "graphisme/couleur.h"
#include "geometrie/Rectangle.h"
#include "geometrie/forme.h"
#include "geometrie/soleil.h" // ou #include "geometrie/Soleil.h"

#include "geometrie/vague.h"
#include "geometrie/bateau.h"
#include "geometrie/Ellipse.h"
#include "geometrie/Coquillage.h"
#include "geometrie/Nuage.h"

int main()
{
    int largeurImage=2000,hauteurImage=1000; /// taille image
    int choix;
/// initialisation de la densité
    int nbNuages;
    int nbBateau;
    int nbCoquillage;
    int nbPalmier;
/// initialisation des couleurs
    Couleur couleurCiel;
    Couleur couleurMer;
    Couleur couleurSable;
    Couleur vert (14,170,70);
/// initialisation de la graine pour chaque plan
    int graine1;
    int graine2;
    int graine3;

                    ///------------------- MENU -----------------------///

    do
    {
        std::cout << "Quel choix faites-vous?" << std :: endl;
        std::cout << "0. Quitter" << std :: endl;
        std::cout << "1. Dessiner scene" << std :: endl;
        std::cin >> choix;

        Svgfile svgout("output.svg",largeurImage, hauteurImage); // ouverture du fichier output.svg

        switch (choix)
        {
        case 0 :
            return 0;
            break;

        case 1 :

///Choix densité

            std::cout << "Choix densite : " << std :: endl<< std :: endl;

            std :: cout << " Combien de nuages voulez-vous ?" << std :: endl;
            std :: cout << "nuages : "<< std :: endl;
            std :: cin >> nbNuages;

            std :: cout << " Combien de bateaux voulez-vous ?" << std :: endl;
            std :: cout << "bateaux : "<< std :: endl;
            std :: cin >> nbBateau;

            std :: cout << " Combien de coquillages voulez-vous ?" << std :: endl;
            std :: cout << "coquillages : "<< std :: endl;
            std :: cin >> nbCoquillage;

            std :: cout << " Combien de palmiers voulez-vous ?" << std :: endl;
            std :: cout << "palmiers : "<< std :: endl;
            std :: cin >> nbPalmier;

            std :: cout << std :: endl;


///Choix couleur

            std::cout << "Choix couleur du fond par plan : " << std :: endl << std :: endl;

            std :: cout << " De quelle couleur voulez-vous le ciel ?" << std :: endl;
            std :: cout << "Une couleur bleu ciel correspond a 116,210,244"<< std :: endl;
            couleurCiel.saisir();


            std :: cout << " De quelle couleur voulez-vous la mer ?" << std :: endl;
            std :: cout << "Une couleur bleu fonce correspond a 168,242,240"<< std :: endl;
            couleurMer.saisir();

             std :: cout << " De quelle couleur voulez-vous le sable ?" << std :: endl;
             std :: cout << "Une couleur jaune orange correspond a 245,232,199"<< std :: endl;
            couleurSable.saisir();

            std :: cout << std :: endl;

            ///pour générer un nombre aléatoire
            using util :: alea;

            /// appel constructeur paysage
            Paysage monPaysage{largeurImage, hauteurImage};

///Choix graine

            std::cout << "Choix de la graine par plan : " << std :: endl<< std :: endl;

            int graine1;
            std :: cout <<"entrez la graine du plan 1 (premier plan) : " << std :: endl;
            std :: cout <<"graine du plan 1 : " ;
            std :: cin>>graine1;
            std :: mt19937 rg1 {graine1};

            int graine2;
            std :: cout <<"entrez la graine du plan 2 (second plan) : " << std :: endl;
            std :: cout <<"graine du plan 2 : " ;
            std :: cin>>graine2;
            std :: mt19937 rg2 {graine2};

            int graine3;
            std :: cout <<"entrez la graine du plan 3 (arriere plan): " << std :: endl;
            std :: cout <<"graine du plan 3: " ;
            std :: cin>>graine3;
            std :: mt19937 rg3 {graine3};

            std :: cout << std :: endl;

/// Déclaration et ajout des plans
/// Ajout des formes spécifiques à chaque plan

            /// ARRIERE PLAN
            Plan* arrierePlan = monPaysage.ajouterPlan(0);
            arrierePlan->ajouterForme(new Rectangle(0,0,largeurImage, hauteurImage, couleurCiel,rg3));
            arrierePlan->ajouterForme(new Soleil(alea(0,largeurImage,rg3),alea(0,hauteurImage/3,rg3),rg3));
            ///ajouter des nuages
            for (int i=0; i<nbNuages; i++)
            {
                arrierePlan->ajouterForme(new Nuage(alea(10,largeurImage,rg3), alea(0, (hauteurImage/3)-100,rg3),rg3));//Pour pas que les nuages soient sur la mer
            }

            /// SECOND PLAN
            Plan* secondPlan = monPaysage.ajouterPlan(1);
            secondPlan->ajouterForme(new Rectangle(0,hauteurImage/3,largeurImage, 2*hauteurImage/3, couleurMer,rg2));

            ///ajouter des vagues
            for (int i=0;i<20;i++)
            {
                secondPlan->ajouterForme(new Vague(alea(0,largeurImage,rg2),alea (400,630,rg2),rg2));
            }

            ///ajouter des bateaux
            for (int i=0; i<nbBateau; i++)
            {
                secondPlan->ajouterForme(new Bateau(alea(0,largeurImage,rg2),alea(hauteurImage/3,2*hauteurImage/3,rg2),rg2));
            }

            /// PREMIER PLAN
            Plan* premierPlan = monPaysage.ajouterPlan(2);
            premierPlan->ajouterForme(new Rectangle(0,2*hauteurImage/3,largeurImage, hauteurImage/3, couleurSable,rg1));

            ///ajouter des coquillages
            for (int i=0;i<nbCoquillage;i++)
            {
                premierPlan->ajouterForme(new Coquillage(alea(0,largeurImage,rg1),alea(2*hauteurImage/3+100,hauteurImage,rg1),rg1));
            }

            ///ajouter des palmiers
              for (int i =0;i<nbPalmier;i++)
            {
                  premierPlan->ajouterForme(new Palmier(alea(0,largeurImage,rg1),alea(2*hauteurImage/3+100,hauteurImage,rg1),rg1));
            }

            monPaysage.dessiner(&svgout);

            break;
        }
    }
    while (choix !=0);

    return 0;
}


