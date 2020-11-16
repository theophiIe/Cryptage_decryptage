
#include "../headers/PrenomDisplayer.hpp"
#include "../headers/Context.hpp"



PrenomDisplayer::PrenomDisplayer()
{

    layout = new QGridLayout();
    setLayout(layout);

    wInput_nom = new QLineEdit();
    wInput_nom->show();
    layout->addWidget(wInput_nom, 2, 0);

    wInput_prenom = new QLineEdit();
    wInput_prenom->show();
    layout->addWidget(wInput_prenom, 3, 0);

    wValider_nom = new QPushButton("Changer nom");
    wValider_nom->show();
    layout->addWidget(wValider_nom, 2, 1);

    wValider_prenom = new QPushButton("Changer Prenom");
    wValider_prenom->show();
    layout->addWidget(wValider_prenom, 3, 1);

    std::string tmp;


    tmp = "Nom : " + Context::getInstance().getNom();
    wNom = new QLabel(QString::fromStdString(tmp));
    wNom->show();
    layout->addWidget(wNom, 0, 0, 1, 3);

    tmp = "Prenom : " + Context::getInstance().getPrenom();
    wPrenom = new QLabel(QString::fromStdString(tmp));
    wPrenom->show();
    layout->addWidget(wPrenom, 1, 0, 1, 3);

    setFrameShape(Panel);
    setFrameShadow(Sunken);

    connect(wValider_nom, SIGNAL(clicked()), this, SLOT(setNom()));
    connect(wInput_nom, SIGNAL(returnPressed()), this, SLOT(setNom()));

    connect(wValider_prenom, SIGNAL(clicked()), this, SLOT(setPrenom()));
    connect(wInput_prenom, SIGNAL(returnPressed()), this, SLOT(setPrenom()));

    connect(&Context::getInstance(), SIGNAL(nomChanged()), this, SLOT(nomChanged()));
    connect(&Context::getInstance(), SIGNAL(prenomChanged()), this, SLOT(prenomChanged()));
}
PrenomDisplayer::~PrenomDisplayer()
{

}

void PrenomDisplayer::setNom()
{
    Context::getInstance().setNom(wInput_nom->text().toStdString());
}

void PrenomDisplayer::setPrenom()
{
    Context::getInstance().setPrenom(wInput_prenom->text().toStdString());
}

void PrenomDisplayer::nomChanged()
{
    std::string tmp = "Nom : " + Context::getInstance().getNom();
    wNom->setText(QString::fromStdString(tmp));
    wInput_nom->setText("");
}

void PrenomDisplayer::prenomChanged()
{
    std::string tmp = "Prenom : " + Context::getInstance().getPrenom();
    wPrenom->setText(QString::fromStdString(tmp));
    wInput_prenom->setText("");
}

