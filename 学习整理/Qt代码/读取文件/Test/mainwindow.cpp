#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "database.h"
#include "qreadxml.h"
#include "qreadjson.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    DataBase data;
}

MainWindow::~MainWindow()
{
    delete ui;
}
