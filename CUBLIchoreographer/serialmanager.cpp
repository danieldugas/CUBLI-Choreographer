#include "serialmanager.h"

SerialManager::SerialManager(MainWindow *parentWindow) :
    parent(parentWindow)
{
    serial = new QSerialPort;
    settings = new SettingsDialog;

}

SerialManager::~SerialManager()
{

}

SerialManager::showSettingsDialog()
{
    settings->show();
}

int SerialManager::openSerialPort()
{
    if (serial->isOpen()) {serial->close();}
    SettingsDialog::Settings p = settings->settings();
    serial->setPortName(p.name);
    serial->setBaudRate(p.baudRate);
    serial->setDataBits(p.dataBits);
    serial->setParity(p.parity);
    serial->setStopBits(p.stopBits);
    serial->setFlowControl(p.flowControl);
    if (serial->open(QIODevice::ReadWrite)) {
            //ui->actionConnect->setEnabled(false);
            //ui->actionDisconnect->setEnabled(true);
            //ui->actionConfigure->setEnabled(false);
            parent->showSerialStatus(
            QObject::tr("Connected to %1 : %2, %3, %4, %5, %6")
                                               .arg(p.name).arg(p.stringBaudRate).arg(p.stringDataBits)
                                               .arg(p.stringParity).arg(p.stringStopBits).arg(p.stringFlowControl)
            );
    } else {
        QMessageBox::critical(parent, QObject::tr("Error"), serial->errorString());

        parent->showSerialStatus(QObject::tr("Open error"));
    }

    return 0;
}

void SerialManager::write(QByteArray writeData)
{
    serial->write(writeData);
}

void SerialManager::read()
{
    parent->showSerialData(QString(serial->readAll()));
}
