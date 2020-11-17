#if !defined(__AFFICHAGE__)
#define __AFFICHAGE__

#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtGui/QPainter>

class Affichage : QFrame {
    private:
        QPixmap *png;
        QLabel *image;

    public:
        Affichage();
        ~Affichage();
        
        void paintEvent(QPaintEvent *event);
        QSize sizeHint() const;
};

#endif