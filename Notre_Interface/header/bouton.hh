#if !defined(__BOUTON__)
#define __BOUTON__

#include <iostream>
#include <QtWidgets/QWidget>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QMenu>

class Bouton : public QWidget {
    private:
        QGridLayout *layout;
        QPushButton *bQuitter;
        QPushButton *bTest;
        QPushButton *bArbre;

    public:
        Bouton();
        ~Bouton();

    public slots:
        void aff_test1();
        void aff_test2();
        void aff_test3();
        void aff_test4();
};

#endif