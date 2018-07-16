import sys
from PyQt5.QtCore import *
from PyQt5.QtWidgets import *

class Communicate(QObject):
    closeApp = pyqtSignal()

class Example(QWidget):
    def __init__(self):
        super().__init__()

        self.initUI()
    def initUI(self):
        self.c = Communicate()
        self.c.closeApp.connect(self.close)

        self.setGeometry(300,300,290,150)
        self.setWindowTitle('Emit signal')
        self.show()
    def mousePressEvent(self, event):
        self.c.closeApp.emit()
