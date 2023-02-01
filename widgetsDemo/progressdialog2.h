#ifndef PROGRESSDIALOG2_H
#define PROGRESSDIALOG2_H


#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <QWidget>
#include <QTimer>
#include <QDebug>

class ProgressDialog2 : public QWidget
{
    Q_OBJECT
public:
    explicit ProgressDialog2(QWidget *parent = nullptr);
    ~ProgressDialog2();
signals:

private slots:
    void timeoutProcess();

private:
    QVBoxLayout *verticalLayout_2;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QProgressBar *progressBar;
    QTimer * timer;
};

#endif // PROGRESSDIALOG2_H
