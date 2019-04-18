#include "bateau.h"
#include "coords.h"

/* IMPLEMENTATION DE LA CLASSE BATEAU */

/// Constructeur

Bateau::Bateau(double m_x, double m_y,std :: mt19937& graine)
    : Forme {m_x,m_y,graine}
{}

/// Destructeur

Bateau::~Bateau()
{}

/// Méthode dessiner (méthode virtuelle de forme)

void Bateau::dessiner(Svgfile* svgout)
{

/// INITIALISATION

    int HauteurBateauInitial=util::alea(100,250,m_graine);  ///Cette valeur va déterminer la position de la base du bateau
                                                            ///Le bateau est toujours déssinée à Y+HauteurBateauIntial puis homothétie éventuelle.
    int LargeurBateauInitial=util::alea(100,250,m_graine);

    int CordX=m_position.getX();
    int CordY=m_position.getY();

    int cX1,cY1,cX2,cY2,cX3,cY3,cX4,cY4,cX5,cY5,cX6,cY6; /// utilisation pour la coque
    int c1,c2,c3; /// utilisation pour la voile

/// PERSPECTIVE

    /// taille des bateaux situés dans le 1er tiers du plan mer
    if(CordY<=(1000/3)+100)
    {
        HauteurBateauInitial=util::alea(10,60,m_graine);
        LargeurBateauInitial=util::alea(30,60,m_graine);
    }

    /// taille des bateaux situés dans le 2ème tiers du plan mer
    else if( CordY<=(1000/3)+200)
    {
        HauteurBateauInitial=util::alea(60,100,m_graine);
        LargeurBateauInitial=util::alea(60,120,m_graine);
    }

    /// taille des bateaux situés dans le dernier tiers du plan mer
    else
    {
        HauteurBateauInitial=util::alea(100,150,m_graine);
        LargeurBateauInitial=util::alea(90,180,m_graine);
    }

/** le bâteau est construit avec un trapèze pour la coque, un triangle pour la voile et un trait pour mat
la coque aura les points P0, P1, P2, P3 où P0 est le point bas gauche de la coque
qui est aussi les coord de création du bâteau
La coque fait 1/3 de la hauteur du bateau : HauteurBateauInitial
La proue, le centre, l'arrière font chacun 1/3 du bateau **/

/// DESSIN DU BATEAU

    /// LA COQUE

    cX1=CordX+(LargeurBateauInitial/2);
    cY1=CordY;
    cX2 = cX1 + LargeurBateauInitial/4;
    cY2 = cY1 - HauteurBateauInitial/3;
    cX3 = cX2 - LargeurBateauInitial;
    cY3 = cY2;
    /// Couleur du bateau (aléatoire)
    Couleur base{128, 64, 0};
    /// Dessin du rectangle
    svgout->addRectangle(CordX,CordY, cX1,cY1,cX2, cY2,cX3, cY3, base);

    /// LA VOILE

    using util :: alea;
    ///couleur de la voile (aléatoire)
    c1= alea(0,255,m_graine);
    c2= alea(0,255,m_graine);
    Couleur voile{c1,c2,c3};

    cX4=CordX+LargeurBateauInitial/4;
    cY4=CordY-HauteurBateauInitial;
    cX5=cX4+LargeurBateauInitial/2;
    cY5=cY2-10;
    cX6=cX4-LargeurBateauInitial/2;
    cY6=cY5;
    /// Dessin du triangle
    svgout->addTriangle(cX4,cY4,cX5,cY5,cX6,cY6,voile);

    /// LE MAT

    /// couleur du mat prédéfinie
    Couleur black{0,0,0};
    /// Dessin de la ligne
    svgout->addLine(cX4, cY5, cX4, cY2, "black");
}
