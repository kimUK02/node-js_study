import sys
from PyQt5.QtWidgets import (QMainWindow, QApplication, QAction, QMenu)
from PyQt5.QtCore import QCoreApplication
class Exam(QMainWindow):
    def __init__(self):
        super().__init__()
        self.initUI()
    def initUI(self):
        self.statusBar()
        self.statusBar().showMessage("hello")
        
        menu = self.menuBar() #메뉴 생성
        #그룹생성
        menu_file = menu.addMenu('File') 
        menu_edit = menu.addMenu('Edit')
        #################################
        
        file_exit = QAction('Exit',self)
        file_exit.setShortcut('Ctrl+Q')
        file_exit.setStatusTip("good bye")
        new_text = QAction('Text file',self)
        new_py = QAction('Python file',self)
        #서브 그룹
        file_new = QMenu('new',self)
        file_new.addAction(new_text)
        file_new.addAction(new_py)
        #         #          #
        file_exit.triggered.connect(QCoreApplication.quit)
        ###
        menu_file.addMenu(file_new)
        menu_file.addAction(file_exit) #메뉴 등록
        self.resize(450,400)
        self.show()

app = QApplication(sys.argv)
w = Exam()
sys.exit(app.exec_())