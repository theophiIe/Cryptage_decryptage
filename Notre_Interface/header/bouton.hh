#if !defined(__BOUTON__)
#define __BOUTON__

#include <iostream>
#include <QtWidgets/QWidget>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>
#include <QtCore/QObject>
#include <QtCore/QTextStream>
#include <QtCore/QFile>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QScrollArea>

class Bouton : public QWidget {
    Q_OBJECT

    private:
        QGridLayout *layout_bouton;
        QGridLayout *layout_text;
        QGridLayout *layout_englobant;
        QPushButton *bQuitter;
        QPushButton *bTest;
        QScrollArea *scoller;
        QTextEdit *texte;

    public:
        Bouton();
        ~Bouton();
        

    public slots:
        void aff_test();
};

#endif