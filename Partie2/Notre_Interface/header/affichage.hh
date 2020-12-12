#if !defined(AFFICHAGE)
#define AFFICHAGE

#include <QtWidgets/QWidget>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtGui/QPainter>
#include <QtGui/QPaintEvent>
#include <math.h>
#include "ArbreB.hh"
#include "bouton.hh"


class Affichage : public QWidget {
    private:
        int ecart_feuille = 5;
        int ecart_ordonnee = 50;
        int cercle_size = 5;
        int racineX = 2000;
        int racineY = 40;
        int profondeur = 0;

        void lecture_fichier_arbre();
        void settings_according_depth();
        void affiche_ligne(int tmpX, int tmpY, int X, int Y);
        void affichage_noeud(std::string s, int abs_X, int ord_Y, int taille_C);

    public:
        Affichage();
        ~Affichage();

        void paintEvent(QPaintEvent *event);
        QSize sizeHint() const;
};

#endif