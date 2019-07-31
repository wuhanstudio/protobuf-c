#include <rtthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <dfs_posix.h>

#include "amessage.pb-c.h"

static void protobuf_decode_from_file(int argc,char *argv[])
{
    rt_kprintf("---- Reading ---\n");

    // Get file size first
    int ret;
    struct stat buf;
    ret = stat("/amessage.onnx", &buf);
    if(ret == 0)
    {
        rt_kprintf("amessage.onnx file size = %d\n", buf.st_size);
    }
    else
    {
        rt_kprintf("amessage.onnx file not fonud\n");
        return;
    }

    // Read protobuf file
    size_t msg_len = buf.st_size;
    uint8_t buffer[128];

    int fd = open("/amessage.onnx", O_RDONLY);
    if (fd>= 0)
    {
        int size = read(fd, buffer, msg_len);
        close(fd);
        rt_kprintf("Read from file amessage.onnx \n");
        if (size < 0)
        {
            return ;
        }
    }

    {
        rt_kprintf("---- Decoding ---\n");

        AMessage* decode_msg;
        decode_msg = amessage__unpack(NULL, msg_len, buffer);
        if (decode_msg == NULL)
        {
          rt_kprintf("Error unpacking incoming message\n");
          return;
        }
        rt_kprintf("Received: a=%d b=%d \n",decode_msg->a, decode_msg->b);  // required field

        amessage__free_unpacked(decode_msg, NULL);
    }

    return;
}
MSH_CMD_EXPORT(protobuf_decode_from_file, protobuf-c decode from file);
