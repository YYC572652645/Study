/***************************************************
 *
 *  名称：--------------------------------------------
 *  参数设置
 *
 *
 *  当前功能：--------------------------------------------
 *  1.接收探头ID为5，6，7，8的数据放到表格控件中
 *  2.其他功能shangwei尚未实现
 *
 *
 *  目的：---------------------------------------------
 *  显示探头5，6，7，8的数据
 *
 * **************************************************/

#include "addwidgettab.h"
#include "ui_addwidgettab.h"

/*************************构造函数*********************/
addWidgetTab::addWidgetTab(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::addWidgetTab)
{
    ui->setupUi(this);

    ui->tableWidget->setMinimumWidth(this->width());
    ui->tableWidget->setSelectionMode(QAbstractItemView::NoSelection);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->horizontalHeader()->setVisible(false);
    ui->tableWidget->verticalHeader()->setVisible(false);

    //为表格设置列宽
    for(int i=0;i<17;i++)
    {
        ui->tableWidget->setColumnWidth(i,200);
    }

    //为表格设置行高
    for(int i=0;i<21;i++)
    {
        ui->tableWidget->setRowHeight(i,50);
    }

    addWidgetControl();

}

/*************************析构函数*********************/
addWidgetTab::~addWidgetTab()
{
    delete ui;
}

/*************************添加控件*********************/
void addWidgetTab::addWidgetControl()
{
    for(int i=0;i<9;i++)
    {
        QTableWidgetItem *checkData=new QTableWidgetItem(tr("0X0%1").arg(i));
        checkData->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->setItem(i,0,checkData);
    }

    QTableWidgetItem *oneThree=new QTableWidgetItem(tr("0X13"));
    oneThree->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget->setItem(9,0,oneThree);

    QTableWidgetItem *oneA=new QTableWidgetItem(tr("0X1A"));
    oneA->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget->setItem(10,0,oneA);

    QTableWidgetItem *twoZero=new QTableWidgetItem(tr("0X20"));
    twoZero->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget->setItem(11,0,twoZero);

    QTableWidgetItem *twoTwo=new QTableWidgetItem(tr("0X22"));
    twoTwo->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget->setItem(12,0,twoTwo);

    QTableWidgetItem *twoFour=new QTableWidgetItem(tr("0X24"));
    twoFour->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget->setItem(13,0,twoFour);

    QTableWidgetItem *twoSix=new QTableWidgetItem(tr("0X26"));
    twoSix->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget->setItem(14,0,twoSix);

    QTableWidgetItem *twoEight=new QTableWidgetItem(tr("0X28"));
    twoEight->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget->setItem(15,0,twoEight);

    QTableWidgetItem *twoA=new QTableWidgetItem(tr("0X2A"));
    twoA->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget->setItem(16,0,twoA);

    QTableWidgetItem *twoC=new QTableWidgetItem(tr("0X2C"));
    twoC->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget->setItem(17,0,twoC);

    QTableWidgetItem *twoD=new QTableWidgetItem(tr("0X2D"));
    twoD->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget->setItem(18,0,twoD);

    QTableWidgetItem *twoE=new QTableWidgetItem(tr("0X2E"));
    twoE->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget->setItem(19,0,twoE);

    QTableWidgetItem *threeZero=new QTableWidgetItem(tr("0X30"));
    threeZero->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget->setItem(20,0,threeZero);

    QTableWidgetItem *threeOne=new QTableWidgetItem(tr("0X31"));
    threeOne->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget->setItem(21,0,threeOne);

    QTableWidgetItem *threeA=new QTableWidgetItem(tr("0X3A"));
    threeA->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget->setItem(22,0,threeA);
    ui->tableWidget->setColumnWidth(0,50);//设置列宽

    /**********************************0X00行控件*********************************/
    //控件循环添加
    for(int i=0;i<14;i++)
    {
        widgetZero[i]=new QWidget(this);
        vboxLayoutZero[i]=new QVBoxLayout();
        lineEditZero[i]=new QComboBox(this);
        lableZero[i]=new QLabel(this);
        lineEditZero[i]->setMinimumHeight(20);
        vboxLayoutZero[i]->addWidget(lableZero[i]);
        vboxLayoutZero[i]->addWidget(lineEditZero[i]);
        vboxLayoutZero[i]->setAlignment(widgetZero[i],Qt::AlignLeft);
        widgetZero[i]->setLayout(vboxLayoutZero[i]);
        ui->tableWidget->setCellWidget(0,i+1,widgetZero[i]);
        lableZero[i]->setText(tr("Start_Slave_%1").arg(i+1));
        if(i<9)
        {
            for(int j=0;j<4;j++)
            {
                lineEditZero[i]->addItem(tr("%1").arg(j));
            }
        }
        else
        {
            for(int j=0;j<2;j++)
            {
                lineEditZero[i]->addItem(tr("%1").arg(j));
            }
        }
    }

    lableZero[8]->setText("MeasurementSetup");
    lableZero[9]->setText("ThresCurveDirect");
    lableZero[10]->setText("ThresCurveIndirect");
    lableZero[11]->setText("ThresScaleDirect");
    lableZero[12]->setText("ThresScaleIndirect");
    lableZero[13]->setText("MonitoringEnable");

    /**********************************0X01行控件*********************************/
    for(int i=0;i<17;i++)
    {
        widgetOne[i]=new QWidget(this);
        vboxLayoutOne[i]=new QVBoxLayout();
        lineEditOne[i]=new QLineEdit(this);
        lableOne[i]=new QLabel(this);
        lineEditOne[i]->setMinimumHeight(20);
        vboxLayoutOne[i]->addWidget(lableOne[i]);
        vboxLayoutOne[i]->addWidget(lineEditOne[i]);
        vboxLayoutOne[i]->setAlignment(widgetOne[i],Qt::AlignLeft);
        widgetOne[i]->setLayout(vboxLayoutOne[i]);
        ui->tableWidget->setCellWidget(1,i+1,widgetOne[i]);
    }
    lableOne[0]->setText("TefEcho1");
    lableOne[1]->setText("HeightEcho1");
    lableOne[2]->setText("TefEcho2");
    lableOne[3]->setText("HeightEcho2");
    lableOne[4]->setText("WidthEcho1");
    lableOne[5]->setText("WidthEcho2");
    lableOne[6]->setText("PeakEcho1");
    lableOne[7]->setText("PeakEcho2");
    lableOne[8]->setText("RingingTime");
    lableOne[9]->setText("FrequencyLow");
    lableOne[10]->setText("FrequencyHigh");
    lableOne[11]->setText("VsupFlag");
    lableOne[12]->setText("NoiseFlag");
    lableOne[13]->setText("LinErrorFlag");
    lableOne[14]->setText("RamConfChksErr");
    lableOne[15]->setText("EepConfChksErr");
    lableOne[16]->setText("LastMeasAborted");

    /**********************************0X02行控件*********************************/
    for(int i=0;i<17;i++)
    {
        widgetTwo[i]=new QWidget(this);
        vboxLayoutTwo[i]=new QVBoxLayout();
        lineEditTwo[i]=new QLineEdit(this);
        lableTwo[i]=new QLabel(this);
        lineEditTwo[i]->setMinimumHeight(20);
        vboxLayoutTwo[i]->addWidget(lableTwo[i]);
        vboxLayoutTwo[i]->addWidget(lineEditTwo[i]);
        vboxLayoutTwo[i]->setAlignment(widgetTwo[i],Qt::AlignLeft);
        widgetTwo[i]->setLayout(vboxLayoutTwo[i]);
        ui->tableWidget->setCellWidget(2,i+1,widgetTwo[i]);
    }
    lableTwo[0]->setText("TefEcho1");
    lableTwo[1]->setText("HeightEcho1");
    lableTwo[2]->setText("TefEcho2");
    lableTwo[3]->setText("HeightEcho2");
    lableTwo[4]->setText("WidthEcho1");
    lableTwo[5]->setText("WidthEcho2");
    lableTwo[6]->setText("PeakEcho1");
    lableTwo[7]->setText("PeakEcho2");
    lableTwo[8]->setText("RingingTime");
    lableTwo[9]->setText("FrequencyLow");
    lableTwo[10]->setText("FrequencyHigh");
    lableTwo[11]->setText("VsupFlag");
    lableTwo[12]->setText("NoiseFlag");
    lableTwo[13]->setText("LinErrorFlag");
    lableTwo[14]->setText("RamConfChksErr");
    lableTwo[15]->setText("EepConfChksErr");
    lableTwo[16]->setText("LastMeasAborted");

    /**********************************0X03行控件*********************************/
    for(int i=0;i<17;i++)
    {
        widgetThree[i]=new QWidget(this);
        vboxLayoutThree[i]=new QVBoxLayout();
        lineEditThree[i]=new QLineEdit(this);
        lableThree[i]=new QLabel(this);
        lineEditThree[i]->setMinimumHeight(20);
        vboxLayoutThree[i]->addWidget(lableThree[i]);
        vboxLayoutThree[i]->addWidget(lineEditThree[i]);
        vboxLayoutThree[i]->setAlignment(widgetThree[i],Qt::AlignLeft);
        widgetThree[i]->setLayout(vboxLayoutThree[i]);
        ui->tableWidget->setCellWidget(3,i+1,widgetThree[i]);
    }
    lableThree[0]->setText("TefEcho1");
    lableThree[1]->setText("HeightEcho1");
    lableThree[2]->setText("TefEcho2");
    lableThree[3]->setText("HeightEcho2");
    lableThree[4]->setText("WidthEcho1");
    lableThree[5]->setText("WidthEcho2");
    lableThree[6]->setText("PeakEcho1");
    lableThree[7]->setText("PeakEcho2");
    lableThree[8]->setText("RingingTime");
    lableThree[9]->setText("FrequencyLow");
    lableThree[10]->setText("FrequencyHigh");
    lableThree[11]->setText("VsupFlag");
    lableThree[12]->setText("NoiseFlag");
    lableThree[13]->setText("LinErrorFlag");
    lableThree[14]->setText("RamConfChksErr");
    lableThree[15]->setText("EepConfChksErr");
    lableThree[16]->setText("LastMeasAborted");

    /**********************************0X04行控件*********************************/
    for(int i=0;i<17;i++)
    {
        widgetFour[i]=new QWidget(this);
        vboxLayoutFour[i]=new QVBoxLayout();
        lineEditFour[i]=new QLineEdit(this);
        lableFour[i]=new QLabel(this);
        lineEditFour[i]->setMinimumHeight(20);
        vboxLayoutFour[i]->addWidget(lableFour[i]);
        vboxLayoutFour[i]->addWidget(lineEditFour[i]);
        vboxLayoutFour[i]->setAlignment(widgetFour[i],Qt::AlignLeft);
        widgetFour[i]->setLayout(vboxLayoutFour[i]);
        ui->tableWidget->setCellWidget(4,i+1,widgetFour[i]);
    }
    lableFour[0]->setText("TefEcho1");
    lableFour[1]->setText("HeightEcho1");
    lableFour[2]->setText("TefEcho2");
    lableFour[3]->setText("HeightEcho2");
    lableFour[4]->setText("WidthEcho1");
    lableFour[5]->setText("WidthEcho2");
    lableFour[6]->setText("PeakEcho1");
    lableFour[7]->setText("PeakEcho2");
    lableFour[8]->setText("RingingTime");
    lableFour[9]->setText("FrequencyLow");
    lableFour[10]->setText("FrequencyHigh");
    lableFour[11]->setText("VsupFlag");
    lableFour[12]->setText("NoiseFlag");
    lableFour[13]->setText("LinErrorFlag");
    lableFour[14]->setText("RamConfChksErr");
    lableFour[15]->setText("EepConfChksErr");
    lableFour[16]->setText("LastMeasAborted");

    /**********************************0X05行控件*********************************/
    for(int i=0;i<17;i++)
    {
        widgetFive[i]=new QWidget(this);
        vboxLayoutFive[i]=new QVBoxLayout();
        lineEditFive[i]=new QLineEdit(this);
        lableFive[i]=new QLabel(this);
        lineEditFive[i]->setMinimumHeight(20);
        vboxLayoutFive[i]->addWidget(lableFive[i]);
        vboxLayoutFive[i]->addWidget(lineEditFive[i]);
        vboxLayoutFive[i]->setAlignment(widgetFive[i],Qt::AlignLeft);
        widgetFive[i]->setLayout(vboxLayoutFive[i]);
        ui->tableWidget->setCellWidget(5,i+1,widgetFive[i]);
    }
    lableFive[0]->setText("TefEcho1");
    lableFive[1]->setText("HeightEcho1");
    lableFive[2]->setText("TefEcho2");
    lableFive[3]->setText("HeightEcho2");
    lableFive[4]->setText("WidthEcho1");
    lableFive[5]->setText("WidthEcho2");
    lableFive[6]->setText("PeakEcho1");
    lableFive[7]->setText("PeakEcho2");
    lableFive[8]->setText("RingingTime");
    lableFive[9]->setText("FrequencyLow");
    lableFive[10]->setText("FrequencyHigh");
    lableFive[11]->setText("VsupFlag");
    lableFive[12]->setText("NoiseFlag");
    lableFive[13]->setText("LinErrorFlag");
    lableFive[14]->setText("RamConfChksErr");
    lableFive[15]->setText("EepConfChksErr");
    lableFive[16]->setText("LastMeasAborted");

    /**********************************0X06行控件*********************************/
    for(int i=0;i<17;i++)
    {
        widgetSix[i]=new QWidget(this);
        vboxLayoutSix[i]=new QVBoxLayout();
        lineEditSix[i]=new QLineEdit(this);
        lableSix[i]=new QLabel(this);
        lineEditSix[i]->setMinimumHeight(20);
        vboxLayoutSix[i]->addWidget(lableSix[i]);
        vboxLayoutSix[i]->addWidget(lineEditSix[i]);
        vboxLayoutSix[i]->setAlignment(widgetSix[i],Qt::AlignLeft);
        widgetSix[i]->setLayout(vboxLayoutSix[i]);
        ui->tableWidget->setCellWidget(6,i+1,widgetSix[i]);
    }
    lableSix[0]->setText("TefEcho1");
    lableSix[1]->setText("HeightEcho1");
    lableSix[2]->setText("TefEcho2");
    lableSix[3]->setText("HeightEcho2");
    lableSix[4]->setText("WidthEcho1");
    lableSix[5]->setText("WidthEcho2");
    lableSix[6]->setText("PeakEcho1");
    lableSix[7]->setText("PeakEcho2");
    lableSix[8]->setText("RingingTime");
    lableSix[9]->setText("FrequencyLow");
    lableSix[10]->setText("FrequencyHigh");
    lableSix[11]->setText("VsupFlag");
    lableSix[12]->setText("NoiseFlag");
    lableSix[13]->setText("LinErrorFlag");
    lableSix[14]->setText("RamConfChksErr");
    lableSix[15]->setText("EepConfChksErr");
    lableSix[16]->setText("LastMeasAborted");

    /**********************************0X07行控件*********************************/
    for(int i=0;i<17;i++)
    {
        widgetSeven[i]=new QWidget(this);
        vboxLayoutSeven[i]=new QVBoxLayout();
        lineEditSeven[i]=new QLineEdit(this);
        lableSeven[i]=new QLabel(this);
        lineEditSeven[i]->setMinimumHeight(20);
        vboxLayoutSeven[i]->addWidget(lableSeven[i]);
        vboxLayoutSeven[i]->addWidget(lineEditSeven[i]);
        vboxLayoutSeven[i]->setAlignment(widgetSeven[i],Qt::AlignLeft);
        widgetSeven[i]->setLayout(vboxLayoutSeven[i]);
        ui->tableWidget->setCellWidget(7,i+1,widgetSeven[i]);
    }
    lableSeven[0]->setText("TefEcho1");
    lableSeven[1]->setText("HeightEcho1");
    lableSeven[2]->setText("TefEcho2");
    lableSeven[3]->setText("HeightEcho2");
    lableSeven[4]->setText("WidthEcho1");
    lableSeven[5]->setText("WidthEcho2");
    lableSeven[6]->setText("PeakEcho1");
    lableSeven[7]->setText("PeakEcho2");
    lableSeven[8]->setText("RingingTime");
    lableSeven[9]->setText("FrequencyLow");
    lableSeven[10]->setText("FrequencyHigh");
    lableSeven[11]->setText("VsupFlag");
    lableSeven[12]->setText("NoiseFlag");
    lableSeven[13]->setText("LinErrorFlag");
    lableSeven[14]->setText("RamConfChksErr");
    lableSeven[15]->setText("EepConfChksErr");
    lableSeven[16]->setText("LastMeasAborted");

    /**********************************0X08行控件*********************************/
    for(int i=0;i<17;i++)
    {
        widgetEight[i]=new QWidget(this);
        vboxLayoutEight[i]=new QVBoxLayout();
        lineEditEight[i]=new QLineEdit(this);
        lableEight[i]=new QLabel(this);
        lineEditEight[i]->setMinimumHeight(20);
        vboxLayoutEight[i]->addWidget(lableEight[i]);
        vboxLayoutEight[i]->addWidget(lineEditEight[i]);
        vboxLayoutEight[i]->setAlignment(widgetEight[i],Qt::AlignLeft);
        widgetEight[i]->setLayout(vboxLayoutEight[i]);
        ui->tableWidget->setCellWidget(8,i+1,widgetEight[i]);
    }
    lableEight[0]->setText("TefEcho1");
    lableEight[1]->setText("HeightEcho1");
    lableEight[2]->setText("TefEcho2");
    lableEight[3]->setText("HeightEcho2");
    lableEight[4]->setText("WidthEcho1");
    lableEight[5]->setText("WidthEcho2");
    lableEight[6]->setText("PeakEcho1");
    lableEight[7]->setText("PeakEcho2");
    lableEight[8]->setText("RingingTime");
    lableEight[9]->setText("FrequencyLow");
    lableEight[10]->setText("FrequencyHigh");
    lableEight[11]->setText("VsupFlag");
    lableEight[12]->setText("NoiseFlag");
    lableEight[13]->setText("LinErrorFlag");
    lableEight[14]->setText("RamConfChksErr");
    lableEight[15]->setText("EepConfChksErr");
    lableEight[16]->setText("LastMeasAborted");

    /**********************************0X13行控件*********************************/
    for(int i=0;i<5;i++)
    {
        widgetOneThree[i]=new QWidget(this);
        vboxLayoutOneThree[i]=new QVBoxLayout();
        lineEditOneThree[i]=new QLineEdit(this);
        lableOneThree[i]=new QLabel(this);
        lineEditOneThree[i]->setMinimumHeight(20);
        vboxLayoutOneThree[i]->addWidget(lableOneThree[i]);
        vboxLayoutOneThree[i]->addWidget(lineEditOneThree[i]);
        vboxLayoutOneThree[i]->setAlignment(widgetOneThree[i],Qt::AlignLeft);
        widgetOneThree[i]->setLayout(vboxLayoutOneThree[i]);
        ui->tableWidget->setCellWidget(9,i+1,widgetOneThree[i]);
        lineEditOneThree[i]->setText("0");
    }
    lableOneThree[0]->setText("RingingSamples");
    lableOneThree[1]->setText("NoiseCounter");
    lableOneThree[2]->setText("SupplyVoltage");
    lableOneThree[3]->setText("IntTemperature");
    lableOneThree[4]->setText("ExtAdcVoltage");

    /**********************************0X1A行控件*********************************/
    for(int i=0;i<5;i++)
    {
        widgetOneA[i]=new QWidget(this);
        vboxLayoutOneA[i]=new QVBoxLayout();
        lineEditOneA[i]=new QComboBox(this);
        lableOneA[i]=new QLabel(this);
        lineEditOneA[i]->setMinimumHeight(20);
        vboxLayoutOneA[i]->addWidget(lableOneA[i]);
        vboxLayoutOneA[i]->addWidget(lineEditOneA[i]);
        vboxLayoutOneA[i]->setAlignment(widgetOneA[i],Qt::AlignLeft);
        widgetOneA[i]->setLayout(vboxLayoutOneA[i]);
        ui->tableWidget->setCellWidget(10,i+1,widgetOneA[i]);
    }
    lineEditOneA[0]->addItem("3");
    for(int i=0;i<8;i++)
    {
        lineEditOneA[1]->addItem(tr("%1μs(%2)").arg((i+1)*64).arg(i));
    }
    for(int i=0;i<256;i++)
    {
        lineEditOneA[2]->addItem(tr("%1ms(%2)").arg(QString::number(i*0.256,'f',3)).arg(i));
    }

    lineEditOneA[3]->addItem(tr("No adjustment of the transducer driver frequency (0)"));
    for(int i=1;i<16;i++)
    {
        lineEditOneA[3]->addItem(tr("%1steps(%2)").arg(i).arg(i));
    }
    lineEditOneA[4]->addItem(tr("Positive adjustment of the transducer driver frequency (0)"));
    lineEditOneA[4]->addItem(tr("Negative adjustment of the transducer driver frequency (1)"));
    lableOneA[0]->setText("SlaveID_2");
    lableOneA[1]->setText("MonModeSamplingF");
    lableOneA[2]->setText("MonModeStartTime");
    lableOneA[3]->setText("FrequencyStep");
    lableOneA[4]->setText("StepDirection");

    /**********************************0X20行控件*********************************/
    for(int i=0;i<11;i++)
    {
        widgetTwoZero[i]=new QWidget(this);
        vboxLayoutTwoZero[i]=new QVBoxLayout();
        lineEditTwoZero[i]=new QComboBox(this);
        lableTwoZero[i]=new QLabel(this);
        lineEditTwoZero[i]->setMinimumHeight(20);
        vboxLayoutTwoZero[i]->addWidget(lableTwoZero[i]);
        vboxLayoutTwoZero[i]->addWidget(lineEditTwoZero[i]);
        vboxLayoutTwoZero[i]->setAlignment(widgetTwoZero[i],Qt::AlignLeft);
        widgetTwoZero[i]->setLayout(vboxLayoutTwoZero[i]);
        ui->tableWidget->setCellWidget(11,i+1,widgetTwoZero[i]);
    }

    lableTwoZero[0]->setText("SlaveID_3");
    lableTwoZero[1]->setText("ThpositionA01");
    lableTwoZero[2]->setText("ThValueA01");
    lableTwoZero[3]->setText("ThpositionA02");
    lableTwoZero[4]->setText("ThValueA02");
    lableTwoZero[5]->setText("ThpositionA03");
    lableTwoZero[6]->setText("ThValueA03");
    lableTwoZero[7]->setText("ThpositionA04");
    lableTwoZero[8]->setText("ThValueA04");
    lableTwoZero[9]->setText("ThpositionA05");
    lableTwoZero[10]->setText("ThValueA05");

    /**********************************0X22行控件*********************************/
    for(int i=0;i<11;i++)
    {
        widgetTwoTwo[i]=new QWidget(this);
        vboxLayoutTwoTwo[i]=new QVBoxLayout();
        lineEditTwoTwo[i]=new QComboBox(this);
        lableTwoTwo[i]=new QLabel(this);
        lineEditTwoTwo[i]->setMinimumHeight(20);
        vboxLayoutTwoTwo[i]->addWidget(lableTwoTwo[i]);
        vboxLayoutTwoTwo[i]->addWidget(lineEditTwoTwo[i]);
        vboxLayoutTwoTwo[i]->setAlignment(widgetTwoTwo[i],Qt::AlignLeft);
        widgetTwoTwo[i]->setLayout(vboxLayoutTwoTwo[i]);
        ui->tableWidget->setCellWidget(12,i+1,widgetTwoTwo[i]);
    }
    lableTwoTwo[0]->setText("SlaveID_3");
    lableTwoTwo[1]->setText("ThpositionA06");
    lableTwoTwo[2]->setText("ThValueA06");
    lableTwoTwo[3]->setText("ThpositionA07");
    lableTwoTwo[4]->setText("ThValueA07");
    lableTwoTwo[5]->setText("ThpositionA08");
    lableTwoTwo[6]->setText("ThValueA08");
    lableTwoTwo[7]->setText("ThpositionA09");
    lableTwoTwo[8]->setText("ThValueA09");
    lableTwoTwo[9]->setText("ThpositionA10");
    lableTwoTwo[10]->setText("ThValueA10");

    /**********************************0X24行控件*********************************/
    for(int i=0;i<11;i++)
    {
        widgetTwoFour[i]=new QWidget(this);
        vboxLayoutTwoFour[i]=new QVBoxLayout();
        lineEditTwoFour[i]=new QComboBox(this);
        lableTwoFour[i]=new QLabel(this);
        lineEditTwoFour[i]->setMinimumHeight(20);
        vboxLayoutTwoFour[i]->addWidget(lableTwoFour[i]);
        vboxLayoutTwoFour[i]->addWidget(lineEditTwoFour[i]);
        vboxLayoutTwoFour[i]->setAlignment(widgetTwoFour[i],Qt::AlignLeft);
        widgetTwoFour[i]->setLayout(vboxLayoutTwoFour[i]);
        ui->tableWidget->setCellWidget(13,i+1,widgetTwoFour[i]);
    }
    lableTwoFour[0]->setText("SlaveID_3");
    lableTwoFour[1]->setText("ThpositionA11");
    lableTwoFour[2]->setText("ThValueA11");
    lableTwoFour[3]->setText("ThpositionA12");
    lableTwoFour[4]->setText("ThValueA12");
    lableTwoFour[5]->setText("ThpositionA13");
    lableTwoFour[6]->setText("ThValueA13");
    lableTwoFour[7]->setText("ThpositionA14");
    lableTwoFour[8]->setText("ThValueA14");
    lableTwoFour[9]->setText("ThpositionA15");
    lableTwoFour[10]->setText("ThValueA15");

    /**********************************0X26行控件*********************************/
    for(int i=0;i<11;i++)
    {
        widgetTwoSix[i]=new QWidget(this);
        vboxLayoutTwoSix[i]=new QVBoxLayout();
        lineEditTwoSix[i]=new QComboBox(this);
        lableTwoSix[i]=new QLabel(this);
        lineEditTwoSix[i]->setMinimumHeight(20);
        vboxLayoutTwoSix[i]->addWidget(lableTwoSix[i]);
        vboxLayoutTwoSix[i]->addWidget(lineEditTwoSix[i]);
        vboxLayoutTwoSix[i]->setAlignment(widgetTwoSix[i],Qt::AlignLeft);
        widgetTwoSix[i]->setLayout(vboxLayoutTwoSix[i]);
        ui->tableWidget->setCellWidget(14,i+1,widgetTwoSix[i]);
    }
    lableTwoSix[0]->setText("SlaveID_3");
    lableTwoSix[1]->setText("ThpositionB01");
    lableTwoSix[2]->setText("ThValueB01");
    lableTwoSix[3]->setText("ThpositionB02");
    lableTwoSix[4]->setText("ThValueB02");
    lableTwoSix[5]->setText("ThpositionB03");
    lableTwoSix[6]->setText("ThValueB03");
    lableTwoSix[7]->setText("ThpositionB04");
    lableTwoSix[8]->setText("ThValueB04");
    lableTwoSix[9]->setText("ThpositionB05");
    lableTwoSix[10]->setText("ThValueB05");

    /**********************************0X28行控件*********************************/
    for(int i=0;i<11;i++)
    {
        widgetTwoEight[i]=new QWidget(this);
        vboxLayoutTwoEight[i]=new QVBoxLayout();
        lineEditTwoEight[i]=new QComboBox(this);
        lableTwoEight[i]=new QLabel(this);
        lineEditTwoEight[i]->setMinimumHeight(20);
        vboxLayoutTwoEight[i]->addWidget(lableTwoEight[i]);
        vboxLayoutTwoEight[i]->addWidget(lineEditTwoEight[i]);
        vboxLayoutTwoEight[i]->setAlignment(widgetTwoEight[i],Qt::AlignLeft);
        widgetTwoEight[i]->setLayout(vboxLayoutTwoEight[i]);
        ui->tableWidget->setCellWidget(15,i+1,widgetTwoEight[i]);
    }
    lableTwoEight[0]->setText("SlaveID_4");
    lableTwoEight[1]->setText("ThpositionB06");
    lableTwoEight[2]->setText("ThValueB06");
    lableTwoEight[3]->setText("ThpositionB07");
    lableTwoEight[4]->setText("ThValueB07");
    lableTwoEight[5]->setText("ThpositionB08");
    lableTwoEight[6]->setText("ThValueB08");
    lableTwoEight[7]->setText("ThpositionB09");
    lableTwoEight[8]->setText("ThValueB09");
    lableTwoEight[9]->setText("ThpositionB10");
    lableTwoEight[10]->setText("ThValueB10");

    /**********************************0X2A行控件*********************************/
    for(int i=0;i<11;i++)
    {
        widgetTwoA[i]=new QWidget(this);
        vboxLayoutTwoA[i]=new QVBoxLayout();
        lineEditTwoA[i]=new QComboBox(this);
        lableTwoA[i]=new QLabel(this);
        lineEditTwoA[i]->setMinimumHeight(20);
        vboxLayoutTwoA[i]->addWidget(lableTwoA[i]);
        vboxLayoutTwoA[i]->addWidget(lineEditTwoA[i]);
        vboxLayoutTwoA[i]->setAlignment(widgetTwoA[i],Qt::AlignLeft);
        widgetTwoA[i]->setLayout(vboxLayoutTwoA[i]);
        ui->tableWidget->setCellWidget(16,i+1,widgetTwoA[i]);
    }
    lableTwoA[0]->setText("SlaveID_4");
    lableTwoA[1]->setText("ThpositionB11");
    lableTwoA[2]->setText("ThValueB11");
    lableTwoA[3]->setText("ThpositionB12");
    lableTwoA[4]->setText("ThValueB12");
    lableTwoA[5]->setText("ThpositionB13");
    lableTwoA[6]->setText("ThValueB13");
    lableTwoA[7]->setText("ThpositionB14");
    lableTwoA[8]->setText("ThValueB14");
    lableTwoA[9]->setText("ThpositionB15");
    lableTwoA[10]->setText("ThValueB15");

    lineEditTwoZero[0]->addItem(tr("3"));
    lineEditTwoTwo[0]->addItem(tr("3"));
    lineEditTwoFour[0]->addItem(tr("3"));
    lineEditTwoSix[0]->addItem(tr("3"));
    lineEditTwoEight[0]->addItem(tr("3"));
    lineEditTwoA[0]->addItem(tr("3"));

    lineEditTwoZero[1]->addItem(tr("rel. time position = 64us (0)"));
    lineEditTwoTwo[1]->addItem(tr("rel. time position = 64us (0)"));
    lineEditTwoFour[1]->addItem(tr("rel. time position = 64us (0)"));
    lineEditTwoSix[1]->addItem(tr("rel. time position = 64us (0)"));
    lineEditTwoEight[1]->addItem(tr("rel. time position = 64us (0)"));
    lineEditTwoA[1]->addItem(tr("rel. time position = 64us (0)"));

    lineEditTwoZero[3]->addItem(tr("rel. time position = 64us (0)"));
    lineEditTwoTwo[3]->addItem(tr("rel. time position = 64us (0)"));
    lineEditTwoFour[3]->addItem(tr("rel. time position = 64us (0)"));
    lineEditTwoSix[3]->addItem(tr("rel. time position = 64us (0)"));
    lineEditTwoEight[3]->addItem(tr("rel. time position = 64us (0)"));
    lineEditTwoA[3]->addItem(tr("rel. time position = 64us (0)"));

    lineEditTwoZero[5]->addItem(tr("rel. time position = 64us (0)"));
    lineEditTwoTwo[5]->addItem(tr("rel. time position = 64us (0)"));
    lineEditTwoFour[5]->addItem(tr("rel. time position = 64us (0)"));
    lineEditTwoSix[5]->addItem(tr("rel. time position = 64us (0)"));
    lineEditTwoEight[5]->addItem(tr("rel. time position = 64us (0)"));
    lineEditTwoA[5]->addItem(tr("rel. time position = 64us (0)"));

    lineEditTwoZero[7]->addItem(tr("rel. time position = 64us (0)"));
    lineEditTwoTwo[7]->addItem(tr("rel. time position = 64us (0)"));
    lineEditTwoFour[7]->addItem(tr("rel. time position = 64us (0)"));
    lineEditTwoSix[7]->addItem(tr("rel. time position = 64us (0)"));
    lineEditTwoEight[7]->addItem(tr("rel. time position = 64us (0)"));
    lineEditTwoA[7]->addItem(tr("rel. time position = 64us (0)"));

    lineEditTwoZero[9]->addItem(tr("rel. time position = 64us (0)"));
    lineEditTwoTwo[9]->addItem(tr("rel. time position = 64us (0)"));
    lineEditTwoFour[9]->addItem(tr("rel. time position = 64us (0)"));
    lineEditTwoSix[9]->addItem(tr("rel. time position = 64us (0)"));
    lineEditTwoEight[9]->addItem(tr("rel. time position = 64us (0)"));
    lineEditTwoA[9]->addItem(tr("rel. time position = 64us (0)"));
    for(int i=1;i<32;i++)
    {
        lineEditTwoZero[1]->addItem(tr("%1ms(%2)").arg(i*0.128).arg(i));
        lineEditTwoTwo[1]->addItem(tr("%1ms(%2)").arg(i*0.128).arg(i));
        lineEditTwoFour[1]->addItem(tr("%1ms(%2)").arg(i*0.128).arg(i));
        lineEditTwoSix[1]->addItem(tr("%1ms(%2)").arg(i*0.128).arg(i));
        lineEditTwoEight[1]->addItem(tr("%1ms(%2)").arg(i*0.128).arg(i));
        lineEditTwoA[1]->addItem(tr("%1ms(%2)").arg(i*0.128).arg(i));

        lineEditTwoZero[3]->addItem(tr("%1ms(%2)").arg(i*0.128).arg(i));
        lineEditTwoTwo[3]->addItem(tr("%1ms(%2)").arg(i*0.128).arg(i));
        lineEditTwoFour[3]->addItem(tr("%1ms(%2)").arg(i*0.128).arg(i));
        lineEditTwoSix[3]->addItem(tr("%1ms(%2)").arg(i*0.128).arg(i));
        lineEditTwoEight[3]->addItem(tr("%1ms(%2)").arg(i*0.128).arg(i));
        lineEditTwoA[3]->addItem(tr("%1ms(%2)").arg(i*0.128).arg(i));

        lineEditTwoZero[5]->addItem(tr("%1ms(%2)").arg(i*0.128).arg(i));
        lineEditTwoTwo[5]->addItem(tr("%1ms(%2)").arg(i*0.128).arg(i));
        lineEditTwoFour[5]->addItem(tr("%1ms(%2)").arg(i*0.128).arg(i));
        lineEditTwoSix[5]->addItem(tr("%1ms(%2)").arg(i*0.128).arg(i));
        lineEditTwoEight[5]->addItem(tr("%1ms(%2)").arg(i*0.128).arg(i));
        lineEditTwoA[5]->addItem(tr("%1ms(%2)").arg(i*0.128).arg(i));

        lineEditTwoZero[7]->addItem(tr("%1ms(%2)").arg(i*0.128).arg(i));
        lineEditTwoTwo[7]->addItem(tr("%1ms(%2)").arg(i*0.128).arg(i));
        lineEditTwoFour[7]->addItem(tr("%1ms(%2)").arg(i*0.128).arg(i));
        lineEditTwoSix[7]->addItem(tr("%1ms(%2)").arg(i*0.128).arg(i));
        lineEditTwoEight[7]->addItem(tr("%1ms(%2)").arg(i*0.128).arg(i));
        lineEditTwoA[7]->addItem(tr("%1ms(%2)").arg(i*0.128).arg(i));

        lineEditTwoZero[9]->addItem(tr("%1ms(%2)").arg(i*0.128).arg(i));
        lineEditTwoTwo[9]->addItem(tr("%1ms(%2)").arg(i*0.128).arg(i));
        lineEditTwoFour[9]->addItem(tr("%1ms(%2)").arg(i*0.128).arg(i));
        lineEditTwoSix[9]->addItem(tr("%1ms(%2)").arg(i*0.128).arg(i));
        lineEditTwoEight[9]->addItem(tr("%1ms(%2)").arg(i*0.128).arg(i));
        lineEditTwoA[9]->addItem(tr("%1ms(%2)").arg(i*0.128).arg(i));
    }

    for(int i=0;i<64;i++)
    {
        lineEditTwoZero[2]->addItem(tr("%1(%2)").arg(3+i*4).arg(i));
        lineEditTwoTwo[2]->addItem(tr("%1(%2)").arg(3+i*4).arg(i));
        lineEditTwoFour[2]->addItem(tr("%1(%2)").arg(3+i*4).arg(i));
        lineEditTwoSix[2]->addItem(tr("%1(%2)").arg(3+i*4).arg(i));
        lineEditTwoEight[2]->addItem(tr("%1(%2)").arg(3+i*4).arg(i));
        lineEditTwoA[2]->addItem(tr("%1(%2)").arg(3+i*4).arg(i));

        lineEditTwoZero[4]->addItem(tr("%1(%2)").arg(3+i*4).arg(i));
        lineEditTwoTwo[4]->addItem(tr("%1(%2)").arg(3+i*4).arg(i));
        lineEditTwoFour[4]->addItem(tr("%1(%2)").arg(3+i*4).arg(i));
        lineEditTwoSix[4]->addItem(tr("%1(%2)").arg(3+i*4).arg(i));
        lineEditTwoEight[4]->addItem(tr("%1(%2)").arg(3+i*4).arg(i));
        lineEditTwoA[4]->addItem(tr("%1(%2)").arg(3+i*4).arg(i));


        lineEditTwoZero[6]->addItem(tr("%1(%2)").arg(3+i*4).arg(i));
        lineEditTwoTwo[6]->addItem(tr("%1(%2)").arg(3+i*4).arg(i));
        lineEditTwoFour[6]->addItem(tr("%1(%2)").arg(3+i*4).arg(i));
        lineEditTwoSix[6]->addItem(tr("%1(%2)").arg(3+i*4).arg(i));
        lineEditTwoEight[6]->addItem(tr("%1(%2)").arg(3+i*4).arg(i));
        lineEditTwoA[6]->addItem(tr("%1(%2)").arg(3+i*4).arg(i));


        lineEditTwoZero[8]->addItem(tr("%1(%2)").arg(3+i*4).arg(i));
        lineEditTwoTwo[8]->addItem(tr("%1(%2)").arg(3+i*4).arg(i));
        lineEditTwoFour[8]->addItem(tr("%1(%2)").arg(3+i*4).arg(i));
        lineEditTwoSix[8]->addItem(tr("%1(%2)").arg(3+i*4).arg(i));
        lineEditTwoEight[8]->addItem(tr("%1(%2)").arg(3+i*4).arg(i));
        lineEditTwoA[8]->addItem(tr("%1(%2)").arg(3+i*4).arg(i));


        lineEditTwoZero[10]->addItem(tr("%1(%2)").arg(3+i*4).arg(i));
        lineEditTwoTwo[10]->addItem(tr("%1(%2)").arg(3+i*4).arg(i));
        lineEditTwoFour[10]->addItem(tr("%1(%2)").arg(3+i*4).arg(i));
        lineEditTwoSix[10]->addItem(tr("%1(%2)").arg(3+i*4).arg(i));
        lineEditTwoEight[10]->addItem(tr("%1(%2)").arg(3+i*4).arg(i));
        lineEditTwoA[10]->addItem(tr("%1(%2)").arg(3+i*4).arg(i));
    }

    /**********************************0X2C行控件*********************************/
    for(int i=0;i<12;i++)
    {
        widgetTwoC[i]=new QWidget(this);
        vboxLayoutTwoC[i]=new QVBoxLayout();
        lineEditTwoC[i]=new QLineEdit(this);
        lableTwoC[i]=new QLabel(this);
        lineEditTwoC[i]->setMinimumHeight(20);
        vboxLayoutTwoC[i]->addWidget(lableTwoC[i]);
        vboxLayoutTwoC[i]->addWidget(lineEditTwoC[i]);
        vboxLayoutTwoC[i]->setAlignment(widgetTwoC[i],Qt::AlignLeft);
        widgetTwoC[i]->setLayout(vboxLayoutTwoC[i]);
        ui->tableWidget->setCellWidget(17,i+1,widgetTwoC[i]);
    }
    lableTwoC[0]->setText("SlaveID_4");
    lableTwoC[1]->setText("FreqPrescaler");
    lableTwoC[2]->setText("DrvCurr");
    lableTwoC[3]->setText("SquareLawDetector");
    lableTwoC[4]->setText("BaseGain");
    lableTwoC[5]->setText("FilterOut");
    lableTwoC[6]->setText("StcStepWidth");
    lableTwoC[7]->setText("FilterSettings");
    lableTwoC[8]->setText("StcMaxStep");
    lableTwoC[9]->setText("ExtAdcMeasOn");
    lableTwoC[10]->setText("StcStartTime");
    lableTwoC[11]->setText("LinAddrMode");
    lineEditTwoC[0]->setText("3");

    /**********************************0X2E行控件*********************************/
    for(int i=0;i<13;i++)
    {
        widgetTwoE[i]=new QWidget(this);
        vboxLayoutTwoE[i]=new QVBoxLayout();
        lineEditTwoE[i]=new QComboBox(this);
        lableTwoE[i]=new QLabel(this);
        lineEditTwoE[i]->setMinimumHeight(20);
        vboxLayoutTwoE[i]->addWidget(lableTwoE[i]);
        vboxLayoutTwoE[i]->addWidget(lineEditTwoE[i]);
        vboxLayoutTwoE[i]->setAlignment(widgetTwoE[i],Qt::AlignLeft);
        widgetTwoE[i]->setLayout(vboxLayoutTwoE[i]);
        ui->tableWidget->setCellWidget(18,i+1,widgetTwoE[i]);
    }
    lableTwoE[0]->setText("SlaveID_4");
    lableTwoE[1]->setText("NoiseMeasSampleNo");
    lableTwoE[2]->setText("noiseMeasThreshold");
    lableTwoE[3]->setText("noiseMeasCountLimit");
    lableTwoE[4]->setText("FreqDeviation");
    lableTwoE[5]->setText("FreqMeasLength");
    lableTwoE[6]->setText("FreqMeasStart");
    lableTwoE[7]->setText("MinimumEchoWidth");
    lableTwoE[8]->setText("RingingTimeThreshold");
    lableTwoE[9]->setText("MaskTimeDirectMeas");
    lableTwoE[10]->setText("ScalingThresholdCurv");
    lableTwoE[11]->setText("MaskTimeIndirectMeas");
    lableTwoE[12]->setText("ScalingThresholdCur");

    lineEditTwoE[0]->addItem("3");
    lineEditTwoE[1]->addItem("0");
    lineEditTwoE[2]->addItem("0");
    lineEditTwoE[3]->addItem("0");
    lineEditTwoE[4]->addItem("+/- 3.125% deviation from nominal driver frequency (0)");
    lineEditTwoE[4]->addItem("+/- 6.25% deviation from nominal driver frequency (1)");
    lineEditTwoE[4]->addItem("+/- 9.375% deviation from nominal driver frequency (2)");
    lineEditTwoE[4]->addItem("+/- 12.5% deviation from nominal driver frequency (3)");
    lineEditTwoE[5]->addItem("8 periods (0)");
    lineEditTwoE[5]->addItem("16 periods (1)");
    for(int i=0;i<8;i++)
    {
        lineEditTwoE[6]->addItem(tr("%1 periods (%2)").arg((i+1)*2).arg(i));
        lineEditTwoE[8]->addItem(tr("%1 periods (%2)").arg(64+i*16).arg(i));
        lineEditTwoE[10]->addItem(tr("%1 periods (%2)").arg(QString::number(0.9375-i*0.0625,'f',3)).arg(i));
        lineEditTwoE[12]->addItem(tr("%1 periods (%2)").arg(QString::number(0.9375-i*0.0625,'f',3)).arg(i));
    }

    lineEditTwoE[7]->addItem("No debouncing during echo measurement (0)");
    for(int i=1;i<16;i++)
    {
        lineEditTwoE[7]->addItem(tr("%1 ms min. width (%2)").arg(i*0.064).arg(i));
    }
    for(int i=1;i<32;i++)
    {
        lineEditTwoE[9]->addItem(tr("%1ms(%2)").arg(i*0.128).arg(i));
        lineEditTwoE[11]->addItem(tr("%1ms(%2)").arg(i*0.128).arg(i));
    }

    /**********************************0X30行控件*********************************/
    for(int i=0;i<11;i++)
    {
        widgetThreeZero[i]=new QWidget(this);
        vboxLayoutThreeZero[i]=new QVBoxLayout();
        lineEditThreeZero[i]=new QComboBox(this);
        lableThreeZero[i]=new QLabel(this);
        lineEditThreeZero[i]->setMinimumHeight(20);
        vboxLayoutThreeZero[i]->addWidget(lableThreeZero[i]);
        vboxLayoutThreeZero[i]->addWidget(lineEditThreeZero[i]);
        vboxLayoutThreeZero[i]->setAlignment(widgetThreeZero[i],Qt::AlignLeft);
        widgetThreeZero[i]->setLayout(vboxLayoutThreeZero[i]);
        ui->tableWidget->setCellWidget(19,i+1,widgetThreeZero[i]);
    }
    lableThreeZero[0]->setText("SlaveID_4");
    lableThreeZero[1]->setText("MeasureLength0");
    lableThreeZero[2]->setText("MeasureLength1");
    lableThreeZero[3]->setText("MeasureLength2");
    lableThreeZero[4]->setText("MeasureLength3");
    lableThreeZero[5]->setText("BurstLength0");
    lableThreeZero[6]->setText("BurstLength1");
    lableThreeZero[7]->setText("BurstLength2");
    lableThreeZero[8]->setText("BurstLength3");
    lableThreeZero[9]->setText("ThressSlopeFalling");
    lableThreeZero[10]->setText("ThresSlopeRising");

    lineEditThreeZero[0]->addItem("0");
    for(int i=0;i<256;i++)
    {
        lineEditThreeZero[1]->addItem(tr("%1ms(%2)").arg(QString::number(i*0.256,'f',3)).arg(i));
        lineEditThreeZero[2]->addItem(tr("%1ms(%2)").arg(QString::number(i*0.256,'f',3)).arg(i));
        lineEditThreeZero[3]->addItem(tr("%1ms(%2)").arg(QString::number(i*0.256,'f',3)).arg(i));
        lineEditThreeZero[4]->addItem(tr("%1ms(%2)").arg(QString::number(i*0.256,'f',3)).arg(i));
    }

    lineEditThreeZero[5]->addItem("short range mode (0)");
    lineEditThreeZero[6]->addItem("short range mode (0)");
    lineEditThreeZero[7]->addItem("short range mode (0)");
    lineEditThreeZero[8]->addItem("short range mode (0)");
    lineEditThreeZero[9]->addItem("Change the threshold value immediately (0)");
    lineEditThreeZero[10]->addItem("Change the threshold value immediately (0)");
    for(int i=1;i<16;i++)
    {
        lineEditThreeZero[5]->addItem(tr("%1 pulses (%2)").arg(i*4).arg(i));
        lineEditThreeZero[6]->addItem(tr("%1 pulses (%2)").arg(i*4).arg(i));
        lineEditThreeZero[7]->addItem(tr("%1 pulses (%2)").arg(i*4).arg(i));
        lineEditThreeZero[8]->addItem(tr("%1 pulses (%2)").arg(i*4).arg(i));
        lineEditThreeZero[9]->addItem(tr("%1 steps/period (%2)").arg(i*4).arg(i));
        lineEditThreeZero[10]->addItem(tr("%1 steps/period (%2)").arg(i*4).arg(i));

    }

    /**********************************0X3A行控件*********************************/
    for(int i=0;i<5;i++)
    {
        widgetThreeA[i]=new QWidget(this);
        vboxLayoutThreeA[i]=new QVBoxLayout();
        lineEditThreeA[i]=new QLineEdit(this);
        lableThreeA[i]=new QLabel(this);
        lineEditThreeA[i]->setMinimumHeight(20);
        vboxLayoutThreeA[i]->addWidget(lableThreeA[i]);
        vboxLayoutThreeA[i]->addWidget(lineEditThreeA[i]);
        vboxLayoutThreeA[i]->setAlignment(widgetThreeA[i],Qt::AlignLeft);
        widgetThreeA[i]->setLayout(vboxLayoutThreeA[i]);
        ui->tableWidget->setCellWidget(20,i+1,widgetThreeA[i]);
    }
    lableThreeA[0]->setText("SlaveID_5");
    lableThreeA[1]->setText("ElmosChipld01");
    lableThreeA[2]->setText("ElmosChipld02");
    lableThreeA[3]->setText("ElmosChipld03");
    lableThreeA[4]->setText("ElmosChipld04");

    lineEditThreeA[0]->setText("3");
    lineEditThreeA[1]->setText("0");
    lineEditThreeA[2]->setText("0");
    lineEditThreeA[3]->setText("0");
    lineEditThreeA[4]->setText("0");

    for(int i=0;i<17;i++)
    {
        lineEditOne[i]->setEnabled(true);
        lineEditOne[i]->setText("0");
        lineEditTwo[i]->setText("0");
        lineEditThree[i]->setText("0");
        lineEditFour[i]->setText("0");
        lineEditFive[i]->setText("0");
        lineEditSix[i]->setText("0");
        lineEditSeven[i]->setText("0");
        lineEditEight[i]->setText("0");
    }
}

/*************************选择探头*********************/
void addWidgetTab::on_comboBox_currentIndexChanged(int index)
{

    switch(index)
    {
    case 0:lineEditThreeA[0]->setText("1");
        for(int i=0;i<17;i++)
        {
            lineEditOne[i]->setEnabled(true);
            lineEditTwo[i]->setEnabled(false);
            lineEditThree[i]->setEnabled(false);
            lineEditFour[i]->setEnabled(false);
            lineEditFive[i]->setEnabled(false);
            lineEditSix[i]->setEnabled(false);
            lineEditSeven[i]->setEnabled(false);
            lineEditEight[i]->setEnabled(false);
        }
        break;
    case 1:
        for(int i=0;i<17;i++)
        {
            lineEditOne[i]->setEnabled(false);
            lineEditTwo[i]->setEnabled(true);
            lineEditThree[i]->setEnabled(false);
            lineEditFour[i]->setEnabled(false);
            lineEditFive[i]->setEnabled(false);
            lineEditSix[i]->setEnabled(false);
            lineEditSeven[i]->setEnabled(false);
            lineEditEight[i]->setEnabled(false);
        }
        lineEditThreeA[0]->setText("2");break;
    case 2:
        for(int i=0;i<17;i++)
        {
            lineEditOne[i]->setEnabled(false);
            lineEditTwo[i]->setEnabled(false);
            lineEditThree[i]->setEnabled(true);
            lineEditFour[i]->setEnabled(false);
            lineEditFive[i]->setEnabled(false);
            lineEditSix[i]->setEnabled(false);
            lineEditSeven[i]->setEnabled(false);
            lineEditEight[i]->setEnabled(false);
        }
        lineEditThreeA[0]->setText("3");break;
    case 3:
        for(int i=0;i<17;i++)
        {
            lineEditOne[i]->setEnabled(false);
            lineEditTwo[i]->setEnabled(false);
            lineEditThree[i]->setEnabled(false);
            lineEditFour[i]->setEnabled(true);
            lineEditFive[i]->setEnabled(false);
            lineEditSix[i]->setEnabled(false);
            lineEditSeven[i]->setEnabled(false);
            lineEditEight[i]->setEnabled(false);
        }
        lineEditThreeA[0]->setText("4");break;
    case 4: for(int i=0;i<17;i++)
        {
            lineEditOne[i]->setEnabled(false);
            lineEditTwo[i]->setEnabled(false);
            lineEditThree[i]->setEnabled(false);
            lineEditFour[i]->setEnabled(false);
            lineEditFive[i]->setEnabled(true);
            lineEditSix[i]->setEnabled(false);
            lineEditSeven[i]->setEnabled(false);
            lineEditEight[i]->setEnabled(false);
        }
        lineEditThreeA[0]->setText("5");break;
    case 5:
        for(int i=0;i<17;i++)
        {
            lineEditOne[i]->setEnabled(false);
            lineEditTwo[i]->setEnabled(false);
            lineEditThree[i]->setEnabled(false);
            lineEditFour[i]->setEnabled(false);
            lineEditFive[i]->setEnabled(false);
            lineEditSix[i]->setEnabled(true);
            lineEditSeven[i]->setEnabled(false);
            lineEditEight[i]->setEnabled(false);
        }
        lineEditThreeA[0]->setText("6");break;
    case 6: for(int i=0;i<17;i++)
        {
            lineEditOne[i]->setEnabled(false);
            lineEditTwo[i]->setEnabled(false);
            lineEditThree[i]->setEnabled(false);
            lineEditFour[i]->setEnabled(false);
            lineEditFive[i]->setEnabled(false);
            lineEditSix[i]->setEnabled(false);
            lineEditSeven[i]->setEnabled(true);
            lineEditEight[i]->setEnabled(false);
        }
        lineEditThreeA[0]->setText("7");break;
    case 7: for(int i=0;i<17;i++)
        {
            lineEditOne[i]->setEnabled(false);
            lineEditTwo[i]->setEnabled(false);
            lineEditThree[i]->setEnabled(false);
            lineEditFour[i]->setEnabled(false);
            lineEditFive[i]->setEnabled(false);
            lineEditSix[i]->setEnabled(false);
            lineEditSeven[i]->setEnabled(false);
            lineEditEight[i]->setEnabled(true);
        }
        lineEditThreeA[0]->setText("8");break;
    }
}

