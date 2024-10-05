/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label_Board;
    QPushButton *button_RollDice;
    QPushButton *button_BuyProperty;
    QPushButton *button_EndTurn;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        label_Board = new QLabel(centralwidget);
        label_Board->setObjectName("label_Board");
        label_Board->setGeometry(QRect(210, 20, 371, 381));
        button_RollDice = new QPushButton(centralwidget);
        button_RollDice->setObjectName("button_RollDice");
        button_RollDice->setGeometry(QRect(40, 70, 100, 32));
        button_BuyProperty = new QPushButton(centralwidget);
        button_BuyProperty->setObjectName("button_BuyProperty");
        button_BuyProperty->setGeometry(QRect(40, 120, 100, 32));
        button_EndTurn = new QPushButton(centralwidget);
        button_EndTurn->setObjectName("button_EndTurn");
        button_EndTurn->setGeometry(QRect(40, 170, 100, 32));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 23));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_Board->setText(QString());
        button_RollDice->setText(QCoreApplication::translate("MainWindow", "Roll Dice", nullptr));
        button_BuyProperty->setText(QCoreApplication::translate("MainWindow", "Buy Property", nullptr));
        button_EndTurn->setText(QCoreApplication::translate("MainWindow", "End Turn", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
