#ifndef MOVIEPLAY_H
#define MOVIEPLAY_H

#include <QWidget>
#include <QMediaPlaylist>
#include <QMediaPlayer>
#include <QVBoxLayout>
#include <QVideoWidget>
#include <QFileDialog>
#include <QListWidgetItem>
#include <QEvent>
#include <QtXml>
#include <QFile>
#include <QIODevice>
#include <QDomNodeList>
#include <QKeyEvent>
#include <QDebug>


namespace Ui {
class MoviePlay;
}

class MoviePlay : public QWidget
{
    Q_OBJECT

public:
    explicit MoviePlay(QWidget *parent = 0);
    ~MoviePlay();

private slots:
    void on_pushButtonStop_clicked();

    void on_pushButtonHide_clicked();

    void on_pushButtonFile_clicked();

    void on_listWidget_doubleClicked(const QModelIndex &index);

    void on_pushButtonZXMovie_clicked();

    void on_horizontalSlider_valueChanged(int value);

    void on_pushButtonKuaiTui_clicked();

    void valueChange(qint64 position);

    void on_horizontalSlider_sliderPressed();

    void on_horizontalSlider_sliderReleased();

    void on_pushButtonSpeed_clicked();

    void on_pushButtonStop_2_clicked();

    void on_pushButtonSound_clicked();

    void on_horizontalSlider_2_sliderMoved(int position);

private:
    Ui::MoviePlay *ui;
    QMediaPlayer *player;
    QVideoWidget*videoWidget;
    QVBoxLayout*vBoxLayout;   //垂直布局
    QList<QString>filePath;
    bool eventFilter(QObject *watched, QEvent *event);
    void writeXml(QString strFile);
    void readXml();
    void deletetXml();
    void ExchangeTime(int duration);
};

#endif // MOVIEPLAY_H
