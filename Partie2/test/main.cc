#include <iostream>
#include <map>

int main() {
    std::string test_code = "je fais juste un test simple!";
    
    char c;
    std::map<char, int> ma_map;
    for(std::string::size_type i = 0; i < test_code.length(); ++i) {
        c = test_code[i];
        //std::cout << "mon char : " << c << std::endl;

        if(ma_map.insert(std::make_pair(c, 1)).second == false) {
            ma_map[c] += 1;
        }
    }

    for (auto const& entry: ma_map) {
        std::cout << entry.first << " occurence : " << entry.second << '\n';
    }

    return 0;
}
