import sys
import os
from distutils.dir_util import copy_tree

from PySide6.QtWidgets import QApplication,QMainWindow, QFileDialog
from PySide6.QtCore import QTimer, QSize


from build import Ui_MainWindow

class apps(QMainWindow):

    def __init__(self):
        super(apps, self).__init__()
        self.ui = Ui_MainWindow()
        self.ui.setupUi(self)
        self.path = ''
        
        self.ui.getdir_toolbutton.clicked.connect(self.getDirectory)
        self.ui.download_button.clicked.connect(self.download)
        
    def getDirectory(self):                                                     # <-----
       dirlist = QFileDialog.getExistingDirectory(self,"Выбрать папку",".")
       self.path = dirlist
       self.ui.path_edit.setText(dirlist)
       self.ui.path_label.setText("Текущий путь:")
       
    def download(self):
        self.ui.download_button.setEnabled(False)
        self.ui.getdir_toolbutton.setEnabled(False)
        os.system("dependencies.bat")
        copy_tree(os.getcwd() + "/ToBuild", self.path)
        os.system("cd " + self.path)
        os.system("Build " + self.path)
       
#точка входа в программу
if __name__ == '__main__':

    app = QApplication(sys.argv)
    
    window = apps()
    window.show()
    
    sys.exit(app.exec())
    