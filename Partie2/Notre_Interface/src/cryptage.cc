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

// Méthode avec le vecteur et pas le tab d'arbre
void fusion_racines(std::vector<ArbreB<int>> &vec_arbre) {
    int j = 0, plus_petite = 0;
    std::cout<<"Vector size : "<< vec_arbre.size()<<std::endl;

    for (int i = 0; i < vec_arbre.size(); i++) {
        if (vec_arbre[i].getEtiquette() < vec_arbre[j].getEtiquette()) {
            std::cout<<"Plus petit ! "<< vec_arbre[i].getEtiquette() << vec_arbre[j].getEtiquette()<<std::endl;
            j = i;           
        }
        std::cout<< vec_arbre[i].getLettre() <<std::endl;        
    }

    plus_petite = j;
    j = 0;

    for (int i = 0; i < vec_arbre.size(); i++) {
        if (vec_arbre[i].getEtiquette() <= vec_arbre[j].getEtiquette() && (i != plus_petite)) {
            std::cout<<"Plus petit ! "<< vec_arbre[i].getEtiquette() << vec_arbre[j].getEtiquette()<<std::endl;
            j = i;  
        }
        std::cout<< vec_arbre[i].getLettre() << " occu " << vec_arbre[i].getEtiquette() <<std::endl; 
    }
    
    std::cout<< "les deux valeurs les plus petites sont sur les lettres : " << vec_arbre[plus_petite].getLettre() << " " << vec_arbre[j].getLettre() <<std::endl;
    // j est le plus petit.
    // On cherche donc le dexieme plus petit qui pourra etre = a j au superieur
    // imma

    vec_arbre[plus_petite] += vec_arbre[j];
    vec_arbre.erase(vec_arbre.begin() + j);
    std::cout<<"New size of vector : "<<vec_arbre.size()<<std::endl;

    for (int i = 0; i < vec_arbre.size(); i++) {
        // if (vec_arbre[i].getEtiquette() < vec_arbre[j].getEtiquette()) {
        //     std::cout<<"Plus petit ! "<< vec_arbre[i].getEtiquette() << vec_arbre[j].getEtiquette()<<std::endl;
        //     j = i;           
        // }
        std::cout<< vec_arbre[i].getLettre() << " occu " << vec_arbre[i].getEtiquette() <<std::endl; 
    }    
}

std::string codage_texte(std::string &texte, std::map<char, std::string> &map) {
    std::string code;

    for(std::string::size_type i = 0; i < texte.length(); i++) {
        auto code_lettre = map.find(texte[i]);
        code += code_lettre->second;
    }

    return code;
}