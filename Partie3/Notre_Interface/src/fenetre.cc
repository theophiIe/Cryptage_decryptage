#include "../header/fenetre.hh"

/* Permet de gérer l'affichage global de la fenetre graphique*/
Fenetre::Fenetre() {
    layout = new  QGridLayout();
    setLayout(layout);
    
    boutons = new Bouton();
    boutons->show();
    layout->addWidget(boutons, 0, 0);

    dessin = new Affichage();
    dessin->show();

    zone_scoll = new QScrollArea();
    zone_scoll->setWidget(dessin);
    zone_scoll->show();
    layout->addWidget(zone_scoll, 1, 0);

    setWindowTitle(tr("Projet IN505 : Partie 3"));
    setMinimumSize(500, 500);    
}

Fenetre::~Fenetre() {}