#include "test.hh"
#include "ArbreB.hh"

// déplacer les fonctions test dans un fichiers dédié

void testParcoursArbre() {
    std::cout<< "\n\t#### Test parcours d'arbre : ####"  << std::endl;
    ArbreB<int>::ecrire_log("\n\t#### Test parcours d'arbre : ####");

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
    ArbreB<int>::ecrire_log("\nParcours Préfixe A :");
    a.parcours_prefixe();

    std::cout<< "\nParcours Postfixe A :"  << std::endl;
    ArbreB<int>::ecrire_log("\nParcours Préfixe A :");
    a.parcours_postfixe();

    std::cout<< "\nParcours Infixe A :"  << std::endl;
    ArbreB<int>::ecrire_log("\nParcours Préfixe A :");
    a.parcours_infixe();
}

void testSuppresionArbre() {
    std::cout<< "\n\t#### Test de la suppresion d'un arbre : ####"  << std::endl;
    ArbreB<int>::ecrire_log("\n\t#### Test de la suppresion d'un arbre : ####");
    
    ArbreB<int> a;
    a.estVide() ? std::cout << "L'arbre est vide" << std::endl : std::cout << "L'arbre n'est pas vide" << std::endl;
    a.estVide() ? ArbreB<int>::ecrire_log("L'arbre est vide") : ArbreB<int>::ecrire_log("L'arbre n'est pas vide");

    a.ajoutG(8);
    a.ajoutG(5);
    a.ajoutD(7);
    a.remonter_racine();
    a.ajoutD(6);
    a.ajoutD(1);

    std::cout<< "\nParcours Préfixe A :"  << std::endl;
    ArbreB<int>::ecrire_log("\nParcours Préfixe A :");
    a.parcours_prefixe();

    a.estVide() ? std::cout << "L'arbre est vide" << std::endl : std::cout << "L'arbre n'est pas vide" << std::endl;
    a.estVide() ? ArbreB<int>::ecrire_log("L'arbre est vide") : ArbreB<int>::ecrire_log("L'arbre n'est pas vide");

    a.tout_supprimer();
    a.estVide() ? std::cout << "L'arbre est vide" << std::endl : std::cout << "L'arbre n'est pas vide" << std::endl;
    a.estVide() ? ArbreB<int>::ecrire_log("L'arbre est vide") : ArbreB<int>::ecrire_log("L'arbre n'est pas vide");
}

void testCopieArbre() {
    std::cout<< "\n\t#### Test de la copie d'arbre : ####"  << std::endl;
    ArbreB<int>::ecrire_log("\n\t#### Test de la copie d'arbre : ####");

    ArbreB<int> a;
    a.ajoutG(8);
    a.ajoutG(5);
    a.ajoutD(7);
    a.remonter_racine();
    a.ajoutD(6);
    a.ajoutD(1);

    std::cout<< "\nParcours Infixe A :"  << std::endl;
    ArbreB<int>::ecrire_log("\nParcours Infixe A :");
    a.parcours_infixe();

    ArbreB<int> b;
    b = a;

    std::cout<< "\nParcours Infixe B :"  << std::endl;
    ArbreB<int>::ecrire_log("\nParcours Infixe B :");
    b.parcours_infixe();

    ArbreB<int> c(b);

    std::cout<< "\nParcours Infixe C :"  << std::endl;
    ArbreB<int>::ecrire_log("\nParcours Infixe C :");
    c.parcours_infixe();
}

void testFusionArbre() {
    std::cout<< "\n\t#### Test de la fusion d'arbre : ####"  << std::endl;
    ArbreB<int>::ecrire_log("\n\t#### Test de la fusion d'arbre : ####");

    ArbreB<int> a;
    a << 8;
    a << 5;
    a.remonter_racine();
    a >> 7;
    
    std::cout<< "\nParcours Postfixe A :"  << std::endl;
    ArbreB<int>::ecrire_log("\nParcours Postfixe A :");

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
    ArbreB<int>::ecrire_log("\nParcours Prefixe B :");
    b.parcours_prefixe();

    a += b;

    std::cout<< "\nParcours Prefixe A :"  << std::endl;
    ArbreB<int>::ecrire_log("\nParcours Prefixe A :");
    a.parcours_prefixe();
}

