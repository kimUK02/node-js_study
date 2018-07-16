import sys

from PyQt5.QtWidgets import (QWidget, QApplication,QPushButton)

class Exam(QWidget):
    def __init__(self):
        super().__init__()
        self.initUI()
    def initUI(self):
        btn = QPushButton('push me!!',self)
        btn.resize(btn.sizeHint())
        btn.move(100,30)
        btn.setToolTip("PUSH ME PLZ\n")#tooltip
        self.setWindowTitle("fist-tme")#title
        self.show()
app = QApplication(sys.argv)
w = Exam()
sys.exit(app.exec_())