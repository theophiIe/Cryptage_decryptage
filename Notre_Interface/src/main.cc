#include <iostream>
#include <fstream>
#include "../header/test.hh"
#include <QtWidgets/QApplication>

#include "../header/fenetre.hh"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    std::ofstream monFlux("log.txt");
    monFlux.close();
    
    testParcoursArbre();
    testAjoutAuto();
    testSuppresionArbre();
    testCopieArbre();
    testFusionArbre();
    testEtiquette();
    testDecompositionArbre();
    testSuppressionFeuille();
    testSuppressionSommet();

    Fenetre fen;
    fen.show();

    return app.exec(); 
}
