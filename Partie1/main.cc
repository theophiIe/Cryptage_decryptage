#include <iostream>
#include "ArbreB.hh"

int main(int argc, char const *argv[])
{

    ArbreB<int> a;
    ArbreB<int> b;

    a.ajoutG(105);
    std::cout << a.getSommet() << std::endl;

    a.ajoutG(20);
    std::cout << a.getSommet() << std::endl;

    //a.ajoutD(5);
    a > 5;
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
    //a.ajoutG(16);
    a < 16;
    std::cout << a.getSommet() << std::endl;

    b.ajoutG(105);
    b.ajoutG(20);
    b > 5;
    b.remonter_racine();
    b.ajoutD(8);
    b.remonter_racine();
    b.deplacementG();
    b.deplacementD();
    b.remonter();
    b.ajoutG(16);

    std::cout<< "\n\t#### Parcours Préfixe : ####"  << std::endl;
    b.parcours_prefixe();

    std::cout<< "\n\t#### Parcours Infixe : ####"  << std::endl;
    b.parcours_infixe();
    
    std::cout<< "\n\t#### Parcours Postfixe : ####"  << std::endl;
    b.parcours_postfixe();

    //test des différents parcours dans un arbre non vide

    std::cout<< "\n\t#### Parcours Préfixe : ####"  << std::endl;
    a.parcours_prefixe();

    std::cout<< "\n\t#### Parcours Infixe : ####"  << std::endl;
    a.parcours_infixe();
    
    std::cout<< "\n\t#### Parcours Postfixe : ####"  << std::endl;
    a.parcours_postfixe();
    
    a + b;

    a.tout_supprimer();
    a.estVide() ? std::cout << "est vide" << std::endl : std::cout << "n'est pas vide" << std::endl;

    // test des différents parcours dans un arbre vide (segfault a regler (probablement au cause du getRacine()))
    
    

    // std::cout<< "\n\t#### Parcours Préfixe : ####"  << std::endl;
    // b.parcours_prefixe();

    // std::cout<< "\n\t#### Parcours Préfixe : ####"  << std::endl;
    // b.parcours_infixe();

    // std::cout<< "\n\t#### Parcours Préfixe : ####"  << std::endl;
    // b.parcours_postfixe();

    return 0;
}
