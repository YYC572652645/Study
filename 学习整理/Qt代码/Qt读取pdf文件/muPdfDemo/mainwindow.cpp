#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "include/mupdf-qt.h"

#include <QFileDialog>
#include <QPixmap>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowTitle(tr("灏夏星辰 - 打开pdf文件"));

    this->setWindowIcon(QIcon(":/new/prefix1/image.png"));

    ui->scrollArea->setFrameShape(QFrame::NoFrame); //设置滑动区域无边框
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionOpenPdf_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("选择文件"), tr(""), tr("pdf文件 (*.pdf)"));

    if(fileName.isNull() || !fileName.contains(".pdf")) return;

    MuPDF::Document * document = MuPDF::loadDocument(fileName);                   //将pdf文件加载进Document

    QWidget * widget = new QWidget(this);

    QVBoxLayout *vboxLayout=new QVBoxLayout();

    for(int i = 0; i < document->numPages(); i ++)
    {
        QLabel * label = new QLabel(this);

        QImage image = document->page(i)->renderImage(2.0, 2.0); //截取pdf文件中的相应图片

        label->setPixmap(QPixmap::fromImage(image));             //将该图片放进label中

        vboxLayout->addWidget(label);
        vboxLayout->setAlignment(widget,Qt::AlignCenter);
    }
    widget->setLayout(vboxLayout);

    ui->scrollArea->setWidget(widget);              //设置widget
}
