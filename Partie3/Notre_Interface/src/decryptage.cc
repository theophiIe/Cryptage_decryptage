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

    for(std::string::size_type i = 0; i < code.length() + 1; i++) {
        if (code[i] == '0') {
            if (arbre.getLettre() == '\0') {
                arbre.deplacementG();
                std::cout << "deplacement G" << std::endl;
            }

            else {
                decode.push_back(arbre.getLettre());
                std::cout << "Ajout de la lettre : " << arbre.getLettre() << std::endl;
                arbre.remonter_racine();
                std::cout << "Remonte" << std::endl;
                i -= 1;
            }
        }

        else {
            if (arbre.getLettre() == '\0') {
                arbre.deplacementD();
                std::cout << "deplacement D" << std::endl;
            }

            else {
                decode.push_back(arbre.getLettre());
                std::cout << "Ajout de la lettre : " << arbre.getLettre() << std::endl;
                arbre.remonter_racine();
                std::cout << "Remonte" << std::endl;
                i -= 1;
            }
        }
    }

    return decode;
}