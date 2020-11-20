#if !defined(__AFFICHAGE__)
#define __AFFICHAGE__

#include <QtWidgets/QWidget>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtGui/QPainter>
#include "ArbreB.hh"
#include "bouton.hh"


class Affichage : public QWidget {
    private:

    public:
        Affichage();
        ~Affichage();

        int lecture_fichier_arbre();

        int ecart_feuille = 200;
        int ecart_ordonnee = 100;
        int cercle_size = 5;
        int racineX = 400;
        int racineY = 100;


        void affiche_ligne(int tmpX, int tmpY, int X, int Y);
        void affichage_noeud(std::string s, int abs_X, int ord_Y, int taille_C);
        template<typename T>
        void paintFils(ArbreB<T> &arbre, int X, int Y);
        template<typename T>
        void creer_un_arbre(ArbreB<T> &arbre);
        void paintEvent(QPaintEvent *event);
        QSize sizeHint() const;
};

#endif