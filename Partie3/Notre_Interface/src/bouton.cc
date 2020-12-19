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

    bCrypter = new QPushButton("Crypter", this);
    bCrypter->show();
    layout_bouton->addWidget(bCrypter, 0, 2);
    connect(bCrypter, SIGNAL(clicked()), this, SLOT(crypter()));

    bDecrypter = new QPushButton("Decrypter", this);
    bDecrypter->show();
    layout_bouton->addWidget(bDecrypter, 0, 3);
    connect(bDecrypter, SIGNAL(clicked()), this, SLOT(decrypter()));
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
    int nombre_occurence = 0;
    std::string texte_non_coder = texte->toPlainText().toStdString();
    
    if (texte_non_coder == "") {
        QString code = QString::fromStdString("");
        codage->setText(code);
        std::ofstream monArbreI("arbre_interface.txt");
        monArbreI.close();
        return;
    }

    char lettre;
    int ctint =-1;
    for(std::string::size_type i = 0; i < texte_non_coder.length(); i++) {
        lettre = texte_non_coder[i];
        ctint = (int)lettre;
        if (ctint > 255 || ctint < 0) {
            std::string char_non_valide = "Impossible de compresser le texte.\n Le caratere en position : " 
                                        + std::to_string(i+1) + " ne fait pas parti du code ascii merci de le modifier ou le supprimer.";
            QString code = QString::fromStdString(char_non_valide);
            codage->setText(code);
            std::ofstream monArbreI("arbre_interface.txt");
            monArbreI.close();
            return;
        }
    }

    std::map<char, int> ma_map = calcul_occurence(texte_non_coder);

    std::vector<ArbreB<int>> a = creation_racines(ma_map);
    
    for (size_t i = 0; i < a.size(); i++) {
        nombre_occurence += a[i].getEtiquette();
    }

    std::cout << "\n\n\n\n\t=============== Nouveau cyptage ===============\n " << std::endl;
    std::cout << "\n\t~#~ Les occurences ~#~\n " << std::endl;
    std::cout << "Nombre d'occurence : " << nombre_occurence <<std::endl;

    for (size_t i = 0; i < a.size(); i++) {
        float ghpd = (float)(a[i].getEtiquette()) / (float)nombre_occurence;
        if (a[i].getLettre() == '\n') {
            std::cout << "Caractère : \\n\t Nombre d'occurence : " << a[i].getEtiquette() << "\t Pourcentage d'occurence : " << ghpd*100 << "%" << std::endl;
        }
        
        else {
            std::cout << "Caractère : "  << a[i].getLettre() << "\t Nombre d'occurence : " << a[i].getEtiquette() << "\t Pourcentage d'occurence : " << ghpd*100 << "%" << std::endl;   
        }
    }

    ArbreB<int> arbre = fusion_racines(a);

    std::map<char, std::string> map = arbre.codage();
    std::cout << "\n\t~#~ Encodage de Huffman ~#~\n" << std::endl;
    for (auto const& entry: map) {
        if (entry.first == '\n') {
            std::cout << "\\n codage : " << entry.second << std::endl;
        }
        
        else {
            std::cout << entry.first << " codage : " << entry.second << std::endl;
        }
    }

    std::string texte_code = codage_texte(texte_non_coder, map);

    std::ofstream monArbreI("arbre_interface.txt");
    monArbreI.close();
    arbre.arbreInterface();

    QString code = QString::fromStdString(texte_code);
    codage->setText(code);
}

void Bouton::decrypter() {
    std::string texte_non_coder = texte->toPlainText().toStdString();

    if (!verif_syntaxique(texte_non_coder)) {
        std::string char_non_valide = "Le texte à decoder est invalide";
        QString code = QString::fromStdString(char_non_valide);
        codage->setText(code);
        std::ofstream monArbreI("arbre_interface.txt");
        monArbreI.close();
        return;
    }
}