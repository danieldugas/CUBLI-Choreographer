#include "timeline.h"

Timeline::Timeline(MainWindow *mom) : parent(mom)
{
    scene = new QGraphicsScene(parent);
    view = new QGraphicsView(scene, parent);
    parent->NewTimelineGraphicsView(view);

        QBrush blueBrush(Qt::blue);
            QPen outlinePen(Qt::black);
            outlinePen.setWidth(2);
        rectangle = scene->addRect(100, 0, 80, 100, outlinePen, blueBrush);

        rectangle->setFlag(QGraphicsItem::ItemIsMovable);
}

Timeline::~Timeline()
{
   //TODO: make sure all is gone.
   parent->DeleteTimelineGraphicsView(view);
}

