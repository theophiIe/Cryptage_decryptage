#if !defined(__FENETRE__)
#define __FENETRE__

#include <QtWidgets/QWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QApplication>
#include <QtWidgets/QScrollArea>

class Fenetre : public QWidget {
    private:
        QGridLayout *layout;
        QPushButton *bQuitter;
        QPushButton *bTest;
        QPushButton *bArbre;
        QScrollArea *scrollbar;

    public:
        Fenetre();
        ~Fenetre();
};

#endif