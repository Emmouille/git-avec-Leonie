#ifndef ELLIPSE_H_INCLUDED
#define ELLIPSE_H_INCLUDED
#include "Forme.h"

/*INTERFACE DE LA CLASSE ELLIPSE*/

class Ellipse : public Forme //Une Ellipse EST une Forme
{
    /// Méthodes : déclarations (prototypes)
public:
    //Constructeur
    Ellipse(int x, int y, double rayonX, double rayonY, Couleur &remplissage, Couleur &contour, int epaisseur,std :: mt19937& graine);
   //Destructeur
    ~Ellipse();
    //Méthode dessiner virtuelle
    void dessiner(Svgfile* svgout);

    /// Attributs : déclarations
private:
    double m_rx;
    double m_ry;
    Couleur m_couleurRemplissage;
    Couleur m_couleurContour;
    int m_epaisseurContour;

};

#endif // ELLIPSE_H_INCLUDED
