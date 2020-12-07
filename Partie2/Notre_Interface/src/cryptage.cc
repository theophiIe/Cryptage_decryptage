#include "../header/cryptage.hh"

std::map<char, int> calcul_occurence(std::string &mon_texte) {
    std::map<char, int> ma_map;
    char lettre;
    
    for(std::string::size_type i = 0; i < mon_texte.length(); i++) {
        lettre = mon_texte[i];

        if(ma_map.insert(std::make_pair(lettre, 1)).second == false) {
            ma_map[lettre] += 1;
        }
    }

    return ma_map;
}

ArbreB<int> *creation_racines(std::map<char, int> &map) {
    ArbreB<int> *tabArbre = new ArbreB<int>[map.size()];

    std::map<char, int>::iterator it = map.begin();

    for (int i = 0; i < map.size(); i++) {
        tabArbre[i].ajoutR(it->second, it->first);
        it++;
    }
    
    for (int i = 0; i < map.size(); i++) {
        std::cout << "Lettre : " << tabArbre[i].getLettre() << "Occurence : " << tabArbre[i].getEtiquette() << std::endl;
    }

    return tabArbre;
}

// A faire 
template<typename T>
void fusion_racines(ArbreB<T> *tabArbre) {

}

std::string codage_texte(std::string &texte, std::map<char, std::string> &map) {
    std::string code;

    for(std::string::size_type i = 0; i < texte.length(); i++) {
        auto code_lettre = map.find(texte[i]);
        code += code_lettre->second;
    }

    return code;
}