
#pragma once

#include <QWidget>
#include <QPixmap>
#include <QPaintEvent>

class ColorFullCircle : public QWidget
{
    Q_OBJECT

public:
    ColorFullCircle() = default;
    ColorFullCircle(QWidget *parent);

    ~ColorFullCircle() override;

    void paintEvent(QPaintEvent *event) override;

    void setRed();
    void setYellow();
    void setGreen();

private:
    QPixmap mButtonCurrent;
    QPixmap mButtonRed;
    QPixmap mButtonGreen;
    QPixmap mButtonYellow;

};
#include <main.moc>

