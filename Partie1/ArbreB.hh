#if !defined(__ARBREB__)
#define __ARBREB__

    #include "Sommet.hh"

    template<typename T>
    class ArbreB {   
        private:
            Sommet<T> *_racine;
            Sommet<T> *_sCourant;
            int _nbr_sommet;

        public:
            ArbreB() : _racine(nullptr), _sCourant(nullptr), _nbr_sommet(0) {}
            ArbreB(const ArbreB &arbre) {}
            
            ~ArbreB() {
                if (_nbr_sommet > 0)
                {
                    supprimer(_racine->_filsG);
                    supprimer(_racine->_filsD);
                    delete _racine;
                }
                
            }

            int getSommet() { return _sCourant->_etiquette; }
            int getNbrSommet() { return _nbr_sommet; }
            Sommet<T> *getRacine() { return _racine; }

            // parcours préfixe
            void parcours_prefixe(Sommet<T> *sommetRacine) {
                std::cout << "Etiquette : " << sommetRacine->_etiquette << std::endl;

                if (sommetRacine->_filsG != nullptr) {
                    parcours_prefixe(sommetRacine->_filsG);
                }
                if (sommetRacine->_filsD != nullptr) {
                    parcours_prefixe(sommetRacine->_filsD);
                }
            }

            //parcours infixe
            void parcours_infixe(Sommet<T> *sommetRacine) {
                if (sommetRacine->_filsG != nullptr) {
                    parcours_infixe(sommetRacine->_filsG);
                }

                std::cout<< "Etiquette : " << sommetRacine->_etiquette << std::endl;

                if (sommetRacine->_filsD != nullptr) {
                    parcours_infixe(sommetRacine->_filsD);
                }
            }

            //parcours postfixe
            void parcours_postfixe(Sommet<T> *sommetRacine) {
                if (sommetRacine->_filsG != nullptr) {
                    parcours_postfixe(sommetRacine->_filsG);
                }

                if (sommetRacine->_filsD != nullptr) {
                    parcours_postfixe(sommetRacine->_filsD);
                }

                std::cout<< "Etiquette : " << sommetRacine->_etiquette << std::endl;
            }

            // Ajout d'un sommet à l'arbre
            void ajoutG(const T &val) {
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

            void ajoutD(const T &val) {
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

            // Pour ce déplacer (le but pouvoir ce deplacer avec les flèches dans l'IG)
            void deplacementG() {
                if (_sCourant->_filsG != nullptr) {
                    _sCourant = _sCourant->_filsG;
                }
            }

            void deplacementD() {
                if (_sCourant->_filsD != nullptr) {
                    _sCourant = _sCourant->_filsD;
                }
            }

            void remonter() {
                if(_sCourant->_parent != nullptr) {
                    _sCourant = _sCourant->_parent;
                }

                else {
                    std::cout << "Vous ne pouvez plus remonter on est à la racine" << std::endl;
                }
            }

            void remonter_racine() { _sCourant = _racine; }

            // Méthode clean METTRE EN PRIVATE
            void supprimer(Sommet<T> *racine) {
                if (racine != nullptr)
                {
                    if (racine->_filsG != nullptr) {
                        supprimer(racine->_filsG);
                    }
                    
                    if (racine->_filsD != nullptr) {
                        supprimer(racine->_filsD);
                    }

                    delete racine;
                }
            }

            void tout_supprimer() {
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

            bool estVide() { return (_racine == nullptr && _sCourant == nullptr) ? true : false; }

            // Surcharge des opérateurs

            // Arbre1 = Arbre2
            ArbreB &operator=(ArbreB &arbre) {
                if (&arbre != this) {
                    this->_racine = arbre._racine;
                    this->_sCourant = arbre._sCourant;
                    this->_nbr_sommet = arbre._nbr_sommet;
                }

                return *this;
            };
            
            // Arbre1 == Arbre2
            bool &operator==(ArbreB &arbre);

            // Fusion des arbres
            ArbreB &operator+=(ArbreB &arbre);
            
            // Fusion des arbres sans affectation
            ArbreB &operator+(ArbreB &arbre);
            
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
            //friend std::ostream &operator<<(std::ostream &flux, ArbreB &arbre);
    };    

#endif