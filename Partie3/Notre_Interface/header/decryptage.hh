#if !defined(__DECRYPTAGE__)
#define __DECRYPTAGE__

#include <iostream>
#include <string>

#include "ArbreB.hh"

bool verif_syntaxique(std::string &texte);
std::string decodage_texte(ArbreB<int> &arbre, std::string &code);

#endif