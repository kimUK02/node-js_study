import sys
from PyQt5.QtWidgets import QApplication,QWidget,QPushButton,QMessageBox
from PyQt5.QtCore import QCoreApplication #event
class Exam(QWidget):
    def __init__(self):
        super().__init__()
        self.initUI()
    def initUI(self):
        btn =QPushButton("Push Me!!",self)
        btn.resize(btn.sizeHint())
        btn.move(50,50)
        btn.clicked.connect(QCoreApplication.instance().quit)
            
        self.resize(500,500)
        self.setWindowTitle("sec time")
        self.show()
    def closeEvent(self, QcloseEvent):
        print('do')
        ans = QMessageBox.question(self, "QUIT","Do you want to quit",
                                    QMessageBox.Yes | QMessageBox.No, QMessageBox.No)
        if ans == QMessageBox.Yes:
            QcloseEvent.accept()
        else:
            QcloseEvent.ignore()
            print("good")
app = QApplication(sys.argv)
w = Exam()
sys.exit(app.exec_())