/*************************发送读取数据信号**************/
void addWidgetTab::on_pushButton_2_clicked()
{
    emit readInfo();
}

/**********************保存数据***********************/
void addWidgetTab::on_pushButtonSaveInfo_clicked()
{
    QDir *testDir = new QDir;
    bool exist = testDir->exists("File"); //判断Test文件夹是否存在
    if(!exist)
    {
        bool ok = testDir->mkdir("File"); //创建TEST文件夹
        if(!ok)
        {
            QMessageBox::warning(this,tr("系统提示"),tr("创建File文件夹失败"));
        }
    }

    QString fileName = "File/";
    fileName += "file.txt";

    QFile* file=new QFile;
    file->setFileName(fileName);

    bool fileOk =file->open(QIODevice::Append|QFile::Text);   //以续写方式打开
    if(fileOk)
    {

        QTextStream out(file);
        out<<ui->lineEditX->text()<<"  "<<ui->lineEditY->text()<<"  ";
        out<<lineEditFive[0]->text()<<"  "<<lineEditSix[0]->text()<<"  "<<lineEditSeven[0]->text()<<"  "<<lineEditEight[0]->text()<<"  ";
        out<<lineEditFive[2]->text()<<"  "<<lineEditSix[2]->text()<<"  "<<lineEditSeven[2]->text()<<"  "<<lineEditEight[2]->text()<<"\r\n";
        file->close();
    }
    else
    {
        QMessageBox::warning(this,tr("系统提示"),tr("保存失败"));
    }

}

