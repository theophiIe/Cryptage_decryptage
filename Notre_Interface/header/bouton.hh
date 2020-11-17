#if !defined(__BOUTON__)
#define __BOUTON__

#include <QtWidgets/QWidget>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>

class Bouton : public QWidget {
    private:
        QGridLayout *layout;
        QPushButton *bQuitter;
        QPushButton *bTest;
        QPushButton *bArbre;

    public:
        Bouton();
        ~Bouton();
};

#endif