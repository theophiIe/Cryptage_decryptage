#if !defined(__AFFICHAGE__)
#define __AFFICHAGE__

#include <QtWidgets/QWidget>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtGui/QPainter>
#include "bouton.hh"

class Affichage : public QWidget {
    private:

    public:
        Affichage();
        ~Affichage();
        
        void paintEvent(QPaintEvent *event);
        QSize sizeHint() const;
};

#endif