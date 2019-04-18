#include "vague.h"
#include <iostream>

/* IMPLEMENTATION DE LA CLASSE VAGUE */

/// Constructeur

Vague::Vague(double m_x, double m_y,std :: mt19937& graine)
    : Forme {m_x,m_y,graine}
{}

/// Destructeur
Vague::~Vague()
{}

/// Méthode dessiner (méthode virtuelle de forme)
void Vague::dessiner(Svgfile* svgout)
{
    using util :: alea;

    /// Initialisation des 4 points utiles pour utiliser la courbe
    int x1V=m_position.getX();
    int y1V=m_position.getY();
    int x2V = alea(x1V,x1V+300,m_graine);
    int y2V = alea(y1V-100,y1V,m_graine);
    int x3V = alea(x2V,x2V+200,m_graine);
    int y3V = y2V;
    int x4V = alea(x3V,x3V+300,m_graine);
    int y4V = y1V;

    Couleur bleuVagues{122,224,214};

    /// Dessin des vagues (courbes)
    svgout->addCourbeBezier(x1V,y1V,x2V,y2V,x3V,y3V,x4V,y4V,bleuVagues);
}
