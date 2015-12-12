/********************************************************************************
** Form generated from reading UI file 'huffman_window.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HUFFMAN_WINDOW_H
#define UI_HUFFMAN_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Huffman_window
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QTextBrowser *textBrowser;
    QHBoxLayout *horizontalLayout;
    QPushButton *button_for_more;
    QSpacerItem *horizontalSpacer;
    QPushButton *button_for_coding;
    QPushButton *button_for_decoding;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Huffman_window)
    {
        if (Huffman_window->objectName().isEmpty())
            Huffman_window->setObjectName(QStringLiteral("Huffman_window"));
        Huffman_window->resize(600, 400);
        centralWidget = new QWidget(Huffman_window);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout_2 = new QHBoxLayout(centralWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));

        verticalLayout->addWidget(textBrowser);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        button_for_more = new QPushButton(centralWidget);
        button_for_more->setObjectName(QStringLiteral("button_for_more"));
        button_for_more->setEnabled(true);
        button_for_more->setMinimumSize(QSize(75, 23));

        horizontalLayout->addWidget(button_for_more);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        button_for_coding = new QPushButton(centralWidget);
        button_for_coding->setObjectName(QStringLiteral("button_for_coding"));
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(14);
        font.setBold(false);
        font.setWeight(50);
        button_for_coding->setFont(font);

        horizontalLayout->addWidget(button_for_coding);

        button_for_decoding = new QPushButton(centralWidget);
        button_for_decoding->setObjectName(QStringLiteral("button_for_decoding"));
        button_for_decoding->setFont(font);

        horizontalLayout->addWidget(button_for_decoding);


        verticalLayout->addLayout(horizontalLayout);


        horizontalLayout_2->addLayout(verticalLayout);

        Huffman_window->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Huffman_window);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 23));
        Huffman_window->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Huffman_window);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Huffman_window->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Huffman_window);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Huffman_window->setStatusBar(statusBar);

        retranslateUi(Huffman_window);

        QMetaObject::connectSlotsByName(Huffman_window);
    } // setupUi

    void retranslateUi(QMainWindow *Huffman_window)
    {
        Huffman_window->setWindowTitle(QApplication::translate("Huffman_window", "Huffman Codec", 0));
        button_for_more->setText(QApplication::translate("Huffman_window", "More..", 0));
        button_for_coding->setText(QApplication::translate("Huffman_window", "Huffman encoding", 0));
        button_for_decoding->setText(QApplication::translate("Huffman_window", "Decoding", 0));
    } // retranslateUi

};

namespace Ui {
    class Huffman_window: public Ui_Huffman_window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HUFFMAN_WINDOW_H
