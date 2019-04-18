#include "Ellipse.h"
#include <iostream>

/* IMPLEMENTATION DE LA CLASSE ELLIPSE */

/// Constructeur

Ellipse::Ellipse(int x, int y, double rayonX, double rayonY, Couleur &remplissage, Couleur &contour , int epaisseur,std :: mt19937& graine)
    : Forme {x,y,graine}
{
    m_rx =rayonX;
    m_ry =rayonY;
    m_couleurRemplissage = remplissage;
    m_couleurContour = contour;
    m_epaisseurContour = epaisseur;
}

/// Destructeur
Ellipse::~Ellipse()
{}

/// Méthode dessiner (méthode virtuelle de forme)
void Ellipse::dessiner(Svgfile* svgout)
{
    svgout->addEllipses(m_position.getX(), m_position.getY(), m_rx, m_ry, m_couleurRemplissage, m_couleurContour, m_epaisseurContour);
}
