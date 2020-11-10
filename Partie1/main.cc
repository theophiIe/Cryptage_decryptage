#include <iostream>
#include "Sommet.hh"
#include "ArbreB.hh"

int main(int argc, char const *argv[])
{
    Sommet<int> S1(10);
    ArbreB<int> a;
    ArbreB<int> b;

    a.ajoutG(10);
    std::cout << a.getSommet() << std::endl;

    a.ajoutG(20);
    std::cout << a.getSommet() << std::endl;

    a.ajoutD(5);
    std::cout << a.getSommet() << std::endl;

    a.remonter_racine();
    a.ajoutD(8);
    std::cout << a.getSommet() << std::endl;

    a.remonter_racine();
    std::cout << a.getSommet() << std::endl;
    a.deplacementG();
    std::cout << a.getSommet() << std::endl;
    a.deplacementD();
    std::cout << a.getSommet() << std::endl;
    
    a.remonter();
    std::cout << a.getSommet() << std::endl;
    a.ajoutG(16);
    std::cout << a.getSommet() << std::endl;

    //test des différents parcours dans un arbre non vide

    std::cout<< "\n\t#### Parcours Préfixe : ####"  << std::endl;
    a.parcours_prefixe(a.getRacine());

    std::cout<< "\n\t#### Parcours Infixe : ####"  << std::endl;
    a.parcours_infixe(a.getRacine());
    
    std::cout<< "\n\t#### Parcours Postfixe : ####"  << std::endl;
    a.parcours_postfixe(a.getRacine());
    


    // test des différents parcours dans un arbre vide (segfault a regler (probablement au cause du getRacine()))

    std::cout<< "\n\t#### Parcours Préfixe : ####"  << std::endl;
    b.parcours_prefixe(b.getRacine());

    std::cout<< "\n\t#### Parcours Préfixe : ####"  << std::endl;
    b.parcours_infixe(b.getRacine());

    std::cout<< "\n\t#### Parcours Préfixe : ####"  << std::endl;
    b.parcours_postfixe(b.getRacine());

    return 0;
}
