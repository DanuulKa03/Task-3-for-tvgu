#include "mywidgetnew.h"

MyWidgetNEW::MyWidgetNEW(QWidget *parent)
    : QWidget{parent}
{
    setFixedSize(100, 110);

    //Object
    textLine1 = new QLineEdit;
    //TODO Добавить валидатор (\/)
    //textLine1->setValidator(new QRegularExpressionValidator(QRegularExpression("^([1-9][0-9]*|0)"), this));
    textLine1->setValidator(new QRegularExpressionValidator(QRegularExpression("^((-[1-9]|[1-9])[0-9][0-9]|0)"), this));

    textLine1->setMaxLength(4);


    buttonPlus = new QPushButton(QIcon(":/icon/plus.jpg"), "");
    buttonMinus = new QPushButton(QIcon(":/icon/minus.png"), "");

    slider = new QSlider(Qt::Horizontal);
    slider->setValue(minRange);
    slider->setMaximum(maxRange);
    slider->setMinimum(minRange);

    dial = new QDial();
    dial->setMaximum(maxRange);
    dial->setMinimum(minRange);

    QGridLayout *layout = new QGridLayout;
    layout->setVerticalSpacing(0);
    layout->setHorizontalSpacing(0);
    layout->addWidget(textLine1, 0, 0, 2, 1);
    layout->addWidget(buttonPlus, 0, 1);
    layout->addWidget(buttonMinus, 1, 1);
    layout->addWidget(slider, 2, 0, 2, 1);
    layout->addWidget(dial, 4, 0, 4, 1);

    setLayout(layout);

    QObject::connect(buttonPlus, &QPushButton::clicked, this, &MyWidgetNEW::setValueButtonPlus);
    QObject::connect(buttonMinus, &QPushButton::clicked, this, &MyWidgetNEW::setValueButtonMinus);

    QObject::connect(slider, &QSlider::valueChanged, this, [=]()
    {
        setValueSlider(slider->value());
    });

    QObject::connect(dial, &QDial::valueChanged, this, [=]()
    {
        setValueDial(dial->value());
    });

    //Реализация обратной связи qlineedit
    QObject::connect(textLine1, &QLineEdit::textChanged, this, &MyWidgetNEW::reactionPressing);
}

int MyWidgetNEW::getValue()
{
    return value;
}

int MyWidgetNEW::getValueLineEdit()
{
    return textLine1->text().toInt();
}

void MyWidgetNEW::setEnabled(bool bButton, bool bSlider, bool bDial) {
   buttonPlus->setEnabled(bButton);
   buttonMinus->setEnabled(bButton);
   slider->setEnabled(bSlider);
   dial->setEnabled(bDial);
}

void MyWidgetNEW::setValueButtonPlus()
{
    int temp = textLine1->text().toInt();
    textLine1->setText(QString::number(++temp));
}

void MyWidgetNEW::setValueButtonMinus()
{
    int temp = textLine1->text().toInt();
    textLine1->setText(QString::number(--temp));
}

void MyWidgetNEW::setValueSlider(int value)
{
    textLine1->setText(QString::number(value));
}

void MyWidgetNEW::setValueDial(int value)
{
    textLine1->setText(QString::number(value));
}

void MyWidgetNEW::reactionPressing()
{
    value = textLine1->text().toInt();
    slider->setValue(value);
    dial->setValue(value);
//    qDebug() << "Value" << value;
//    qDebug() << "Value Slider:" << slider->value();
}
