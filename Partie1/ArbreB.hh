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
            inline bool recherche(Sommet<T> *sommetRacine, const T &val, bool &existe);

        public:
            ArbreB() : _racine(nullptr), _sCourant(nullptr), _nbr_sommet(0) {}
            
            ArbreB(const ArbreB<T> &arbre) { 
                _racine = copie(arbre._racine);
                _sCourant = _racine;
                _nbr_sommet = arbre._nbr_sommet;
            }
            
            ~ArbreB() {
                if (_nbr_sommet > 0) {
                    supprimer(_racine->_filsG);
                    supprimer(_racine->_filsD);
                    delete _racine;
                    _racine = nullptr;
                }
            }

            int getEtiquette() const { return _sCourant->_etiquette; }
            void setEtiquette(const T &val) { _sCourant->_etiquette = val; }
            int getNbrSommet() const { return _nbr_sommet; }

            // Ne pas garder ou mettre en privé
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

            bool estPrensent(const T &val) { bool existe = false; return recherche(_racine, val, existe) ? true : false; }

            inline void decomposition(ArbreB<T> &arbre);

            inline void tout_supprimer();
            bool estVide() { return (_racine == nullptr && _sCourant == nullptr) ? true : false; }

            // Surcharge des opérateurs

            // Arbre1 = Arbre2
            ArbreB<T> &operator=(const ArbreB<T> &arbre) {
                if (_racine != nullptr) {
                    tout_supprimer();
                }
                
                _racine = copie(arbre._racine);
                _sCourant = _racine;
                _nbr_sommet = arbre._nbr_sommet;

                return *this;
            }

            // Fusion des arbres
            ArbreB<T> &operator+=(ArbreB<T> &arbre) {
                Sommet<T> *nouvRacine = new Sommet(_racine->_etiquette + arbre._racine->_etiquette);
                
                nouvRacine->_filsG = _racine;  
                nouvRacine->_filsD = copie(arbre._racine);          
                _racine->_parent = nouvRacine;
                _racine = nouvRacine;
                _nbr_sommet += arbre._nbr_sommet + 1;
                
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
            ArbreB<T> &operator<(const T &val) {
                ajoutG(val);
                return *this;
            }
            
            // Ajout d'une valeur à droite
            ArbreB<T> &operator>(const T &val) {
                ajoutD(val);
                return *this;
            }
            
            // Affiche de l'arbre (Objectif afficher dans l'IG)
            // friend std::ostream &operator<<(std::ostream &flux, ArbreB &arbre){

            // }
    };    

    //Suppression d'un sommet 

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
            racine = nullptr;
        }

        //gestion d'erreur a ajouter ?
        else {
            std::cout<<"La racine est vide, on ne peut la supprimer"<<std::endl;
        }
    }

    //parcours préfixe d'un arbre donné

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

    //parcours infixe d'un arbre donné

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

    //parcours postfixe/sufixe d'un arbre donné

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
    
    //Copie d'un arbre donné, on retourne le sommet du nouvel arbre

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
            _nbr_sommet++;

            return newSommet;
        }
    }

    //Fonction de recherche d'un etiquette, retourne un booléen en fonction du résultat

    template<typename T>
    bool ArbreB<T>::recherche(Sommet<T> *sommetRacine, const T &val, bool &existe) {
        if (sommetRacine->_filsG != nullptr) {
            recherche(sommetRacine->_filsG, val, existe);
        }

        if (sommetRacine->_filsD != nullptr) {
            recherche(sommetRacine->_filsD, val, existe);
        }

        if (sommetRacine->_etiquette == val) {
            existe = true;
        }
        
        return existe;
    }

    //ajoute un sommet fils gauche à la racine donnée

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

    //ajoute un sommet fils droit à la racine donné

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

    //Permet de se rendre dans le fils gauche si celui-ci existe

    template<typename T>
    void ArbreB<T>::deplacementG() {
        if (_sCourant->_filsG != nullptr) {
            _sCourant = _sCourant->_filsG;
        }
    }

    //Permet de se rendre dans le fils droit si celui-ci existe


    template<typename T>
    void ArbreB<T>::deplacementD() {
        if (_sCourant->_filsD != nullptr) {
            _sCourant = _sCourant->_filsD;
        }
    }

    //Permet de se rendre dans le père si le sommet n'est pas une racine

    template<typename T>
    void ArbreB<T>::remonter() {
        if(_sCourant->_parent != nullptr) {
            _sCourant = _sCourant->_parent;
        }

        else {
            std::cout << "Vous ne pouvez plus remonter on est à la racine" << std::endl;
        }
    }

    // suppression dans le père du sommet pointé du lien vers le sommet fils donné
    
    template<typename T>
    void ArbreB<T>::decomposition(ArbreB<T> &arbre) {
        if (_racine == nullptr) {
            std::cout << "L'arbre est vide impossible de faire une décomposition" << std::endl;
            return;
        }

        // Probleme de leak à corriger
        if (_sCourant->_etiquette != _racine->_etiquette) {
            arbre.tout_supprimer();
            arbre._racine = copie(_sCourant);
            arbre._sCourant = arbre._racine;

            supprimer(_sCourant);
            
            _sCourant = _racine;
            _racine->_filsG = nullptr;
        }

        else {
            std::cout << "Impossible de faire une decomposition depuis la racine" << std::endl;
            return;
        }
    }

    //supression totale de l'arbre

    template<typename T>
    void ArbreB<T>::tout_supprimer() {
        _sCourant = _racine;
        
        if (_nbr_sommet > 0) {
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