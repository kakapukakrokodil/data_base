# -*- coding: utf-8 -*-

################################################################################
## Form generated from reading UI file 'build.ui'
##
## Created by: Qt User Interface Compiler version 6.4.2
##
## WARNING! All changes made in this file will be lost when recompiling UI file!
################################################################################

from PySide6.QtCore import (QCoreApplication, QDate, QDateTime, QLocale,
    QMetaObject, QObject, QPoint, QRect,
    QSize, QTime, QUrl, Qt)
from PySide6.QtGui import (QBrush, QColor, QConicalGradient, QCursor,
    QFont, QFontDatabase, QGradient, QIcon,
    QImage, QKeySequence, QLinearGradient, QPainter,
    QPalette, QPixmap, QRadialGradient, QTransform)
from PySide6.QtWidgets import (QApplication, QGridLayout, QLabel, QMainWindow,
    QPushButton, QSizePolicy, QSpacerItem, QTextEdit,
    QToolButton, QWidget)

class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        if not MainWindow.objectName():
            MainWindow.setObjectName(u"MainWindow")
        MainWindow.resize(570, 350)
        MainWindow.setMinimumSize(QSize(570, 350))
        self.centralwidget = QWidget(MainWindow)
        self.centralwidget.setObjectName(u"centralwidget")
        self.centralwidget.setStyleSheet(u"QWidget{\n"
"	\n"
"	background-color: qlineargradient(spread:pad, x1:0.034, y1:0.495, x2:0.778, y2:0.494318, stop:0.00568182 rgba(0, 0, 255, 255), stop:0.681818 rgba(255, 0, 200, 255));\n"
"}")
        self.gridLayout = QGridLayout(self.centralwidget)
        self.gridLayout.setObjectName(u"gridLayout")
        self.verticalSpacer = QSpacerItem(20, 51, QSizePolicy.Minimum, QSizePolicy.Minimum)

        self.gridLayout.addItem(self.verticalSpacer, 1, 0, 1, 1)

        self.horizontalSpacer_3 = QSpacerItem(228, 87, QSizePolicy.Preferred, QSizePolicy.Minimum)

        self.gridLayout.addItem(self.horizontalSpacer_3, 6, 2, 1, 2)

        self.hello_label = QLabel(self.centralwidget)
        self.hello_label.setObjectName(u"hello_label")
        sizePolicy = QSizePolicy(QSizePolicy.Preferred, QSizePolicy.Preferred)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.hello_label.sizePolicy().hasHeightForWidth())
        self.hello_label.setSizePolicy(sizePolicy)
        font = QFont()
        font.setFamilies([u"Segoe UI Black"])
        font.setPointSize(14)
        font.setBold(True)
        font.setItalic(True)
        self.hello_label.setFont(font)
        self.hello_label.setContextMenuPolicy(Qt.NoContextMenu)
        self.hello_label.setScaledContents(False)
        self.hello_label.setAlignment(Qt.AlignCenter)

        self.gridLayout.addWidget(self.hello_label, 0, 0, 1, 4)

        self.getdir_toolbutton = QToolButton(self.centralwidget)
        self.getdir_toolbutton.setObjectName(u"getdir_toolbutton")
        self.getdir_toolbutton.setEnabled(True)
        self.getdir_toolbutton.setMinimumSize(QSize(40, 40))
        self.getdir_toolbutton.setMaximumSize(QSize(40, 40))
        font1 = QFont()
        font1.setFamilies([u"Segoe UI Black"])
        font1.setPointSize(12)
        font1.setBold(True)
        font1.setItalic(True)
        self.getdir_toolbutton.setFont(font1)
        self.getdir_toolbutton.setStyleSheet(u"QToolButton{\n"
"	background:transparent;\n"
"	border: 2px outset;\n"
"	border-color: black;\n"
"	border-top-right-radius: 1em;\n"
"	border-top-left-radius: 1em;\n"
"	border-bottom-left-radius: 1em;\n"
"	border-bottom-right-radius: 1em;\n"
"}\n"
"\n"
"QToolButton:hover{\n"
"	background-color: rgb(197, 18, 217);\n"
"}\n"
"\n"
"QToolButton:pressed{\n"
"	background:rgb(179, 17, 194);\n"
"	border-style: inset;\n"
"}\n"
"\n"
"QToolButton:disabled{\n"
"	color: black;\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:0.114, x2:1, y2:0, 	stop:0 rgba(41, 41, 41, 255), stop:1 rgba(124, 124, 124, 255));\n"
"}")

        self.gridLayout.addWidget(self.getdir_toolbutton, 4, 3, 1, 1)

        self.verticalSpacer_2 = QSpacerItem(20, 42, QSizePolicy.Minimum, QSizePolicy.Ignored)

        self.gridLayout.addItem(self.verticalSpacer_2, 5, 1, 1, 1)

        self.download_button = QPushButton(self.centralwidget)
        self.download_button.setObjectName(u"download_button")
        self.download_button.setEnabled(True)
        sizePolicy1 = QSizePolicy(QSizePolicy.Minimum, QSizePolicy.Expanding)
        sizePolicy1.setHorizontalStretch(0)
        sizePolicy1.setVerticalStretch(0)
        sizePolicy1.setHeightForWidth(self.download_button.sizePolicy().hasHeightForWidth())
        self.download_button.setSizePolicy(sizePolicy1)
        self.download_button.setMinimumSize(QSize(100, 60))
        self.download_button.setMaximumSize(QSize(180, 90))
        self.download_button.setFont(font1)
        self.download_button.setCursor(QCursor(Qt.PointingHandCursor))
        self.download_button.setStyleSheet(u"QPushButton{\n"
"	background:transparent;\n"
"	border: 2px outset;\n"
"	border-color: black;\n"
"	border-top-right-radius: 1em;\n"
"	border-top-left-radius: 1em;\n"
"	border-bottom-left-radius: 1em;\n"
"	border-bottom-right-radius: 1em;\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"	background-color: rgb(197, 18, 217);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	background:rgb(179, 17, 194);\n"
"	border-style: inset;\n"
"}\n"
"\n"
"QPushButton:disabled{\n"
"	color: black;\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:0.114, x2:1, y2:0, 	stop:0 rgba(41, 41, 41, 255), stop:1 rgba(124, 124, 124, 255));\n"
"}")

        self.gridLayout.addWidget(self.download_button, 6, 1, 1, 1)

        self.path_label = QLabel(self.centralwidget)
        self.path_label.setObjectName(u"path_label")
        sizePolicy2 = QSizePolicy(QSizePolicy.Preferred, QSizePolicy.Fixed)
        sizePolicy2.setHorizontalStretch(0)
        sizePolicy2.setVerticalStretch(0)
        sizePolicy2.setHeightForWidth(self.path_label.sizePolicy().hasHeightForWidth())
        self.path_label.setSizePolicy(sizePolicy2)
        self.path_label.setFont(font1)

        self.gridLayout.addWidget(self.path_label, 2, 0, 1, 4)

        self.path_edit = QTextEdit(self.centralwidget)
        self.path_edit.setObjectName(u"path_edit")
        sizePolicy3 = QSizePolicy(QSizePolicy.Expanding, QSizePolicy.Fixed)
        sizePolicy3.setHorizontalStretch(0)
        sizePolicy3.setVerticalStretch(0)
        sizePolicy3.setHeightForWidth(self.path_edit.sizePolicy().hasHeightForWidth())
        self.path_edit.setSizePolicy(sizePolicy3)
        self.path_edit.setMinimumSize(QSize(0, 40))
        self.path_edit.setMaximumSize(QSize(16777215, 40))
        font2 = QFont()
        font2.setPointSize(8)
        self.path_edit.setFont(font2)
        self.path_edit.setStyleSheet(u"QTextEdit{\n"
"	border: 2px outset;\n"
"	border-color: black;\n"
"	border-top-right-radius: 1em;\n"
"	border-top-left-radius: 1em;\n"
"	border-bottom-left-radius: 1em;\n"
"	border-bottom-right-radius: 1em;\n"
"}")
        self.path_edit.setReadOnly(True)

        self.gridLayout.addWidget(self.path_edit, 4, 0, 1, 3)

        self.horizontalSpacer_2 = QSpacerItem(201, 20, QSizePolicy.Preferred, QSizePolicy.Minimum)

        self.gridLayout.addItem(self.horizontalSpacer_2, 6, 0, 1, 1)

        self.verticalSpacer_3 = QSpacerItem(19, 0, QSizePolicy.Minimum, QSizePolicy.Fixed)

        self.gridLayout.addItem(self.verticalSpacer_3, 3, 0, 1, 1)

        MainWindow.setCentralWidget(self.centralwidget)

        self.retranslateUi(MainWindow)

        QMetaObject.connectSlotsByName(MainWindow)
    # setupUi

    def retranslateUi(self, MainWindow):
        MainWindow.setWindowTitle(QCoreApplication.translate("MainWindow", u"MainWindow", None))
        self.hello_label.setText(QCoreApplication.translate("MainWindow", u"\u041f\u0440\u0438\u0432\u0435\u0442\u0441\u0442\u0432\u0443\u044e \u0432 \u043b\u0443\u0447\u0448\u0435\u043c \u043d\u0430 \u0441\u0432\u0435\u0442\u0435 \u0443\u0441\u0442\u0430\u043d\u043e\u0432\u0449\u0438\u043a\u0435!;)", None))
        self.getdir_toolbutton.setText(QCoreApplication.translate("MainWindow", u"...", None))
        self.download_button.setText(QCoreApplication.translate("MainWindow", u"\u0421\u043a\u0430\u0447\u0430\u0442\u044c", None))
        self.path_label.setText(QCoreApplication.translate("MainWindow", u"\u0412\u044b\u0431\u0435\u0440\u0438 \u043f\u0443\u0442\u044c \u0443\u0441\u0442\u0430\u043d\u043e\u0432\u043a\u0438:", None))
    # retranslateUi

