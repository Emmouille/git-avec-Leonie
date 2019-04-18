#ifndef RECTANGLE_H_INCLUDED
#define RECTANGLE_H_INCLUDED
#include <iostream>
#include <fstream>
#include <string>
#include "forme.h"

/* INTERFACE DE LA CLASSE RECTANGLE */

class Rectangle : public Forme //Une rectangle EST une Forme
{
/// Attributs : d�clarations
private :
    //largeur, hauteur et couleur du rectangle
    double m_largeur;
    double m_hauteur;
    Couleur m_couleur;

/// M�thodes : d�clarations (prototypes)
public:
    Rectangle(double m_x, double m_y, double largeur, double hauteur, Couleur& couleur,std :: mt19937& graine); //constructeur
    ~Rectangle(); //Destructeur
    void dessiner(Svgfile *svgout); //Dessiner un rectangle (m�thode virtuelle)
};

#endif // RECTANGLE_H_INCLUDED
