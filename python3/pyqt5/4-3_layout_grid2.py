import sys
from PyQt5.QtWidgets import QWidget, QGridLayout, QPushButton, QApplication

class Example(QWidget):
    def __init__(self):      
        super().__init__()
        
        self.initUI()

    def initUI(self):

k
        self.setGeometry(300,300,250,150)
        self.setWindowTitle('teach')
        self.show()

if __name__ == '__main__':
    app = QApplication(sys.argv)
    ex = Example()
    sys.exit(app.exec_())
