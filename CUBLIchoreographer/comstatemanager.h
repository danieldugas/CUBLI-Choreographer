#ifndef COMSTATEMANAGER_H
#define COMSTATEMANAGER_H

#include "com_protocol.h"
#include "mainwindow.h"

class ComStateManager
{
public:
    ComStateManager();
    ComStateManager(MainWindow *parentWindow);
    ~ComStateManager();
    update(com_mcode message_code, char *extra_content, com_id sender);

private:
    MainWindow *parent;
    com_state state;
    com_state prev_state;
    int action;
    int progress;
};

#endif // COMSTATEMANAGER_H
