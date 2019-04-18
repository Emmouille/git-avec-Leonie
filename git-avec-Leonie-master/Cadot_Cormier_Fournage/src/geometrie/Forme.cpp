#include "Forme.h"

/* IMPLEMENTATION DE LA CLASSE ABSTRAITE FORME */

///Constructeur de forme

Forme::Forme(double m_x, double m_y,  std :: mt19937 graine)
    :m_position{m_x,m_y}, m_graine{graine}
{}

///m�thode qui permet de r�cup�rer la coordonnn�e x
double Forme :: getX()
{
    return m_position.getX();
}

///m�thode qui permet de r�cup�rer la coordonnn�e y
double Forme :: getY()
{
    return m_position.getY();
}

