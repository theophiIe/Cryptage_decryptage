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
        int _racine_x = 600;
        int _racine_y = 100;

        void paintEvent(QPaintEvent *event);
        QSize sizeHint() const;
};

#endif