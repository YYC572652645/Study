from student import   Ui_MainWindow
from PyQt5 import QtCore, QtGui, QtWidgets

from database import DataBase
from golbaldef import STUDENTDATABASE
import  res

class MainWindow(QtWidgets.QMainWindow, Ui_MainWindow):
    def __init__(self, parent = None):
        super(MainWindow, self).__init__(parent)
        self.setupUi(self)

        self.setWindowTitle("灏夏星辰")                            #设置程序名称
        self.setWindowIcon(QtGui.QIcon(":/image/res/myname.png"))  #设置程序图标
        self.setMinimumSize(800, 700)                              #设置最小大小

        # 设置列表控件等宽显示
        self.headerView = self.tableWidget.horizontalHeader()
        self.headerView.setSectionResizeMode(QtWidgets.QHeaderView.Stretch)

        # 设置列表控件等高显示
        self.headerView = self.tableWidget.verticalHeader()
        self.headerView.setSectionResizeMode(QtWidgets.QHeaderView.Stretch)
        self.headerView.setHidden(True)

        # 设置单行选中
        self.tableWidget.setSelectionBehavior(QtWidgets.QAbstractItemView.SelectRows)
        self.tableWidget.setSelectionMode(QtWidgets.QAbstractItemView.SingleSelection)

        # 设置表格选中样式
        self.tableWidget.setStyleSheet("QTableWidget::item:selected:active{ background-color: qlineargradient(x1: 0, y1: 0, x2: 0.7, y2: 0.7, stop: 0.5 #FF92BB, stop: 1 rgb(9,150,200));}")

        self.initSlot()

        self.dataBase = DataBase()

    #******************   初始化信号和槽   ************************#
    def initSlot(self):
        self.pushButtonSelectData.clicked.connect(self.pushButtonSelect)

    #******************   按钮槽函数       ************************#
    def pushButtonSelect(self):
        self.dataBase.selectData()
        self.tableWidget.setRowCount(len(self.dataBase.data))

        #将从数据库查询到的信息放到表格中
        for lineData in self.dataBase.data:
            index = self.dataBase.data.index(lineData)
            self.tableWidget.setItem(index, STUDENTDATABASE.NAME, QtWidgets.QTableWidgetItem(lineData[STUDENTDATABASE.NAME]))
            self.tableWidget.setItem(index, STUDENTDATABASE.SEX, QtWidgets.QTableWidgetItem(lineData[STUDENTDATABASE.SEX]))
            self.tableWidget.setItem(index, STUDENTDATABASE.NUMBER, QtWidgets.QTableWidgetItem(lineData[STUDENTDATABASE.NUMBER]))
            self.tableWidget.setItem(index, STUDENTDATABASE.NATION, QtWidgets.QTableWidgetItem(lineData[STUDENTDATABASE.NATION]))
            self.tableWidget.setItem(index, STUDENTDATABASE.BORNDATE, QtWidgets.QTableWidgetItem(lineData[STUDENTDATABASE.BORNDATE]))
            self.tableWidget.setItem(index, STUDENTDATABASE.POLITICAL, QtWidgets.QTableWidgetItem(lineData[STUDENTDATABASE.POLITICAL]))
            self.tableWidget.setItem(index, STUDENTDATABASE.COLLEGE, QtWidgets.QTableWidgetItem(lineData[STUDENTDATABASE.COLLEGE]))
            self.tableWidget.setItem(index, STUDENTDATABASE.PROFESS, QtWidgets.QTableWidgetItem(lineData[STUDENTDATABASE.PROFESS]))
            self.tableWidget.setItem(index, STUDENTDATABASE.NOWCLASS, QtWidgets.QTableWidgetItem(lineData[STUDENTDATABASE.NOWCLASS]))