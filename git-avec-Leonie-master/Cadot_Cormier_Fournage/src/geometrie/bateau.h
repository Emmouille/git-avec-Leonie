#ifndef BATEAU_H_INCLUDED
#define BATEAU_H_INCLUDED
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "forme.h"

/* INTERFACE DE LA CLASSE BATEAU */

class Bateau : public Forme //Un Bateau EST une Forme
{

/// Méthodes : déclarations (prototypes)
public:
    Bateau(double m_x, double m_y,std :: mt19937& graine); //constructeur
    ~Bateau(); // destructeur
    void dessiner(Svgfile* svgout); // méthode dessiner virtuelle
};

#endif // BATEAU_H_INCLUDED
