#if !defined(__ARBREB__)
#define __ARBREB__

    #include "Sommet.hh"

    template<typename T> class ArbreB {   
        private:
            Sommet<T> *_racine;
            Sommet<T> *_sCourant;
            int _nbr_sommet;

            inline void supprimer(Sommet<T> *racine);

            inline void prefixe(Sommet<T> *sommetRacine);
            inline void infixe(Sommet<T> *sommetRacine);
            inline void postfixe(Sommet<T> *sommetRacine);
            inline Sommet<T> *copie(Sommet<T> *node);

        public:
            ArbreB() : _racine(nullptr), _sCourant(nullptr), _nbr_sommet(0) {}
            ArbreB(const ArbreB &arbre) {}
            
            ~ArbreB() {
                if (_nbr_sommet > 0)
                {
                    supprimer(_racine->_filsG);
                    supprimer(_racine->_filsD);
                    delete _racine;
                    _racine = nullptr;
                }
            }

            int getEtiquette() { return _sCourant->_etiquette; }
            int getNbrSommet() { return _nbr_sommet; }
            Sommet<T> *getRacine() { return _racine; }

            // parcours de l'arbre
            void parcours_prefixe() { prefixe(_racine); };
            void parcours_infixe() { infixe(_racine); };
            void parcours_postfixe() { postfixe(_racine); };

            // Ajout d'un sommet à l'arbre
            inline void ajoutG(const T &val);
            inline void ajoutD(const T &val);

            // Pour ce déplacer (le but pouvoir ce deplacer avec les flèches dans l'IG)
            inline void deplacementG();
            inline void deplacementD();

            inline void remonter();
            void remonter_racine() { _sCourant = _racine; }

            inline void tout_supprimer();
            bool estVide() { return (_racine == nullptr && _sCourant == nullptr) ? true : false; }

            // Surcharge des opérateurs

            // Arbre1 = Arbre2
            // ArbreB &operator=(ArbreB &arbre) {
            //     tout_supprimer();

            //     _racine = arbre._racine;
            //     _sCourant = arbre._sCourant;
            //     _nbr_sommet = arbre._nbr_sommet;

            //     return *this;
            // }

            // Fusion des arbres
            ArbreB &operator+=(ArbreB<T> *arbre)
            {
                Sommet<T> *nouvRacine = new Sommet(_racine->_etiquette + arbre->_racine->_etiquette);
                
                nouvRacine->_filsG = _racine;  
                nouvRacine->_filsD = copie(arbre->_racine);          
                _racine->_parent = nouvRacine;
                _racine = nouvRacine;
                _nbr_sommet += arbre->_nbr_sommet + 1;
                
                return *this;
            }
            
            // Fusion des arbres sans affectation
            // ArbreB &operator+(ArbreB &arbre) {
            //     ArbreB<T> *arbreFusionne;
            //     arbreFusionne->_racine->_filsG;
            //     arbreFusionne->_racine->_filsD;

            //     return *arbreFusionne;
            // }
            
            // Ajout d'une valeur à gauche
            ArbreB &operator<(const T &val) {
                ajoutG(val);
                return *this;
            }
            
            // Ajout d'une valeur à droite
            ArbreB &operator>(const T &val) {
                ajoutD(val);
                return *this;
            }
            
            // Affiche de l'arbre (Objectif afficher dans l'IG)
            // friend std::ostream &operator<<(std::ostream &flux, ArbreB &arbre){

            // }
    };    

    template<typename T>
    void ArbreB<T>::supprimer(Sommet<T> *racine) {
        if (racine != nullptr)
        {
            if (racine->_filsG != nullptr) {
                supprimer(racine->_filsG);
            }
            
            if (racine->_filsD != nullptr) {
                supprimer(racine->_filsD);
            }

            delete racine;
            racine = NULL;
        }
    }

    template<typename T>
    void ArbreB<T>::prefixe(Sommet<T> *sommetRacine) {
        std::cout << "Etiquette : " << sommetRacine->_etiquette << std::endl;

        if (sommetRacine->_filsG != nullptr) {
            prefixe(sommetRacine->_filsG);
        }
        if (sommetRacine->_filsD != nullptr) {
            prefixe(sommetRacine->_filsD);
        }
    }

    template<typename T>
    void ArbreB<T>::infixe(Sommet<T> *sommetRacine) {
        if (sommetRacine->_filsG != nullptr) {
            infixe(sommetRacine->_filsG);
        }

        std::cout<< "Etiquette : " << sommetRacine->_etiquette << std::endl;

        if (sommetRacine->_filsD != nullptr) {
            infixe(sommetRacine->_filsD);
        }
    }

    template<typename T>
    void ArbreB<T>::postfixe(Sommet<T> *sommetRacine) {
        if (sommetRacine->_filsG != nullptr) {
            postfixe(sommetRacine->_filsG);
        }

        if (sommetRacine->_filsD != nullptr) {
            postfixe(sommetRacine->_filsD);
        }

        std::cout<< "Etiquette : " << sommetRacine->_etiquette << std::endl;
    }
    
    template<typename T>
    Sommet<T> *ArbreB<T>::copie(Sommet<T> *node) {
        if (node == nullptr) {
            return nullptr;
        }
        
        else {
            Sommet<T> *newGauche = copie(node->_filsG);
            Sommet<T> *newDroit = copie(node->_filsD);
            Sommet<T> *newSommet = new Sommet(node->_etiquette);

            newSommet->_filsG = newGauche;
            newSommet->_filsD= newDroit;

            return newSommet;
        }
    }

    template<typename T>
    void ArbreB<T>::ajoutG(const T &val) {
        if (_racine == nullptr) {
            Sommet<T> *s = new Sommet(val);
            _sCourant = s;
            _racine = s;
            _nbr_sommet++;
        }

        else {
            Sommet<T> *s = new Sommet(val);
            s->_parent = _sCourant;
            _sCourant->_filsG = s;
            _sCourant->_parent = _sCourant;
            _sCourant = s;
            _nbr_sommet++;
        }
    }

    template<typename T>
    void ArbreB<T>::ajoutD(const T &val) {
        if (_racine == nullptr) {
            Sommet<T> *s = new Sommet(val);
            _sCourant = s;
            _sCourant->_etiquette = val;
            _racine = s;
            _nbr_sommet++;
        }

        else {
            Sommet<T> *s = new Sommet(val);
            s->_parent = _sCourant;
            _sCourant->_filsD = s;
            _sCourant->_parent = _sCourant;
            _sCourant = s;
            _nbr_sommet++;
        }
    }

    template<typename T>
    void ArbreB<T>::deplacementG() {
        if (_sCourant->_filsG != nullptr) {
            _sCourant = _sCourant->_filsG;
        }
    }

    template<typename T>
    void ArbreB<T>::deplacementD() {
        if (_sCourant->_filsD != nullptr) {
            _sCourant = _sCourant->_filsD;
        }
    }

    template<typename T>
    void ArbreB<T>::remonter() {
        if(_sCourant->_parent != nullptr) {
            _sCourant = _sCourant->_parent;
        }

        else {
            std::cout << "Vous ne pouvez plus remonter on est à la racine" << std::endl;
        }
    }

    template<typename T>
    void ArbreB<T>::tout_supprimer() {
        _sCourant = _racine;
        
        if (_nbr_sommet > 0)
        {
            if (_racine->_filsG != nullptr) {
                supprimer(_racine->_filsG);
            }
            
            if (_racine->_filsD != nullptr) {
                supprimer(_racine->_filsD);
            }

            delete _racine;
            _racine = nullptr;
            _sCourant = nullptr;
            _nbr_sommet = 0;
        }
    }

#endif