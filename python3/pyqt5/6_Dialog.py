from PyQt5.QtWidgets import *
import sys

class Example(QWidget):
    def __init__(self):
        super().__init__()
        
        self.initUI()

    def initUI(self):
        self.btn = QPushButton('dialog', self)
        self.btn.move(20,28)
        self.btn.clicked.connect(self.showDialog)

        self.le = QLineEdit(self)
        self.le.move (131,22)

        self.setGeometry(300,300,290,150)
        self.setWindowTitle('Input Dialog')
        self.show()

    def showDialog(self):
        text, ok = QInputDialog.getText(self, 'Input Text','Enter your gender: ')

        if ok:
            # print(ok)
            self.le.setText(str(text))
    
if __name__ == '__main__':
    app = QApplication(sys.argv)
    ex =Example()
    sys.exit(app.exec_())
