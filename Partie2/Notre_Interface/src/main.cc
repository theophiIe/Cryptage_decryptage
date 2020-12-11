#include <iostream>
#include <fstream>
#include "../header/test.hh"
#include <QtWidgets/QApplication>

#include "../header/fenetre.hh"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // On ouvre et on referme les fichiers textes afin de les créer  
    // s'il n'existe pas et de supprimer leurs contenus s'ils existes
    std::ofstream mesLog("log.txt");
    mesLog.close();

    std::ofstream monArbre("arbre.txt");
    monArbre.close();
    
    std::ofstream monArbreI("arbre_interface.txt");
    monArbreI.close();

    // Les tests du projet
    // testParcoursArbre();
    // testAjoutAuto();
    // testSuppresionArbre();
    // testCopieArbre();
    // testFusionArbre();
    // testEtiquette();
    // testDecompositionArbre();
    // testSuppressionSommet();
    // testCryptage();
    // testDessinArbre();
    // testCodage();

    // Affichage graphique de l'application
    Fenetre fen;
    fen.show();

    return app.exec(); 
}
