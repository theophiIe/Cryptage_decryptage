#include "../header/affichage.hh"
#include <fstream>
#include <string>

Affichage::Affichage() {}
Affichage::~Affichage() {}

/* Permet de gérer la taille de la zone de dessin de l'arbre */
QSize Affichage::sizeHint() const {
    return QSize(5000, 2000);
}

void Affichage::settings_according_depth() {
    switch (profondeur) {
        case 2:
            ecart_feuille = 100;
            ecart_ordonnee = 100;
            cercle_size = 5;
            racineX = 200;
            racineY = 40;
            break;

        case 3:
            ecart_feuille = 100;
            ecart_ordonnee = 100;
            cercle_size = 5;
            racineX = 200;
            racineY = 40;
            break;

        case 4:
            ecart_feuille = 75;
            ecart_ordonnee = 60;
            cercle_size = 5;
            racineX = 290;
            racineY = 40;
            break;

        case 5:
            ecart_feuille = 60;
            ecart_ordonnee = 70;
            cercle_size = 5;
            racineX = 500;
            racineY = 40;
            break;

        case 6:
            ecart_feuille = 50;
            ecart_ordonnee = 65;
            cercle_size = 5;
            racineX = 800;
            racineY = 40;
            break;

        case 7:
            ecart_feuille = 40;
            ecart_ordonnee = 48;
            cercle_size = 5;
            racineX = 1300;
            racineY = 40;
            break;

        // Pas encore testé apres
        case 8:
            ecart_feuille = 12;
            ecart_ordonnee = 200;
            cercle_size = 5;
            racineX = 2000;
            racineY = 40;
            break;

        case 9:
            ecart_feuille = 12;
            ecart_ordonnee = 200;
            cercle_size = 5;
            racineX = 2000;
            racineY = 40;
            break;

        case 10:
            ecart_feuille = 12;
            ecart_ordonnee = 200;
            cercle_size = 5;
            racineX = 2000;
            racineY = 40;
            break;
        
        case 11:
            ecart_feuille = 12;
            ecart_ordonnee = 200;
            cercle_size = 5;
            racineX = 2000;
            racineY = 40;
            break;

        case 12:
            ecart_feuille = 12;
            ecart_ordonnee = 200;
            cercle_size = 5;
            racineX = 2000;
            racineY = 40;
            break;
        
        case 13:
            ecart_feuille = 12;
            ecart_ordonnee = 200;
            cercle_size = 5;
            racineX = 2000;
            racineY = 40;
            break;

        default:
            break;
    }
}

/* Lecture du fichier contenant les informations sur l'arbre à dessiner 
   + appel des fonctions permettant de dessiner l'arbre */
void Affichage::lecture_fichier_arbre() {
    std::ifstream fichier("arbre_interface.txt");
    if (fichier) {
        std::string s = "";
        int X = racineX;
        int Y = racineY;
        int tmpX = 0;
        int tmpY = 0;
        int depth = 1;
        

        fichier >> s;
        if (s != "") {
            profondeur = std::stoi(s);
            settings_according_depth();
        }

        else {
            fichier.close();
            return;
        }

        // print racine
        fichier >> s;
        affichage_noeud(s, X, Y, cercle_size);
        
        while(fichier >> s) {            
            if ( s == "RG") {
                depth--;
                X -= (ecart_feuille*pow(2,(profondeur-depth)-2));
                Y -= ecart_ordonnee;
            }

            else if ( s == "RD") {
                depth--;
                X += (ecart_feuille*pow(2,(profondeur-depth)-2));
                Y -= ecart_ordonnee;
            }

            else if ( s == "G") {
                fichier >> s;
                tmpX = X;
                tmpY = Y;
                X -= (ecart_feuille*pow(2,(profondeur-depth)-2));
                Y += ecart_ordonnee;
                affiche_ligne(tmpX,tmpY,X,Y);
                affichage_noeud(s, X, Y, cercle_size);
                depth++;
            }

            else if ( s == "D") {
                fichier >> s;
                tmpX = X;
                tmpY = Y;
                X += (ecart_feuille*pow(2,(profondeur-depth)-2));
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

    fichier.close();
}

/* Permet d'afficher les arêtes de l'arbre */
void Affichage::affiche_ligne(int tmpX, int tmpY, int X, int Y) {
    QPainter paint(this);
    paint.drawLine(tmpX, tmpY, X, Y);
}

/* Affiche le sommet et son étiquette */
void Affichage::affichage_noeud(std::string s, int abs_X, int ord_Y, int taille_C) {
    QPainter paint(this);
    QPen pen(Qt::red, 5, Qt::SolidLine);
    paint.setPen(pen);
    paint.setFont(QFont("Calibri", 13));

    QString str = QString::fromStdString(s);
    
    paint.drawEllipse(abs_X - 2, ord_Y -2 , taille_C, taille_C);
    QPen pen1(Qt::black, 70, Qt::SolidLine);
    paint.setPen(pen1);
    paint.drawText(abs_X - 8, ord_Y -10, str);
}

/* Permet de faire l'affichage de l'arbre */
void Affichage::paintEvent(QPaintEvent* event) {
    const QRect &rect = event->rect();
    QPainter paint(this);
    paint.eraseRect(rect);
    paint.setRenderHint(QPainter::Antialiasing);
    lecture_fichier_arbre();
}

