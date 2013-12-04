/********************************************************************************
** Form generated from reading UI file 'GLRender.ui'
**
** Created: Wed Dec 4 14:09:08 2013
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GLRENDER_H
#define UI_GLRENDER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>
#include "ccanvas.h"

QT_BEGIN_NAMESPACE

class Ui_GLRender
{
public:
    QAction *actionLoad;
    QAction *actionSave;
    QAction *actionExit;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    CCanvas *canvas;
    QMenuBar *menubar;
    QMenu *menuFile;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *GLRender)
    {
        if (GLRender->objectName().isEmpty())
            GLRender->setObjectName(QString::fromUtf8("GLRender"));
        GLRender->resize(800, 600);
        actionLoad = new QAction(GLRender);
        actionLoad->setObjectName(QString::fromUtf8("actionLoad"));
        actionSave = new QAction(GLRender);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionExit = new QAction(GLRender);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        centralwidget = new QWidget(GLRender);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        canvas = new CCanvas(centralwidget);
        canvas->setObjectName(QString::fromUtf8("canvas"));

        gridLayout->addWidget(canvas, 0, 0, 1, 1);

        GLRender->setCentralWidget(centralwidget);
        menubar = new QMenuBar(GLRender);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        GLRender->setMenuBar(menubar);
        statusbar = new QStatusBar(GLRender);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        GLRender->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menuFile->addAction(actionLoad);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionExit);

        retranslateUi(GLRender);
        QObject::connect(actionExit, SIGNAL(triggered()), GLRender, SLOT(close()));

        QMetaObject::connectSlotsByName(GLRender);
    } // setupUi

    void retranslateUi(QMainWindow *GLRender)
    {
        GLRender->setWindowTitle(QApplication::translate("GLRender", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionLoad->setText(QApplication::translate("GLRender", "Load", 0, QApplication::UnicodeUTF8));
        actionSave->setText(QApplication::translate("GLRender", "Save", 0, QApplication::UnicodeUTF8));
        actionExit->setText(QApplication::translate("GLRender", "Exit", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("GLRender", "File", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class GLRender: public Ui_GLRender {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GLRENDER_H
