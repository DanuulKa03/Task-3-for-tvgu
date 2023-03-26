#ifndef MYWIDGETNEW_H
#define MYWIDGETNEW_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QSlider>
#include <QPushButton>
#include <QValidator>
#include <QDial>
#include <QRegularExpressionValidator>
#include <QRegularExpression>
#include <QDebug>

class MyWidgetNEW : public QWidget
{
    Q_OBJECT
public:
    explicit MyWidgetNEW(QWidget *parent = nullptr);

    int getValue();
    int getValueLineEdit();

    void setEnabled(bool bButton, bool bSlider, bool bDial);
private:
    QLineEdit *textLine1;
    QPushButton *buttonPlus;
    QPushButton *buttonMinus;
    QSlider *slider;
    QDial *dial;

    const int maxRange = 100;
    const int minRange = -100;
    int value = 0;

    //void setValue();
    void setValueButtonPlus();
    void setValueButtonMinus();
    void setValueSlider(int value);
    void setValueDial(int value);

    //TODO (|/)
    //сделай так, чтобы при изменение диапозона другими способами, слайдер перемещался сам по себе, то есть чтобы qlineedit излучал постоянный сигнал
    void reactionPressing();
};

#endif // MYWIDGETNEW_H
