from demo import  Ui_MainWindow
from PyQt5 import QtCore, QtGui, QtWidgets
from ReadIni import ReadIni
import  res

class MainWindow(QtWidgets.QMainWindow, Ui_MainWindow):
    def __init__(self, parent = None):
        super(MainWindow, self).__init__(parent)
        self.setupUi(self)
        self.setWindowTitle("灏夏星辰")
        self.setWindowIcon(QtGui.QIcon(":/image/res/myname.png"))
        self.initSlot()
        self.readIni = ReadIni()

    def initSlot(self):
        self.pushButton.clicked.connect(self.pushButtonClicked)

    def pushButtonClicked(self):
        self.textEdit.setText("themeStyle:" + self.readIni.themeStyle + "\n\n" + "language:" + self.readIni.language)