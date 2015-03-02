#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <vector>
#include "timeline.h"
class Timeline;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    NewTimelineGraphicsView(QGraphicsView *view);
    DeleteTimelineGraphicsView(QGraphicsView *view);

public slots:
    addTimeline();

private:
    Ui::MainWindow *ui;
    std::vector<Timeline*> timelines;

};

#endif // MAINWINDOW_H
