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

// // A faire 
// void fusion_racines(ArbreB<int> *tabArbre) {
//     int j = 4;
//     std::cout << "Size of tabArbre : " << sizeof(tabArbre) <<std::endl; // probablment mal transféré, ici tabArbre = 8 au lieu de 6

//     // for (int i = 0; i < sizeof(tabArbre); i++) {
//     //         std::cout << "Occurence mialelv,qn : " << tabArbre[j].getEtiquette() << std::endl;

//     //     if ( tabArbre[i].getEtiquette() < tabArbre[j].getEtiquette()) {
//     //             std::cout << "Occurence mi: " << tabArbre[j].getEtiquette() << std::endl;

//     //         j=i;
//     //     }
//     //         std::cout << "Occurecap,l: " << tabArbre[j].getEtiquette() << std::endl;

    
//     // }
//     // std::cout << "Occurence min : " << tabArbre[j].getEtiquette() << std::endl; // problème sur let abArbre[j]
// }


// Méthode avec le vecteur et pas le tab d'arbre
void fusion_racines(std::vector<ArbreB<int>> &vec_arbre) {
    std::cout<<"Encryptage !\n";
    std::cout<<"Vector size : ";
    std::cout<< vec_arbre.size()<<std::endl;
    std::cout<< vec_arbre[4].getEtiquette() <<std::endl;
}

std::string codage_texte(std::string &texte, std::map<char, std::string> &map) {
    std::string code;

    for(std::string::size_type i = 0; i < texte.length(); i++) {
        auto code_lettre = map.find(texte[i]);
        code += code_lettre->second;
    }

    return code;
}