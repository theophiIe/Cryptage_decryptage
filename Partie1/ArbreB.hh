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
            inline void suppression_un_fils(Sommet<T> *sommet);
            inline void suppression_deux_fils(Sommet<T> *sommet);
            inline void prefixe(Sommet<T> *sommetRacine);
            inline void infixe(Sommet<T> *sommetRacine);
            inline void postfixe(Sommet<T> *sommetRacine);
            inline Sommet<T> *copie(Sommet<T> *sommet);
            inline bool recherche(Sommet<T> *sommetRacine, const T &val, bool &existe);
            inline void nbrSommet(Sommet<T> *sommetRacine, int *&val);
            inline void recherchePere(Sommet<T> *courant, Sommet<T> *recherche, Sommet<T> *&pere);

        public:
            ArbreB() : _racine(nullptr), _sCourant(nullptr), _nbr_sommet(0) {}
            inline ArbreB(const ArbreB<T> &arbre);
            inline ~ArbreB();

            int getEtiquette() const { return _sCourant->_etiquette; }
            void setEtiquette(const T &val) { _sCourant->_etiquette = val; }
            int getNbrSommet() const { return _nbr_sommet; }

            // parcours de l'arbre
            void parcours_prefixe() { prefixe(_racine); };
            void parcours_infixe() { infixe(_racine); };
            void parcours_postfixe() { postfixe(_racine); };

            // Ajout d'un sommet à l'arbre
            inline void ajoutG(const T &val);
            inline void ajoutD(const T &val);
            inline void ajoutAuto(const T &val);

            // Pour ce déplacer dans l'arbre
            void remonter_racine() { _sCourant = _racine; }
            inline void deplacementG();
            inline void deplacementD();


            bool estPrensent(const T &val) { bool existe = false; return recherche(_racine, val, existe) ? true : false; }

            inline void decomposition(ArbreB<T> &arbre);

            inline void supprimer_feuille();
            inline void supprimer_sommet();
            inline void tout_supprimer();
            bool estVide() { return (_racine == nullptr && _sCourant == nullptr) ? true : false; }

            /* Surcharge des opérateurs */

            inline ArbreB<T> &operator=(const ArbreB<T> &arbre);

            /* Fusion des arbres */
            inline ArbreB<T> &operator+=(ArbreB<T> &arbre);
            
            /*Ajout d'une valeur à gauche */
            inline ArbreB<T> &operator<<(const T &val);
            
            /* Ajout d'une valeur à droite */
            inline ArbreB<T> &operator>>(const T &val);
    };    

    /* Constructeur de copie de la classe ArbreB */
    template<typename T>
    ArbreB<T>::ArbreB(const ArbreB<T> &arbre) { 
        _racine = copie(arbre._racine);
        _sCourant = _racine;
        _nbr_sommet = arbre._nbr_sommet;
    }

    /* Destructeur de la classe ArbreB */
    template<typename T>
    ArbreB<T>::~ArbreB() {
        if (_nbr_sommet > 0) {
            supprimer(_racine->_filsG);
            supprimer(_racine->_filsD);
            delete _racine;
            _racine = nullptr;
        }
    }

    /* Ajout d'une valeur à l'arbre en fonction de son étiquette */
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

    /* Suppression d'un sommet */
    template<typename T>
    void ArbreB<T>::supprimer(Sommet<T> *racine) {
        if (racine != nullptr) {
            if (racine->_filsG != nullptr) {
                supprimer(racine->_filsG);
            }
            
            if (racine->_filsD != nullptr) {
                supprimer(racine->_filsD);
            }

            delete racine;
            racine = nullptr;
        }

        else {
            std::cout<<"La racine est vide, on ne peut la supprimer"<<std::endl;
        }
    }

    template<typename T>
    void ArbreB<T>::suppression_un_fils(Sommet<T> *sommet) {
        ArbreB<T> tmp;
        tmp._racine = copie(sommet);
        
        tout_supprimer();
        _racine = tmp._racine;
        _sCourant = _racine;

        int *val{ new int(0) };
        nbrSommet(_racine, val);
        _nbr_sommet = *val;
        
        tmp.tout_supprimer();

        delete val;
    }

    template<typename T>
    void ArbreB<T>::suppression_deux_fils(Sommet<T> *sommet) {
        Sommet <T> *tmp = _racine;
        Sommet <T> *pere = _racine;

        recherchePere(tmp, _sCourant, pere);
        
        if (pere->_filsG != nullptr && pere->_filsG->_etiquette == _sCourant->_etiquette) {
            pere->_filsG = sommet;
        }

        else if (pere->_filsD != nullptr && pere->_filsD->_etiquette == _sCourant->_etiquette) {
            pere->_filsD = sommet;
        }

        delete _sCourant;
        _sCourant = _racine;
        _nbr_sommet -= 1;
    }

    /* Parcours préfixe de l'arbre, on doit passer la racine en parametre */
    template<typename T>
    void ArbreB<T>::prefixe(Sommet<T> *sommetRacine) {
        if (sommetRacine != nullptr) {
            std::cout << "Etiquette : " << sommetRacine->_etiquette << std::endl;

            if (sommetRacine->_filsG != nullptr) {
                prefixe(sommetRacine->_filsG);
            }
            if (sommetRacine->_filsD != nullptr) {
                prefixe(sommetRacine->_filsD);
            }
        }

        else {
            std::cout << "ERR : parcours impossible l'arbre est vide" << std::endl;
        }
    }

    /* Parcours infixe de l'arbre, on doit passer la racine en parametre */
    template<typename T>
    void ArbreB<T>::infixe(Sommet<T> *sommetRacine) {
        if (sommetRacine != nullptr) {
            if (sommetRacine->_filsG != nullptr) {
                infixe(sommetRacine->_filsG);
            }

            std::cout<< "Etiquette : " << sommetRacine->_etiquette << std::endl;

            if (sommetRacine->_filsD != nullptr) {
                infixe(sommetRacine->_filsD);
            }
        }

        else {
            std::cout << "ERR : parcours impossible l'arbre est vide" << std::endl;
        }        
    }

    /* Parcours postfixe de l'arbre, on doit passer la racine en parametre */
    template<typename T>
    void ArbreB<T>::postfixe(Sommet<T> *sommetRacine) {
        if (sommetRacine != nullptr) {
            if (sommetRacine->_filsG != nullptr) {
                postfixe(sommetRacine->_filsG);
            }

            if (sommetRacine->_filsD != nullptr) {
                postfixe(sommetRacine->_filsD);
            }

            std::cout<< "Etiquette : " << sommetRacine->_etiquette << std::endl;
        }

        else {
            std::cout << "ERR : parcours impossible l'arbre est vide" << std::endl;
        }
    }
    
    /* Permet de copier un arbre à partir d'un sommet passé en parametre et renvoi la racine de l'arbre copié */
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

    /*  La méthode recherche va rechercher à partir du sommet passé en parametre une valeur
     *   elle aussi passé en parametre et renvoir true si la valeur et trouvé sinon false */
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

    /* La méthode va incrémenter la valeur val passé en parametre en fonction du nombre de sommet dans l'arbre*/
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

    /* Permet de récuperer le sommet père du sommet courant */
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

    /* Si la racine n'existe pas on la créer et on lui affecte la valeur passé en parametre 
     * sinon on ajoute val aux fils gauche du sommet courant */
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

    /* Si la racine n'existe pas on la créer et on lui affecte la valeur passé en parametre 
     * sinon on ajoute val aux fils gauche du sommet courant */
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

    /* Ajout d'une valeur en utilisant la méthode ajout qui va remplir l'arbre comme si c'étais un ABR */
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

    /* Permet de ce déplacer sur le fils gauche du sommet courant */
    template<typename T>
    void ArbreB<T>::deplacementG() {
        if (_sCourant->_filsG != nullptr) {
            _sCourant = _sCourant->_filsG;
        }

        else {
            std::cout << "Impossible de ce déplacer à gauche vous êtes sur une feuille" << std::endl;
        }
    }

    /* Permet de ce déplacer sur le fils droit du sommet courant */
    template<typename T>
    void ArbreB<T>::deplacementD() {
        if (_sCourant->_filsD != nullptr) {
            _sCourant = _sCourant->_filsD;
        }

        else {
            std::cout << "Impossible de ce déplacer à droite vous êtes sur une feuille" << std::endl;
        }
    }

    /* Permet de décomposer l'arbre this la partie décomposé va être supprimé de l'arbre this et va être mis dans l'arbre passé en parametre */
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

    /* Permet de supprimer une une feuille de l'arbre */
    template<typename T>
    void ArbreB<T>::supprimer_feuille() {
        if (_sCourant == _racine && (_sCourant->_filsG == nullptr && _sCourant->_filsD == nullptr)) {
            delete _racine;
            _racine = nullptr;

            _nbr_sommet = 0;
        }
        
        else if (_sCourant->_filsG == nullptr && _sCourant->_filsD == nullptr) {
            Sommet <T> *tmp = _racine;
            Sommet <T> *pere = _racine;

            recherchePere(tmp, _sCourant, pere);
            
            if (pere->_filsG != nullptr && pere->_filsG->_etiquette == _sCourant->_etiquette) {
                pere->_filsG = nullptr;
            }

            else if (pere->_filsD != nullptr && pere->_filsD->_etiquette == _sCourant->_etiquette) {
                pere->_filsD = nullptr;
            }

            delete _sCourant;
            _nbr_sommet -= 1;

        }
        
        else {
            std::cout << "Ce sommet n'est pas une feuille" << std::endl;
        }
    }
    
    //Fonction de suppression d'un sommet dans l'arbre (gestion de tous les cas possibles)
    template<typename T>
    void ArbreB<T>::supprimer_sommet() {
        if (_racine == nullptr) {
            std::cout << "l'arbre est vide aucune suppresion possible" << std::endl;
            return;
        }

        //si le sommet est la racine de l'arbre
        if (_sCourant == _racine) {
            //si le fils gauche est non null et le droit est null, on crée un arbre
            //tmp, on copie la racine dans le fils gauche, on supprime l'arbre initial
            //puis on reatribut les valeur de l'abre tmp dans l'arbre initial;
            //on réajuste la valeur de val pour pouvoir liberer la mémoire correctement
            // et on finit par supprimer l'arbre tmp puis on libère val.
            if (_sCourant->_filsG != nullptr && _sCourant->_filsD == nullptr) {
                suppression_un_fils(_racine->_filsG);
            }
            
            // pareil que le if au dessus, mais avec fils droit non null
            else if (_sCourant->_filsD != nullptr && _sCourant->_filsG == nullptr) {
                suppression_un_fils(_racine->_filsD);
            }
            
            //si les deux sommets sont non vides on creer une copie de chaque arbre
            //on supprime l'arbre initial et on link l'arbre gauche a la racine.

            else if (_sCourant->_filsG != nullptr && _sCourant->_filsD != nullptr) {
                ArbreB<T> tmpG;
                ArbreB<T> tmpD;

                tmpG._racine = copie(_racine->_filsG);
                tmpD._racine = copie(_racine->_filsD);
                
                tout_supprimer();
                _racine = tmpG._racine;
                _sCourant = _racine;

                while (_sCourant->_filsD != nullptr) {
                    _sCourant = _sCourant->_filsD;
                }
                
                _sCourant->_filsD = tmpD._racine;

                int *val{ new int(0) };
                nbrSommet(tmpG._racine, val);
                nbrSommet(tmpD._racine, val);
                _nbr_sommet = *val;
                
                tmpG.tout_supprimer();

                delete val;
            }

            else {
                tout_supprimer();
            }
        }

        //si le sommet courant n'est pas la racine de l'arbre, que fils gauche est non
        //null, et que fils droit est null alors ta fonction a l'air bien trop compliqué
        else if (_sCourant->_filsG != nullptr && _sCourant->_filsD == nullptr) {
            suppression_deux_fils(_sCourant->_filsG);
        }

        else if (_sCourant->_filsD != nullptr && _sCourant->_filsG == nullptr) {
            suppression_deux_fils(_sCourant->_filsD);
        }
        
        else if (_sCourant->_filsD == nullptr && _sCourant->_filsG == nullptr) {
            supprimer_feuille();
        }
        
        else {
            Sommet <T> *tmp = _racine;
            Sommet <T> *pere = _racine;

            recherchePere(tmp, _sCourant, pere);

            if (pere->_filsG != nullptr && pere->_filsG->_etiquette == _sCourant->_etiquette) {
                pere->_filsG = _sCourant->_filsG;
            }

            else if (pere->_filsD != nullptr && pere->_filsD->_etiquette == _sCourant->_etiquette) {
                pere->_filsD = _sCourant->_filsG;
            }

            tmp = _sCourant->_filsD;
            Sommet <T> *tmpCourant = _sCourant->_filsG;

            while (tmpCourant->_filsD != nullptr) {
                tmpCourant = tmpCourant->_filsD;
            }

            tmpCourant->_filsD = tmp;            

            delete _sCourant;
            _sCourant = _racine;
            _nbr_sommet -= 1;
        }
    }

    /* Supprime totalement l'arbre */
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

    /* Permet de copier l'arbre this avec l'abre passer en parametre*/
    template<typename T>
    ArbreB<T> &ArbreB<T>::operator=(const ArbreB<T> &arbre) {
        if (_racine != nullptr) {
            tout_supprimer();
        }
        
        _racine = copie(arbre._racine);
        _sCourant = _racine;
        _nbr_sommet = arbre._nbr_sommet;

        return *this;
    }

    /* Permet de fusionner un arbre */
    template<typename T>
    ArbreB<T> &ArbreB<T>::operator+=(ArbreB<T> &arbre) {
        Sommet<T> *nouvRacine = new Sommet<T>(_racine->_etiquette + arbre._racine->_etiquette);
        
        nouvRacine->_filsG = _racine;  
        nouvRacine->_filsD = copie(arbre._racine);
        _racine = nouvRacine;
        _nbr_sommet += arbre._nbr_sommet + 1;
        
        return *this;
    }

    /* Permet de faire un ajout de sommet gauche */
    template<typename T>
    ArbreB<T> &ArbreB<T>::operator<<(const T &val) {
        ajoutG(val);
        return *this;
    }

    /* Permet de faire un ajout de sommet droit */
    template<typename T>
    ArbreB<T> &ArbreB<T>::operator>>(const T &val) {
        ajoutD(val);
        return *this;
    }

#endif