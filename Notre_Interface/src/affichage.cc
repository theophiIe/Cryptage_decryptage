#include "../header/affichage.hh"
#include <fstream>
#include <string>
Affichage::Affichage() {

}

QSize Affichage::sizeHint() const {
    return QSize(3000, 1500);
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
                std::cout<<"remontée\n";
                X -= (ecart_feuille/depth);
                Y -= ecart_ordonnee;
                
            }
            else if ( s == "RD") {
                depth--;
                std::cout<<"remontée\n";
                X += (ecart_feuille/depth);
                Y -= ecart_ordonnee;
                
            }

            else if ( s == "G") {
                fichier >> s;
                std::cout<<"A gauche : "<<s<<std::endl;
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
                std::cout<<"A droite : "<<s<<std::endl;
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
    QPen pen(Qt::red, 70, Qt::SolidLine);
    paint.setPen(pen);
    paint.setFont(QFont("Calibri", 25));

    QString str = QString::fromStdString(s);
    
    paint.drawEllipse(abs_X, ord_Y, taille_C, taille_C);
    QPen pen1(Qt::black, 70, Qt::SolidLine);
    paint.setPen(pen1);
    paint.drawText(abs_X - 8, ord_Y -4, str);

    

}


template<typename T>
void Affichage::paintFils(ArbreB<T> &arbre, int X, int Y) {
    QPainter paint(this);
        
    paint.drawEllipse(racineX, racineY,cercle_size,cercle_size);

   //  if (arbre.existe_fils_gauche())   {
        X = X - ecart_feuille;
        Y = Y + ecart_ordonnee;
        paint.drawEllipse(X, Y,cercle_size,cercle_size);
     //   arbre.deplacementG();
        std::cout<<"print1\n";
        paintFils(arbre, X, Y);
         std::cout<<"print\n";
  //  }
    X = X + ecart_feuille;
    Y = Y - ecart_ordonnee;


  //   if (arbre.existe_fils_droit())   {
        X = X + ecart_feuille;
        Y = Y + ecart_ordonnee;
        paint.drawEllipse(X, Y,cercle_size,cercle_size);
       // arbre.deplacementD();
        std::cout<<"print2\n";
        paintFils(arbre, X, Y);
         std::cout<<"print\n";
   // }
    X = X - ecart_feuille;
    Y = Y - ecart_ordonnee;
    std::cout<<"Remontadaaaaa x\n";
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
    
    // QRect rect(0, 0, 170, 45);
    // paint.drawText(rect, Qt::AlignCenter, *Bouton::contenu_fichier);

    // paint.drawEllipse(100,100,10,10);
    // paint.drawEllipse(300,100,10,10);

    // paint.drawLine(150,150,260,150);

    // paint.drawLine(150,150,110,160);
    // paint.drawLine(300,160,260,150);

    // paint.drawLine(110,80,90,90);
    lecture_fichier_arbre();

}

Affichage::~Affichage() {

}