#if !defined(__BOUTON__)
#define __BOUTON__

#include <iostream>
#include <QtWidgets/QWidget>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QMenu>
#include <QtCore/QObject>

// #include <QtWidgets/QApplication>
// #include <QtWidgets/QMainWindow>
// #include <QtWidgets/QPushButton>
// #include <QtWidgets/QGridLayout>
// #include <QtWidgets/QScrollArea>
// #include <QtWidgets/QMessageBox>
// #include <QtWidgets/QLineEdit>
// #include <QtWidgets/QFrame>
// #include <QtGui/QPainter>
// #include <QtGui/QFontMetrics>
// #include <QtCore/QFile>
// #include <QtCore/QTextStream>
// #include <QtWidgets/QTextEdit>
// #include <iostream>

class Bouton : public QWidget {
    Q_OBJECT

    private:
        QGridLayout *layout;
        QPushButton *bQuitter;
        QPushButton *bTest;
        QPushButton *bArbre;

        // QAction *test1;
        // QAction *test2;
        // QAction *test3;
        // QAction *test4;

    public:
        Bouton();
        ~Bouton();

    public slots:
        void aff_test1();
};

#endif