#include "../header/fenetre.hh"

Fenetre::Fenetre() {
    layout = new  QGridLayout();
    setLayout(layout);
    
    boutons = new Bouton();
    boutons->show();
    layout->addWidget(boutons, 0, 0);

    dessin = new Affichage();
    dessin->show();
    layout->addWidget(dessin, 1, 0);

    zone_scoll = new QScrollArea();
    zone_scoll->setWidget(dessin);
    zone_scoll->show();
    layout->addWidget(zone_scoll, 0, 1);

    
    setMinimumSize(500, 500);    
}

Fenetre::~Fenetre() {

}