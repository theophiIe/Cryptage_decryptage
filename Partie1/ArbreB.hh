#if !defined(__ARBREB__)
#define __ARBREB__

    #include "Sommet.hh"

    template<typename T> class ArbreB {   
        private:
            Sommet<T> *_racine;
            Sommet<T> *_sCourant;
            int _nbr_sommet;

            inline void ajout(const T &val);
            inline void supprimer(Sommet<T> *racine);
            inline void prefixe(Sommet<T> *sommetRacine);
            inline void infixe(Sommet<T> *sommetRacine);
            inline void postfixe(Sommet<T> *sommetRacine);
            inline Sommet<T> *copie(Sommet<T> *sommet);
            inline bool recherche(Sommet<T> *sommetRacine, const T &val, bool &existe);
            inline void nbrSommet(Sommet<T> *sommetRacine, int *&val);
            inline void recherchePere(Sommet<T> *courant, Sommet<T> *recherche, Sommet<T> *&pere);

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
            inline void ajoutAuto(const T &val);

            // Pour ce déplacer (le but pouvoir ce deplacer avec les flèches dans l'IG)
            inline void deplacementG();
            inline void deplacementD();

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
                Sommet<T> *nouvRacine = new Sommet<T>(_racine->_etiquette + arbre._racine->_etiquette);
                
                nouvRacine->_filsG = _racine;  
                nouvRacine->_filsD = copie(arbre._racine);
                _racine = nouvRacine;
                _nbr_sommet += arbre._nbr_sommet + 1;
                
                return *this;
            }
            
            // Ajout d'une valeur à gauche
            ArbreB<T> &operator<<(const T &val) {
                ajoutG(val);
                return *this;
            }
            
            // Ajout d'une valeur à droite
            ArbreB<T> &operator>>(const T &val) {
                ajoutD(val);
                return *this;
            }
    };    

    template<typename T>
    void ArbreB<T>::ajout(const T &val) {
        if (_racine == nullptr) {
            Sommet<T> *s = new Sommet<T>(val);
            _sCourant = s;
            _sCourant->_etiquette = val;
            _racine = s;
            _nbr_sommet++;
        }

        else if (val < _sCourant->_etiquette) {
            if (_sCourant->_filsG != nullptr) {
                deplacementG();
                ajout(val);
            }
            
            else {
                ajoutG(val);
            }
        }

        else if (val > _sCourant->_etiquette) {
            if (_sCourant->_filsD != nullptr) {
                deplacementD();
                ajout(val);
            }
            
            else {
                ajoutD(val);
            }
        }
        
        else if (_sCourant->_etiquette == val) {
            std::cout << "Valeur deja implémenté dans l'arbre" << std::endl;
        }
        
        else {
            std::cout << "Erreur lors de l'ajout de la valeur" << std::endl;
        }
    }

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
    Sommet<T> *ArbreB<T>::copie(Sommet<T> *sommet) {
        if (sommet == nullptr) {
            return nullptr;
        }
        
        else {
            Sommet<T> *newGauche = copie(sommet->_filsG);
            Sommet<T> *newDroit = copie(sommet->_filsD);
            Sommet<T> *newSommet = new Sommet<T>(sommet->_etiquette);

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

    template<typename T>
    void ArbreB<T>::nbrSommet(Sommet<T> *sommetRacine, int *&val) {
        *val += 1;

        if (sommetRacine->_filsG != nullptr) {
            nbrSommet(sommetRacine->_filsG, val);
        }

        if (sommetRacine->_filsD != nullptr) {
            nbrSommet(sommetRacine->_filsD, val);
        }        
    }

    template<typename T>
    void ArbreB<T>::recherchePere(Sommet<T> *courant, Sommet<T> *recherche, Sommet<T> *&pere) {
        if (courant->_filsG != nullptr) {
            if (courant->_filsG->_etiquette != recherche->_etiquette) {
                recherchePere(courant->_filsG, recherche, pere);
            }

            else {
                pere = courant;
            }
            
        }

        if (courant->_filsD != nullptr) {
            if (courant->_filsD->_etiquette != recherche->_etiquette) {
                recherchePere(courant->_filsD, recherche, pere);
            }
            
            else {
                pere = courant;
            }
            
        }
    }
    

    //ajoute un sommet fils gauche à la racine donnée

    template<typename T>
    void ArbreB<T>::ajoutG(const T &val) {
        if (_racine == nullptr) {
            Sommet<T> *s = new Sommet<T>(val);
            _sCourant = s;
            _racine = s;
            _nbr_sommet++;
        }

        else {
            if (_sCourant->_filsG == nullptr) {
                Sommet<T> *s = new Sommet<T>(val);
                _sCourant->_filsG = s;
                _sCourant = s;
                _nbr_sommet++;
            }

            else {
                std::cout << "Vous ne pouvez pas créer une branche ici, une branche existe déjà" << std::endl;
            }
        }
    }

    //ajoute un sommet fils droit à la racine donné

    template<typename T>
    void ArbreB<T>::ajoutD(const T &val) {
        if (_racine == nullptr) {
            Sommet<T> *s = new Sommet<T>(val);
            _sCourant = s;
            _sCourant->_etiquette = val;
            _racine = s;
            _nbr_sommet++;
        }

        else {
            if (_sCourant->_filsD == nullptr) {
                Sommet<T> *s = new Sommet<T>(val);
                _sCourant->_filsD = s;
                _sCourant = s;
                _nbr_sommet++;
            }
            
            else {
                std::cout << "Vous ne pouvez pas créer une branche ici, une branche existe déjà" << std::endl;
            }
        }
    }

    template<typename T>
    void ArbreB<T>::ajoutAuto(const T &val) {
        if (_sCourant != nullptr) {
            remonter_racine();
            ajout(val);
        }

        else {
            ajout(val);
        }
    }

    //Permet de se rendre dans le fils gauche si celui-ci existe

    template<typename T>
    void ArbreB<T>::deplacementG() {
        if (_sCourant->_filsG != nullptr) {
            _sCourant = _sCourant->_filsG;
        }

        else {
            std::cout << "Impossible de ce déplacer à gauche vous êtes sur une feuille" << std::endl;
        }
    }

    //Permet de se rendre dans le fils droit si celui-ci existe


    template<typename T>
    void ArbreB<T>::deplacementD() {
        if (_sCourant->_filsD != nullptr) {
            _sCourant = _sCourant->_filsD;
        }

        else {
            std::cout << "Impossible de ce déplacer à droite vous êtes sur une feuille" << std::endl;
        }
    }

    // suppression dans le père du sommet pointé du lien vers le sommet fils donné
    
    template<typename T>
    void ArbreB<T>::decomposition(ArbreB<T> &arbre) {
        if (_racine == nullptr) {
            std::cout << "L'arbre est vide impossible de faire une décomposition" << std::endl;
            return;
        }

        if (_sCourant->_etiquette != _racine->_etiquette) {
            arbre.tout_supprimer();
            arbre._racine = copie(_sCourant);
            arbre._sCourant = arbre._racine;
            
            int *val{new int(0)};

            arbre.nbrSommet(arbre._racine, val);
            arbre._nbr_sommet = *val;

            Sommet <T> *tmp = _racine;
            Sommet <T> *pere = _racine;

            recherchePere(tmp, _sCourant, pere);
            
            if (pere->_filsG->_etiquette == _sCourant->_etiquette) {
                pere->_filsG = nullptr;
            }

            else if (pere->_filsD->_etiquette == _sCourant->_etiquette) {
                pere->_filsD = nullptr;
            }
            
            supprimer(_sCourant);
            _sCourant = _racine;
            _nbr_sommet -= *val;

            delete val;
            val = nullptr;
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