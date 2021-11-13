/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *AddButton;
    QPushButton *DeleteButton;
    QPushButton *Sliyanie;
    QSpinBox *spinBoxAdd;
    QSpinBox *spinBoxDelete;
    QSpinBox *spinBoxSliynue;
    QScrollBar *horizontalScrollBar;
    QScrollBar *verticalScrollBar;
    QGraphicsView *graphicsView;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(573, 388);
        MainWindow->setStyleSheet(QString::fromUtf8("color: rgb(255, 85, 0);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        AddButton = new QPushButton(centralwidget);
        AddButton->setObjectName(QString::fromUtf8("AddButton"));
        AddButton->setGeometry(QRect(380, 50, 111, 51));
        AddButton->setStyleSheet(QString::fromUtf8(""));
        DeleteButton = new QPushButton(centralwidget);
        DeleteButton->setObjectName(QString::fromUtf8("DeleteButton"));
        DeleteButton->setGeometry(QRect(380, 120, 111, 51));
        Sliyanie = new QPushButton(centralwidget);
        Sliyanie->setObjectName(QString::fromUtf8("Sliyanie"));
        Sliyanie->setGeometry(QRect(380, 190, 111, 51));
        spinBoxAdd = new QSpinBox(centralwidget);
        spinBoxAdd->setObjectName(QString::fromUtf8("spinBoxAdd"));
        spinBoxAdd->setGeometry(QRect(500, 60, 42, 22));
        spinBoxDelete = new QSpinBox(centralwidget);
        spinBoxDelete->setObjectName(QString::fromUtf8("spinBoxDelete"));
        spinBoxDelete->setGeometry(QRect(500, 130, 42, 22));
        spinBoxSliynue = new QSpinBox(centralwidget);
        spinBoxSliynue->setObjectName(QString::fromUtf8("spinBoxSliynue"));
        spinBoxSliynue->setGeometry(QRect(500, 200, 42, 22));
        horizontalScrollBar = new QScrollBar(centralwidget);
        horizontalScrollBar->setObjectName(QString::fromUtf8("horizontalScrollBar"));
        horizontalScrollBar->setGeometry(QRect(10, 320, 341, 20));
        horizontalScrollBar->setOrientation(Qt::Horizontal);
        verticalScrollBar = new QScrollBar(centralwidget);
        verticalScrollBar->setObjectName(QString::fromUtf8("verticalScrollBar"));
        verticalScrollBar->setGeometry(QRect(350, 20, 16, 311));
        verticalScrollBar->setOrientation(Qt::Vertical);
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(5, 20, 341, 301));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 573, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
#if QT_CONFIG(tooltip)
        MainWindow->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#aa557f;\"><br/></span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        AddButton->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        DeleteButton->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        Sliyanie->setText(QCoreApplication::translate("MainWindow", "\320\241\320\273\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
