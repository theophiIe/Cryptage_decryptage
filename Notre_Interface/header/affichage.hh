#if !defined(__AFFICHAGE__)
#define __AFFICHAGE__

#include <QtWidgets/QFrame>
#include <QtWidgets/QScrollArea>

class Affichage : QFrame {
    private:
        QScrollArea *scrollbar;
    public:
        Affichage();
        ~Affichage();
};

#endif