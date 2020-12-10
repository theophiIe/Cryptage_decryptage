#include "../header/bouton.hh"

/* Création des boutons et de l'affichage des tests */
Bouton::Bouton() {
    layout_englobant = new QGridLayout();
    setLayout(layout_englobant);
    layout_englobant->setAlignment(Qt::AlignTop);

    layout_bouton = new QGridLayout();
    layout_bouton->setAlignment(Qt::AlignBottom);

    layout_text = new QGridLayout();
    layout_text->setAlignment(Qt::AlignTop);

    layout_englobant->addLayout(layout_bouton, 0, 0);
    layout_englobant->addLayout(layout_text, 1, 0);

    texte = new QTextEdit(this);
    layout_text->addWidget(texte);

    codage = new QTextEdit(this);
    codage->setReadOnly(true);
    layout_text->addWidget(codage);

    bQuitter = new QPushButton("Quitter", this);
    bQuitter->show();
    layout_bouton->addWidget(bQuitter, 0, 1);
    connect(bQuitter, SIGNAL(clicked()), qApp, SLOT(quit()));

    bTest = new QPushButton("Crypter", this);
    bTest->show();
    layout_bouton->addWidget(bTest, 0, 2);
    connect(bTest, SIGNAL(clicked()), this, SLOT(crypter()));
}

Bouton::~Bouton() {}

/* Permet de récuper les tests du fichier log.txt et les affiches*/
void Bouton::aff_test() {
    QString chemin = "log.txt";
    QFile fichier(chemin);
    fichier.open(QIODevice::ReadOnly);
    QTextStream lire_log(&fichier);
    QString contenu_fichier = lire_log.readAll();
    texte->setText(contenu_fichier);
    texte->show();
}

void Bouton::crypter() {
    std::string texte_non_coder = texte->toPlainText().toStdString();

    std::map<char, int> ma_map = calcul_occurence(texte_non_coder);

    //ArbreB<int> *a = creation_racines(ma_map);
    std::vector<ArbreB<int>> a = creation_racines(ma_map);

    for (size_t i = 0; i < ma_map.size(); i++) {
        std::cout << "test lettre : " << a[i].getLettre() << "\ttest recurrence : " << a[i].getEtiquette() << std::endl;
    }
    std::cout<<"Vector size bouton : ";
    std::cout<< a.size()<<std::endl;

    fusion_racines(a);

    // Affichage du texte codé dans l'interface
    // std::map<char, std::string> map = arbre.codage();

    // std::cout << "taille de la map " << map.size() << std::endl;

    // for (auto const& entry: map) {
    //     std::cout << entry.first << " codage : " << entry.second << '\n';
    // }

    // std::string texte_code = codage_texte(texte_non_coder, map);

    // std::ofstream monArbreI("arbre_interface.txt");
    // monArbreI.close();
    // arbre.arbreInterface();

    // QString code = QString::fromStdString(texte_code);
    // codage->setText(code);
}