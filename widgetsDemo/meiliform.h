#ifndef MEILIFORM_H
#define MEILIFORM_H

#include <QWidget>

namespace Ui {
class MeiliForm;
}

class MeiliForm : public QWidget
{
    Q_OBJECT

public:
    explicit MeiliForm(QWidget *parent = nullptr);
    ~MeiliForm();

private slots:
    void on_MeiliForm_customContextMenuRequested(const QPoint &pos);

private:
    Ui::MeiliForm *ui;
};

#endif // MEILIFORM_H
