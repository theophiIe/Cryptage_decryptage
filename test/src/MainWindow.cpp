
#include "../headers/MainWindow.hpp"

/**
 * @brief Construct a new Main Window object
 *
 */
MainWindow::MainWindow()
{
  layout = new  QGridLayout();
  setLayout(layout);

  wAffiche_image = new ImageDisplayer();
  wAffiche_image->show();

  // On créer une zone avec défilement
  wZone_dessin = new QScrollArea();
  wZone_dessin->setWidget(wAffiche_image);
  wZone_dessin->show();
  wZone_dessin->setMinimumSize(500, 500);
  layout->addWidget(wZone_dessin, 0, 0);

  wAffiche_prenom = new PrenomDisplayer();
  wAffiche_prenom->show();
  layout->addWidget(wAffiche_prenom, 2, 0);

  wMenu = new MainMenu();
  wMenu->show();
  layout->addWidget(wMenu, 3, 0);

}
/**
 * @brief Destroy the Main Window object
 *
 */
MainWindow::~MainWindow()
{

}
/**
 * @brief Slot pour recuperer le sinal "Appuyé sur entrée"
 *
 */
void MainWindow::textEntered()
{
}
