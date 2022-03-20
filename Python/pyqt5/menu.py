# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'menu.ui'
#
# Created by: PyQt5 UI code generator 5.15.6
#
# WARNING: Any manual changes made to this file will be lost when pyuic5 is
# run again.  Do not edit this file unless you know what you are doing.


from PyQt5 import QtCore, QtGui, QtWidgets


class Ui_Menu(object):
    def setupUi(self, Menu):
        Menu.setObjectName("Menu")
        Menu.resize(560, 519)
        self.centralwidget = QtWidgets.QWidget(Menu)
        self.centralwidget.setObjectName("centralwidget")
        self.label = QtWidgets.QLabel(self.centralwidget)
        self.label.setGeometry(QtCore.QRect(140, 100, 231, 61))
        font = QtGui.QFont()
        font.setPointSize(16)
        self.label.setFont(font)
        self.label.setObjectName("label")
        self.label_2 = QtWidgets.QLabel(self.centralwidget)
        self.label_2.setGeometry(QtCore.QRect(140, 170, 181, 31))
        font = QtGui.QFont()
        font.setPointSize(12)
        self.label_2.setFont(font)
        self.label_2.setObjectName("label_2")
        self.radioButton_H_VS_H = QtWidgets.QRadioButton(self.centralwidget)
        self.radioButton_H_VS_H.setGeometry(QtCore.QRect(140, 220, 191, 20))
        font = QtGui.QFont()
        font.setPointSize(12)
        self.radioButton_H_VS_H.setFont(font)
        self.radioButton_H_VS_H.setObjectName("radioButton_H_VS_H")
        self.buttonGroup = QtWidgets.QButtonGroup(Menu)
        self.buttonGroup.setObjectName("buttonGroup")
        self.buttonGroup.addButton(self.radioButton_H_VS_H)
        self.radioButton_H_VS_P = QtWidgets.QRadioButton(self.centralwidget)
        self.radioButton_H_VS_P.setGeometry(QtCore.QRect(140, 260, 151, 20))
        font = QtGui.QFont()
        font.setPointSize(12)
        self.radioButton_H_VS_P.setFont(font)
        self.radioButton_H_VS_P.setChecked(True)
        self.radioButton_H_VS_P.setObjectName("radioButton_H_VS_P")
        self.buttonGroup.addButton(self.radioButton_H_VS_P)
        self.radioButton_P_VS_P = QtWidgets.QRadioButton(self.centralwidget)
        self.radioButton_P_VS_P.setGeometry(QtCore.QRect(140, 300, 111, 20))
        font = QtGui.QFont()
        font.setPointSize(12)
        self.radioButton_P_VS_P.setFont(font)
        self.radioButton_P_VS_P.setObjectName("radioButton_P_VS_P")
        self.buttonGroup.addButton(self.radioButton_P_VS_P)
        self.radioButton_black = QtWidgets.QRadioButton(self.centralwidget)
        self.radioButton_black.setGeometry(QtCore.QRect(350, 260, 71, 21))
        font = QtGui.QFont()
        font.setPointSize(12)
        self.radioButton_black.setFont(font)
        self.radioButton_black.setChecked(True)
        self.radioButton_black.setObjectName("radioButton_black")
        self.buttonGroup_2 = QtWidgets.QButtonGroup(Menu)
        self.buttonGroup_2.setObjectName("buttonGroup_2")
        self.buttonGroup_2.addButton(self.radioButton_black)
        self.radioButton_white = QtWidgets.QRadioButton(self.centralwidget)
        self.radioButton_white.setGeometry(QtCore.QRect(430, 260, 81, 20))
        font = QtGui.QFont()
        font.setPointSize(12)
        self.radioButton_white.setFont(font)
        self.radioButton_white.setObjectName("radioButton_white")
        self.buttonGroup_2.addButton(self.radioButton_white)
        self.pushButton_START = QtWidgets.QPushButton(self.centralwidget)
        self.pushButton_START.setGeometry(QtCore.QRect(220, 360, 93, 28))
        font = QtGui.QFont()
        font.setPointSize(12)
        self.pushButton_START.setFont(font)
        self.pushButton_START.setObjectName("pushButton_START")
        Menu.setCentralWidget(self.centralwidget)
        self.statusbar = QtWidgets.QStatusBar(Menu)
        self.statusbar.setObjectName("statusbar")
        Menu.setStatusBar(self.statusbar)

        self.retranslateUi(Menu)
        QtCore.QMetaObject.connectSlotsByName(Menu)

    def retranslateUi(self, Menu):
        _translate = QtCore.QCoreApplication.translate
        Menu.setWindowTitle(_translate("Menu", "Menu"))
        self.label.setText(_translate("Menu", "Welcome to Othello"))
        self.label_2.setText(_translate("Menu", "Choose Game Mode"))
        self.radioButton_H_VS_H.setText(_translate("Menu", "Human VS Human"))
        self.radioButton_H_VS_P.setText(_translate("Menu", "Human VS PC"))
        self.radioButton_P_VS_P.setText(_translate("Menu", "PC VS PC"))
        self.radioButton_black.setText(_translate("Menu", "Black"))
        self.radioButton_white.setText(_translate("Menu", "White"))
        self.pushButton_START.setText(_translate("Menu", "START"))


if __name__ == "__main__":
    import sys
    app = QtWidgets.QApplication(sys.argv)
    Menu = QtWidgets.QMainWindow()
    ui = Ui_Menu()
    ui.setupUi(Menu)
    Menu.show()
    sys.exit(app.exec_())
