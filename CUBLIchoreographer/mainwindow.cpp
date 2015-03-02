#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QObject::connect(ui->addTimelineButton, SIGNAL(clicked()), this, SLOT(addTimeline()));
    //timelines.push_back(new Timeline(this));


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

MainWindow::NewTimelineGraphicsView(QGraphicsView *view)
{
    ui->timelineLayout->addWidget(view);
    view->setFixedHeight(110);
}

MainWindow::DeleteTimelineGraphicsView(QGraphicsView *view)
{
    ui->timelineLayout->removeWidget(view);

}
