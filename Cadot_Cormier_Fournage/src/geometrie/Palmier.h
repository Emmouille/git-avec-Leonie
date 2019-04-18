#ifndef PALMIER_H_INCLUDED
#define PALMIER_H_INCLUDED
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "forme.h"
#include "transformation.h"

/*INTERFACE DE LA CLASSE PALMIER*/

class Palmier : public Forme //Un Palmier EST une Forme
{
/// Méthodes : déclarations (prototypes)
public:
    Palmier(double m_x, double m_y,std :: mt19937& graine);//constructeur
    ~Palmier();// destructeur
    void dessiner(Svgfile* svgout);// méthode dessiner virtuelle (classe Forme)

};

#endif // PALMIER_H_INCLUDED
