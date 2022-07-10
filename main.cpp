#include <QApplication>
#include <QVBoxLayout>
#include <QSlider>

#include "ColorCircle.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    auto window = QWidget();


    auto *circle = new ColorFullCircle(nullptr);
    circle->setFixedSize(150, 150);

    auto *slider = new QSlider(Qt::Horizontal);
    slider->setMinimum(0);
    slider->setMaximum(100);
    slider->setTickPosition(QSlider::TicksAbove);
    slider->setTickInterval(33); /// 1/3 - границы состояния цвета кнопки
    slider->setFixedWidth(150);


    auto *boxLayout = new QVBoxLayout(&window);
    boxLayout->addWidget(circle);
    boxLayout->addWidget(slider);
    boxLayout->setSizeConstraint(QLayout::SetFixedSize);


    ///в примере к заданию приведен лаямбда захват [&slider, &circle], но вроде работает и без &slider.

    /// &circle нужен, что бы нужные методы (set-ы) вызвать, а параметр (int newValue) уже передался этим &slider-ом
    /// в момент коннекта и по идее слайдер сам по себе и не нужен, т.к. в лямбде я не вызываю slider.value().
    QObject::connect(slider, &QSlider::valueChanged, [&circle](int newValue) {

        if (newValue > 66) {circle->setRed();}
        else if (newValue > 33) {circle->setYellow();}
        else if (newValue >=0) {circle->setGreen();}
    });

    window.move(700, 400);
    window.show();

    return QApplication::exec();
}


