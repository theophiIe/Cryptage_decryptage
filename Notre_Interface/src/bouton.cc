#include "../header/bouton.hh"

Bouton::Bouton() {
    layout = new QGridLayout();
    setLayout(layout);
    layout->setAlignment(Qt::AlignBottom);

    bQuitter = new QPushButton("Quitter", this);
    bQuitter->show();
    layout->addWidget(bQuitter, 0, 0);
    connect(bQuitter, SIGNAL(clicked()), qApp, SLOT(quit()));
    
    bTest = new QPushButton(tr("Choisir un test"));
    QMenu *menu = new QMenu(this);
    menu->addAction(tr("Test 1"));
    menu->addAction(tr("Test 2"));
    menu->addAction(tr("Test 3"));
    menu->addAction(tr("Test 4"));
    bTest->setMenu(menu);
    layout->addWidget(bTest, 0, 1);

    // faire la connexion avec les boutons    

    bArbre = new QPushButton("Arbre", this);
    bArbre->show();
    layout->addWidget(bArbre, 0, 2);
}

Bouton::~Bouton() {

}

void Bouton::aff_test1() {
    std::cout << "test1 :" << std::endl;
}

void Bouton::aff_test2() {
    std::cout << "test2 :" << std::endl;
}

void Bouton::aff_test3() {
    std::cout << "test3 :" << std::endl;
}

void Bouton::aff_test4() {
    std::cout << "test4 :" << std::endl;
}
