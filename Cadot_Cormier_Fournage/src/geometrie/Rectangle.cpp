#include "Rectangle.h"
#include <iostream>

/* IMPLEMENTATION DE LA CLASSE RECTANGLE */

///Constructeur
Rectangle::Rectangle(double m_x, double m_y, double largeur, double hauteur, Couleur& couleur,std :: mt19937& graine)
   : Forme {m_x,m_y,graine}
{
    ///Initialisation des variables
    m_couleur = couleur;
    m_largeur= largeur;
    m_hauteur= hauteur;
}

/// Destructeur
Rectangle::~Rectangle()
{}

/// Méthode dessiner (méthode virtuelle de forme)
void Rectangle::dessiner(Svgfile* svgout)
{
    svgout->addRectangle(m_position.getX(),m_position.getY(),
                         m_position.getX()+m_largeur, m_position.getY(),
                         m_position.getX()+m_largeur,m_position.getY()+m_hauteur,
                         m_position.getX(),m_position.getY()+m_hauteur, m_couleur);
}
