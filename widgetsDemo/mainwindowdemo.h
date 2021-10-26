#ifndef MAINWINDOWDEMO_H
#define MAINWINDOWDEMO_H

#include <QMainWindow>

namespace Ui {
class MainWindowDemo;
}

class MainWindowDemo : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindowDemo(QWidget *parent = nullptr);
    ~MainWindowDemo();

private:
    Ui::MainWindowDemo *ui;
};

#endif // MAINWINDOWDEMO_H
