#ifndef __CLASS_SPEC
#define __CLASS_SPEC

#include "Classe_capteurs.h"

class CapteurDigital : public Capteur {
    int bits;
    int bitsmax;
    double range;

public:
    CapteurDigital(void);
    CapteurDigital(const int iid, double const drange, int const bus = 1024 );
    CapteurDigital(const CapteurDigital &p);
    ~CapteurDigital(void);

    void read(void);
};


class CapteurAnalogique : public Capteur {
    double volts;
    double vmin;
    double vmax;
    double range;

public:
    CapteurAnalogique(void);
    CapteurAnalogique(const int iid, double const drange, double const voltmin=-5, double const voltmax=5);
    CapteurAnalogique(const CapteurAnalogique &p);
    ~CapteurAnalogique(void);

    void read(void);
};


#endif
