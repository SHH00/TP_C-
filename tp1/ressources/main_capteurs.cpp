#include <iostream>
#include "Classe_capteurs.h"

using namespace std;

int main(void)
{
    Capteur A;
    Capteur B(4, 10);
    Capteur C(B);
    Capteur& D = C;
    Capteur* E = new Capteur(10, 5); // Créatition de l'objet dynamyque E

    /// D-6 : Cela permet de suivre etape par etape la création des objets.
    /// D-7 : Il y a 4 appel de constructeur et 4 de destructeur, c'est normal car Capteur& D = C utilsie un alias, donc D est le meme objet que C il n'y a donc pas besoin de le construire ou de le detruire.
    ///       Concernant l'ordre des appels c'est normal on commence par crée le 1er puis le 2nd puis le3eme puis le 4eme et ensuite on detruit chaque couche en commançant par le dernier objet aoppelé
    /// D-8 : Actuellement les données membres de la classe sont statique, il serait interressant les passé en dinamique avec l'utilisation de new ex: tata = new double il faudrait alors faire un delete tata
    ///       dans le destructeur.
    std::cout << "La valeur de A est : " << A.get() << std::endl;
    std::cout << "La valeur de B est : " << B.get() << std::endl;
    std::cout << "La valeur de E est : " << E->get() << std::endl;
    C.set(14);
    E->set(232);
    std::cout << "La valeur de D est : " << D.get() << std::endl;
    /// La valeur de D est la meme que C voir question D-7
    std::cout << "La valeur de B est : " << B.get() << std::endl;
    /// La valeur de B n'est en aucun cas modifié si l'on modifie la valeur de C ce sont deux objet differents
    std::cout << "La valeur de l'ecart A et B est : " << A.ecart(B) << std::endl;
    std::cout << "La valeur de l'ecart C et D est : " << C.ecart(D) << std::endl;
    std::cout << "La valeur de l'ecart E et A est : " << E->ecart(A) << std::endl;
    std::cout << "La valeur de l'ecart E et D est : " << E->ecart(D) << std::endl;
    std::cout << "La valeur de l'ecart D et C est : " << D.ecart(C) << std::endl;
    delete E ;/// Liberation de la memoire à l'adresse de E
    /// Les resultats obtenus sont corrects
    /// Depuis l'objet E pour appeler la methode nous utilisons "->" au lieu de "."
    /// Depuis l'objet D il n'est pas necessaire de changer la syntaxe normale
    /// Si l'on change la syntaxe de la methode ecart en retirant le & cela entraine la copie de l'objet dont on veux faire l'ecart avant l'execution de la methode, ce qui crée une utilisation non optimisé des ressources.
    Capteur tab1;
    Capteur tab2;
    Capteur tab3;
    static Capteur F[3] = {tab1, tab2, tab3};
    /// L'utilisation de tbleau static entraine l'utilisation du constructeur par copie des 3 objets utilisé precedement et donc la destruction de ces 3 objets en fin de programme.
    /// Ici aussi cela entraine un mauvaise optimisation des ressources
    Capteur* G = new Capteur[3] {tab1, tab2, tab3};
    std::cout << "Adresse de F[0] : " << &F[0] << std::endl; // Affichage de l'adresse de la premiere valeur de F
    for (int i = 0; i < 3; i++)
    {
        std::cout << "Adresse de G[" << i << "] : " << &G[i] << std::endl; // Affichage des adresse de G
    }
    delete[] G;
    /// L'utilisation de tableau dynamique entraine l'utilisation du constructeur par copie des 3 objets utilisé precedement et donc la destruction de ces 3 objets en fin de programme.
    /// Ici aussi cela entraine un mauvaise optimisation des ressources
    Capteur* H = new Capteur[3] {tab1, tab2, tab3};
    std::cout << "Adresse de H[0] : " << &H[0] << std::endl; // Affichage de l'adresse de la premiere valeur de H
    delete[] H;

    std::vector<Capteur> vecteur = { Capteur(1, 2), Capteur(3, 4), Capteur(5, 6) };


}

