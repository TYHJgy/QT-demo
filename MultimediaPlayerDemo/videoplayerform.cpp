#include "videoplayerform.h"
#include "ui_videoplayerform.h"

VideoPlayerForm::VideoPlayerForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VideoPlayerForm)
{
    ui->setupUi(this);

    m_player = new QMediaPlayer(this);
    m_player->setAudioRole(QAudio::VideoRole);
//    qInfo() << "Supported audio roles:";
    for (QAudio::Role role : m_player->supportedAudioRoles())
        qInfo() << "    " << role;
    // owned by PlaylistModel
    m_playlist = new QMediaPlaylist();
    m_player->setPlaylist(m_playlist);

//    m_videoWidget = new QVideoWidget(this);
    m_player->setVideoOutput(ui->widget);

//    ui->verticalLayout->addWidget(m_videoWidget,0);



}

VideoPlayerForm::~VideoPlayerForm()
{
    delete ui;
}

void VideoPlayerForm::on_start_clicked()
{
    QUrl url = QUrl("file:///C:/Users/gy/Videos/Captures/07d273289fad00218536ad9d4bdc83cd.mp4");
//    m_playlist->load(url);
    m_playlist->addMedia(url);
    m_playlist->setCurrentIndex(0);
    m_player->play();
}
