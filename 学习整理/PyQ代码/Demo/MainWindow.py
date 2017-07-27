from demo import  Ui_MainWindow
from PyQt5 import QtCore, QtGui, QtWidgets
import  res

class MainWindow(QtWidgets.QMainWindow, Ui_MainWindow):
    def __init__(self, parent = None):
        super(MainWindow, self).__init__(parent)
        self.setupUi(self)
        self.setWindowTitle("灏夏星辰")
        self.setWindowIcon(QtGui.QIcon(":/image/res/myname.png"))

        self.initSlot()

    def initSlot(self):
        self.pushButton.clicked.connect(self.pushButtonClicked)

    def pushButtonClicked(self):
        self.textEdit.setText("第一个PyQt应用程序，欢迎学习PyQt！")