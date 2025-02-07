#ifndef __CLASS_INFRA
#define __CLASS_INFRA

#include "Classe_derived.h"


class Infrastructure {
private:
    std::vector<CapteurAnalogique> humidity;
    std::vector<CapteurDigital> temperature;
    int nombre_ca;
    int nombre_cd;
    struct moyenne
    {
        double humidite_moyenne;
        double temperature_moyenne;
    };
public:
    Infrastructure(void);
    Infrastructure(int Na, int Nc);
    Infrastructure(CapteurAnalogique * Vhum, CapteurDigital * Vtmp, int Nhum, int Ntmp);
    Infrastructure(std::vector<CapteurAnalogique> Vhum, std::vector<CapteurDigital> Vtmp);
    Infrastructure(Infrastructure const &p);
    ~Infrastructure(void);

    int nombre_capteurs(void);
    void print(void);
    void ajouter_valeur_digital(int N);
    void ajouter_valeur_analogique(int N);
    void moy(void);
};


#endif
