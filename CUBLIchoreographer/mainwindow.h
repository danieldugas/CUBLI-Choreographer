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
#include "com_protocol.h"
#include "comstatemanager.h"




// Circular dependencies
class SerialManager;
class Timeline;
class ComStateManager;

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
    sendMessage(com_mcode message_code, char * extra_content, com_id recipient);

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
    ComStateManager *comstatemanager;


};

#endif // MAINWINDOW_H
