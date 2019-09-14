#include <rtthread.h>
#include <stdio.h>
#include <stdlib.h>
#include "amessage.pb-c.h"

static void protobuf_encode_decode(int argc, char *argv[])
{
    void *buf;                     // Buffer to store serialized data
    unsigned msg_len;              // Length of serialized data

    if (argc != 3)
    {
        rt_kprintf("Usage: %s a b\n", argv[0]);
        return ;
    }

    // Encode message to buffer
    {
        rt_kprintf("---- Encoding ---\n");
        AMessage encode_msg = AMESSAGE__INIT;

        encode_msg.has_a  = 1;
        encode_msg.a      = atoi(argv[1]);
        encode_msg.has_b  = 1;
        encode_msg.b      = atoi(argv[2]); 

        msg_len = amessage__get_packed_size(&encode_msg);
        buf = malloc(msg_len);

        rt_kprintf("Encoding %d serialized bytes\n", msg_len);
        amessage__pack(&encode_msg, buf);
    }

    // Unpack the message from buffer.
    {
        rt_kprintf("---- Decoding ---\n");

        AMessage* decode_msg;
        decode_msg = amessage__unpack(NULL, msg_len, buf);
        if (decode_msg == NULL)
        {
          rt_kprintf("Error unpacking incoming message\n");
          return;
        }
        rt_kprintf("Received: a=%d b=%d \n",decode_msg->a, decode_msg->b);  // required field

        amessage__free_unpacked(decode_msg, NULL);
    }

    free(buf);

    return;
}
MSH_CMD_EXPORT(protobuf_encode_decode, protobuf-c encode decode test);
