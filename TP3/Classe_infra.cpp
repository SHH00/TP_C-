#include "Classe_infra.h"

/// /////////////////////////////////////
/// ///CONSTRUCTEUR / DESTRUCTEUR////////
/// /////////////////////////////////////

Infrastructure::Infrastructure(void)
{
    nombre_ca = 0;
    nombre_cd = 0;
    humidity = std::vector<CapteurAnalogique>(nombre_ca, CapteurAnalogique());
    temperature = std::vector<CapteurDigital>(nombre_cd, CapteurDigital());
    std::cout << "Constructeur de Infrastucture de l'objet [" << this << "] "<< std::endl;
}

Infrastructure::Infrastructure(int Na, int Nc)
{
    nombre_ca = Na;
    nombre_cd = Nc;
    humidity = std::vector<CapteurAnalogique>(Na, CapteurAnalogique());
    temperature = std::vector<CapteurDigital>(Nc, CapteurDigital());
    std::cout << "Constructeur surcharge numero 1 de Infrastucture de l'objet [" << this << "] "<< std::endl;
}

Infrastructure::Infrastructure(CapteurAnalogique * Vhum, CapteurDigital * Vtmp, int Nhum, int Ntmp)
{
    humidity = std::vector<CapteurAnalogique>(Vhum, Vhum + Nhum);
    temperature = std::vector<CapteurDigital>(Vtmp, Vtmp + Ntmp);
    nombre_ca = humidity.size();
    nombre_cd = temperature.size();
    std::cout << "Constructeur surcharge numero 2 de Infrastucture de l'objet [" << this << "] "<< std::endl;
}

Infrastructure::Infrastructure(std::vector<CapteurAnalogique> Vhum, std::vector<CapteurDigital> Vtmp)
{
    humidity = Vhum;
    temperature = Vtmp;
    nombre_ca = humidity.size();
    nombre_cd = temperature.size();
    std::cout << "Constructeur surcharge numero 3 de Infrastucture de l'objet [" << this << "] "<< std::endl;
}

Infrastructure::Infrastructure(Infrastructure const &p):nombre_ca{p.nombre_ca},nombre_cd{p.nombre_cd},humidity{p.humidity},temperature{p.temperature}
{
    std::cout << "Constructeur par copie de Infrastucture de l'objet [" << this << "] "<< std::endl;
}

Infrastructure::~Infrastructure(void)
{
    std::cout<<"Destructeur de l'Infrastructure [" << this << "] "<< std::endl;
}

/// /////////////////////////////////////
/// ///////////////METHODES//////////////
/// /////////////////////////////////////

int Infrastructure::nombre_capteurs(void)
{
    return nombre_ca + nombre_cd;
}

void Infrastructure::print(void)
{
    /*
    for (int i = 0; i < nombre_ca; i++)
    {
        std::cout << "La valeur du " << (i+1) << " Capteur d'humidite est : " << humidity[i].value << std::endl;
    }
    for (int i = 0; i < nombre_cd; i++)
    {
        std::cout << "La valeur du " << (i+1) << " Capteur de temperature est : " << temperature[i].value << std::endl;
    }
    */
    for(auto& elem:humidity)
    {
        std::cout << "La valeur du  Capteur d'humidite est : " << elem.value << std::endl;
    }

    for(auto& elem:temperature)
    {
        std::cout << "La valeur du  Capteur de temperature est : " << elem.value << std::endl;
    }
}

void Infrastructure::ajouter_valeur_digital(int N)
{
    temperature.resize(temperature.size() + N);
}

void Infrastructure::ajouter_valeur_analogique(int N)
{
    humidity.resize(humidity.size() + N);
}

void Infrastructure::moy(void)
{
    double total_hum = 0;
    double total_temp = 0;
    /*
    for (int i = 0; i < nombre_ca; i++)
    {
        total_hum += humidity[i].value;
    }
    for (int i = 0; i < nombre_cd; i++)
    {
        total_temp += temperature[i].value;
    }
    */
    for(auto& elem:humidity)
    {
        total_hum += elem.value;
    }
    for(auto& elem:temperature)
    {
        total_temp += elem.value;
    }

    std::cout<<"La valeur moyenne de l'humidite est : " <<total_hum / nombre_ca << std::endl;
    std::cout<<"La valeur moyenne de la temperature est : " <<total_temp / nombre_cd << std::endl;
}

