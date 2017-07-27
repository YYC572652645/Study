#include "setuplangue.h"
#include "ui_setuplangue.h"
#include "qreadwrite/qreadwriteini.h"
#include "globaldef.h"
#include "QDebug"

SetUpLangue::SetUpLangue(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::setuplangue)
{
    ui->setupUi(this);

    this->setWindowFlags(Qt::Dialog | Qt::WindowCloseButtonHint);

    INICONFIG->readIni();
    if(INICONFIG->getLanguage() == QString::number(CHINESE))
    {
        ui->radioButtonChinese->setChecked(true);
    }
    else
    {
        ui->radioButtonEnglish->setChecked(true);
    }
}

SetUpLangue::~SetUpLangue()
{
    delete ui;
}

void SetUpLangue::on_pushButtonOk_clicked()
{
    if(ui->radioButtonChinese->isChecked())
    {
        emit sendLanguage(CHINESE);

        if(translater.load(CHINESEQMPATH))
        {
            qApp->installTranslator(&translater);
        }
        ui->retranslateUi(this);

        INICONFIG->setLanguage(QString::number(CHINESE));
        INICONFIG->writeLanguage();
    }

    if(ui->radioButtonEnglish->isChecked())
    {
        emit sendLanguage(ENGLISH);

        if(translater.load(ENGLISHQMPATH))
        {
            qApp->installTranslator(&translater);
        }
        ui->retranslateUi(this);

        INICONFIG->setLanguage(QString::number(ENGLISH));
        INICONFIG->writeLanguage();
    }

    this->close();
}

void SetUpLangue::on_pushButtonCancel_clicked()
{
    this->close();
}
