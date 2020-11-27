#if !defined(__CRYPTAGE__)
#define __CRYPTAGE__

#include <iostream>
#include <map>
#include "ArbreB.hh"

std::map<char, int> calcul_occurence(std::string &mon_texte);

void creation_racines(std::map<char, int> &map);

#endif