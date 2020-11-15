#include <iostream>
#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include "fenetre.hpp"

int main(int argc, char** argv) {

    QApplication app(argc, argv);

    MaFenetre truc;
    truc.show();

    return app.exec();
}


