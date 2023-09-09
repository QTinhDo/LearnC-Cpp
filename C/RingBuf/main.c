#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "ringbuf.h"

uint8_t buf[10];
uint32_t len;
RINGBUF ring;

void *myThreadFun1(void *vargp)
{
    static uint8_t data[4] = {1,2,3,4};
    static uint8_t data1[4] = {5,6,7,8};
    while(1)
    {
        if(RINGBUF_Put(&ring, data, 4) == RING_OK)
        {
            printf("-->");
            for(int i=0; i<4;i++)
            {
                printf("%3d", data[i]);
            }
            printf("\r\n");
        }
        else
            printf("FULL\n");

        if(RINGBUF_Put(&ring, data1, 4) == RING_OK)
        {
            printf("-->");
            for(int i=0; i<4;i++)
            {
                printf("%3d", data1[i]);
            }
            printf("\r\n");
        }
        else
            printf("FULL\n");
        sleep(4);
    }
}


void *myThreadFun2(void *vargp)
{
    uint8_t read_data[10];
    while(1)
    {
        if(RINGBUF_Get(&ring, read_data, &len) == RING_OK)
        {
            printf("Data read: ");
            for(int i=0; i<len;i++)
            {
                printf("%3d", read_data[i]);
            }
            printf("\n");
        }
        else
            printf("Empty\n");
        sleep(1);
    }
}

int main()
{
    RINGBUF_Init(&ring, buf, 10);
    pthread_t thread_id1;
    printf("Thread 1 Init\n");
    pthread_t thread_id2;
    printf("Thread 2 Init\n");
    pthread_create(&thread_id1, NULL, myThreadFun1, NULL);
    pthread_create(&thread_id2, NULL, myThreadFun2, NULL);
    pthread_join(thread_id1, NULL);
    pthread_join(thread_id2, NULL);
    exit(0);
    return 0;
}
