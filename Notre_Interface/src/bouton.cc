#include "../header/bouton.hh"

Bouton::Bouton() {
    layout_englobant = new QGridLayout();
    setLayout(layout_englobant);
    layout_englobant->setAlignment(Qt::AlignTop);

    layout_bouton = new QGridLayout();
    setLayout(layout_bouton);
    layout_bouton->setAlignment(Qt::AlignBottom);

    layout_text = new QGridLayout();
    setLayout(layout_text);
    layout_text->setAlignment(Qt::AlignTop);

    layout_englobant->addLayout(layout_bouton, 0, 0);
    layout_englobant->addLayout(layout_text, 1, 0);

    texte = new QTextEdit(this);
    texte->setMinimumSize(900, 800);
    layout_text->addWidget(texte);

    scoller = new QScrollArea();
    scoller->setWidget(texte);
    scoller->show();
    layout_text->addWidget(scoller, 0, 0);

    bQuitter = new QPushButton("Quitter", this);
    bQuitter->show();
    layout_bouton->addWidget(bQuitter, 0, 1);
    connect(bQuitter, SIGNAL(clicked()), qApp, SLOT(quit()));

    bTest = new QPushButton("Test", this);
    bTest->show();
    layout_bouton->addWidget(bTest, 0, 2);
    connect(bTest, SIGNAL(clicked()), this, SLOT(aff_test1()));  
}

Bouton::~Bouton() {

}

void Bouton::aff_test1() {
    QString chemin = "log.txt";
    QFile fichier(chemin);
    fichier.open(QIODevice::ReadOnly);
    QTextStream lire_log(&fichier);
    QString contenu_fichier = lire_log.readAll();
    texte->setText(contenu_fichier);
    texte->show();
}
