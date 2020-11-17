#if !defined(__FENETRE__)
#define __FENETRE__

#include <QtWidgets/QWidget>
#include <QtWidgets/QLayout>
#include "bouton.hh"
#include "affichage.hh"

class Fenetre : public QWidget {
    private:
        Bouton *boutons;
        QGridLayout* layout;

    public:
        Fenetre();
        ~Fenetre();
};

#endif