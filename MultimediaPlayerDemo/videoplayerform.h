#ifndef VIDEOPLAYERFORM_H
#define VIDEOPLAYERFORM_H

#include <QWidget>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QVideoWidget>
#include <QDir>
#include <QFileDialog>

namespace Ui {
class VideoPlayerForm;
}

class VideoPlayerForm : public QWidget
{
    Q_OBJECT

public:
    explicit VideoPlayerForm(QWidget *parent = nullptr);
    ~VideoPlayerForm();

private slots:

    void on_start_clicked();

private:
    Ui::VideoPlayerForm *ui;

    QMediaPlayer *m_player = nullptr;
    QMediaPlaylist *m_playlist = nullptr;
    QVideoWidget * m_videoWidget = nullptr;
};

#endif // VIDEOPLAYERFORM_H
