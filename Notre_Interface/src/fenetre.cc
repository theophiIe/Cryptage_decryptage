#include "../header/fenetre.hh"

/* Permet de gérer l'affichage global de la fenetre graphique*/
Fenetre::Fenetre() {
    layout = new  QGridLayout();
    setLayout(layout);
    
    boutons = new Bouton();
    boutons->show();
    layout->addWidget(boutons, 1, 0);

    dessin = new Affichage();
    dessin->show();
    layout->addWidget(dessin, 0, 0);

    zone_scoll = new QScrollArea();
    zone_scoll->setWidget(dessin);
    zone_scoll->show();
    layout->addWidget(zone_scoll, 1, 1);

    setWindowTitle(tr("Projet IN505 : Partie 1"));
    setMinimumSize(500, 500);    
}

Fenetre::~Fenetre() {}