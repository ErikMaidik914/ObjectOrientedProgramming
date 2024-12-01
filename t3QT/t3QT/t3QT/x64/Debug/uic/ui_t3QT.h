/********************************************************************************
** Form generated from reading UI file 't3QT.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_T3QT_H
#define UI_T3QT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_t3QTClass
{
public:
    QWidget *centralWidget;
    QListWidget *listWidget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *t3QTClass)
    {
        if (t3QTClass->objectName().isEmpty())
            t3QTClass->setObjectName("t3QTClass");
        t3QTClass->resize(600, 400);
        centralWidget = new QWidget(t3QTClass);
        centralWidget->setObjectName("centralWidget");
        listWidget = new QListWidget(centralWidget);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(105, 40, 321, 192));
        t3QTClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(t3QTClass);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 600, 21));
        t3QTClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(t3QTClass);
        mainToolBar->setObjectName("mainToolBar");
        t3QTClass->addToolBar(Qt::ToolBarArea::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(t3QTClass);
        statusBar->setObjectName("statusBar");
        t3QTClass->setStatusBar(statusBar);

        retranslateUi(t3QTClass);

        QMetaObject::connectSlotsByName(t3QTClass);
    } // setupUi

    void retranslateUi(QMainWindow *t3QTClass)
    {
        t3QTClass->setWindowTitle(QCoreApplication::translate("t3QTClass", "t3QT", nullptr));
    } // retranslateUi

};

namespace Ui {
    class t3QTClass: public Ui_t3QTClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_T3QT_H
