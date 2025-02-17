#if !defined(__SOMMET__)
#define __SOMMET__

    #include <iostream>

    template <class T> class ArbreB;

    template<class T> class Sommet {
        friend class ArbreB<T>;
        
        private:
            Sommet<T> *_filsG;
            Sommet<T> *_filsD;
            T _etiquette;
            
            Sommet(const T &etiquette) : _filsG(nullptr), _filsD(nullptr), _etiquette(etiquette) {}
            
    };
 
#endif