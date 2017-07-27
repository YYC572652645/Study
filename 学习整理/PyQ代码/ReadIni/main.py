
from PyQt5 import QtWidgets,QtGui
from MainWindow import MainWindow
import sys

if __name__ == "__main__":
    app = QtWidgets.QApplication(sys.argv)
    mainWindow = MainWindow()
    app.setFont(QtGui.QFont("ZYSong18"))
    mainWindow.show()
    sys.exit(app.exec_())
