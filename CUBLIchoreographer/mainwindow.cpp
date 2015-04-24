#include "mainwindow.h"
#include "ui_mainwindow.h"

extern char   _sequence[];
extern size_t _seq_len;

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

    comstatemanager = new ComStateManager(this);


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
    ui->serialTextEdit->moveCursor (QTextCursor::End);
    ui->serialTextEdit->insertPlainText(text);
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
    QByteArray dataread = serialmanager->read();
    int i = 0;
    for(i = 0; i < dataread.length();i++)
    {
        this->showSerialData(QString(dataread.data()[i]));
    }

    com_mcode message_code = COM_MCODE_NOMESSAGE;
    com_id sender;
    char extra_content[] = "";
    size_t chars_read;
    chars_read = decrypt_message(dataread.data(),dataread.length(),&sender, &message_code,extra_content);
    if(chars_read)
    {
        comstatemanager->update(message_code,extra_content,sender);
        ui->textEdit->append("decrypted");
    }
}

MainWindow::sendData()
{
    serialmanager->write((ui->sendTextEdit->toPlainText()).toStdString().c_str());

    comstatemanager->update(COM_MCODE_ERROR,"",COM_ID_NEWCUBLI);
}

MainWindow::sendMessage(com_mcode message_code, char * extra_content, com_id recipient)
{
    //creates the wrapped sequence, converts it to QByteArray and writes it to port
    send_message(message_code,extra_content,recipient);
    QByteArray messagedata = QByteArray(_sequence,_seq_len);
    this->showSerialData(">>");
    for(int i = 0; i < _seq_len; i++) { this->showSerialData(QString(_sequence[i])); }
    this->showSerialData("\r\n");
    serialmanager->write(messagedata);

    //Debugging
#ifdef CHOREOGRAPHER_DEBUG
    ui->serialTextEdit->setText(">>: ");
    for(int i = 0; i < _seq_len; i++) {
#include "C:\Users\daniel\skydrive\files\development\c\toolbox\to_binary.c"
        char bin[9]; to_binary((unsigned long long)_sequence[i],1,bin);
        ui->serialTextEdit->insertPlainText(QString(_sequence[i]));
        ui->serialTextEdit->insertPlainText(":");
        ui->textEdit->insertPlainText(QString(bin));
        ui->textEdit->insertPlainText("|");
    }
#endif

}
