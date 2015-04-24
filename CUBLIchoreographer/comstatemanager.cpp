#include "comstatemanager.h"

#define TOSTATE prev_state=state;progress=0;state=
ComStateManager::ComStateManager() :
    ComStateManager(NULL)
{

}

ComStateManager::ComStateManager(MainWindow* parentWindow) :
    parent(parentWindow)
{
    state=COM_STATE_START;
    prev_state=state;
    progress=0;
    action=0;
}

ComStateManager::~ComStateManager()
{

}

//TODO: decide to rename message_code to received_mcode
ComStateManager::update(com_mcode message_code, char* extra_content, com_id sender)
{

    switch(state) {

        case COM_STATE_START :
            switch(message_code)
            {
                case COM_MCODE_NOMESSAGE :
                    break;
                default :
                    // received any message
                    TOSTATE COM_STATE_CHECK;
                    break;
            }
            break;

        case COM_STATE_CHECK :
            switch(message_code)
            {
                case COM_MCODE_CHECK :
                    parent->sendMessage(COM_MCODE_ANSWER, "", COM_ID_ALL);
                    break;
                case COM_MCODE_ANSWER :
                    printf("ANSWERED, OVER");
                    TOSTATE COM_STATE_ANSWERED;
                    break;
                case COM_MCODE_NOMESSAGE :
                    parent->sendMessage(COM_MCODE_CHECK, "", COM_ID_ALL);
                    break;
            default :
                parent->sendMessage(COM_MCODE_CHECK, "", COM_ID_ALL);
                break;
            }
            break;

        case COM_STATE_ANSWERED :
            switch(message_code)
            {
                case COM_MCODE_CHECK :
                    parent->sendMessage(COM_MCODE_ANSWER, "", COM_ID_ALL);
                    break;
            }
            break;

    }

}
