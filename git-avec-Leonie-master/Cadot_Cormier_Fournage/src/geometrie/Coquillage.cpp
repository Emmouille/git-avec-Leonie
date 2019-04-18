#include "Coquillage.h"

/* IMPLEMENTATION DE LA CLASSE COQUILLAGE */

/// Constructeur

Coquillage::Coquillage(double m_x, double m_y,std :: mt19937& graine)
    : Forme {m_x,m_y,graine}
{}

/// Destructeur

Coquillage::~Coquillage()
{}

/// Méthode dessiner (méthode virtuelle de forme)

void Coquillage::dessiner(Svgfile* svgout)
{
    using util :: alea;
    /// déclaration des variables pour une couleur aléatoire des coquillages
    int c1,c2,c3;
    c1 = alea(230,255);
    c2 = alea(185,210);
    c3 = alea(135,155);
    /// Couleur du coquillage (aléatoire)
    Couleur base{c1, c2, c3};

    ///nb permettant d'avoir le 2e point en x (pour ajouter le 2e sommet du triangle
    /// composant le coquillage (base du coquilage)
    double xnbAleatoire = alea(10,30,m_graine);

    ///nb permettant d'avoir le 2e point en y (pour ajouter le 3eme sommet du triangle
    /// composant le coquillage
    double ynbAleatoire = alea(10,30,m_graine);

    /// coord x de la base du coquillage (coin inférieur gauche)
    double xBaseCoquillage = m_position.getX();

    /// coord y de la base du coquillage
    double yBaseCoquillage = m_position.getY();

    ///on ajoute la base du triangle
    svgout->addTriangle(xBaseCoquillage,yBaseCoquillage,xBaseCoquillage+xnbAleatoire,yBaseCoquillage-ynbAleatoire,
                        xBaseCoquillage-xnbAleatoire, yBaseCoquillage-ynbAleatoire, base);

    ///on ajoute le haut du triangle (ellipse)
    svgout->addEllipses(xBaseCoquillage,yBaseCoquillage-ynbAleatoire,xnbAleatoire,ynbAleatoire/2,base,base,0);
}
