#if !defined(__CRYPTAGE__)
#define __CRYPTAGE__

#include <iostream>
#include <map>
#include "ArbreB.hh"

std::map<char, int> calcul_occurence(std::string &mon_texte);

ArbreB<int> *creation_racines(std::map<char, int> &map);

template<typename T>
void fusion_racines(ArbreB<T> *tabArbre);

std::string codage_texte(std::string &texte, std::map<char, std::string> &map);

#endif