#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queue.h"


queue_t *create_queue(int capacity)
{
    queue_t *qt = (queue_t *)malloc(sizeof(queue_t));
    qt->front = 0;
    qt->rear = -1;
    qt->used = 0;
    qt->capacity = capacity;
    qt->array = (int *) malloc(capacity * sizeof(int));

    return qt;
}

 static bool isEmpty(queue_t *queue)
{
    return (queue->used == 0);
}


 static bool isFull(queue_t *queue)
{
    return (queue->used == queue->capacity);
}


int getFront(queue_t *queue)
{
    return queue->array[queue->front];
}

int getRear(queue_t *queue)
{
    return queue->array[queue->rear];
}



queue_stt_t enqueue(queue_t *queue, int item)
{
    if (isFull(queue))
        return QUEUE_FAIL;
    queue->rear = (queue->rear+1)%queue->capacity;
    queue->array[queue->rear] = item;
    queue->used++;

    return QUEUE_OK;
}

queue_stt_t dequeue(queue_t *queue, int *item)
{
    if(isEmpty(queue))
        return QUEUE_FAIL;
    *item = queue->array[queue->front];
    queue->front = (queue->front+1)%queue->capacity;
    queue->used--;

    return QUEUE_OK;
}
