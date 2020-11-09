#if !defined(__SOMMET__)
#define __SOMMET__

    #include <iostream>

    template<class T>
    class Sommet
    {
        private:
            Sommet<T> *_filsG;
            Sommet<T> *_filsD;
            T _etiquette;
            
        public:
            Sommet() : _filsG(nullptr), _filsD(nullptr) {}
            Sommet(const T &etiquette) : _filsG(nullptr), _filsD(nullptr), _etiquette(etiquette) {}
            ~Sommet(){}
    };
 
#endif