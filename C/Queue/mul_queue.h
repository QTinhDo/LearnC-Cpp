#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE     20
#define MAX_ELEMENT 10

typedef enum {
    QUEUE_FAIL = -1,
    QUEUE_OK = 0,
} mul_queue_stt_t;


typedef struct {
    int len;
    int buf[MAXSIZE];
} buf_data_t;


typedef struct {
    int front;                  // chỉ số của phần tử đầu Queue
    int rear;                   // chỉ số của phần tử cuối Queue
    int used;                   // số  phần tử đang có trong Queue
    int capacity;               // dung lượng max của Queue
    buf_data_t *array;          // con trỏ đến mảng tượng trưng
} mul_queue_t;


mul_queue_t *create_mul_queue(int capacity);
mul_queue_stt_t mul_enqueue(mul_queue_t *queue, int *data,int len);
mul_queue_stt_t mul_dequeue(mul_queue_t *queue, int *data,int *len);


#endif // QUEUE_H_INCLUDED
