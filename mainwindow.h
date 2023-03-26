#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtContainerFwd>
#include <QDebug>
#include <fstream>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_3_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    std::string str_file = "file1.txt";

    void setEnabledInCustomWidgets(bool bButton, bool bSlider, bool bDial);
    //генерирует случайные числа от/до
    int generationRandomValue(int leftValue, int rightValue);
    void insertTextRedColor(QString str);
    //по стандарту печатает без "\n"
    void insertText(const QString str, bool flag = true);
    //выводит массив в textedit
    void outputArrayTextEdit(QVector<int> &arr);
    //вызов методов для заданий
    void taskA(const size_t size, const int C);
    void taskB(const size_t size);
    //TODO
    //Написать метод, который записывает результат в файл

    //TODO (\/)
    //Написать метод, который выводит красным цветом уведомление об ошибке в textedit

};
#endif // MAINWINDOW_H
