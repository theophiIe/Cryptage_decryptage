#if !defined(__SOMMET__)
#define __SOMMET__

    #include <iostream>

    template <class T> class ArbreB;

    template<class T> class Sommet {
        friend class ArbreB<T>;
        
        private:
            Sommet<T> *_filsG;
            Sommet<T> *_filsD;
            Sommet<T> *_parent;
            T _etiquette;
            
            Sommet(const T &etiquette) : _filsG(nullptr), _filsD(nullptr), _parent(nullptr), _etiquette(etiquette) {}

        public:
            // SommetA == SommetB
            bool operator==(Sommet const& sommet) {
                if (sommet._etiquette == this->_etiquette) {
                    std::cout<<"fga = fgb";
                    return true;
                }
                else
                std::cout<<"fga != fgb";
                return false;
            }
    };
 
#endif