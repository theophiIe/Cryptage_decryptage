

#pragma once

#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QBoxLayout>
#include <QFrame>

 /**
  * @brief Menu principal de l'application
  *
  */
class MainMenu : public QFrame {
private:
  QPushButton* bReinitialiser;
  QPushButton* bQuitter;
  QHBoxLayout* layout;

public:

  MainMenu();
  ~MainMenu();
};
