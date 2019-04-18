#ifndef FORME_H_INCLUDED
#define FORME_H_INCLUDED
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "coords.h"
#include "../svg/svgfile.h"
#include "../util/util.h"
#include "../graphisme/couleur.h"

/* INTERFACE DE LA CLASSE FORME */ /* Forme est une classe abstraite */

enum typeDecor {BATEAU, CRABE, NUAGE};

class Forme
{
/// Attributs : d�clarations
protected :
    Coords m_position;
    std :: mt19937 m_graine;

/// M�thodes : d�clarations (prototypes)
public :
    Forme(double m_x, double m_y,  std :: mt19937 graine);  // Constructeur
    void positionF(); // pour modifier la valeur des coordonn�es

    /// Polymorphisme
    double getX();
    double getY();
    ~Forme() = default; // Destructeur
   virtual void dessiner(Svgfile* svgout)=0;// m�thode dessiner virtuelle pur
};

#endif // FORME_H_INCLUDED
