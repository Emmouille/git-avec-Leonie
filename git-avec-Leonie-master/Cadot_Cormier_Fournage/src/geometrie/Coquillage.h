#ifndef COQUILLAGE_H_INCLUDED
#define COQUILLAGE_H_INCLUDED
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "forme.h"

/*INTERFACE DE LA CLASSE COQUILLAGE*/

class Coquillage : public Forme //Un Coquillage EST une Forme
{
    /// Méthodes : déclarations (prototypes)
    public:
    Coquillage(double m_x, double m_y, std :: mt19937& graine); //constructeur
    ~Coquillage(); // destructeur
    void dessiner(Svgfile* svgout); // méthode dessiner virtuelle (classe Forme)
};

#endif // COQUILLAGE_H_INCLUDED
