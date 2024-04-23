/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton_resize;
    QLabel *label;
    QPlainTextEdit *plainTextEdit;
    QPushButton *pushButton_location;
    QComboBox *comboBox;
    QProgressBar *progressBar;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QLabel *label_copyright;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(400, 370);
        MainWindow->setMinimumSize(QSize(400, 370));
        MainWindow->setMaximumSize(QSize(400, 370));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        pushButton_resize = new QPushButton(centralWidget);
        pushButton_resize->setObjectName(QString::fromUtf8("pushButton_resize"));
        pushButton_resize->setEnabled(false);
        pushButton_resize->setGeometry(QRect(210, 80, 171, 23));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 110, 371, 16));
        plainTextEdit = new QPlainTextEdit(centralWidget);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(10, 130, 371, 111));
        plainTextEdit->setReadOnly(true);
        pushButton_location = new QPushButton(centralWidget);
        pushButton_location->setObjectName(QString::fromUtf8("pushButton_location"));
        pushButton_location->setGeometry(QRect(10, 10, 371, 23));
        comboBox = new QComboBox(centralWidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(10, 80, 191, 23));
        progressBar = new QProgressBar(centralWidget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(10, 250, 371, 23));
        progressBar->setValue(0);
        radioButton = new QRadioButton(centralWidget);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setGeometry(QRect(210, 50, 103, 21));
        radioButton->setChecked(true);
        radioButton_2 = new QRadioButton(centralWidget);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
        radioButton_2->setGeometry(QRect(10, 50, 221, 21));
        label_copyright = new QLabel(centralWidget);
        label_copyright->setObjectName(QString::fromUtf8("label_copyright"));
        label_copyright->setGeometry(QRect(150, 280, 111, 16));
        QFont font;
        font.setFamily(QString::fromUtf8("DejaVu Sans"));
        font.setPointSize(7);
        label_copyright->setFont(font);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 20));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "ImgFolderResizer", nullptr));
        pushButton_resize->setText(QApplication::translate("MainWindow", "Skaluj zdj\304\231cia", nullptr));
        label->setText(QApplication::translate("MainWindow", "..", nullptr));
        pushButton_location->setText(QApplication::translate("MainWindow", "Otw\303\263rz folder ze zdj\304\231ciami", nullptr));
        comboBox->setItemText(0, QApplication::translate("MainWindow", "fotografia (h:1200px)", nullptr));
        comboBox->setItemText(1, QApplication::translate("MainWindow", "do artyku\305\202u (h:600px)", nullptr));
        comboBox->setItemText(2, QApplication::translate("MainWindow", "miniatura (h:200px)", nullptr));
        comboBox->setItemText(3, QApplication::translate("MainWindow", "Ikona (h:50px)", nullptr));

        radioButton->setText(QApplication::translate("MainWindow", "Nadpisz", nullptr));
        radioButton_2->setText(QApplication::translate("MainWindow", "Tw\303\263rz oddzielnie miniatury", nullptr));
        label_copyright->setText(QApplication::translate("MainWindow", "MF NoweEnergie.org", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
