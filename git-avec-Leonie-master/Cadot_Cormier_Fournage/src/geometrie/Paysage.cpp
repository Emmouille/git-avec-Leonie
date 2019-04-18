#include "Paysage.h"

/* IMPLEMENTATION DE LA CLASSE PAYSAGE */

///Constructeur
Paysage :: Paysage(int largeur, int hauteur)
{
    ///initialisation des variables
    m_largeur=largeur;
    m_hauteur=hauteur;
}

///Destructeur
Paysage :: ~Paysage ()
{}

/// On ajoute des plans dans le paysage
Plan* Paysage::ajouterPlan(int profondeur)
{
    Plan* ptrsom = new Plan(profondeur, m_largeur, m_hauteur);///Création d'un plan
    mes_plans.push_back(ptrsom);///On met les plans à la fin du vecteur
    return ptrsom;///on retourne le pointeur sur plan
}

/// On dessine les plans
void Paysage::dessiner(Svgfile* svgout)
{
    for (size_t i = 0; i<mes_plans.size(); ++i)///On parcout le vecteur de plans
    {
        if (mes_plans[1])///trier les formes du second plan
        {
            mes_plans[1]->trier();
        }
        if (mes_plans[2])///trier les formes du premier plan
        {
            mes_plans[2]->trier();
        }

        mes_plans[i]->dessiner(svgout);///On dessiner les formes qui ont été trié, sur chaque plan
    }
}
