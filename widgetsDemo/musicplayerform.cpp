
#include "musicplayerform.h"
#include "ui_musicplayerform.h"
#include <QDebug>

MusicPlayerForm::MusicPlayerForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MusicPlayerForm)
{
    ui->setupUi(this);
    player = new QMediaPlayer(this);//播放器
      playlist = new QMediaPlaylist(this);//播放列表
      playlist->setPlaybackMode(QMediaPlaylist::Loop); //循环模式
      player->setPlaylist(playlist);

      connect(player,SIGNAL(stateChanged(QMediaPlayer::State)),
            this, SLOT(onStateChanged(QMediaPlayer::State)));
      connect(player,SIGNAL(positionChanged(qint64)),
            this, SLOT(onPositionChanged(qint64)));
      connect(player,SIGNAL(durationChanged(qint64)),
            this, SLOT(onDurationChanged(qint64)));
      connect(playlist,SIGNAL(currentIndexChanged(int)),
            this, SLOT(onPlaylistChanged(int)));

}

MusicPlayerForm::~MusicPlayerForm()
{
    delete ui;
}

//歌曲列表——添加歌曲
void MusicPlayerForm::on_addSong_clicked()
{
    qDebug() << "enter on_addSong_clicked";
    //添加文件
    QString curPath=QDir::homePath();//获取用户目录
    QString dlgTitle="选择音频文件";
    QString filter="音频文件(*.mp3 *.wav *.wma);;mp3文件(*.mp3);;wav文件(*.wav);;wma文件(*.wma);;所有文件(*.*)";
    QStringList fileList=QFileDialog::getOpenFileNames(this, dlgTitle, curPath, filter);
    if (fileList.count()<1)
       return;
    for (int i=0; i<fileList.count();i++)
    {
      QString aFile=fileList.at(i);
      playlist->addMedia(QUrl::fromLocalFile(aFile));//添加文件
      QFileInfo   fileInfo(aFile);
      ui->listWidget->addItem(fileInfo.fileName());//添加到界面文件列表
    }

}

//开始播放
void MusicPlayerForm::on_start_player_clicked()
{
    qDebug() << "enter on_start_player_clicked";

    if (player->state()!=QMediaPlayer::PlayingState)
       playlist->setCurrentIndex(0);
    player->play();
}

void MusicPlayerForm::onStateChanged(QMediaPlayer::State state)
{
    qDebug() << "enter onStateChanged";
    //播放器状态变化，更新按钮状态
    ui->start_player->setEnabled(!(state==QMediaPlayer::PlayingState));
    ui->pause_player->setEnabled(state==QMediaPlayer::PlayingState);
    ui->stop_player->setEnabled(state==QMediaPlayer::PlayingState);
}



void MusicPlayerForm::onPlaylistChanged(int position)
{
    qDebug() << "enter onPlaylistChanged";
    //播放列表变化,更新当前播放文件名显示
    ui->listWidget->setCurrentRow(position);
    QListWidgetItem  *item=ui->listWidget->currentItem();
    if (item)
        ui->LabCurMedia->setText(item->text());
}
void MusicPlayerForm::onDurationChanged(qint64 duration)
{
    qDebug() << "enter onDurationChanged";
    //文件时长变化，更新进度显示
    ui->sliderPosition->setMaximum(duration);
    int   secs=duration/1000;//秒
    int   mins=secs/60; //分钟
    secs=secs % 60;//余数秒
    durationTime=QString::asprintf("%d:%d",mins,secs);
    ui->LabRatio->setText(positionTime+"/"+durationTime);
}
void MusicPlayerForm::onPositionChanged(qint64 position)
{
    //qDebug() << "enter onPositionChanged";
    //当前文件播放位置变化，更新进度显示
    if (ui->sliderPosition->isSliderDown())//正处于手动调整状态，不处理
        return;
    ui->sliderPosition->setSliderPosition(position);
    int   secs=position/1000;//秒
    int   mins=secs/60; //分钟
    secs=secs % 60;//余数秒
    positionTime=QString::asprintf("%d:%d",mins,secs);
    ui->LabRatio->setText(positionTime+"/"+durationTime);
}

//暂停播放
void MusicPlayerForm::on_pause_player_clicked()
{
    player->pause();
}

//停止播放
void MusicPlayerForm::on_stop_player_clicked()
{
    player->stop();
}

//播放进度调整
void MusicPlayerForm::on_sliderPosition_sliderReleased()
{
    qDebug() << "enter on_sliderPosition_sliderReleased";
    qDebug() << "position:" << ui->sliderPosition->sliderPosition();
    qDebug() << "value:" << ui->sliderPosition->value();
    player->setPosition(ui->sliderPosition->value());
}

//双击时切换播放文件
void MusicPlayerForm::on_listWidget_doubleClicked(const QModelIndex &index)
{
    int rowNo=index.row();
    playlist->setCurrentIndex(rowNo);
    player->play();
}

void MusicPlayerForm::on_next_clicked()
{
    qDebug() << "enter on_next_clicked";
    qDebug() << playlist->currentIndex();
    playlist->next();
    qDebug() << playlist->currentIndex();
}


void MusicPlayerForm::on_previous_clicked()
{
    qDebug() << "enter on_previous_clicked";
    qDebug() << playlist->currentIndex();
    playlist->previous();
    qDebug() << playlist->currentIndex();
}


void MusicPlayerForm::on_btnSound_clicked()
{//静音控制
   bool mute=player->isMuted();
   player->setMuted(!mute);
   if (mute)
      ui->btnSound->setIcon(QIcon(":/images/images/volumn.bmp"));
   else
      ui->btnSound->setIcon(QIcon(":/images/images/mute.bmp"));
}

//调整音量
void MusicPlayerForm::on_sliderVolumn_valueChanged(int value)
{
   player->setVolume(value);
}

//移除一个文件
void MusicPlayerForm::on_removeSong_clicked()
{
   int pos=ui->listWidget->currentRow();
   QListWidgetItem *item=ui->listWidget->takeItem(pos);
   delete item;//从listWidget里删除
   playlist->removeMedia(pos); //从播放列表里删除
}

//清空列表
void MusicPlayerForm::on_clearSong_clicked()
{
   playlist->clear();
   ui->listWidget->clear();
   player->stop();
}


