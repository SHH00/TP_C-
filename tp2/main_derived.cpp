#include <iostream>
#include "Classe_derived.h"

using namespace std;

int main(void)
{
    CapteurAnalogique A_PT100;
    CapteurAnalogique A_TT100(1,80,0,5);
    CapteurAnalogique A_TT101(A_TT100);
    A_PT100.read();
    A_TT100.read();
    A_TT101.read();
    /// Oui ça entraine automatiquement l'appel d'un constructeur de classe, le contructeur par defaut pour les instanciation d'objet par argument mais lors d'une instanciation par copie cela appel le constructeur par argument de la classe mere. cela permet une initialisation correcte de l'objet, et permet aussi de respecter la hierarchie d'heritage.
    /// Les destructeur fonctionnent de la meme façon mais dans l'ordre inverse.

    CapteurDigital D_LT100;
    CapteurDigital D_AT100(1,100);
    CapteurDigital D_AT101(D_AT100);
    D_LT100.read();
    D_AT100.read();
    D_AT100.read();
    /// Un appel du constructeur de classe CapteurDigital entraine automatiquement l'appel d'un constructeur de classe Capteur mais cela n'entraine pas un appel du constructeur de CapteurAnalogique
    /// Les destructeurs fonctionnent de la meme façon.

    return 0;
}

