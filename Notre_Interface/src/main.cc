#include <iostream>
#include <QtWidgets/QApplication>

#include "../header/fenetre.hh"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Fenetre fen;
    fen.show();

    return app.exec(); 
}
