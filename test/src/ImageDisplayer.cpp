#include "../headers/ImageDisplayer.hpp"


ImageDisplayer::ImageDisplayer()
{
    png = new QPixmap("../pomme.png");
    setFixedSize(2000, 2000);
    image = new QLabel(this);
    image->setPixmap(*png);

    // On dit au Label de se centrer
    image->setAlignment(Qt::AlignCenter);
    image->show();
}

ImageDisplayer ::~ImageDisplayer()
{

}
