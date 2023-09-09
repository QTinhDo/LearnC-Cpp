#ifndef RINGBUF_H_INCLUDED
#define RINGBUF_H_INCLUDED

#include <stdint.h>

typedef enum {
    RING_FAIL = -1,
    RING_OK = 0,
} RINGSTT;

typedef struct {
    uint32_t len;
    uint8_t arr[20];
} data_buf_t;


typedef struct{
    uint32_t write;
    uint32_t read;
    uint32_t size;
    data_buf_t *buf;
} RINGBUF;


RINGSTT RINGBUF_Init(RINGBUF *ring, uint8_t *buf, uint32_t max_size);
RINGSTT RINGBUF_Put(RINGBUF *ring, uint8_t *data, uint32_t len);
RINGSTT RINGBUF_Get(RINGBUF *ring, uint8_t *data, uint32_t *len);

#endif // RINGBUF_H_INCLUDED
