#include "Palmier.h"

/* IMPLEMENTATION DE LA CLASSE PALMIER */

/// Constructeur
Palmier::Palmier(double m_x, double m_y,std :: mt19937& graine)
    : Forme {m_x,m_y,graine}
{}

/// Destructeur
Palmier::~Palmier()
{}

/// Méthode dessiner (méthode virtuelle de forme)
void Palmier::dessiner(Svgfile* svgout)
{
    Couleur tronc{127, 65, 31};        /// Couleur du tronc (aléatoire)
    Couleur feuille{65,154,34};

    using util :: alea;
    int x1Tronc = m_position.getX(); /// coord x de la base du tronc (coin bas gauche)
    int y1Tronc = m_position.getY(); /// coord y de la base du tronc (coin bas gauche)

    int x2Tronc = alea(x1Tronc+20,x1Tronc+70,m_graine);
    int y2Tronc = y1Tronc;

    int x3Tronc = x2Tronc;
    int y3Tronc = alea(y1Tronc-250,y1Tronc-130,m_graine);   /// on inverve les coordonnées (x1, x2 en bas et x3, x4 en haut)

    int x4Tronc = x1Tronc;
    int y4Tronc = y3Tronc;

    svgout->addRectangle(x1Tronc,y1Tronc,x2Tronc,y2Tronc,
                         x3Tronc, y3Tronc, x4Tronc,y4Tronc,tronc);


    /// AJOUT DE LA PREMIERE FEUILLE DU PALMIER (TRIANGLE)

    int x1Triangle1 = (x4Tronc+x3Tronc)/2;
    int y1Triangle1 = y4Tronc;

    int x2Triangle1 = x3Tronc+200;
    int y2Triangle1 = y3Tronc;

    int x3Triangle1 = x2Triangle1;
    int y3Triangle1 = y2Triangle1-100;

    /// Rotation angle du 1er triangle , angle varie entre 30 et 90 degrés

    Coords c1T1{x1Triangle1, y1Triangle1};
    Coords c2T1{x2Triangle1, y2Triangle1};
    Coords c3T1{x3Triangle1, y3Triangle1};
    Coords centreT1{x1Triangle1, y1Triangle1};
    double angleT1 = util::alea(30,90,m_graine);
    Transformation transfoT1{ Rotation{centreT1, angleT1} };
    transfoT1.appliquer(c1T1);
    transfoT1.appliquer(c2T1);
    transfoT1.appliquer(c3T1);

    svgout->addTriangle(c1T1.getX(),c1T1.getY(),c2T1.getX(),c2T1.getY(),c3T1.getX(),c3T1.getY(), feuille);


    /// AJOUT DE LA DEUXIEME FEUILLE DU PALMIER

    int x1Triangle2 = (x4Tronc+x3Tronc)/2;
    int y1Triangle2 = y4Tronc;

    int x2Triangle2 = x3Tronc+50;
    int y2Triangle2 = y3Tronc-170;

    int x3Triangle2 = x4Tronc-50;
    int y3Triangle2 = y4Tronc-140;

    /// Rotation angle du 2ème triangle , angle varie entre 30 et 90 degrés

    Coords c1T2{x1Triangle2, y1Triangle2};
    Coords c2T2{x2Triangle2, y2Triangle2};
    Coords c3T2{x3Triangle2, y3Triangle2};
    Coords centreT2{x1Triangle2, y1Triangle2};
    double angleT2 = util::alea(30,90,m_graine);
    Transformation transfoT2{ Rotation{centreT2, angleT2} };
    transfoT2.appliquer(c1T2);
    transfoT2.appliquer(c2T2);
    transfoT2.appliquer(c3T2);

    svgout->addTriangle(c1T2.getX(),c1T2.getY(),c2T2.getX(),c2T2.getY(),c3T2.getX(),c3T2.getY(), feuille);


    /// AJOUT DE LA TROISIEME FEUILLE DU PALMIER

    int x1Triangle3 = (x4Tronc+x3Tronc)/2;
    int y1Triangle3 = y4Tronc;

    int x2Triangle3 = x4Tronc-200;
    int y2Triangle3 = y4Tronc-100;

    int x3Triangle3 = x4Tronc-200;
    int y3Triangle3 = y4Tronc;

    /// Rotation angle du 3ème triangle , angle varie entre 30 et 90 degrés

    Coords c1T3{x1Triangle3, y1Triangle3};
    Coords c2T3{x2Triangle3, y2Triangle3};
    Coords c3T3{x3Triangle3, y3Triangle3};
    Coords centreT3{x1Triangle3, y1Triangle3};
    double angleT3 = util::alea(30,90,m_graine);
    Transformation transfoT3{ Rotation{centreT3, angleT3} };
    transfoT3.appliquer(c1T3);
    transfoT3.appliquer(c2T3);
    transfoT3.appliquer(c3T3);

    svgout->addTriangle(c1T3.getX(),c1T3.getY(),c2T3.getX(),c2T3.getY(),c3T3.getX(),c3T3.getY(), feuille);


    /// AJOUT DE LA QUATRIEME FEUILLE DU PALMIER

    int x1Triangle4 = (x4Tronc+x3Tronc)/2;
    int y1Triangle4 = y4Tronc;

    int x2Triangle4 = x3Tronc+180;
    int y2Triangle4 = y3Tronc-100;

    int x3Triangle4 = x3Tronc+120;
    int y3Triangle4 = y3Tronc-70;

    /// Rotation angle du 4ème triangle , angle varie entre 30 et 90 degrés

    Coords c1T4{x1Triangle4, y1Triangle4};
    Coords c2T4{x2Triangle4, y2Triangle4};
    Coords c3T4{x3Triangle4, y3Triangle4};
    Coords centreT4{x1Triangle4, y1Triangle4};
    double angleT4 = util::alea(30,90,m_graine);
    Transformation transfoT4{ Rotation{centreT4, angleT4} };
    transfoT4.appliquer(c1T4);
    transfoT4.appliquer(c2T4);
    transfoT4.appliquer(c3T4);

    svgout->addTriangle(c1T4.getX(),c1T4.getY(),c2T4.getX(),c2T4.getY(),c3T4.getX(),c3T4.getY(), feuille);

    /// AJOUT DE LA CINQUIEME FEUILLE DU PALMIER

    int x1Triangle5 = (x4Tronc+x3Tronc)/2;
    int y1Triangle5 = y4Tronc;

    int x2Triangle5 = x4Tronc+120;
    int y2Triangle5 = y4Tronc-100;

    int x3Triangle5 = x4Tronc+180;
    int y3Triangle5 = y4Tronc-70;

    /// Rotation angle du 5ème triangle , angle varie entre 30 et 90 degrés

    Coords c1T5{x1Triangle5, y1Triangle5};
    Coords c2T5{x2Triangle5, y2Triangle5};
    Coords c3T5{x3Triangle5, y3Triangle5};
    Coords centreT5{x1Triangle5, y1Triangle5};
    double angleT5 = util::alea(30,90,m_graine);
    Transformation transfoT5{ Rotation{centreT5, angleT5} };
    transfoT5.appliquer(c1T5);
    transfoT5.appliquer(c2T5);
    transfoT5.appliquer(c3T5);

    svgout->addTriangle(c1T5.getX(),c1T5.getY(),c2T5.getX(),c2T5.getY(),c3T5.getX(),c3T5.getY(), feuille);
}
