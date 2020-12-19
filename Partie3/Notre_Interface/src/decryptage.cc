#include "../header/decryptage.hh"

bool verif_syntaxique(std::string &texte) {
    for(std::string::size_type i = 0; i < texte.length(); i++) {
        if (texte[i] != '1' && texte[i] != '0') {
            return false;
        }
    }

    return true;
}