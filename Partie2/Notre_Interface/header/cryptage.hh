#if !defined(__CRYPTAGE__)
#define __CRYPTAGE__

#include <iostream>
#include <map>
#include <vector>
#include "ArbreB.hh"

std::map<char, int> calcul_occurence(std::string &mon_texte);

std::vector<ArbreB<int>> creation_racines(std::map<char, int> &map);

// void fusion_racines(ArbreB<int> *tabArbre);

void fusion_racines(std::vector<ArbreB<int>> &vec_arbre);

std::string codage_texte(std::string &texte, std::map<char, std::string> &map);

#endif