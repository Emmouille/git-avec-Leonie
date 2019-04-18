#ifndef SOLEIL_H_INCLUDED
#define SOLEIL_H_INCLUDED
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "forme.h"

/* INTERFACE DE LA CLASSE SOLEIL */

class Soleil : public Forme //Un Soleil EST une Forme
{
/// Méthodes : déclarations (prototypes)
public:
    Soleil(double m_x, double m_y,std :: mt19937& graine); //Constructeur
    ~Soleil(); // Destructeur
    void dessiner(Svgfile *svgout); // Méthode virtuelle dessiner
};

#endif // SOLEIL_H_INCLUDED
