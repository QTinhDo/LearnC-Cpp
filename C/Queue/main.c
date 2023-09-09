#include <stdio.h>
#include <stdlib.h>
#include "mul_queue.h"


void printArray(int *arr, int count)
{
    for (int i=0; i<count;i++)
    {
        printf("%3d", arr[i]);
    }
}


int main()
{
    int data_send[20] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    int data_read[50];
    int data_read_len = 0;
    static random = 0;

    mul_queue_t *queue = create_mul_queue(5);
    while (1)
    {
        if (random == 1)
        {
            mul_enqueue(queue, data_send, 20);
        } else
            mul_enqueue(queue, data_send, 10);

        random = 1 - random;
        sleep(1);

        if (mul_dequeue(queue, data_read, &data_read_len) == QUEUE_OK)
        {
            printf("Data read length: %d\n", data_read_len);
            printArray(data_read, data_read_len);
            printf("\n-------------------------------------------------------------------\n");
        }
        else
            printf("Get queue FAIL\n");
    }

    return 0;
}
