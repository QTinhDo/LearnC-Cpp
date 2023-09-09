#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "ringbuf.h"
#include "min.h"
#include <time.h>
#include <errno.h>

/* msleep(): Sleep for the requested number of milliseconds. */
int msleep(long msec)
{
    struct timespec ts;
    int res;

    if (msec < 0)
    {
        errno = EINVAL;
        return -1;
    }

    ts.tv_sec = msec / 1000;
    ts.tv_nsec = (msec % 1000) * 1000000;

    do {
        res = nanosleep(&ts, &ts);
    } while (res && errno == EINTR);

    return res;
}




RINGBUF ring;
uint8_t BUFF[10];

struct min_context min;

typedef enum {
    SET,
    GET,
    REQ,
    RESP,
    ACK
}   min_id_t;


void min_application_handler(uint8_t min_id, uint8_t const *min_payload, uint8_t len_payload, uint8_t port)
{
    printf("\n****RECV_MIN****");
    printf("\nID: %d", min_id);
    printf("\nLength: %d", len_payload);
    printf("\nPayload: ");
    for (int i=0;i<len_payload;i++)
    {
        printf("0x0%-2d", min_payload[i]);
    }
}


uint8_t min_frame_send[] = {0xaa, 0xaa, 0xaa, 0x00, 0x05, 0x01, 0x02, 0x03, 0x04, 0x05, 0x4c, 0x88, 0x20, 0x24, 0x55};


typedef struct {
    bool is_send;
    uint8_t char_send;
} data_send_t;

data_send_t data_send = {
    .is_send = false,
    .char_send = 0,
};

data_send_t data_recv;
//send data to Thread_2 (1s/1time)
void *my_Thread_1(void *vargp)
{
    while (1)
    {
        for (int i=0; i < sizeof(min_frame_send);i++)
        {
            data_send.char_send = min_frame_send[i];
            data_send.is_send = true;
            printf("\nSend(0x%02x)",data_send.char_send);
            msleep(1000);
        }
    }
}


void *my_Thread_2(void *vargp)
{
    while (1)
    {
        if (data_send.is_send == true)
        {
            data_send.is_send = false;
            data_recv = data_send;
            RINGBUF_Put(&ring, data_recv.char_send);
            printf("\nPut (0x%02x)",data_recv.char_send);
        }
    }
}

void *my_Thread_3(void *vargp)
{
    uint8_t RX_Data;
    while (1)
    {
        if(RINGBUF_Get(&ring, &RX_Data) == RING_OK)
        {
            min_poll(&min, &RX_Data, 1);
        }
    }
}


int main()
{
    RINGBUF_Init(&ring, BUFF, 10);
    min_init_context(&min, 0);

    pthread_t thread_id_1;
    pthread_t thread_id_2;
    pthread_t thread_id_3;

    pthread_create(&thread_id_1, NULL, my_Thread_1, NULL);
    pthread_create(&thread_id_2, NULL, my_Thread_2, NULL);
    pthread_create(&thread_id_3, NULL, my_Thread_3, NULL);

    pthread_join(thread_id_1, NULL);
    pthread_join(thread_id_2, NULL);
    pthread_join(thread_id_3, NULL);

    return 0;
}
