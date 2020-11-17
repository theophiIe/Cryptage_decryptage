#if !defined(__AFFICHAGE__)
#define __AFFICHAGE__

#include <QtWidgets/QWidget>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtGui/QPainter>

class Affichage : public QWidget {
    private:

    public:
        Affichage();
        ~Affichage();
        
        void paintEvent(QPaintEvent *event);
        QSize sizeHint() const;
};

#endif