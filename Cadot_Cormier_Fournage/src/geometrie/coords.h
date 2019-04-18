#ifndef COORDS_H_INCLUDED
#define COORDS_H_INCLUDED
#include "coords.h"
#include <random>
#include <ctime>
#include <iostream>
#include <cstdio>

/*INTERFACE DE LA CLASSE COORDS */

class Coords
{
    /// Méthodes : déclarations (prototypes)
    public :
        Coords(double x, double y);
        Coords();
        static Coords aleatoire(double amplitude,std :: mt19937 graine);

        void afficher() const;
        void saisir();

        double getX() const;
        double getY() const;

        /// Positions relatives
        bool estAGauche(const Coords& autre) const;
        bool estADroite(const Coords& autre) const;
        bool estAuDessus(const Coords& autre) const;
        bool estAuDessous(const Coords& autre) const;

        bool bouger();
        /// Somme vectorielle
        friend Coords operator+(const Coords& c1, const Coords& c2);

        /// Soustraction vectorielle
        friend Coords operator-(const Coords& c1, const Coords& c2);

        /// Produit vectoriel
        friend double operator*(const Coords& c1, const Coords& c2);

        /// Multiplication par un réel
        friend Coords operator*(double m, const Coords& c);

    /// Attributs : déclarations
    private :
        double m_x;
        double m_y;
};


#endif // COORDS_H_INCLUDED
