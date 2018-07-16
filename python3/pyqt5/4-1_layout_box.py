import sys
from PyQt5.QtWidgets import (QWidget, QPushButton,
                            QHBoxLayout, QVBoxLayout, QApplication)
class Example(QWidget):
    def __init__(self):
        super().__init__()
        
        self.initUI()

    def initUI(self):
        okButton = QPushButton('ok')
        cancelButton = QPushButton('cancel')
        
        hbox = QHBoxLayout() #가로 
        hbox.addStretch(1)
        hbox.addWidget(okButton)
        hbox.addWidget(cancelButton)

        vbox = QVBoxLayout() #세로
        vbox.addStretch(1)
        vbox.addLayout(hbox)

        self.setLayout(vbox)

        self.setGeometry(300,300,250,150)
        self.setWindowTitle('teach')
        self.show()

if __name__ == '__main__':
    app = QApplication(sys.argv)
    ex = Example()
    sys.exit(app.exec_())