void testEtiquette() {
    std::cout<< "\n\t#### Test de la modification d'une étiquette et de sa présence : ####"  << std::endl;
    ArbreB<int>::ecrire_log("\n\t#### Test de la modification d'une étiquette et de sa présence : ####");

    ArbreB<int> a;
    a << 8;
    a << 5;
    a.remonter_racine();
    a >> 7;

    std::cout<< "\nParcours Prefixe A :"  << std::endl;
    ArbreB<int>::ecrire_log("\nParcours Prefixe A :");
    a.parcours_prefixe();

    a.remonter_racine();
    a.deplacementD();
    a.setEtiquette(14);

    std::cout<< "\nParcours Prefixe A :"  << std::endl;
    ArbreB<int>::ecrire_log("\nParcours Prefixe A :");
    a.parcours_prefixe();

    a.estPrensent(14) ? std::cout<< "14 est dans l'arbre" << std::endl : std::cout<< "14 n'est pas dans l'arbre" << std::endl;
    a.estPrensent(2) ? std::cout<< "2 est dans l'arbre" << std::endl : std::cout<< "2 n'est pas dans l'arbre" << std::endl;
    a.estPrensent(7) ? std::cout<< "7 est dans l'arbre" << std::endl : std::cout<< "7 n'est pas dans l'arbre" << std::endl;

    a.estPrensent(14) ? ArbreB<int>::ecrire_log("14 est dans l'arbre") : ArbreB<int>::ecrire_log("14 n'est pas dans l'arbre");
    a.estPrensent(2) ? ArbreB<int>::ecrire_log("2 est dans l'arbre") : ArbreB<int>::ecrire_log("2 n'est pas dans l'arbre");
    a.estPrensent(7) ? ArbreB<int>::ecrire_log("7 est dans l'arbre") : ArbreB<int>::ecrire_log("7 n'est pas dans l'arbre");
}

void testDecompositionArbre() {
    std::cout<< "\n\t#### Test de la décomposition d'un arbre : ####"  << std::endl;
    ArbreB<int>::ecrire_log("\n\t#### Test de la décomposition d'un arbre : ####");

    ArbreB<int> a;
    a << 8;
    a << 5;
    a << 3;
    a << 9;
    a.remonter_racine();
    a >> 7;

    std::cout<< "\nParcours Prefixe A :"  << std::endl;
    ArbreB<int>::ecrire_log("\nParcours Prefixe A :");
    a.parcours_prefixe();
    
    a.remonter_racine();
    a.deplacementG();

    ArbreB<int> b;
    a.decomposition(b);

    std::cout<< "\nParcours Prefixe A :"  << std::endl;
    ArbreB<int>::ecrire_log("\nParcours Prefixe A :");
    a.parcours_prefixe();

    std::cout<< "\nParcours Prefixe B :"  << std::endl;
    ArbreB<int>::ecrire_log("\nParcours Prefixe B :");
    b.parcours_prefixe();
}

void testAjoutAuto() {
    std::cout<< "\n\t#### Test ajout automatiquement par rapport au poid de l'étiquette : ####"  << std::endl;
    ArbreB<int>::ecrire_log("\n\t#### Test ajout automatiquement par rapport au poid de l'étiquette : ####");

    ArbreB<int> a;
    a.ajoutAuto(5);
    a.ajoutAuto(9);
    a.ajoutAuto(3);
    a.ajoutAuto(2);
    a.ajoutAuto(4);
    a.ajoutAuto(15);
    a.ajoutAuto(7);

    std::cout<< "\nParcours Préfixe A :"  << std::endl;
    ArbreB<int>::ecrire_log("\nParcours Préfixe A :");
    a.parcours_prefixe();

    std::cout<< "\nParcours Postfixe A :"  << std::endl;
    ArbreB<int>::ecrire_log("\nParcours Postfixe A :");
    a.parcours_postfixe();

    std::cout<< "\nParcours Infixe A :"  << std::endl;
    ArbreB<int>::ecrire_log("\nParcours Infixe A :");
    a.parcours_infixe();
}

void testSuppressionFeuille() {
    std::cout<< "\n\t#### Test de la suppression d'une feuille dans l'arbre : ####"  << std::endl;
    ArbreB<int>::ecrire_log("\n\t#### Test de la suppression d'une feuille dans l'arbre : ####");

    ArbreB<int> a;
    a.ajoutAuto(5);
    a.ajoutAuto(3);
    a.ajoutAuto(15);
    a.ajoutAuto(7);

    std::cout<< "\nParcours Préfixe A :"  << std::endl;
    ArbreB<int>::ecrire_log("\nParcours Préfixe A :");
    a.parcours_prefixe();

    a.remonter_racine();
    a.deplacementG();

    // on supprime la feuille : 3
    a.supprimer_feuille();
    std::cout<< "\nParcours Préfixe A :"  << std::endl;
    ArbreB<int>::ecrire_log("\nParcours Préfixe A :");
    a.parcours_prefixe();

    a.remonter_racine();
    a.deplacementD();
    a.deplacementG();

    // on supprime la feuille : 7
    a.supprimer_feuille();
    std::cout<< "\nParcours Préfixe A :"  << std::endl;
    ArbreB<int>::ecrire_log("\nParcours Préfixe A :");
    a.parcours_prefixe();

    a.remonter_racine();
    a.deplacementD();

    // on supprime la feuille : 15
    a.supprimer_feuille();
    std::cout<< "\nParcours Préfixe A :"  << std::endl;
    ArbreB<int>::ecrire_log("\nParcours Préfixe A :");
    a.parcours_prefixe();

    a.remonter_racine();

    // on supprime la feuille : racine : 5
    a.supprimer_feuille();
    std::cout<< "\nParcours Préfixe A :"  << std::endl;
    ArbreB<int>::ecrire_log("\nParcours Préfixe A :");
    a.parcours_prefixe();
}

