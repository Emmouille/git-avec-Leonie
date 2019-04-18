#include "Plan.h"
#include <algorithm>   ///pour le sort

/* IMPLEMENTATION DE LA CLASSE PLAN */

/// Constructeur
Plan::Plan(int profondeur, int largeur, int hauteur)
{
    /// Initialisation des variables
    m_largeur = largeur;
    m_profondeur = profondeur;
    m_hauteur = hauteur;
}

/// Méthode permettant d'ajouter une forme (un objet) à chaque plan
void Plan::ajouterForme(Forme* forme)
{
    mes_formes.push_back(forme);    ///On ajoute la forme au vecteur de forme
}

/// Méthode permettant de dessiner les plans en fonction des formes qu'ils contiennent
void Plan :: dessiner(Svgfile* svgout)
{
    for (size_t i = 0; i<mes_formes.size(); ++i)///On parcourt le vecteur qui contient les formes
    {
        mes_formes[i]->dessiner(svgout);///On dessine chaque forme
    }
}

/// Méthode de tri qui permet aux formes de ne pas se supperposer
void Plan :: trier ()
{
    ///Tri des formes selon y pour effet de perspective (grâce à la méthode sort)
    std::sort(mes_formes.begin(),mes_formes.end(), [](Forme* a, Forme* b)
    {
        return a->getY()< b->getY();///si le y de la première forme est supérieur au y de la 2ème forme
                                    ///l'objet sera donc avant
    });
}
