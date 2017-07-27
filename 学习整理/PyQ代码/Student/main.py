
from PyQt5 import QtWidgets, QtGui, QtCore
from MainWindow import MainWindow
import sys
import res

if __name__ == "__main__":
    app = QtWidgets.QApplication(sys.argv)
    mainWindow = MainWindow()
    app.setFont(QtGui.QFont("ZYSong18"))
    mainWindow.show()
    sys.exit(app.exec_())
