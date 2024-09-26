#ifndef CUSTOMBUTTON_H
#define CUSTOMBUTTON_H

#include <QPushButton>

class CustomButton : public QPushButton
{
    Q_OBJECT
public:
    explicit CustomButton(QWidget *parent = nullptr);

protected:
    void mousePressEvent(QMouseEvent *event);

private:
    void onButtonCliecked();
};

#endif // CUSTOMBUTTON_H
