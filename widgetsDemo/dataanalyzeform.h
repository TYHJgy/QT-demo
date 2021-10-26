#ifndef DATAANALYZEFORM_H
#define DATAANALYZEFORM_H

#include <QWidget>

namespace Ui {
class DataAnalyzeForm;
}

class DataAnalyzeForm : public QWidget
{
    Q_OBJECT

public:
    explicit DataAnalyzeForm(QWidget *parent = nullptr);
    ~DataAnalyzeForm();

private:
    Ui::DataAnalyzeForm *ui;
};

#endif // DATAANALYZEFORM_H
