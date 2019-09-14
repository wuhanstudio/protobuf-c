#include <rtthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <dfs_posix.h>

#include "amessage.pb-c.h"

static void protobuf_encode_to_file(int argc, char *argv[])
{
    void *buffer;                      // Buffer to store serialized data
    unsigned msg_len;                  // Length of serialized data

    if (argc != 3)
    {
        rt_kprintf("Usage: %s a b\n", argv[0]);
        return ;
    }

    // Encode message to buffer
    {
        rt_kprintf("---- Encoding ---\n");
        AMessage encode_msg = AMESSAGE__INIT;   // AMessage

        encode_msg.has_a  = 1;
        encode_msg.a      = atoi(argv[1]);
        encode_msg.has_b  = 1;
        encode_msg.b      = atoi(argv[2]); 

        msg_len = amessage__get_packed_size(&encode_msg);
        buffer = malloc(msg_len);

        rt_kprintf("Encoding %d serialized bytes\n", msg_len);
        amessage__pack(&encode_msg, buffer);

        rt_kprintf("---- Saving ---\n");
        int fd = open("/amessage.onnx", O_WRONLY | O_CREAT | O_TRUNC);
        if (fd>= 0)
        {
            write(fd, buffer, msg_len);
            close(fd);
            rt_kprintf("Written to file amessage.onnx.\n");
        }
    }

    free(buffer);

    return;
}
MSH_CMD_EXPORT(protobuf_encode_to_file, protobuf-c encode to file test);
