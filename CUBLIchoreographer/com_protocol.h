#ifndef COM_PROTOCOL_H
#define COM_PROTOCOL_H

#pragma once


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Debugging flags
#define COM_VERBOSE
#define COM_DEBUG

// Public Com Parameters
#define COM_P_MAX_EXTRA_CONTENT_SIZE (4)

typedef enum comstates
{
    COM_STATE_START,
    COM_STATE_INITIALIZING,
    COM_STATE_SAYING,
    COM_STATE_TELLING,
    COM_STATE_CHECK,
    COM_STATE_ANSWERED
} com_state;

typedef enum CommunicationIDs {
    COM_ID_ALL = 0,
    COM_ID_COMPUTER = '1',
    COM_ID_OLDCUBLI = '2',
    COM_ID_NEWCUBLI = '3',
    COM_ID_CUBLI2   = '4'
} com_id;

typedef enum messagecodes
{
    COM_MCODE_NOMESSAGE,
    COM_MCODE_ERROR,
    COM_MCODE_CHECK,
    COM_MCODE_ANSWER,
    COM_MCODE_BGN_SND_TMLN,
    COM_N_MESSAGE_CODES // keep last: defines the size
} com_mcode;

#ifdef COM_VERBOSE
static const char *msg_code_strings[COM_N_MESSAGE_CODES+1] =
{
"",
"Error",
"Check",
"Answer",
"BeginSendTimeline:",
"ILLEGAL MCODE N"
};
#endif

int send_message(com_mcode message_code, char* extra_content, com_id dest_id);
size_t decrypt_message(char* buffer, unsigned int max_bytes,
        com_id* sender, com_mcode* message_code, char* extra_content);

#endif
