#ifndef COULEUR_H_INCLUDED
#define COULEUR_H_INCLUDED
#include <string>
#include <cstdint>

/*INTERFACE DE LA CLASSE COULEUR*/

class Couleur
{
/// Attributs : déclarations
    public :
        Couleur(uint8_t rouge, uint8_t vert, uint8_t bleu);
        Couleur();
        void afficher() const;
        void saisir();
        double getOpacity();
        void muter(double amplitude);
        operator std::string() const;

/// Méthodes : déclarations (prototypes)
    private :
        // uint8_t équivalent à unsigned char :
        // unsigned 8 bits (8 bits non signé)
        uint8_t m_rouge, m_vert, m_bleu;
        double m_opacity;
};

#endif // COULEUR_H_INCLUDED
