#if !defined(__ARBREB__)
#define __ARBREB__

#include "Sommet.hh"
#include <fstream>
#include <string>

template<typename T> class ArbreB {   
    private:
        Sommet<T> *_racine;
        Sommet<T> *_sCourant;
        int _nbr_sommet;

        inline void ajout(const T &val);
        inline void supprimer(Sommet<T> *racine);
        inline void supprimer_feuille();
        inline void suppression_un_fils(Sommet<T> *sommet);
        inline void suppression_deux_fils(Sommet<T> *sommet);
        inline void prefixe(Sommet<T> *sommetRacine);
        inline void infixe(Sommet<T> *sommetRacine);
        inline void postfixe(Sommet<T> *sommetRacine);
        inline Sommet<T> *copie(Sommet<T> *sommet);
        inline bool recherche(Sommet<T> *sommetRacine, const T &val, bool &existe);
        inline void nbrSommet(Sommet<T> *sommetRacine, int *&val);
        inline void recherchePere(Sommet<T> *courant, Sommet<T> *recherche, Sommet<T> *&pere);
        inline int  profondeur(Sommet<T> *racine);
        inline void affichage_arbre(Sommet<T> *racine, int decalage);
        inline static void ecrire_fichier(const std::string &&fichier, const std::string &log);
        void ecrire_arbre(const std::string &info) { ecrire_fichier("arbre.txt", info); }
        void ecrire_arbre_interface(const std::string &info) { ecrire_fichier("arbre_interface.txt", info); }
        inline void ecrire_fichier_arbre(Sommet<T> *racine);

    public:
        ArbreB() : _racine(nullptr), _sCourant(nullptr), _nbr_sommet(0) {}
        inline ArbreB(const ArbreB<T> &arbre);
        inline ~ArbreB();

        static void ecrire_log(const std::string &log) { ArbreB<T>::ecrire_fichier("log.txt", log); }

        int getEtiquette() const { return _sCourant->_etiquette; }
        void setEtiquette(const T &val) { _sCourant->_etiquette = val; }
        int getNbrSommet() const { return _nbr_sommet; }
        int get_profondeur() { return profondeur(_racine); }

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
        inline bool deplacementG();
        inline bool deplacementD();


        bool estPrensent(const T &val) { bool existe = false; return recherche(_racine, val, existe) ? true : false; }

        inline void decomposition(ArbreB<T> &arbre);

        inline void supprimer_sommet();
        inline void tout_supprimer();
        bool estVide() { return (_racine == nullptr && _sCourant == nullptr) ? true : false; }

        void dessin_arbre() { affichage_arbre(_racine, 0); }

        inline void ecrire_fichier(Sommet<T> *racine);
        void arbre3D() { ecrire_fichier_arbre(_racine); }

        /* Surcharge des opérateurs */
        inline ArbreB<T> &operator=(const ArbreB<T> &arbre);
        inline ArbreB<T> &operator+=(ArbreB<T> &arbre);
        inline ArbreB<T> &operator<<(const T &val);
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

/* Permet d'écrire dans un fichier */
template<typename T>
void ArbreB<T>::ecrire_fichier(const std::string &&fichier, const std::string &log) {
    std::string const nomFichier(fichier);
    std::fstream monFlux(nomFichier.c_str());
    monFlux.seekp(0, std::ios::end);

    if(monFlux) {
        fichier == "arbre.txt" ? monFlux << log : monFlux << log << std::endl;
        monFlux.close();
    }

    else {
        std::cout << "ERREUR: Impossible d'ouvrir le fichier." << std::endl;
    }
}

/* Permet d'écrire dans un fichier la représentation de notre arbre pour l'affichage graphique */
template<typename T>
void ArbreB<T>::ecrire_fichier_arbre(Sommet<T> *racine) {
    if (racine != nullptr) {
        ecrire_arbre_interface(std::to_string(racine->_etiquette));

        if (racine->_filsG != nullptr) {
            ecrire_arbre_interface("G");
            ecrire_fichier_arbre(racine->_filsG);
        }

        if (racine->_filsG != nullptr) {
            ecrire_arbre_interface("RD");
        }

        if (racine->_filsD != nullptr) {
            ecrire_arbre_interface("D");
            ecrire_fichier_arbre(racine->_filsD);
        }

        if (racine->_filsD != nullptr) {
            ecrire_arbre_interface("RG");
        }
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
        ecrire_log("Valeur deja implémenté dans l'arbre");
    }
    
    else {
        std::cout << "Erreur lors de l'ajout de la valeur" << std::endl;
        ecrire_log("Erreur lors de l'ajout de la valeur");
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
        ecrire_log("Ce sommet n'est pas une feuille");
    }
}

/* Supprime un sommet avec seulement un fils */
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

/* Supprime un sommet avec deux fils */
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
        ecrire_log("Etiquette : " + std::to_string(sommetRacine->_etiquette));

        if (sommetRacine->_filsG != nullptr) {
            prefixe(sommetRacine->_filsG);
        }
        if (sommetRacine->_filsD != nullptr) {
            prefixe(sommetRacine->_filsD);
        }
    }

    else {
        std::cout << "ERR : parcours impossible l'arbre est vide" << std::endl;
        ecrire_log("ERR : parcours impossible l'arbre est vide");
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
        ecrire_log("Etiquette : " + std::to_string(sommetRacine->_etiquette));

        if (sommetRacine->_filsD != nullptr) {
            infixe(sommetRacine->_filsD);
        }
    }

    else {
        std::cout << "ERR : parcours impossible l'arbre est vide" << std::endl;
        ecrire_log("ERR : parcours impossible l'arbre est vide");
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
        ecrire_log("Etiquette : " + std::to_string(sommetRacine->_etiquette));
    }

    else {
        std::cout << "ERR : parcours impossible l'arbre est vide" << std::endl;
        ecrire_log("ERR : parcours impossible l'arbre est vide");
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

/* Retourne la profondeur de l'arbre */
template<typename T>
int ArbreB<T>::profondeur(Sommet<T> *racine) {
    if (racine == nullptr) {
        return 0;
    }

    if (racine->_filsG == nullptr && racine->_filsD == nullptr) {
        return 1;
    }

    else {
        int fgauche = profondeur(racine->_filsG);
        int fdroit = profondeur(racine->_filsD);

        return fgauche > fdroit ? (fgauche + 1) : (fdroit + 1);
    }
}

/* Permet de faire un affichage textuel de l'arbre pour le terminal */
template<typename T>
void ArbreB<T>::affichage_arbre(Sommet<T> *racine, int decalage) {
    if (racine == nullptr) {
        return;
    }

    int profondeur = 5;

    decalage += profondeur;

    affichage_arbre(racine->_filsD, decalage);

    std::cout << "\n";
    ecrire_arbre("\n");
    
    for (auto i = profondeur; i < decalage; i++) {
        std::cout << " ";
        ecrire_arbre(" ");
    }

    std::cout << racine->_etiquette << std::endl;
    ecrire_arbre(std::to_string(racine->_etiquette));
    
    affichage_arbre(racine->_filsG, decalage);
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
            ecrire_log("Vous ne pouvez pas créer une branche ici, une branche existe déjà");
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
            ecrire_log("Vous ne pouvez pas créer une branche ici, une branche existe déjà");
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
bool ArbreB<T>::deplacementG() {
    if (_sCourant->_filsG != nullptr) {
        _sCourant = _sCourant->_filsG;
        return true;
    }

    else {
        std::cout << "Impossible de ce déplacer à gauche vous êtes sur une feuille" << std::endl;
        ecrire_log("Impossible de ce déplacer à gauche vous êtes sur une feuille");
        return false;
    }
}

/* Permet de ce déplacer sur le fils droit du sommet courant */
template<typename T>
bool ArbreB<T>::deplacementD() {
    if (_sCourant->_filsD != nullptr) {
        _sCourant = _sCourant->_filsD;
        return true;
    }

    else {
        std::cout << "Impossible de ce déplacer à droite vous êtes sur une feuille" << std::endl;
        ecrire_log("Impossible de ce déplacer à droite vous êtes sur une feuille");
        return false;
    }
}

/* Permet de décomposer l'arbre this la partie décomposé va être supprimé de l'arbre this et va être mis dans l'arbre passé en parametre */
template<typename T>
void ArbreB<T>::decomposition(ArbreB<T> &arbre) {
    if (_racine == nullptr) {
        std::cout << "L'arbre est vide impossible de faire une décomposition" << std::endl;
        ecrire_log("L'arbre est vide impossible de faire une décomposition");
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
        ecrire_log("Impossible de faire une decomposition depuis la racine");
        return;
    }
}

//Fonction de suppression d'un sommet dans l'arbre (gestion de tous les cas possibles)
template<typename T>
void ArbreB<T>::supprimer_sommet() {
    if (_racine == nullptr) {
        std::cout << "l'arbre est vide aucune suppresion possible" << std::endl;
        ecrire_log("L'arbre est vide aucune suppresion possible");
        return;
    }

    if (_sCourant == _racine) {
        if (_sCourant->_filsG != nullptr && _sCourant->_filsD == nullptr) {
            suppression_un_fils(_racine->_filsG);
        }
        
        else if (_sCourant->_filsD != nullptr && _sCourant->_filsG == nullptr) {
            suppression_un_fils(_racine->_filsD);
        }

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