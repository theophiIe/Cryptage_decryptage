#include <iostream>
#include "ArbreB.hh"

int main(int argc, char const *argv[])
{

    ArbreB<int> a;
    ArbreB<int> b;
    ArbreB<int> c;

    // Replissage arbre A
    a.ajoutG(105);
    a.ajoutG(20);
    a > 5;
    a.remonter_racine();
    a.ajoutD(8);
    a.remonter_racine();
    a.deplacementG();
    a.deplacementD(); 
    a.remonter();
    a < 16;

    // Remplissage arbre B
    b.ajoutG(185);
    b.ajoutG(25);
    b > 5;
    b.remonter_racine();
    b.ajoutD(868);
    b.remonter_racine();
    b.deplacementG();
    b.deplacementD();
    b.remonter();
    b.ajoutG(1669);

    std::cout<< "\n\t#### Parcours Préfixe A : ####"  << std::endl;
    a.parcours_prefixe();

    // std::cout<< "\n\t#### Parcours Infixe B : ####"  << std::endl;
    // b.parcours_infixe();
    
    // std::cout<< "\n\t#### Parcours Postfixe B : ####"  << std::endl;
    // b.parcours_postfixe();

    //test des différents parcours dans un arbre non vide

    std::cout<< "\n\t#### Parcours Préfixe B : ####"  << std::endl;
    b.parcours_prefixe();

    // std::cout<< "\n\t#### Parcours Infixe A : ####"  << std::endl;
    // a.parcours_infixe();
    
    // std::cout<< "\n\t#### Parcours Postfixe A : ####"  << std::endl;
    // a.parcours_postfixe();
    
    //c = a + b;
    b += &a;



    std::cout<< "\n\t#### Parcours Préfixe B Fusionné : ####"  << std::endl;
    b.parcours_prefixe();
    std::cout<< "ALED"  << std::endl;
    // c.parcours_infixe();
    
    // std::cout<< "\n\t#### Parcours Postfixe C : ####"  << std::endl;
    // c.parcours_postfixe();


    return 0;
}
