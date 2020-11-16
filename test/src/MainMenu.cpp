
#include "../headers/MainMenu.hpp"
#include "../headers/Context.hpp"


MainMenu::MainMenu()
{
    layout = new QHBoxLayout();
    setLayout(layout);
    layout->setAlignment(Qt::AlignTop);

    bReinitialiser = new QPushButton("Reinitialiser le prenom et le nom", this);
    bReinitialiser->show();
    layout->addWidget(bReinitialiser);

    bQuitter = new QPushButton("Quitter", this);
    bQuitter->show();
    layout->addWidget(bQuitter);

    // On défini le style de Frame
    setFrameShape(Panel);
    // On défini l'ombre de frame
    setFrameShadow(Sunken);
    setMaximumHeight(75);

    // On connect le bouton quitter au quitter de l'application Qt
    connect(bQuitter, SIGNAL(clicked()), qApp, SLOT(quit()));
    connect(bReinitialiser, SIGNAL(clicked()), &Context::getInstance(), SLOT(resetNom()));
    connect(bReinitialiser, SIGNAL(clicked()), &Context::getInstance(), SLOT(resetPrenom()));
}

MainMenu::~MainMenu()
{

}
