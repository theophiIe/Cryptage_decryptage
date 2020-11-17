#include "../header/fenetre.hh"

Fenetre::Fenetre() {
    layout = new  QGridLayout();
    setLayout(layout);

    boutons = new Bouton();
    boutons->show();
    layout->addWidget(boutons, 0, 0);
}

Fenetre::~Fenetre() {

}