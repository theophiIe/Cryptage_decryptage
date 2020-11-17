#include "../header/fenetre.hh"

Fenetre::Fenetre() {
    layout = new  QGridLayout();
    setLayout(layout);
    layout->setAlignment(Qt::AlignBottom);

    boutons = new Bouton();
    boutons->show();
    layout->addWidget(boutons, 0, 0);

    // MARCHE PAS C'EST NUL QT
    dessin = new Affichage();
    dessin->show();
    layout->addWidget(dessin, 1, 0);

    zone_scoll = new QScrollArea();
    // zone_scoll->setWidget();

    
    setMinimumSize(500, 500);
    //dessin = new Affichage();
    
}

Fenetre::~Fenetre() {

}