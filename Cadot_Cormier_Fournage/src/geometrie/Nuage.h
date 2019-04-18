#ifndef NUAGE_H_INCLUDED
#define NUAGE_H_INCLUDED
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "forme.h"

/*INTERFACE DE LA CLASSE NUAGE*/

class Nuage : public Forme //Un Nuage EST une Forme
{
/// Méthodes : déclarations (prototypes)
public :
    Nuage(double m_x, double m_y, std :: mt19937& graine); //Constructeur
    ~Nuage(); //Destructeur
    void dessiner(Svgfile *svgout); //Méthode qui permet de dessiner les nuages (méthode virtuelle)
};

#endif // NUAGE_H_INCLUDED
