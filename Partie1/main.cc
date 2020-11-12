#include <iostream>
#include "ArbreB.hh"

int main(int argc, char const *argv[]) {
    ArbreB<int> a;
    ArbreB<int> b;
    ArbreB<int> c;

    // Replissage arbre A
    // a.ajoutG(105);
    // a.ajoutG(20);
    // a > 5;
    // a.remonter_racine();
    // a.ajoutD(8);
    // a.remonter_racine();
    // a.deplacementG();
    // a.deplacementD(); 
    // a.remonter();
    // a < 16;
    a.ajoutG(5);
    a.ajoutG(10);
    a.setEtiquette(8);
    a.remonter_racine();
    a.ajoutD(2);

    // Remplissage arbre B
    // b.ajoutG(185);
    // b.ajoutG(25);
    // b > 5;
    // b.remonter_racine();
    // b.ajoutD(868);
    // b.remonter_racine();
    // b.deplacementG();
    // b.deplacementD();
    // b.remonter();
    // b.ajoutG(1669);
    b.ajoutG(4);
    b.ajoutG(6);
    b.remonter_racine();
    b.ajoutD(7);

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
    a += b;

    std::cout<< "\n\t#### Parcours Préfixe A Fusionné : ####"  << std::endl;
    a.parcours_prefixe();
    
    a = b;
    std::cout<< "\n\t#### Parcours Préfixe A = B : ####"  << std::endl;
    a.parcours_prefixe();

    a.estPrensent(7) ? std::cout<< "TRUE" << std::endl : std::cout<< "FALSE"  << std::endl;
    a.estPrensent(8) ? std::cout<< "TRUE" << std::endl : std::cout<< "FALSE"  << std::endl;

    // ArbreB<int> d(a);
    // std::cout<< "\n\t#### Parcours Préfixe D = A : ####"  << std::endl;
    // d.parcours_prefixe();

    std::cout<< "ALED"  << std::endl;
    // c.parcours_infixe();
    
    // std::cout<< "\n\t#### Parcours Postfixe C : ####"  << std::endl;
    // c.parcours_postfixe();


    return 0;
}
