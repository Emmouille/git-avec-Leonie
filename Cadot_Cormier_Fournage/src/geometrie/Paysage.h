#ifndef PAYSAGE_H_INCLUDED
#define PAYSAGE_H_INCLUDED
#include "coords.h"
#include <vector>
#include "Plan.h"
#include "../svg/svgfile.h"

/*INTERFACE DE LA CLASSE PAYSAGE*/

/***************************************************************
* Classe principale qui contient les plans et peut les dessiner*
***************************************************************/

class Paysage
{
/// Attributs : déclarations
private :
    std :: vector < Plan *> mes_plans;//Vecteur qui contient les plans
    /// dimensions de l'image
    int m_largeur;       //largeur de l'image
    int m_hauteur;

/// Méthodes : déclarations (prototypes)
public :
    Paysage(int m_largeur, int m_hauteur);  //Constructeur
    Plan* ajouterPlan(int profondeur);      //On ajoute des plans grâce au pointeur sur plan
    void dessiner(Svgfile* svgout);         //On dessine le paysage
    ~Paysage();
};
#endif // PAYSAGE_H_INCLUDED
