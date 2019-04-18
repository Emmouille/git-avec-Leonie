#ifndef COULEUR_H_INCLUDED
#define COULEUR_H_INCLUDED
#include <string>
#include <cstdint>

/*INTERFACE DE LA CLASSE COULEUR*/

class Couleur
{
/// Attributs : d�clarations
    public :
        Couleur(uint8_t rouge, uint8_t vert, uint8_t bleu);
        Couleur();
        void afficher() const;
        void saisir();
        double getOpacity();
        void muter(double amplitude);
        operator std::string() const;

/// M�thodes : d�clarations (prototypes)
    private :
        // uint8_t �quivalent � unsigned char :
        // unsigned 8 bits (8 bits non sign�)
        uint8_t m_rouge, m_vert, m_bleu;
        double m_opacity;
};

#endif // COULEUR_H_INCLUDED
