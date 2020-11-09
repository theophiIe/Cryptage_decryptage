#if !defined(__ARBREB__)
#define __ARBREB__

    #include "Sommet.hh"

    template<class T>
    class ArbreB
    {   
        private:
            Sommet<T> *_racine;
            Sommet<T> *_sCourant;
            int _nbr_sommet;

        public:
            ArbreB() : _racine(nullptr), _sCourant(nullptr), _nbr_sommet(0) {}
            ArbreB(const ArbreB &arbre) {}
            ~ArbreB() {}

            void parcours();
            int getSommet();
    };    

#endif