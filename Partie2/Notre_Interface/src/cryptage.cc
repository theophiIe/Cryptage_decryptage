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

std::vector<ArbreB<int>> creation_racines(std::map<char, int> &map) {
    std::vector<ArbreB<int>> vec_arbre;

    std::map<char, int>::iterator it = map.begin();

    for (int i = 0; i < map.size(); i++) {
        ArbreB<int> arbre;
        arbre.ajoutR(it->second, it->first);   
        vec_arbre.emplace_back(arbre);
        it++;
    }

    return vec_arbre;
}

ArbreB<int> la_plus_petite(std::vector<ArbreB<int>> &vec_arbre) {
    int j = 0;

    for (int i = 0; i < vec_arbre.size(); i++) {
        if (vec_arbre[i].getEtiquette() < vec_arbre[j].getEtiquette()) {
            j = i;           
        }
    }

    ArbreB<int> tmp;
    tmp = vec_arbre[j];
    vec_arbre.erase(vec_arbre.begin() + j);
    return tmp;
}

//Méthode avec le vecteur et pas le tab d'arbre
ArbreB<int> fusion_racines(std::vector<ArbreB<int>> &vec_arbre) {
    
    int j = 0, laplusp, ladeuxplusp;

    while (vec_arbre.size() != 1) {

        ArbreB<int> tmp1 = la_plus_petite(vec_arbre);
        ArbreB<int> tmp2 = la_plus_petite(vec_arbre);

        vec_arbre.insert(vec_arbre.begin(), tmp1 += tmp2);
    }

    return vec_arbre[0];
}

std::string codage_texte(std::string &texte, std::map<char, std::string> &map) {
    std::string code;

    for(std::string::size_type i = 0; i < texte.length(); i++) {
        auto code_lettre = map.find(texte[i]);
        code += code_lettre->second;
    }

    return code;
}