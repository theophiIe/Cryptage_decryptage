#include "../header/fenetre.hh"

Fenetre::Fenetre() {
    setFixedSize(800, 500);
    layout = new QGridLayout();
    setLayout(layout);
    layout->setAlignment(Qt::AlignBottom);

    bQuitter = new QPushButton("Quitter", this);
    bQuitter->show();
    layout->addWidget(bQuitter, 0, 0);
    connect(bQuitter, SIGNAL(clicked()), qApp, SLOT(quit()));
    
    bTest = new QPushButton("Test", this);
    bTest->show();
    layout->addWidget(bTest, 0, 1);
    
    bArbre = new QPushButton("Arbre", this);
    bArbre->show();
    layout->addWidget(bArbre, 0, 2);

    //scrollbar = new QScrollArea();
    //scrollbar->setWidget();
}

Fenetre::~Fenetre() {

}