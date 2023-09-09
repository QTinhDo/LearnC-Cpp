#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "mul_queue.h"


mul_queue_t *create_mul_queue(int capacity)
{
    mul_queue_t *qt = (mul_queue_t *)malloc(sizeof(mul_queue_t));
    qt->front = 0;
    qt->rear = -1;
    qt->used = 0;
    qt->capacity = capacity;
    qt->array = (buf_data_t *) malloc(capacity * sizeof(buf_data_t));

    return qt;
}

 static bool ismul_Empty(mul_queue_t *queue)
{
    return (queue->used == 0);
}


 static bool ismul_Full(mul_queue_t *queue)
{
    return (queue->used == queue->capacity);
}


mul_queue_stt_t mul_enqueue(mul_queue_t *queue, int *data, int len)
{
    if (ismul_Full(queue))
        return QUEUE_FAIL;
    queue->rear = (queue->rear+1)%queue->capacity;
    memcpy(queue->array[queue->rear].buf, data, len * sizeof(int));
    queue->array[queue->rear].len = len;
    queue->used++;

    return QUEUE_OK;
}

mul_queue_stt_t mul_dequeue(mul_queue_t *queue, int *data,int *len)
{
    if(ismul_Empty(queue))
        return QUEUE_FAIL;
    memcpy(data , queue->array[queue->front].buf, queue->array[queue->front].len * sizeof(int));
    *len = queue->array[queue->front].len;
    queue->front = (queue->front+1)%queue->capacity;
    queue->used--;

    return QUEUE_OK;
}
