
#pragma once

#include <QApplication>
#include <QFrame>
#include <QGridLayout>
#include <QLabel>
#include <QPainter>
#include "Context.hpp"

/**
 * @brief Affichage principale de l'application
 *
 */
class ImageDisplayer : public QFrame {
private:
  QPixmap* png;
  QLabel* image;
public:

  ImageDisplayer();

  ~ImageDisplayer();
};