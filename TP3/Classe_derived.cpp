#include "Classe_derived.h"

/// /////////////////////////////////////////////////////////////////////////
/// //////////////////////////// Capteur Analogique /////////////////////////
/// /////////////////////////////////////////////////////////////////////////

CapteurAnalogique::CapteurAnalogique(void):Capteur()
{
    volts = 2;
    vmin = 0;
    vmax = 5;
    range = 100;
    std::cout << "Constucteur pour la classe CapteurAnalogique de l'objet [" << this << "] "<< std::endl;
}

CapteurAnalogique::CapteurAnalogique(const int iid, double drange, double voltmin, double voltmax)
{
    volts = 2;
    id = iid;
    range = drange;
    vmin = voltmin;
    vmax = voltmax;
    std::cout << "Constucteur avec arguments pour la classe CapteurAnalogique de l'objet [" << this << "] "<< std::endl;
}

CapteurAnalogique::CapteurAnalogique(const CapteurAnalogique &p):volts{p.volts}, range{p.range}, vmin{p.vmin}, vmax{p.vmax}, Capteur(p.id)
{
    std::cout << "Constructeur du CapteurAnalogique par copie depuis [" << &p << "] vers le nouvel objet [" << this << "] " << std::endl;
}


CapteurAnalogique::~CapteurAnalogique(void)
{
    std::cout << "Destructeur du CapteurAnalogique [" << this << "] "<< std::endl;
}

void CapteurAnalogique::read(void)
{
    std::cout << "La valeur analogique mesure est "<<(volts * range)/(vmax-vmin) << " % "<< std::endl;
}

/// /////////////////////////////////////////////////////////////////////////
/// //////////////////////////// Capteur Digital ////////////////////////////
/// /////////////////////////////////////////////////////////////////////////

CapteurDigital::CapteurDigital(void):Capteur()
{
    bits = 200;
    bitsmax = 256;
    range = 100;
    std::cout << "Constucteur pour la classe CapteurDigital de l'objet [" << this << "] "<< std::endl;
}

CapteurDigital::CapteurDigital(const int iid, double const drange, int const bus)
{
    id = iid;
    bits = 200;
    bitsmax = bus;
    range = drange;
    std::cout << "Constucteur avec arguments pour la classe CapteurDigital de l'objet [" << this << "] "<< std::endl;
}

CapteurDigital::CapteurDigital(const CapteurDigital &p):bits{p.bits}, range{p.range}, bitsmax{p.bitsmax}, Capteur(p.id)
{
    std::cout << "Constructeur du CapteurDigital par copie depuis [" << &p << "] vers le nouvel objet [" << this << "] " << std::endl;
}

CapteurDigital::~CapteurDigital(void)
{
    std::cout << "Destructeur du CapteurDigital [" << this << "] "<< std::endl;
}

void CapteurDigital::read(void)
{
    std::cout << "La valeur digital mesure est "<<(bits * range) / bitsmax << " % "<< std::endl;
}

