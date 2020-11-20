#include <iostream>
#include <fstream>
#include "../header/test.hh"
#include <QtWidgets/QApplication>

#include "../header/fenetre.hh"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    std::ofstream mesLog("log.txt");
    mesLog.close();

    std::ofstream monArbre("arbre.txt");
    monArbre.close();
    
    std::ofstream monArbreI("arbre_interface.txt");
    monArbreI.close();

    testParcoursArbre();
    testAjoutAuto();
    testSuppresionArbre();
    testCopieArbre();
    testFusionArbre();
    testEtiquette();
    testDecompositionArbre();
    testSuppressionFeuille();
    testSuppressionSommet();
    testDessinArbre();

    Fenetre fen;
    fen.show();

    return app.exec(); 
}
