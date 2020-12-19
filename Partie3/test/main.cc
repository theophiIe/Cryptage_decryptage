#include <iostream>
#include <map>
#include <string>

int main() {
    std::string test_code = "je fais juste un test simple!";
    
    char c;
    std::map<char, int> ma_map;
    for(std::string::size_type i = 0; i < test_code.length(); ++i) {
        c = test_code[i];

        if(ma_map.insert(std::make_pair(c, 1)).second == false) {
            ma_map[c] += 1;
        }
    }

    for (auto const& entry: ma_map) {
        std::cout << entry.first << " occurence : " << entry.second << '\n';
    }

    std::cout << "taill de la map : " << ma_map.size() << std::endl;

    std::map<char, int>::iterator it = ma_map.begin();
    it++;
    std::cout << "val en pos 5 de la map : " << it->first << std::endl;

    std::string tmp = "je fais un test";

    tmp = tmp.substr(0, tmp.size() - 1);

    std::cout << tmp << std::endl;

    // test de la création du codage du texte Bonjour
    std::string texte = "Bonjour";
    std::map<char, std::string> map;
    map.insert(std::make_pair('B', "011")).second;
    map.insert(std::make_pair('o', "10")).second;
    map.insert(std::make_pair('n', "010")).second;
    map.insert(std::make_pair('j', "001")).second;
    map.insert(std::make_pair('u', "000")).second;
    map.insert(std::make_pair('r', "11")).second;

    std::string code;

    for(std::string::size_type i = 0; i < texte.length(); i++) {
        auto code_lettre = map.find(texte[i]);
        code += (code_lettre->second + " ");
    }

    std::cout << "le code pour le mot Bonjour : " << code << std::endl;

    return 0;
}
