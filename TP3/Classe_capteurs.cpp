#include "Classe_capteurs.h"
#include <cmath>  // Pour utiliser sqrt()

//NE PAS TOUCHER A CES 2 DEFINITIONS
//genere un nombre entier aleatoire entre 0 et imax
unsigned int randint(unsigned int const imax)
{
    return rand() % imax;
}

//genere un nombre decimal aleatoire entre 0 et dmax
double randdouble(double const dmax, double const dmin)
{
    return dmin+(rand() / (1. + RAND_MAX))*dmax;
}

/// //////////////////////////////////////////////////////////////////////////////
/// ////////////////////// CLASSE CAPTEUR ////////////////////////////////////////
/// //////////////////////////////////////////////////////////////////////////////

/// CONSTRUCTEURS ET DESTRUCTEUR

//Constructeur par defaut
Capteur::Capteur(void)
{
    value = -1;
    id = -1;
    nombre_de_modification_value = 1;
    std::cout << "Constructeur de capteur de l'objet [" << this << "] "<< std::endl;
}

// Constructeur avec argument
Capteur::Capteur(const int iid, const double dvalue)
{
    id = iid;
    value = dvalue;
    nombre_de_modification_value = 1;
    std::cout << "Constucteur avec arguments pour la classe capteur de l'objet [" << this << "] "<< std::endl;
}

// Constructeur par copie
Capteur::Capteur(const Capteur &p):id{p.id+1}, value{p.value}
{
    std::cout << "Constructeur du capteur par copie depuis [" << &p << "] vers le nouvel objet [" << this << "] " << std::endl;
}

// Destructeur
Capteur::~Capteur(void)
{
    std::cout << "Destructeur du capteur [" << this << "] "<< std::endl;
}

/// ROUTI DE CLASSE

// Fonction get
double Capteur::get(void) const
{
    return value ;
}

double Capteur::get_modification(void) const
{
    return nombre_de_modification_value ;
}

// Fonction set
void Capteur::set(const double val)
{
    value_precredente = value;
    value = val ;
    if (value=!value_precredente)
    {
        nombre_de_modification_value++;
    }

}
// Fonction affichage de l'id
void Capteur::cout_id(void) const
{
    std::cout << "L'identifiant du capteur est : " << id << std::endl;
}

double Capteur::ecart(const Capteur &p) const
{
    return sqrt(pow(p.value - value, 2)); // j'utilise pow de cmath pour mettre au carré, faire la racine de la difference au carré me permet de récuperer la valeur absolu de l'ecart
}

