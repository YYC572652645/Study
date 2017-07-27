#ifndef MESSAGEDIALOG_H
#define MESSAGEDIALOG_H

#include <QDialog>
#include <QToolButton>
#include <QPushButton>
#include <QLabel>
#include <QCheckBox>
#include <QPainter>
#include <QPaintEvent>
#include <QPixmap>
#include <QBitmap>
#include <QMouseEvent>
#include <QStyle>
namespace Ui {
class MessageDialog;
}

class MessageDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MessageDialog(QWidget *parent = 0);
    ~MessageDialog();

    /****************************************静态函数*******************************/
    static MessageDialog *getInstance()
    {
        if(m_staticInstance==NULL)
        {
            m_staticInstance=new MessageDialog();
        }
        return m_staticInstance;
    }


    /****************************************设置函数*******************************/
    void setInfo(QString titleInfo,QString info,QPixmap pixmap,bool isOkHidden);

public slots:
    void okOperate();    //确定
    void cancelOperate();//取消


private:
    Ui::MessageDialog *ui;
    static MessageDialog *m_staticInstance;//静态对象
    bool mousePress;          //按钮是否被点击
    QPoint movePoint;         //鼠标移动
    QToolButton *closeButton; //关闭按钮
    QLabel *titleLabel;       //标题框
    QLabel *imgLabel;         //图片框
    QLabel *msgLabel;         //消息框
    QPushButton*cancelButton; //取消按钮
    QPushButton*okButton;     //确定按钮

     /****************************************画图函数*******************************/
    void paintEvent(QPaintEvent *event);

     /****************************************鼠标点击*******************************/
    void mousePressEvent(QMouseEvent*event);

    /****************************************鼠标释放*******************************/
    void mouseReleaseEvent(QMouseEvent *event);

    /****************************************鼠标移动*******************************/
    void mouseMoveEvent(QMouseEvent *event);
};

#endif // MESSAGEDIALOG_H
