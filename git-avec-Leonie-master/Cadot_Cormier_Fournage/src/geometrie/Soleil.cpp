#include "soleil.h"
#include <iostream>

/* IMPLENTATION DE LA CLASSE SOLEIL */

/// Constructeur
Soleil::Soleil(double m_x, double m_y,std :: mt19937& graine)
    : Forme {m_x,m_y,graine}
{}

/// Destructeur
Soleil::~Soleil()
{}

/// Méthode virtuelle dessiner
void Soleil::dessiner(Svgfile* svgout)
{
    using util :: alea;
    Couleur jaune{231, 226, 25};

    /// Initialisation des variables
    double m_x = m_position.getX();
    double m_y = m_position.getY();

    /// DESSIN DU SOLEIL
    svgout->addDisk(m_x,m_y,40,jaune);  ///Dessin du disque

    double xL2,yL2;         ///coordonnées pour les rayons du soleil (fin du rayon)
    double aleax2,aleay2;   ///Coordonnées pour avoir des grands rayons

    for (int i=0;i<30;i++)     ///30 est le nombre de rayons
    {
        /// On génére de des nombre aléatoire
        aleax2=alea(-m_x+10,m_y+30,m_graine);
        aleay2= alea(-m_y+10,m_y+30,m_graine);
        xL2= alea(m_x+10,aleax2,m_graine);
        yL2= alea(m_y+10,aleay2,m_graine);
        svgout->addLine(m_x,m_y, xL2,yL2,jaune);    ///On dessine les rayons (grâce à des lignes)
                                                    ///Le rayon demarre à (m_x, m_y) -> centre du disque
    }
}
