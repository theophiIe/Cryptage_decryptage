#if !defined(AFFICHAGE)
#define AFFICHAGE

#include <QtWidgets/QWidget>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtGui/QPainter>
#include "ArbreB.hh"
#include "bouton.hh"


class Affichage : public QWidget {
    private:
        int lecture_fichier_arbre();

        int ecart_feuille = 300;
        int ecart_ordonnee = 100;
        int cercle_size = 5;
        int racineX = 800;
        int racineY = 50;

        void affiche_ligne(int tmpX, int tmpY, int X, int Y);
        void affichage_noeud(std::string s, int abs_X, int ord_Y, int taille_C);

    public:
        Affichage();
        ~Affichage();

        void paintEvent(QPaintEvent *event);
        QSize sizeHint() const;
};

#endif