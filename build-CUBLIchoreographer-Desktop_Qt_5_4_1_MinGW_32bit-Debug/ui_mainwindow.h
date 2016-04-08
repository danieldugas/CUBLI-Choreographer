/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *serialSettings;
    QWidget *MainWidget;
    QVBoxLayout *verticalLayout;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QWidget *DEBUG;
    QVBoxLayout *verticalLayout_3;
    QLabel *WidgetLabel;
    QGridLayout *DebugInputGrid;
    QPushButton *C4B1;
    QLabel *C4L;
    QPushButton *C5B2;
    QPushButton *C5B1;
    QPushButton *C4B2;
    QPushButton *C5B3;
    QLabel *C5L;
    QPushButton *C4B3;
    QPushButton *C5B4;
    QPushButton *C5B5;
    QPushButton *C4B4;
    QLabel *C2L;
    QPushButton *C2B2;
    QPushButton *C2B1;
    QPushButton *C4B5;
    QPushButton *C2B3;
    QLabel *StateLabel;
    QLabel *NewcubliLabel;
    QLabel *Cubli2Label;
    QTextEdit *serialData;
    QTextEdit *sendTextEdit;
    QPushButton *sendButton;
    QGridLayout *MainLayout;
    QWidget *optionsWidget;
    QGridLayout *gridLayout_2;
    QGridLayout *OptionGrid;
    QSpacerItem *verticalSpacer_2;
    QLabel *primitiveTitle;
    QLabel *primitiveDescription;
    QVBoxLayout *rendererWidget;
    QGraphicsView *rendererGraphicsView;
    QScrollArea *timelineScrollArea;
    QWidget *timelinesWidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *timelineLayout;
    QLabel *AddTimelineLabel;
    QPushButton *plusButton;
    QSpacerItem *verticalSpacer;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *applyButton;
    QWidget *dockWidget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *playButton;
    QLabel *appInfoLabel;
    QMenuBar *menuBar;
    QMenu *menuCUBLI_Choreographer_V1;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(959, 795);
        MainWindow->setAutoFillBackground(false);
        MainWindow->setStyleSheet(QLatin1String("/*\n"
".QWidget\n"
"{\n"
"background: #454545;\n"
"}\n"
"\n"
"QGraphicsView\n"
"{\n"
"background: #D0D0D0;\n"
"}\n"
"\n"
"QPushButton\n"
"{\n"
"background: grey;\n"
"padding: 6px;\n"
"}\n"
"\n"
"QLabel {  color : white; }\n"
"\n"
"QPushButton#pushButton {\n"
"    width: 0;\n"
"	height: 0;\n"
"	border-top: 25px solid transparent;\n"
"	border-left: 50px solid green;\n"
"	border-bottom: 25px solid transparent;\n"
"}\n"
"*/\n"
"QLabel#appInfoLabel\n"
"{\n"
"color: white;\n"
"}\n"
"QWidget#dockWidget\n"
"{\n"
"background : #505050;\n"
"}"));
        serialSettings = new QAction(MainWindow);
        serialSettings->setObjectName(QStringLiteral("serialSettings"));
        MainWidget = new QWidget(MainWindow);
        MainWidget->setObjectName(QStringLiteral("MainWidget"));
        MainWidget->setAutoFillBackground(true);
        verticalLayout = new QVBoxLayout(MainWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        centralWidget = new QWidget(MainWidget);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setAutoFillBackground(true);
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(15);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        DEBUG = new QWidget(centralWidget);
        DEBUG->setObjectName(QStringLiteral("DEBUG"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(DEBUG->sizePolicy().hasHeightForWidth());
        DEBUG->setSizePolicy(sizePolicy);
        verticalLayout_3 = new QVBoxLayout(DEBUG);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        WidgetLabel = new QLabel(DEBUG);
        WidgetLabel->setObjectName(QStringLiteral("WidgetLabel"));

        verticalLayout_3->addWidget(WidgetLabel);

        DebugInputGrid = new QGridLayout();
        DebugInputGrid->setSpacing(6);
        DebugInputGrid->setObjectName(QStringLiteral("DebugInputGrid"));
        C4B1 = new QPushButton(DEBUG);
        C4B1->setObjectName(QStringLiteral("C4B1"));

        DebugInputGrid->addWidget(C4B1, 1, 1, 1, 1);

        C4L = new QLabel(DEBUG);
        C4L->setObjectName(QStringLiteral("C4L"));

        DebugInputGrid->addWidget(C4L, 0, 1, 1, 1);

        C5B2 = new QPushButton(DEBUG);
        C5B2->setObjectName(QStringLiteral("C5B2"));

        DebugInputGrid->addWidget(C5B2, 2, 2, 1, 1);

        C5B1 = new QPushButton(DEBUG);
        C5B1->setObjectName(QStringLiteral("C5B1"));

        DebugInputGrid->addWidget(C5B1, 1, 2, 1, 1);

        C4B2 = new QPushButton(DEBUG);
        C4B2->setObjectName(QStringLiteral("C4B2"));

        DebugInputGrid->addWidget(C4B2, 2, 1, 1, 1);

        C5B3 = new QPushButton(DEBUG);
        C5B3->setObjectName(QStringLiteral("C5B3"));

        DebugInputGrid->addWidget(C5B3, 3, 2, 1, 1);

        C5L = new QLabel(DEBUG);
        C5L->setObjectName(QStringLiteral("C5L"));

        DebugInputGrid->addWidget(C5L, 0, 2, 1, 1);

        C4B3 = new QPushButton(DEBUG);
        C4B3->setObjectName(QStringLiteral("C4B3"));

        DebugInputGrid->addWidget(C4B3, 3, 1, 1, 1);

        C5B4 = new QPushButton(DEBUG);
        C5B4->setObjectName(QStringLiteral("C5B4"));

        DebugInputGrid->addWidget(C5B4, 4, 2, 1, 1);

        C5B5 = new QPushButton(DEBUG);
        C5B5->setObjectName(QStringLiteral("C5B5"));

        DebugInputGrid->addWidget(C5B5, 5, 2, 1, 1);

        C4B4 = new QPushButton(DEBUG);
        C4B4->setObjectName(QStringLiteral("C4B4"));

        DebugInputGrid->addWidget(C4B4, 4, 1, 1, 1);

        C2L = new QLabel(DEBUG);
        C2L->setObjectName(QStringLiteral("C2L"));

        DebugInputGrid->addWidget(C2L, 0, 0, 1, 1);

        C2B2 = new QPushButton(DEBUG);
        C2B2->setObjectName(QStringLiteral("C2B2"));

        DebugInputGrid->addWidget(C2B2, 2, 0, 1, 1);

        C2B1 = new QPushButton(DEBUG);
        C2B1->setObjectName(QStringLiteral("C2B1"));

        DebugInputGrid->addWidget(C2B1, 1, 0, 1, 1);

        C4B5 = new QPushButton(DEBUG);
        C4B5->setObjectName(QStringLiteral("C4B5"));

        DebugInputGrid->addWidget(C4B5, 5, 1, 1, 1);

        C2B3 = new QPushButton(DEBUG);
        C2B3->setObjectName(QStringLiteral("C2B3"));

        DebugInputGrid->addWidget(C2B3, 3, 0, 1, 1);


        verticalLayout_3->addLayout(DebugInputGrid);

        StateLabel = new QLabel(DEBUG);
        StateLabel->setObjectName(QStringLiteral("StateLabel"));

        verticalLayout_3->addWidget(StateLabel);

        NewcubliLabel = new QLabel(DEBUG);
        NewcubliLabel->setObjectName(QStringLiteral("NewcubliLabel"));

        verticalLayout_3->addWidget(NewcubliLabel);

        Cubli2Label = new QLabel(DEBUG);
        Cubli2Label->setObjectName(QStringLiteral("Cubli2Label"));

        verticalLayout_3->addWidget(Cubli2Label);

        serialData = new QTextEdit(DEBUG);
        serialData->setObjectName(QStringLiteral("serialData"));
        serialData->setMinimumSize(QSize(0, 20));

        verticalLayout_3->addWidget(serialData);

        sendTextEdit = new QTextEdit(DEBUG);
        sendTextEdit->setObjectName(QStringLiteral("sendTextEdit"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(sendTextEdit->sizePolicy().hasHeightForWidth());
        sendTextEdit->setSizePolicy(sizePolicy1);
        sendTextEdit->setMinimumSize(QSize(0, 0));
        sendTextEdit->setMaximumSize(QSize(16777215, 30));
        sendTextEdit->setToolTipDuration(78);

        verticalLayout_3->addWidget(sendTextEdit);

        sendButton = new QPushButton(DEBUG);
        sendButton->setObjectName(QStringLiteral("sendButton"));

        verticalLayout_3->addWidget(sendButton);


        gridLayout->addWidget(DEBUG, 1, 1, 1, 1);

        MainLayout = new QGridLayout();
        MainLayout->setSpacing(6);
        MainLayout->setObjectName(QStringLiteral("MainLayout"));
        optionsWidget = new QWidget(centralWidget);
        optionsWidget->setObjectName(QStringLiteral("optionsWidget"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(optionsWidget->sizePolicy().hasHeightForWidth());
        optionsWidget->setSizePolicy(sizePolicy2);
        optionsWidget->setMinimumSize(QSize(0, 0));
        optionsWidget->setAutoFillBackground(true);
        gridLayout_2 = new QGridLayout(optionsWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        OptionGrid = new QGridLayout();
        OptionGrid->setSpacing(6);
        OptionGrid->setObjectName(QStringLiteral("OptionGrid"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        OptionGrid->addItem(verticalSpacer_2, 7, 1, 1, 1);

        primitiveTitle = new QLabel(optionsWidget);
        primitiveTitle->setObjectName(QStringLiteral("primitiveTitle"));
        primitiveTitle->setMinimumSize(QSize(0, 20));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        primitiveTitle->setFont(font);

        OptionGrid->addWidget(primitiveTitle, 1, 1, 1, 1);

        primitiveDescription = new QLabel(optionsWidget);
        primitiveDescription->setObjectName(QStringLiteral("primitiveDescription"));

        OptionGrid->addWidget(primitiveDescription, 2, 1, 1, 1);


        gridLayout_2->addLayout(OptionGrid, 0, 0, 1, 1);

        rendererWidget = new QVBoxLayout();
        rendererWidget->setSpacing(6);
        rendererWidget->setObjectName(QStringLiteral("rendererWidget"));
        rendererGraphicsView = new QGraphicsView(optionsWidget);
        rendererGraphicsView->setObjectName(QStringLiteral("rendererGraphicsView"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(rendererGraphicsView->sizePolicy().hasHeightForWidth());
        rendererGraphicsView->setSizePolicy(sizePolicy3);

        rendererWidget->addWidget(rendererGraphicsView);


        gridLayout_2->addLayout(rendererWidget, 0, 2, 1, 1);


        MainLayout->addWidget(optionsWidget, 1, 0, 1, 1);

        timelineScrollArea = new QScrollArea(centralWidget);
        timelineScrollArea->setObjectName(QStringLiteral("timelineScrollArea"));
        timelineScrollArea->setMinimumSize(QSize(0, 200));
        timelineScrollArea->setAutoFillBackground(true);
        timelineScrollArea->setWidgetResizable(true);
        timelinesWidget = new QWidget();
        timelinesWidget->setObjectName(QStringLiteral("timelinesWidget"));
        timelinesWidget->setGeometry(QRect(0, 0, 648, 316));
        verticalLayout_2 = new QVBoxLayout(timelinesWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        timelineLayout = new QVBoxLayout();
        timelineLayout->setSpacing(6);
        timelineLayout->setObjectName(QStringLiteral("timelineLayout"));
        timelineLayout->setSizeConstraint(QLayout::SetDefaultConstraint);

        verticalLayout_2->addLayout(timelineLayout);

        AddTimelineLabel = new QLabel(timelinesWidget);
        AddTimelineLabel->setObjectName(QStringLiteral("AddTimelineLabel"));

        verticalLayout_2->addWidget(AddTimelineLabel);

        plusButton = new QPushButton(timelinesWidget);
        plusButton->setObjectName(QStringLiteral("plusButton"));
        QSizePolicy sizePolicy4(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(plusButton->sizePolicy().hasHeightForWidth());
        plusButton->setSizePolicy(sizePolicy4);
        plusButton->setMinimumSize(QSize(100, 110));
        plusButton->setMaximumSize(QSize(10000, 110));

        verticalLayout_2->addWidget(plusButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        timelineScrollArea->setWidget(timelinesWidget);

        MainLayout->addWidget(timelineScrollArea, 2, 0, 1, 1);

        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        applyButton = new QPushButton(widget);
        applyButton->setObjectName(QStringLiteral("applyButton"));

        horizontalLayout->addWidget(applyButton);


        MainLayout->addWidget(widget, 3, 0, 1, 1);


        gridLayout->addLayout(MainLayout, 1, 0, 1, 1);


        verticalLayout->addWidget(centralWidget);

        dockWidget = new QWidget(MainWidget);
        dockWidget->setObjectName(QStringLiteral("dockWidget"));
        dockWidget->setAutoFillBackground(false);
        horizontalLayout_2 = new QHBoxLayout(dockWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        playButton = new QPushButton(dockWidget);
        playButton->setObjectName(QStringLiteral("playButton"));
        playButton->setEnabled(true);
        sizePolicy3.setHeightForWidth(playButton->sizePolicy().hasHeightForWidth());
        playButton->setSizePolicy(sizePolicy3);
        playButton->setMinimumSize(QSize(50, 50));
        playButton->setMaximumSize(QSize(50, 50));
        playButton->setBaseSize(QSize(0, 0));
        playButton->setAutoFillBackground(false);
        playButton->setStyleSheet(QStringLiteral(""));

        horizontalLayout_2->addWidget(playButton);

        appInfoLabel = new QLabel(dockWidget);
        appInfoLabel->setObjectName(QStringLiteral("appInfoLabel"));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        appInfoLabel->setPalette(palette);
        QFont font1;
        font1.setPointSize(8);
        appInfoLabel->setFont(font1);
        appInfoLabel->setStyleSheet(QStringLiteral(""));

        horizontalLayout_2->addWidget(appInfoLabel);


        verticalLayout->addWidget(dockWidget);

        MainWindow->setCentralWidget(MainWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 959, 20));
        menuCUBLI_Choreographer_V1 = new QMenu(menuBar);
        menuCUBLI_Choreographer_V1->setObjectName(QStringLiteral("menuCUBLI_Choreographer_V1"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuCUBLI_Choreographer_V1->menuAction());
        menuCUBLI_Choreographer_V1->addAction(serialSettings);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        serialSettings->setText(QApplication::translate("MainWindow", "Serial Port Settings", 0));
        WidgetLabel->setText(QApplication::translate("MainWindow", "TEST & DEBUG", 0));
        C4B1->setText(QApplication::translate("MainWindow", "Waiting", 0));
        C4L->setText(QApplication::translate("MainWindow", "Newcubli (4)", 0));
        C5B2->setText(QApplication::translate("MainWindow", "Received", 0));
        C5B1->setText(QApplication::translate("MainWindow", "Waiting", 0));
        C4B2->setText(QApplication::translate("MainWindow", "Received", 0));
        C5B3->setText(QApplication::translate("MainWindow", "Connect", 0));
        C5L->setText(QApplication::translate("MainWindow", "Cubli2 (5)", 0));
        C4B3->setText(QApplication::translate("MainWindow", "Connect", 0));
        C5B4->setText(QApplication::translate("MainWindow", "...", 0));
        C5B5->setText(QApplication::translate("MainWindow", "...", 0));
        C4B4->setText(QApplication::translate("MainWindow", "...", 0));
        C2L->setText(QApplication::translate("MainWindow", "Button codes", 0));
        C2B2->setText(QApplication::translate("MainWindow", "...", 0));
        C2B1->setText(QApplication::translate("MainWindow", "Debug", 0));
        C4B5->setText(QApplication::translate("MainWindow", "...", 0));
        C2B3->setText(QApplication::translate("MainWindow", "...", 0));
        StateLabel->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        NewcubliLabel->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        Cubli2Label->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        sendButton->setText(QApplication::translate("MainWindow", "Send", 0));
        primitiveTitle->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        primitiveDescription->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        AddTimelineLabel->setText(QString());
        plusButton->setText(QApplication::translate("MainWindow", "+", 0));
        applyButton->setText(QApplication::translate("MainWindow", "Apply", 0));
        playButton->setText(QApplication::translate("MainWindow", "Play", 0));
        appInfoLabel->setText(QString());
        menuCUBLI_Choreographer_V1->setTitle(QApplication::translate("MainWindow", "Settings", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
