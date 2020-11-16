

#include <QApplication>
#include <QMessageBox>
#include "../headers/MainWindow.hpp"

int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    Context& context = Context::getInstance();

    MainWindow fenetre;
    fenetre.show();

    return app.exec();
}
