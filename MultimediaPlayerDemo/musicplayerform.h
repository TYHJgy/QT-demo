#ifndef MusicPlayerForm_H
#define MusicPlayerForm_H

#include <QWidget>
#include <QFileDialog>
#include <QMediaPlayer>
#include <QMediaPlaylist>

namespace Ui {
class MusicPlayerForm;
}

class MusicPlayerForm : public QWidget
{
    Q_OBJECT
private:
   QMediaPlayer   *player;//播放器
   QMediaPlaylist  *playlist;//播放列表
   QString  durationTime;//总长度
   QString  positionTime;//当前播放到的位置

public:
    explicit MusicPlayerForm(QWidget *parent = nullptr);
    ~MusicPlayerForm();

private slots:

    void on_addSong_clicked();

    void on_start_player_clicked();
    //自定义槽函数
    void onStateChanged(QMediaPlayer::State state);
    void onPlaylistChanged(int position);
    void onDurationChanged(qint64 duration);
    void onPositionChanged(qint64 position);


    void on_pause_player_clicked();

    void on_stop_player_clicked();

    void on_listWidget_doubleClicked(const QModelIndex &index);

    void on_next_clicked();


    void on_previous_clicked();


    void on_sliderPosition_sliderReleased();

    void on_btnSound_clicked();


    void on_sliderVolumn_valueChanged(int value);

    void on_clearSong_clicked();

//    void on_removeSong_clicked();

private:
    Ui::MusicPlayerForm *ui;
};

#endif // MusicPlayerForm_H
