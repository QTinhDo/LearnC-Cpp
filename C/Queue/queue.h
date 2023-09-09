#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>


typedef enum {
    QUEUE_FAIL = -1,
    QUEUE_OK = 0,
} queue_stt_t;

typedef struct {
    int front;                  // chỉ số của phần tử đầu Queue
    int rear;                   // chỉ số của phần tử cuối Queue
    int used;                   // số  phần tử đang có trong Queue
    int capacity;      // dung lượng max của Queue
    int *array;                 // con trỏ đúng mảng tượng trưng
} queue_t;

queue_t *create_queue(int capacity);
queue_stt_t enqueue(queue_t *queue, int item);
queue_stt_t dequeue(queue_t *queue, int *item);
int getFront(queue_t *queue);
int getRear(queue_t *queue);


#endif // QUEUE_H_INCLUDED
