#pragma once


#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QPainter>

/**
 * @brief Fenetre principale du programme
 * 
 */
class MaFenetre : public QWidget {
private:

public:
    /**
     * @brief Construct a new Ma Fenetre object
     * 
     */
    MaFenetre()
    {

    }

    /**
     * @brief Redessine la fenetre
     * 
     * @param event 
     */
    void paintEvent(QPaintEvent* event)
    {
        // Declare un outil de peinture
        QPainter paint(this);

        // Recupere la taille en X de "Mon texte"
        int taille_x = paint.fontMetrics().width("Mon texte") + 10;

        // Recupere la taille Y d'un texte
        int taille_y = paint.fontMetrics().height() + 5;

        for (int i = 0; i < 500; i++)
        {
            // Affiche un texte
            paint.drawText(50, 50 + i * 25, "Mon texte");

            // Affiche un rectangle
            paint.drawRect(45, 40 - taille_y / 2 + i * 25, taille_x, taille_y);
        }


    }

    /**
     * @brief Destroy the Ma Fenetre object
     * 
     */
    ~MaFenetre()
    {

    }
};
