#ifndef STANDARDITEMWINDOW_H
#define STANDARDITEMWINDOW_H

#include <QMainWindow>

namespace Ui {
class StandardItemWindow;
}

class StandardItemWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit StandardItemWindow(QWidget *parent = nullptr);
    ~StandardItemWindow();

private:
    Ui::StandardItemWindow *ui;
};

#endif // STANDARDITEMWINDOW_H
