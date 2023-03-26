#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //setWindowFlag(Qt::WA_DeleteOnClose);

    ui->textEdit->setReadOnly(1);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setEnabledInCustomWidgets(bool bButton, bool bSlider, bool bDial) {
    ui->widget->setEnabled(bButton, bSlider, bDial);
    ui->widget_2->setEnabled(bButton, bSlider, bDial);
}

void MainWindow::on_radioButton_clicked()
{
   setEnabledInCustomWidgets(ui->radioButton->isChecked(), ui->radioButton_2->isChecked(), ui->radioButton_3->isChecked());
}


void MainWindow::on_radioButton_2_clicked()
{
    setEnabledInCustomWidgets(ui->radioButton->isChecked(), ui->radioButton_2->isChecked(), ui->radioButton_3->isChecked());
}


void MainWindow::on_radioButton_3_clicked()
{
    setEnabledInCustomWidgets(ui->radioButton->isChecked(), ui->radioButton_2->isChecked(), ui->radioButton_3->isChecked());
}

int MainWindow::generationRandomValue(int leftValue, int rightValue)
{
    //srand((unsigned int)time(0));
    return ( leftValue + (rightValue - leftValue) * (double)(rand())/RAND_MAX );
}

void MainWindow::insertTextRedColor(const QString str)
{
    ui->textEdit->clear();
    ui->textEdit->setTextColor( Qt::red );
    ui->textEdit->insertPlainText("ОШИБКА -->" + str);
    ui->textEdit->setTextColor( Qt::black );
}

void MainWindow::insertText(const QString str, bool flag)
{
    if (flag)
    {
        ui->textEdit->insertPlainText(str);
    }
    else
    {
        ui->textEdit->insertPlainText("\n" + str);
    }
}

void MainWindow::outputArrayTextEdit(QVector<int> &arr)
{
    insertText("Исходный массив:\n", 0);
    for(auto i: arr)
    {
        insertText(QString::number(i) + " ");
    }
}

void MainWindow::taskA(const size_t size, const int C)
{
    ui->textEdit->clear();
    QVector<int> randowValues;
    for (size_t i = 0; i < size; i++)
    {
        randowValues.append(generationRandomValue(ui->widget->getValueLineEdit(), ui->widget_2->getValueLineEdit()));
    }

    outputArrayTextEdit(randowValues);

    if (ui->checkBox->isChecked())
    {
        std::ofstream file(str_file);

        for (auto it : randowValues)
        {
            if (it > C)
            {
                file << it << " ";
            }
        }
        file.close();
        insertText("Данные были записанные в файл", 0);
    }
    else
    {
        insertText("Вывод чисел по заданию А:\n", 0);
        for (auto it: randowValues)
        {
            if (it > C)
            {
                insertText(QString::number(it) + " ");
            }
        }
    }
}

void MainWindow::taskB(const size_t size)
{
    ui->textEdit->clear();
    QVector<int> randowValues;
    for (size_t i = 0; i < size; i++)
    {
        randowValues.append(generationRandomValue(ui->widget->getValueLineEdit(), ui->widget_2->getValueLineEdit()));
    }

    outputArrayTextEdit(randowValues);

    auto max_abs = [](int x, int y)
    {
        return (y < 0 ? y : -y) < (x < 0 ? x : -x);
    };

    auto maximum = std::max_element(std::begin( randowValues ), std::end( randowValues ), max_abs);

    int product = 1;

    for(auto it = ++maximum; it != randowValues.end(); it++ )
    {
        product *= *it;
    }

    if (ui->checkBox->isChecked())
    {
        std::ofstream file("file1.txt");
        file << product;
        file.close();
        insertText("Данные были записанные в файл", 0);
    }
    else
    {
        insertText("Вывод числа по заданию B: ", 0);
        insertText(QString::number(product));
    }
}

void MainWindow::on_pushButton_clicked()
{

    if(ui->lineEdit->text().toInt() <= 0)
    {
        //TODO (\/)
        //Вывести ошибку красным текстом, что размер меньше 0
        insertTextRedColor("Введите размер массива >0");
    }
    else if (ui->radioButton_5->isChecked())
    {
        taskA(ui->lineEdit->text().toInt(), ui->lineEdit_2->text().toInt());
    }
    else if (ui->radioButton_4->isChecked())
    {
        taskB( ui->lineEdit->text().toInt() );
    }
    else
    {
        insertTextRedColor("Выберите задания а) или б)");
    }
}
