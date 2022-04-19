#ifndef AUDIORECORDERFORM_H
#define AUDIORECORDERFORM_H

#include <QWidget>

namespace Ui {
class AudioRecorderForm;
}

class AudioRecorderForm : public QWidget
{
    Q_OBJECT

public:
    explicit AudioRecorderForm(QWidget *parent = nullptr);
    ~AudioRecorderForm();

private:
    Ui::AudioRecorderForm *ui;
};

#endif // AUDIORECORDERFORM_H
