#ifndef PLANS_H_INCLUDED
#define PLANS_H_INCLUDED
#include "Forme.h"
#include <vector>
#include <iostream>
#include "coords.h"
#include "../svg/svgfile.h"

/*INTERFACE DE LA CLASSE PLAN*/

class Plan
{
/// Méthodes : déclarations (prototypes)
public:
    Plan(int profondeur, int largeur, int hauteur); // constructeur
    void ajouterForme(Forme* forme); //ajoute des formes dans les plans
    void dessiner(Svgfile* svgout); //dessine les plans
    void trier(); //permet de trier les formes pour pas qu'elles se supperposent
    ~Plan(); //Destructeur

/// Attributs : déclarations
private:
    // coordonnées de délimitation de chaque plan
    Coords m_x;
    Coords m_y;
    int m_largeur;
    int m_hauteur;
    std :: vector < Forme *> mes_formes;//Vecteur de forme (il contient les formes)

    int m_profondeur;//Pour savoir dans quel plan on est :
                    // 0 : arrière plan
                    // 1 : Second plan
                    // 2 : premier plan
};

#endif // PLANS_H_INCLUDED
