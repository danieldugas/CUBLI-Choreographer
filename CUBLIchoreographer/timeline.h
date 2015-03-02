#ifndef TIMELINE_H
#define TIMELINE_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include "mainwindow.h"
class MainWindow; // cyclic dependency otherwise.

class Timeline
{
public:
    Timeline(MainWindow *parent);
    ~Timeline();

private:
    QGraphicsScene *scene;
    QGraphicsView *view;
    QGraphicsRectItem *rectangle;
    MainWindow *parent;
    // TODO: Vector full of items?
};

#endif // TIMELINE_H
