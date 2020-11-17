#if !defined(__FENETRE__)
#define __FENETRE__

#include <QtWidgets/QWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QScrollArea>

#include "bouton.hh"
#include "affichage.hh"

class Fenetre : public QWidget {
    private:
        Bouton *boutons;
        Affichage *dessin;
        QScrollArea *zone_scoll;
        QGridLayout* layout;

    public:
        Fenetre();
        ~Fenetre();
};

#endif