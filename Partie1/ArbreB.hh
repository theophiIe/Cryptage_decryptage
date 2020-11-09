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

            // Ajout d'un sommet à l'arbre
            void ajoutG(const T &val);
            void ajoutD(const T &val);

            // Pour ce déplacer (le but pouvoir ce deplacer avec les flèches dans la partie graphique)
            void deplacementG();
            void deplacementD();
            void remonter();

            // Méthode clean
            void supprimer();
            void tout_supprimer();
    };    

#endif