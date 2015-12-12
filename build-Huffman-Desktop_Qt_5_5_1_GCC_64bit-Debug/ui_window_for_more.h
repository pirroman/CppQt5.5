/********************************************************************************
** Form generated from reading UI file 'window_for_more.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOW_FOR_MORE_H
#define UI_WINDOW_FOR_MORE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_window_for_more
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QTableWidget *table_for_viewFrequencyChars;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QTableWidget *table_for_viewPrefixCode;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *button_for_close;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *window_for_more)
    {
        if (window_for_more->objectName().isEmpty())
            window_for_more->setObjectName(QStringLiteral("window_for_more"));
        window_for_more->resize(574, 420);
        centralWidget = new QWidget(window_for_more);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);

        verticalLayout->addWidget(label);

        table_for_viewFrequencyChars = new QTableWidget(centralWidget);
        table_for_viewFrequencyChars->setObjectName(QStringLiteral("table_for_viewFrequencyChars"));
        table_for_viewFrequencyChars->setAutoFillBackground(false);
        table_for_viewFrequencyChars->horizontalHeader()->setMinimumSectionSize(10);

        verticalLayout->addWidget(table_for_viewFrequencyChars);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        verticalLayout_2->addWidget(label_2);

        table_for_viewPrefixCode = new QTableWidget(centralWidget);
        table_for_viewPrefixCode->setObjectName(QStringLiteral("table_for_viewPrefixCode"));
        table_for_viewPrefixCode->horizontalHeader()->setMinimumSectionSize(10);

        verticalLayout_2->addWidget(table_for_viewPrefixCode);


        horizontalLayout->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        button_for_close = new QPushButton(centralWidget);
        button_for_close->setObjectName(QStringLiteral("button_for_close"));

        horizontalLayout_2->addWidget(button_for_close);


        verticalLayout_3->addLayout(horizontalLayout_2);


        gridLayout->addLayout(verticalLayout_3, 0, 0, 1, 1);

        window_for_more->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(window_for_more);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 574, 23));
        window_for_more->setMenuBar(menuBar);
        mainToolBar = new QToolBar(window_for_more);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        window_for_more->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(window_for_more);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        window_for_more->setStatusBar(statusBar);

        retranslateUi(window_for_more);

        QMetaObject::connectSlotsByName(window_for_more);
    } // setupUi

    void retranslateUi(QMainWindow *window_for_more)
    {
        window_for_more->setWindowTitle(QApplication::translate("window_for_more", "more...", 0));
        label->setText(QApplication::translate("window_for_more", "Frequency characters", 0));
        label_2->setText(QApplication::translate("window_for_more", "Code characters", 0));
        button_for_close->setText(QApplication::translate("window_for_more", "Close", 0));
    } // retranslateUi

};

namespace Ui {
    class window_for_more: public Ui_window_for_more {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW_FOR_MORE_H
