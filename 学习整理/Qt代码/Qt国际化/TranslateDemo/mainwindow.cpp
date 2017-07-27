#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    if (translater.load(":/qm/chinese.qm"))
    {
        qApp->installTranslator(&translater);
    }
    ui->retranslateUi(this);
}

void MainWindow::on_pushButton_2_clicked()
{
    if (translater.load(":/qm/english.qm"))
    {
        qApp->installTranslator(&translater);
    }
    ui->retranslateUi(this);
}
