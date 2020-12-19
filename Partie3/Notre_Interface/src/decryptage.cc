#include "../header/decryptage.hh"

bool verif_syntaxique(std::string &texte) {
    for(std::string::size_type i = 0; i < texte.length(); i++) {
        if (texte[i] != '1' && texte[i] != '0') {
            return false;
        }
    }

    return true;
}

std::string decodage_texte(ArbreB<int> &arbre, std::string &code) {
    std::string decode = "";
    arbre.remonter_racine();

    for(std::string::size_type i = 0; i < code.length(); i++) {
        if (arbre.getLettre() == '\0') {
            code[i] == '0' ? arbre.deplacementG() : arbre.deplacementD();
            if (arbre.getLettre() != '\0') {
                decode.push_back(arbre.getLettre());
                arbre.remonter_racine();
            }
        }
    }

    return decode;
}