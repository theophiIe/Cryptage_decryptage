#include "../header/affichage.hh"

Affichage::Affichage() {

}

QSize Affichage::sizeHint() const {
    return QSize(3000, 1500);
}

void Affichage::paintEvent(QPaintEvent* event) {
    QPainter paint(this);
    
    // QRect rect(0, 0, 170, 45);
    // paint.drawText(rect, Qt::AlignCenter, *Bouton::contenu_fichier);

    paint.drawEllipse(100,100,10,10);
    paint.drawEllipse(300,100,10,10);

    paint.drawLine(150,150,260,150);

    paint.drawLine(150,150,110,160);
    paint.drawLine(300,160,260,150);

    paint.drawLine(110,80,90,90);
}

Affichage::~Affichage() {

}