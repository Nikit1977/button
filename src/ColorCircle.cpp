#include <QPainter>
#include "ColorCircle.h"

ColorFullCircle::ColorFullCircle(QWidget *parent) {

    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    mButtonRed = QPixmap("..\\images\\red_button.png");
    mButtonGreen = QPixmap("..\\images\\green_button.png");
    mButtonYellow = QPixmap("..\\images\\yellow_button.png");
    mButtonCurrent = mButtonGreen;

}

ColorFullCircle::~ColorFullCircle() {};

void ColorFullCircle::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    p.drawPixmap(event->rect(), mButtonCurrent);
}

void ColorFullCircle::setRed()
{
    mButtonCurrent = mButtonRed;
    update();
}

void ColorFullCircle::setYellow()
{
    mButtonCurrent = mButtonYellow;
    update();
}

void ColorFullCircle::setGreen()
{
    mButtonCurrent = mButtonGreen;
    update();
}