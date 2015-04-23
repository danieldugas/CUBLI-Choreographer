#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QScrollBar>
#include <vector>
#include "timeline.h"
#include "serialmanager.h"
#include "settingsdialog.h"

// Circular dependencies
class SerialManager;
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
    showSerialStatus(const QString& text);
    showSerialData(const QString& text);

private slots:
    addTimeline();
    showSettingsDialog();
    openSerialPort();
    readData();
    sendData();

private:
    Ui::MainWindow *ui;
    std::vector<Timeline*> timelines;
    SerialManager *serialmanager;


};

#endif // MAINWINDOW_H
