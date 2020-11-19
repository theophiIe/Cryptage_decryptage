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
        
        int ecart_feuille = 50;
        int ecart_ordonnee = 50;
        int cercle_size = 35;
        int racineX = 250;
        int racineY = 100;

        template<typename T>
        void paintFils(ArbreB<T> &arbre, int X, int Y);
        template<typename T>
        void creer_un_arbre(ArbreB<T> &arbre);
        void paintEvent(QPaintEvent *event);
        QSize sizeHint() const;
};

#endif