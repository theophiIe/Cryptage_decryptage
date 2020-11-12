#include <iostream>
#include "ArbreB.hh"

// déplacer les fonctions test dans un fichiers dédié

void testParcoursArbre() {
    std::cout<< "\n\t#### Test parcours d'arbre : ####"  << std::endl;
    ArbreB<int> a;
    a.ajoutG(8);
    a < 5;
    a > 7;
    a.remonter_racine();
    a.ajoutD(6);
    a.ajoutD(1);
    a.remonter_racine();
    a.deplacementG();
    a.ajoutG(4);

    std::cout<< "\nParcours Préfixe A :"  << std::endl;
    a.parcours_prefixe();

    std::cout<< "\nParcours Postfixe A :"  << std::endl;
    a.parcours_postfixe();

    std::cout<< "\nParcours Infixe A :"  << std::endl;
    a.parcours_infixe();
}

void testSuppresionArbre() {
    std::cout<< "\n\t#### Test de la suppresion d'un arbre : ####"  << std::endl;
    ArbreB<int> a;
    a.estVide() ? std::cout << "L'arbre est vide" << std::endl : std::cout << "L'arbre n'est pas vide" << std::endl;

    a.ajoutG(8);
    a.ajoutG(5);
    a.ajoutD(7);
    a.remonter_racine();
    a.ajoutD(6);
    a.ajoutD(1);

    std::cout<< "\nParcours Préfixe A :"  << std::endl;
    a.parcours_prefixe();

    a.estVide() ? std::cout << "L'arbre est vide" << std::endl : std::cout << "L'arbre n'est pas vide" << std::endl;

    a.tout_supprimer();
    a.estVide() ? std::cout << "L'arbre est vide" << std::endl : std::cout << "L'arbre n'est pas vide" << std::endl;
}

void testCopieArbre() {
    std::cout<< "\n\t#### Test de la copie d'arbre : ####"  << std::endl;
    ArbreB<int> a;
    a.ajoutG(8);
    a.ajoutG(5);
    a.ajoutD(7);
    a.remonter_racine();
    a.ajoutD(6);
    a.ajoutD(1);

    std::cout<< "\nParcours Infixe A :"  << std::endl;
    a.parcours_infixe();

    ArbreB<int> b;
    b = a;

    std::cout<< "\nParcours Infixe B :"  << std::endl;
    b.parcours_infixe();

    ArbreB<int> c(b);

    std::cout<< "\nParcours Infixe C :"  << std::endl;
    c.parcours_infixe();
}

void testFusionArbre() {
    std::cout<< "\n\t#### Test de la fusion d'arbre : ####"  << std::endl;
    ArbreB<int> a;
    a < 8;
    a < 5;
    a.remonter_racine();
    a > 7;
    
    std::cout<< "\nParcours Postfixe A :"  << std::endl;
    a.parcours_prefixe();

    ArbreB<int> b;
    b > 6;
    b > 4;
    b.remonter_racine();
    b < 9;
    b.remonter_racine();
    b.deplacementD();
    b < 7;

    std::cout<< "\nParcours Prefixe B :"  << std::endl;
    b.parcours_prefixe();

    a += b;

    std::cout<< "\nParcours Prefixe A :"  << std::endl;
    a.parcours_prefixe();
}

void testEtiquette() {
    std::cout<< "\n\t#### Test de la modification d'une étiquette et de sa présence : ####"  << std::endl;
    ArbreB<int> a;
    a < 8;
    a < 5;
    a.remonter_racine();
    a > 7;

    std::cout<< "\nParcours Prefixe A :"  << std::endl;
    a.parcours_prefixe();

    a.remonter_racine();
    a.deplacementD();
    a.setEtiquette(14);

    std::cout<< "\nParcours Prefixe A :"  << std::endl;
    a.parcours_prefixe();

    a.estPrensent(14) ? std::cout<< "14 est dans l'arbre" << std::endl : std::cout<< "14 n'est pas dans l'arbre" << std::endl;
    a.estPrensent(2) ? std::cout<< "2 est dans l'arbre" << std::endl : std::cout<< "2 n'est pas dans l'arbre" << std::endl;
    a.estPrensent(7) ? std::cout<< "7 est dans l'arbre" << std::endl : std::cout<< "7 n'est pas dans l'arbre" << std::endl;
}

void testDecompositionArbre() {
    std::cout<< "\n\t#### Test de la décomposition d'un arbre : ####"  << std::endl;
}

int main(int argc, char const *argv[]) {
    testParcoursArbre();
    testSuppresionArbre();
    testCopieArbre();
    testFusionArbre();
    testEtiquette();

    return 0;
}
