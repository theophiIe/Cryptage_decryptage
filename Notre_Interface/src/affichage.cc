#include "../header/affichage.hh"
#include <fstream>
#include <string>

Affichage::Affichage() {}
Affichage::~Affichage() {}

QSize Affichage::sizeHint() const {
    return QSize(1800, 600);
}

int Affichage::lecture_fichier_arbre() {
    std::ifstream fichier("arbre_interface.txt");
    if (fichier) {
        std::string s = "mot";
        char c;
        int X = racineX;
        int Y = racineY;
        int tmpX = 0;
        int tmpY = 0;
        int depth = 1;

        // print racine
        fichier >> s;
        affichage_noeud(s, X, Y, cercle_size);

        while(fichier >> s) {            
            if ( s == "RG") {
                depth--;
                X -= (ecart_feuille/depth);
                Y -= ecart_ordonnee;
            }

            else if ( s == "RD") {
                depth--;
                X += (ecart_feuille/depth);
                Y -= ecart_ordonnee;
            }

            else if ( s == "G") {
                fichier >> s;
                tmpX = X;
                tmpY = Y;
                X -= (ecart_feuille /depth);
                Y += ecart_ordonnee;
                affiche_ligne(tmpX,tmpY,X,Y);
                affichage_noeud(s, X, Y, cercle_size);
                depth++;
                
            }

            else if ( s == "D") {
                fichier >> s;
                tmpX = X;
                tmpY = Y;
                X += (ecart_feuille /depth);
                Y += ecart_ordonnee;
                affiche_ligne(tmpX,tmpY,X,Y);
                affichage_noeud(s, X, Y, cercle_size);
                depth++;
               
            }

            else {
                std::cout<<"Mot non reconnu !\n";
            }  
        }      
    }

    return 0;
}

void Affichage::affiche_ligne(int tmpX, int tmpY, int X, int Y) {
    QPainter paint(this);
    paint.drawLine(tmpX, tmpY, X, Y);
    
}

void Affichage::affichage_noeud(std::string s, int abs_X, int ord_Y, int taille_C) {
    QPainter paint(this);
    QPen pen(Qt::red, 5, Qt::SolidLine);
    paint.setPen(pen);
    paint.setFont(QFont("Calibri", 25));

    QString str = QString::fromStdString(s);
    
    paint.drawEllipse(abs_X - 2, ord_Y -2 , taille_C, taille_C);
    QPen pen1(Qt::black, 70, Qt::SolidLine);
    paint.setPen(pen1);
    paint.drawText(abs_X - 8, ord_Y -10, str);
}


template<typename T>
void Affichage::paintFils(ArbreB<T> &arbre, int X, int Y) {
    QPainter paint(this);
        
    paint.drawEllipse(racineX, racineY,cercle_size,cercle_size);

    X = X - ecart_feuille;
    Y = Y + ecart_ordonnee;
    paint.drawEllipse(X, Y,cercle_size,cercle_size);

    paintFils(arbre, X, Y);

    X = X + ecart_feuille;
    Y = Y - ecart_ordonnee;

    X = X + ecart_feuille;
    Y = Y + ecart_ordonnee;

    paint.drawEllipse(X, Y,cercle_size,cercle_size);
    paintFils(arbre, X, Y);
         
    X = X - ecart_feuille;
    Y = Y - ecart_ordonnee;
}

template<typename T>
void Affichage::creer_un_arbre(ArbreB<T> &a) {
    a.ajoutG(8);
    a << 5;
    a >> 7;
    a.remonter_racine();
    a.ajoutD(6);
    a.ajoutD(1);
    a.remonter_racine();
    a.deplacementG();
    a.ajoutG(4);
    a.ajoutG(9);
}

void Affichage::paintEvent(QPaintEvent* event) {
    QPainter paint(this);
    lecture_fichier_arbre();
}

