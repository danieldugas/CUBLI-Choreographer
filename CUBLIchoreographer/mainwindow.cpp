#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->addTimelineButton,  SIGNAL(clicked()),  this,   SLOT(addTimeline())         );
    //timelines.push_back(new Timeline(this));


    serialmanager = new SerialManager(this);
    connect(ui->toolButton,         SIGNAL(clicked()),  this,   SLOT(showSettingsDialog())  );
    connect(ui->connectButton,      SIGNAL(clicked()),  this,   SLOT(openSerialPort())      );
    connect(ui->sendButton,         SIGNAL(clicked()),  this,   SLOT(sendData())            );
    connect(serialmanager->serial,  SIGNAL(readyRead()),this,   SLOT(readData())            );




    //QByteArray data = "Hello";
    //serialmanager->setSerialPort("COM5", 115200);
    //serialmanager->write(data);

    //deal with widget sizes
    ui->addTimelineButton->setFixedSize(100,100);
    ui->renderererGraphicsView->setFixedSize(200,200);
}

MainWindow::~MainWindow()
{
    delete ui;
}

MainWindow::addTimeline()
{
    timelines.push_back(new Timeline(this));
}

MainWindow::showSettingsDialog()
{
    serialmanager->showSettingsDialog();
}

MainWindow::showSerialStatus(const QString& text)
{
    ui->textEdit->setText(text);
    ui->textEdit->verticalScrollBar()->setValue(ui->textEdit->verticalScrollBar()->maximum()); // Scrolls to the bottom

}

MainWindow::showSerialData(const QString& text)
{
    ui->serialTextEdit->append(text);
    ui->serialTextEdit->verticalScrollBar()->setValue(ui->serialTextEdit->verticalScrollBar()->maximum()); // Scrolls to the bottom

}

MainWindow::openSerialPort()
{
    serialmanager->openSerialPort();
}

MainWindow::NewTimelineGraphicsView(QGraphicsView *view)
{
    ui->timelineLayout->addWidget(view);
    view->setFixedHeight(110);
}

MainWindow::DeleteTimelineGraphicsView(QGraphicsView *view)
{
    ui->timelineLayout->removeWidget(view);

}

MainWindow::readData()
{
    serialmanager->read();
}

MainWindow::sendData()
{
    serialmanager->write((ui->sendTextEdit->toPlainText()).toStdString().c_str());
}
