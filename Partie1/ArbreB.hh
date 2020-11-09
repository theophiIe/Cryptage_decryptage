#if !defined(__ARBREB__)
#define __ARBREB__

    #include "Sommet.hh"

    template<typename T>
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

            int getSommet() { return _sCourant->_etiquette; }
            void parcours();

            // Ajout d'un sommet à l'arbre
            void ajoutG(const T &val)
            {
                if (_racine == nullptr)
                {
                    Sommet<T> *s = new Sommet(val);
                    _sCourant = s;
                    _racine = s;
                    _nbr_sommet++;
                }

                else
                {
                    Sommet<T> *s = new Sommet(val);
                    _sCourant->_filsG = s;
                    _sCourant = s;
                    _nbr_sommet++;
                }
            }

            void ajoutD(const T &val)
            {
                if (_racine == nullptr)
                {
                    Sommet<T> *s = new Sommet(val);
                    _sCourant = s;
                    _racine = s;
                    _nbr_sommet++;
                }

                else
                {
                    Sommet<T> *s = new Sommet(val);
                    _sCourant->_filsD = s;
                    _sCourant = s;
                    _nbr_sommet++;
                }
            }

            // Pour ce déplacer (le but pouvoir ce deplacer avec les flèches dans l'IG)
            void deplacementG()
            {
                if (_sCourant->_filsG != nullptr)
                {
                    _sCourant = _sCourant->_filsG;
                }
                
            }

            void deplacementD()
            {
                if (_sCourant->_filsD != nullptr)
                {
                    _sCourant = _sCourant->_filsD;
                }
            }

            void remonter() { _sCourant = _racine; }

            // Méthode clean
            void supprimer_sommet();
            void tout_supprimer();

            // Surcharge des opérateurs

            // Arbre1 = Arbre2
            ArbreB &operator=(ArbreB &arbre);
            
            // Fusion des arbres
            ArbreB &operator+=(ArbreB &arbre);
            
            // Fusion des arbres sans affectation
            ArbreB &operator+(ArbreB &arbre);
            
            // Ajout d'une valeur à gauche
            ArbreB &operator<(T &val);
            
            // Ajout d'une valeur à droite
            ArbreB &operator>(T &val);
            
            // Affiche de l'arbre (Objectif afficher dans l'IG)
            //friend std::ostream &operator<<(std::ostream &flux, ArbreB &arbre);
    };    

#endif