void testSuppressionSommet() {
    std::cout<< "\n\t#### Test de la suppression d'un Sommet dans l'arbre : ####"  << std::endl;
    ArbreB<int>::ecrire_log("\n\t#### Test de la suppression d'un Sommet dans l'arbre : ####");

    ArbreB<int> c;
    c << 1 << 2<< 4;
    c.remonter_racine();
    c >> 3 >> 6;
    c.remonter_racine();
    c.deplacementG();
    c >> 5 >> 8;
    c.remonter_racine();
    c.deplacementG();
    c.deplacementD();
    c << 7;

    std::cout<< "\nParcours Préfixe C : "  << std::endl;
    ArbreB<int>::ecrire_log("\nParcours Préfixe C : ");
    c.parcours_prefixe();

    c.remonter_racine();
    c.deplacementG();
    c.supprimer_sommet();

    std::cout<< "\nParcours Préfixe C apres suppression de 2 : "  << std::endl;
    ArbreB<int>::ecrire_log("\nParcours Préfixe C apres suppression de 2 : ");
    c.parcours_prefixe();

    c.remonter_racine();
    c.deplacementD();
    c.supprimer_sommet();

    std::cout<< "\nParcours Préfixe C apres suppression de 3 : "  << std::endl;
    ArbreB<int>::ecrire_log("\nParcours Préfixe C apres suppression de 3 : ");
    c.parcours_prefixe();

    c.remonter_racine();
    c.supprimer_sommet();

    std::cout<< "\nParcours Préfixe C apres suppression de 1 : "  << std::endl;
    ArbreB<int>::ecrire_log("\nParcours Préfixe C apres suppression de 1 : ");
    c.parcours_prefixe();

    c.remonter_racine();
    c.deplacementD();
    c.deplacementD();
    c.deplacementD();
    c << 80;

    std::cout<< "\nParcours Préfixe C apres ajout de 80 : "  << std::endl;
    ArbreB<int>::ecrire_log("\nParcours Préfixe C apres ajout de 80 : ");
    c.parcours_prefixe();

    c.remonter_racine();
    c.deplacementD();
    c.deplacementD();
    c.deplacementD();
    c.supprimer_sommet();

    std::cout<< "\nParcours Préfixe C apres suppression de 6 : "  << std::endl;
    ArbreB<int>::ecrire_log("\nParcours Préfixe C apres suppression de 6 : ");
    c.parcours_prefixe();

    c.remonter_racine();
    c.supprimer_sommet();

    std::cout<< "\nParcours Préfixe C apres suppression de 4 : "  << std::endl;
    ArbreB<int>::ecrire_log("\nParcours Préfixe C apres suppression de 4 : ");
    c.parcours_prefixe();

    c.remonter_racine();
    c.deplacementD();
    c.deplacementD();
    c.supprimer_sommet();

    std::cout<< "\nParcours Préfixe C apres suppression de 80 : "  << std::endl;
    ArbreB<int>::ecrire_log("\nParcours Préfixe C apres suppression de 80 : ");
    c.parcours_prefixe();
    
    c.remonter_racine();
    c.deplacementD();
    c.supprimer_sommet();

    std::cout<< "\nParcours Préfixe C apres suppression de 8 : "  << std::endl;
    ArbreB<int>::ecrire_log("\nParcours Préfixe C apres suppression de 8 : ");
    c.parcours_prefixe();

    c.remonter_racine();
    c.deplacementG();
    c.supprimer_sommet();

    std::cout<< "\nParcours Préfixe C apres suppression de 7 : "  << std::endl;
    ArbreB<int>::ecrire_log("\nParcours Préfixe C apres suppression de 7 : ");
    c.parcours_prefixe();


    // Modifer pour supprimer la racine dernier seul sommet du l'arbre
    c.remonter_racine();
    c.supprimer_sommet();

    std::cout<< "\nParcours Préfixe C apres suppression de 5 : "  << std::endl;
    ArbreB<int>::ecrire_log("\nParcours Préfixe C apres suppression de 5 : ");
    c.parcours_prefixe();
}