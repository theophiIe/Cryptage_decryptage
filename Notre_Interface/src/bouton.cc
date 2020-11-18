#include "../header/bouton.hh"

Bouton::Bouton() {
    layout = new QGridLayout();
    setLayout(layout);
    layout->setAlignment(Qt::AlignBottom);

    bQuitter = new QPushButton("Quitter", this);
    bQuitter->show();
    layout->addWidget(bQuitter, 0, 1);
    connect(bQuitter, SIGNAL(clicked()), qApp, SLOT(quit()));

    texte = new QTextEdit(this);
    //layout->addWidget(texte);

    scoller = new QScrollArea();
    scoller->setWidget(texte);
    scoller->show();
    layout->addWidget(scoller, 0, 0);
    

    bTest = new QPushButton("Test", this);
    bTest->show();
    layout->addWidget(bTest, 0, 2);
    connect(bTest, SIGNAL(clicked()), this, SLOT(aff_test1()));  

    bArbre = new QPushButton("Arbre", this);
    bArbre->show();
    layout->addWidget(bArbre, 0, 3);
}

Bouton::~Bouton() {

}

void Bouton::aff_test1() {
    QString chemin = "log.txt";
    QFile fichier(chemin);
    fichier.open(QIODevice::ReadOnly);
    QTextStream lire_log(&fichier);
    QString test = lire_log.readAll();
    texte->setText(test);
    texte->show();
}
