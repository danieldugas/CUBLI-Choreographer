#ifndef SERIALMANAGER_H
#define SERIALMANAGER_H

#include <QtSerialPort/QSerialPort>
#include <QMessageBox>
#include <QObject>

#include "mainwindow.h"
#include "settingsdialog.h"

class MainWindow;


class SerialManager
{
public:
    SerialManager();
    SerialManager(MainWindow *parentWindow);
    ~SerialManager();
    int openSerialPort();
    void write(QByteArray writeData);
    showSettingsDialog();

    // SHOULD BE PRIVATE
    QSerialPort *serial;

    void read();


private:
    MainWindow *parent;
    SettingsDialog *settings;


};

#endif // SERIALMANAGER_H
