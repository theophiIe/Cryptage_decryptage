#include <iostream>
#include "test.hh"
#include <fstream>

int main() {
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
    
    return 0;
}
