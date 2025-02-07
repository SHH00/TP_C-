#include <iostream>
#include "Classe_infra.h"

using namespace std;

int main(void)
{
    Infrastructure CInfrastructure_0(2,4);
    std::vector<CapteurAnalogique> Ana_inf1 = {CapteurAnalogique(5, 40, 0, 10), CapteurAnalogique(5, 40, 0, 10)};
    std::vector<CapteurDigital> Dig_inf1 = {CapteurDigital(7,4000,2048), CapteurDigital(7,4000,2048), CapteurDigital(7,4000,2048), CapteurDigital(7,4000,2048)};
    Infrastructure CInfrastructure_1(Ana_inf1,Dig_inf1);
    CapteurAnalogique* Ana_inf2 = new CapteurAnalogique[2] {CapteurAnalogique(5,40,0,10), CapteurAnalogique(6,40,0,10)};
    CapteurDigital* Dig_inf2 = new CapteurDigital[4] {CapteurDigital(7,4000,2048), CapteurDigital(8,4000,2048), CapteurDigital(9,4000,2048), CapteurDigital(10,4000,2048)};
    Infrastructure CInfrastructure_2(Ana_inf2,Dig_inf2,2,4);
    CInfrastructure_0.print();
    CInfrastructure_1.print();
    CInfrastructure_2.print();
    CInfrastructure_0.moy();
    CInfrastructure_1.moy();
    CInfrastructure_2.moy();
    Infrastructure CInfrastructure_3(CInfrastructure_2);
    CInfrastructure_3.print();
    CInfrastructure_3.moy();
    delete[] Ana_inf2;
    delete[] Dig_inf2;

    return 0;
}

