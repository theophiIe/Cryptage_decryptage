

#pragma once
#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QScrollArea>
#include <QMessageBox>
#include <QLineEdit>

#include "MainMenu.hpp"
#include "ImageDisplayer.hpp"
#include "PrenomDisplayer.hpp"

/**
 * @brief Fenetre principale du programme
 *
 */
class MainWindow : public QWidget {

    // On prépare l'utilsation des Slot et Signaux
    Q_OBJECT

private:

    MainMenu* wMenu;
    // Agencement en grille
    QGridLayout* layout;

    ImageDisplayer* wAffiche_image;
    // zone avec barre de scroll
    QScrollArea* wZone_dessin;

    PrenomDisplayer* wAffiche_prenom;

public:

    /**
     * @brief Construct a new Main Window object
     *
     */
    MainWindow();
    /**
     * @brief Destroy the Main Window object
     *
     */
    ~MainWindow();

public slots:
    /**
     * @brief Slot pour recuperer le sinal "Appuyé sur entrée"
     *
     */
    void textEntered();

signals:

};
