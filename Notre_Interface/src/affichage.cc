#include "../header/affichage.hh"
#include <fstream>
#include <string>
Affichage::Affichage() {

}

QSize Affichage::sizeHint() const {
    return QSize(3000, 1500);
}
int Affichage::lecture_fichier_arbre() {
    std::ifstream fichier("fichier_arbre.txt");
    if (fichier) {
        std::string ligne;
        char c;
        while(getline(fichier, ligne)) {
            std::cout<<"getline\t";
            fichier.get(c);
            switch (c)
            {
            case 'R':
                std::cout<<"remontée\n";
                break;

            case 'G':
                std::cout<<"A gauche !\n";
                break;
            
            case 'D':
                std::cout<<"A droite !\n";
                break;

            default :
                std::cout<<"vide\n";
                break;
            }
        }

      
    }
    return 0;
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

     paint.drawEllipse(100,100,10,10);
    // paint.drawEllipse(300,100,10,10);

    // paint.drawLine(150,150,260,150);

    // paint.drawLine(150,150,110,160);
    // paint.drawLine(300,160,260,150);

    // paint.drawLine(110,80,90,90);
    lecture_fichier_arbre();

}

Affichage::~Affichage() {

}