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

            // Pour ce déplacer (le but pouvoir ce deplacer avec les flèches dans l'IG)
            void deplacementG();
            void deplacementD();
            void remonter();

            // Méthode clean
            void supprimer();
            void tout_supprimer();

            // Surcharge des opérateurs

            // Arbre1 = Arbre2
            ArbreB &operator=(ArbreB &arbre);
            
            // Fusion des arbres
            ArbreB &operator+=(ArbreB &arbre);
            
            // Fusion des arbres sans affectation
            ArbreB &operator+(ArbreB &arbre);
            
            // Ajout d'une valeur à gauche
            void &operator<(T &val);
            
            // Ajout d'une valeur à droite
            void &operator>(T &val);
            
            // Affiche de l'arbre (Objectif afficher dans l'IG)
            friend std::ostream &operator<<(std::ostream &flux, ArbreB &arbre);
    };    

#endif