#if !defined(__FENETRE__)
#define __FENETRE__

#include <QtWidgets/QWidget>
#include <QtWidgets/QLayout>
#include <QtGui/QPainter>
#include "bouton.hh"
#include "affichage.hh"

class Fenetre : public QWidget {
    private:
        Bouton *boutons;
        //Affichage *dessin;
        QGridLayout* layout;

    public:
        Fenetre();
        ~Fenetre();

        void paintEvent(QPaintEvent *event);
};

#endif