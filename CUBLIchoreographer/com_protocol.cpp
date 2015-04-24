#include "com_protocol.h"

// INFO
//
// With the exception of lines of code marked with 'CHANGED'
// this is a copy of the com_protocol.c in the cubli project
// TODO: Turn this into a class

// CHANGED: added global passing variable=
char   _sequence[64];
size_t _seq_len = 0;

// Private Protocol Parameters
#define HASH_SIZE (2)
#define MESSAGE_CODE_SIZE (1)
#define MAX_PACKET_SIZE (128/4) // CHANGED: 128 is RX_SIZE in original file
#define MAX_MESSAGE_SIZE (100)
#define STRT_BYTE (0xFF)
#define END_BYTE (0xFE)

com_id this_pc_id = COM_ID_COMPUTER; // CHANGED: _cubliParameters.this_cube_id in original file

unsigned long generate_hash(char *key)
{
    //This function generates the hash for a char sequence
    //according to the bitwise XOR bernstein algorithm

    unsigned long hash = 0;

    while(*key)
    {
        hash = (33 * hash) ^ (unsigned char)*key++;
    }

    return hash;
}

int compare_hash(unsigned long hash1, unsigned long hash2)
{

    
    unsigned long MASK = 0x00000000;
    unsigned long FIRST_BYTE = 0x000000FF;
    size_t i;
    for(i = 0; i < HASH_SIZE; i++) { MASK |= FIRST_BYTE << i*8; }


    return ( (hash1 & MASK) == (hash2 & MASK) );

}

int send_message(com_mcode message_code, char* extra_content, com_id dest_id)
{
    // Creates a protocol-conforming sequence from the message code

#ifdef COM_DEBUG
    printf("<Debug: in function send_message\r\n");
#endif

    int i;
        char message[MAX_MESSAGE_SIZE] = {0};
        message[0]=(char)message_code;
        strcat(message,extra_content);
        strcat(message,".");
#ifdef COM_VERBOSE
        // When debugging append verbose message reference
        strcat(message,msg_code_strings[message_code]);
        strcat(message,extra_content);
#endif
    int len = strlen(message);
    int seq_len = 1+1+2+len+HASH_SIZE+1;
    char sequence[MAX_PACKET_SIZE] = {0};
    unsigned long hash = 0;

    sequence[0] = STRT_BYTE; //Startbyte
    sequence[1] = (char)len; //Message Length
    sequence[2] = (char)this_pc_id; //Sender // CHANGED: see this_pc_id
    sequence[3] = (char)dest_id; //Recipient
    for(i = 0; i < len; i++) { sequence[4+i] = message[i]; } //Message
    hash = generate_hash(sequence);
    for(i = 0; i < HASH_SIZE; i++) { 
        sequence[4+len+i] = (hash >> (i*8)) & 0xFF; } //Hash
    sequence[seq_len-1] = END_BYTE; //Endbyte
    
    // Outputs sequence
    for(i = 0; i < seq_len; i++) { _sequence[i] = sequence[i];} // CHANGED: is a printf in the original file
    _seq_len = seq_len; // CHANGED: Added this line

    
#ifdef COM_DEBUG
    printf("hash=%lu",hash);
    printf(">\r\n");
#endif

    return 0;
}

size_t decrypt_message(char* buffer, unsigned int max_bytes,
        com_id* sender, com_mcode* message_code, char* extra_content)
{
    // This Function checks if the first max_bytes bytes in a buffer
    // contain a valid message, and unwraps it if the recipient is
    // this cube.

#ifdef COM_DEBUG
    printf("<Debug: in function decrypt_message\r\n");
#endif

    // declarations
    size_t i = 0;
    size_t count = 0;
    size_t chars_read = 0;
    char sequence[MAX_PACKET_SIZE] = {0};
    int len = 0;
    int seq_len = 0;
    com_id recipient;
    unsigned long hash = 0;
    *message_code = COM_MCODE_NOMESSAGE;

    // ignore anything before a start byte
    while((unsigned char)buffer[i]!=STRT_BYTE && i<max_bytes) { 
        i++; }
    // extract sequence until end byte
    while((unsigned char)buffer[i]!=END_BYTE && i<max_bytes) { 
        sequence[count] = buffer[i]; i++; count++; }
    //append end byte
    sequence[count] = END_BYTE; count++;
    chars_read = i;


    // read wrapped data
    len         = (int)sequence[1]; 
    seq_len     = 1+1+2+len+HASH_SIZE+1;
    *sender     = (com_id)sequence[2];
    recipient   = (com_id)sequence[3];

    // verify message length
    if(count != seq_len)
    {
#ifdef COM_DEBUG
        printf("Error in com_protocol decrypt_message: seq_len is %i,", count);
        printf(" should be %i.\r\n", seq_len);
        for(i = 0; i < max_bytes; i++) { printf("%c", buffer[i]);}
        printf("\n\r");
        printf(">\n\r");
#endif
        return 0;
    }

    // read message
    char message[MAX_MESSAGE_SIZE] = {0};
    for(i = 0; i < len; i++) { message[i] = sequence[4+i]; }
    // read hash
    for(i = 0; i < HASH_SIZE; i++) { 
        hash = ((unsigned char)sequence[4+len+i] << (i*8)) | hash; }
    sequence[4+len]=0; //prevent hash function from parsing last bytes

    // verify hash
    if( !compare_hash(hash,generate_hash(sequence)) ) {
#ifdef COM_DEBUG
        printf("Error in com_protocol decrypt_message: incorrect hash,");
        printf(" is %lu,", hash);
        printf(" should be %lu.\r\n", generate_hash(sequence));
        for(i = 0; i < max_bytes; i++) { printf("%c", buffer[i]);}
        printf("\n\r");
        printf(">\n\r");
#endif
        return 0; }

    //  verify recipient
    if((recipient!=this_pc_id) & (recipient!=COM_ID_ALL)) { // CHANGED: see this_pc_id
        return 0; }

    // read message code and content
    *message_code = (com_mcode)message[0];
    for(i = 0; i < COM_P_MAX_EXTRA_CONTENT_SIZE; i++) 
    {
       extra_content[i] = message[i+MESSAGE_CODE_SIZE]; 
       if(extra_content[i] == '.') { extra_content[i] = 0; break; }
    }

#ifdef COM_DEBUG
    //Debug: outputs buffer and sequence
    for(i = 0; i < max_bytes; i++) { printf("%c", buffer[i]);} printf("\n\r");
    for(i = 0; i < count; i++) { printf("%c", sequence[i]);} printf("\n\r");
    for(i = 0; i < len; i++) { printf("%c", message[i]);} printf("\n\r");
    printf(">\n\r");
#endif
    
    return chars_read;
}

// vim: set foldmethod=syntax:
