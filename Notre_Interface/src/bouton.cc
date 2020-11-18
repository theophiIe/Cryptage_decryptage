#include "../header/bouton.hh"

Bouton::Bouton() {
    layout = new QGridLayout();
    setLayout(layout);
    layout->setAlignment(Qt::AlignBottom);

    bQuitter = new QPushButton("Quitter", this);
    bQuitter->show();
    layout->addWidget(bQuitter, 0, 0);
    connect(bQuitter, SIGNAL(clicked()), qApp, SLOT(quit()));
    
    // bTest = new QPushButton(tr("Choisir un test"));
    // QMenu *bMenu = new QMenu(this);
    
    // test1 = new QAction(tr("Test1"));
    // connect(test1, SIGNAL(clicked()), qApp, SLOT(quit()));

    // test2 = new QAction(tr("Test2"));
    // connect(test2, SIGNAL(clicked()), qApp, SLOT(quit()));

    // test3 = new QAction(tr("Test3"));
    // connect(test3, SIGNAL(clicked()), qApp, SLOT(quit()));

    // test4 = new QAction(tr("Test4"));
    // connect(test4, SIGNAL(clicked()), qApp, SLOT(quit()));
    
    // bMenu->addAction(test1);
    // bMenu->addAction(test2);
    // bMenu->addAction(test3);
    // bMenu->addAction(test4);
    // bTest->setMenu(bMenu);
    // layout->addWidget(bTest, 0, 1);

    bTest = new QPushButton("Test", this);
    bTest->show();
    layout->addWidget(bTest, 0, 1);
    connect(bTest, SIGNAL(clicked()), this, SLOT(aff_test1()));

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
