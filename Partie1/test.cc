#include "test.hh"
#include "ArbreB.hh"

// déplacer les fonctions test dans un fichiers dédié

void testParcoursArbre() {
    std::cout<< "\n\t#### Test parcours d'arbre : ####"  << std::endl;
    ArbreB<int> a;
    a.ajoutG(8);
    a << 5;
    a >> 7;
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
    a << 8;
    a << 5;
    a.remonter_racine();
    a >> 7;
    
    std::cout<< "\nParcours Postfixe A :"  << std::endl;
    a.parcours_prefixe();

    ArbreB<int> b;
    b >> 6;
    b >> 4;
    b.remonter_racine();
    b << 9;
    b.remonter_racine();
    b.deplacementD();
    b << 7;

    std::cout<< "\nParcours Prefixe B :"  << std::endl;
    b.parcours_prefixe();

    a += b;

    std::cout<< "\nParcours Prefixe A :"  << std::endl;
    a.parcours_prefixe();
}

void testEtiquette() {
    std::cout<< "\n\t#### Test de la modification d'une étiquette et de sa présence : ####"  << std::endl;
    ArbreB<int> a;
    a << 8;
    a << 5;
    a.remonter_racine();
    a >> 7;

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
    ArbreB<int> a;
    a << 8;
    a << 5;
    a << 3;
    a << 9;
    a.remonter_racine();
    a >> 7;

    std::cout<< "\nParcours Prefixe A :"  << std::endl;
    a.parcours_prefixe();
    
    a.remonter_racine();
    //a.deplacementD();
    a.deplacementG();

    ArbreB<int> b;
    a.decomposition(b);

    std::cout<< "\nParcours Prefixe A :"  << std::endl;
    a.parcours_prefixe();

    std::cout<< "\nParcours Prefixe B :"  << std::endl;
    b.parcours_prefixe();
}

void testAjoutAuto() {
    std::cout<< "\n\t#### Test ajout automatiquement par rapport au poid de l'étiquette : ####"  << std::endl;
    ArbreB<int> a;
    a.ajoutAuto(5);
    a.ajoutAuto(9);
    a.ajoutAuto(3);
    a.ajoutAuto(2);
    a.ajoutAuto(4);
    a.ajoutAuto(15);
    a.ajoutAuto(7);

    std::cout<< "\nParcours Préfixe A :"  << std::endl;
    a.parcours_prefixe();

    std::cout<< "\nParcours Postfixe A :"  << std::endl;
    a.parcours_postfixe();

    std::cout<< "\nParcours Infixe A :"  << std::endl;
    a.parcours_infixe();
}

void testSuppressionFeuille() {
    std::cout<< "\n\t#### Test de la suppression d'une feuille dans l'arbre : ####"  << std::endl;
    ArbreB<int> a;
    a.ajoutAuto(5);
    a.ajoutAuto(3);
    a.ajoutAuto(15);
    a.ajoutAuto(7);

    std::cout<< "\nParcours Préfixe A :"  << std::endl;
    a.parcours_prefixe();

    a.remonter_racine();
    a.deplacementG();

    // on supprime la feuille : 3
    a.supprimer_feuille();
    std::cout<< "\nParcours Préfixe A :"  << std::endl;
    a.parcours_prefixe();

    a.remonter_racine();
    a.deplacementD();
    a.deplacementG();

    // on supprime la feuille : 7
    a.supprimer_feuille();
    std::cout<< "\nParcours Préfixe A :"  << std::endl;
    a.parcours_prefixe();

    a.remonter_racine();
    a.deplacementD();

    // on supprime la feuille : 15
    a.supprimer_feuille();
    std::cout<< "\nParcours Préfixe A :"  << std::endl;
    a.parcours_prefixe();

    a.remonter_racine();

    // on supprime la feuille : racine : 5
    a.supprimer_feuille();
    std::cout<< "\nParcours Préfixe A :"  << std::endl;
    a.parcours_prefixe();
}

void testSuppressionSommet() {
    // std::cout<< "\n\t#### Test de la suppression d'un Sommet dans l'arbre : ####"  << std::endl;
    // ArbreB<int> a;
    // a << 1;
    // a << 2;
    // a.remonter_racine();
    // a >> 3;

    // std::cout<< "\nParcours Préfixe A :" << std::endl;
    // a.parcours_prefixe();

    // a.remonter_racine();
    // a.deplacementG();
    // a.supprimer_sommet();

    // std::cout<< "\nParcours Préfixe A apres suppression n°1"  << std::endl;
    // a.parcours_prefixe();

    // a.remonter_racine();
    // a << 2;
    // a.remonter_racine();
    // a.deplacementD();
    // a >> 5;

    // std::cout<< "\nParcours Préfixe A apres suppression n°1"  << std::endl;
    // a.parcours_prefixe();

    // a.remonter_racine();
    // a.deplacementD();
    // a.supprimer_sommet();

    // std::cout<< "\nParcours Préfixe A apres suppression n°1"  << std::endl;
    // a.parcours_prefixe();

    ArbreB<int> b;
    b << 1;
    b << 2;
    b << 3;
    b.remonter_racine();
    b.deplacementG();
    b >> 4;
    b.remonter_racine();
    b >> 5;
    b >> 9;
    b >> 10;
    b.remonter_racine();
    b.deplacementD();
    b << 6;
    b << 7;
    b.remonter_racine();
    b.deplacementD();
    b.deplacementG();
    b >> 8;

    b.remonter_racine();
    b.deplacementD();

    std::cout<< "\nParcours Préfixe B :"  << std::endl;
    b.parcours_prefixe();

    b.supprimer_sommet();

    std::cout<< "\nParcours Préfixe B apres suppression n°1"  << std::endl;
    b.parcours_prefixe();
}