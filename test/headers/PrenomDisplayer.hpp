
#pragma once

#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QFrame>
#include <QLineEdit>
#include <QLabel>

 /**
  * @brief affichage et modification du prénoms et du nom
  *
  */
class PrenomDisplayer : public QFrame {

    Q_OBJECT

private:
    QGridLayout* layout;

    QLineEdit* wInput_nom;
    QLineEdit* wInput_prenom;

    QPushButton* wValider_nom;
    QPushButton* wValider_prenom;

    QLabel* wNom;
    QLabel* wPrenom;

public:

    PrenomDisplayer();
    ~PrenomDisplayer();

public slots:
    /**
     * @brief Set the Nom
     * 
     */
    void setNom();
    /**
     * @brief Set the Prenom
     * 
     */
    void setPrenom();

    /**
     * @brief Update the label if the nom changed
     * 
     */
    void nomChanged();

    /**
     * @brief Update the label if the prenom changed
     * 
     */
    void prenomChanged();

signals:

};