#include <iostream>
#include "Sommet.hh"
#include "ArbreB.hh"

int main(int argc, char const *argv[])
{
    Sommet<int> S1(10);
    ArbreB<int> a;

    a.ajoutG(10);
    std::cout << a.getSommet() << std::endl;

    a.ajoutG(20);
    std::cout << a.getSommet() << std::endl;

    a.remonter();
    std::cout << a.getSommet() << std::endl;

    // a.ajoutD(5);
    // std::cout << a.getSommet() << std::endl;

    // a.remonter_racine();
    // a.ajoutD(8);
    // std::cout << a.getSommet() << std::endl;

    // a.remonter_racine();
    // std::cout << a.getSommet() << std::endl;
    // a.deplacementG();
    // std::cout << a.getSommet() << std::endl;
    // a.deplacementD();
    // std::cout << a.getSommet() << std::endl;
    
    // a.remonter();
    // std::cout << a.getSommet() << std::endl;
    //a.ajoutG(16);
    //std::cout << a.getSommet() << std::endl;

    return 0;
}
