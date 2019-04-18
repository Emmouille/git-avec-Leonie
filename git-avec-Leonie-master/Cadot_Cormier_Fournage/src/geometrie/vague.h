#ifndef VAGUE_H_INCLUDED
#define VAGUE_H_INCLUDED
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "forme.h"

/* INTERFACE DE LA CLASSE VAGUE */

class Vague : public Forme //Une vague est une Forme
{
/// M�thodes : d�clarations (prototypes)
public:
    Vague(double m_x, double m_y,std :: mt19937& graine); //Constructeur
    ~Vague(); //Destructeur
    void dessiner(Svgfile* svgout); //m�thode dessiner virtuelle
};

#endif // VAGUE_H_INCLUDED
