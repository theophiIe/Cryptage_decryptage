#include "../header/decryptage.hh"

/* Permet de vérifier que le texte passé en parametre est composé uniquement de 0 et de 1 */
bool verif_syntaxique(std::string &texte) {
    for(std::string::size_type i = 0; i < texte.length(); i++) {
        if (texte[i] != '1' && texte[i] != '0') {
            return false;
        }
    }

    return texte.empty() ? false : true;
}

/* Permet de décoder le texte passé en parametre à l'aide de l'arbre passé en parametre */
std::string decodage_texte(ArbreB<int> &arbre, std::string &code) {
    if (arbre.estVide()){
        return "Il n'y a pas d'arbre de creer merci de crypter un texte avant de le decrypter";
    }

    std::string decode = "";
    arbre.remonter_racine();

    for(std::string::size_type i = 0; i < code.length(); i++) {
        if (arbre.getLettre() == '\0') {
            code[i] == '0' ? arbre.deplacementG() : arbre.deplacementD();
            if (arbre.getLettre() != '\0') {
                decode.push_back(arbre.getLettre());
                if (i != code.length() - 1) {
                    arbre.remonter_racine();
                }
            }
        }
    }

    return arbre.getLettre() != '\0' ? decode : "Erreur le code est incorrect";
}