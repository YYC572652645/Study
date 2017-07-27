from PyQt5 import QtGui, QtCore
import threading
lock = threading.Lock()

class ReadIni():
    def __init__(self):
        self.readIni()

    # ***************************    读取配置文件     ********************************* #
    def readIni(self):
        try:
            self.configRed = QtCore.QSettings("config.ini", QtCore.QSettings.IniFormat)
            self.themeStyle = self.configRed.value("config/themeStyle")
            self.language = self.configRed.value("config/language")
        except Exception as e:
            print("读取配置文件失败")
        finally:
            self.configRed.clear()