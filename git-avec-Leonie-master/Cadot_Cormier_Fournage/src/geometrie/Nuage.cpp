#include "Nuage.h"
#include <iostream>

/* IMPLEMENTATION DE LA CLASSE NUAGE */

///Contructeur
Nuage::Nuage(double m_x, double m_y,std :: mt19937& graine)
    : Forme {m_x,m_y,graine}
{}

///Destructeur
Nuage::~Nuage()
{}

///Méthode qui permet de dessiner les nuages (composés de 2 ellipses)
void Nuage::dessiner(Svgfile* svgout)
{
    ///coordonnées de la première ellipse
    using util :: alea;
    int m_x = m_position.getX();
    int m_y = m_position.getY();
    int m_rx = alea(30,100,m_graine);
    int m_ry = alea(20, 30,m_graine);
    Couleur blanc{255, 255, 255};


    ///coordonnes de la 2ème ellipse
    int x2 = m_x+10;
    int y2 = m_y+20;
    int rx2 = m_rx*2;
    int ry2 = m_ry;


    ///Dessin des 2 ellipses
    svgout->addEllipses(m_x,m_y,m_rx, m_ry, blanc, blanc, 0);
    svgout->addEllipses(x2,y2,rx2,ry2, blanc, blanc, 0);
}
