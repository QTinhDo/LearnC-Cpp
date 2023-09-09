#ifndef RINGBUF_H_INCLUDED
#define RINGBUF_H_INCLUDED

#include <stdint.h>

#include <stdint.h>
#include <stdbool.h>

typedef enum{
    RING_FAIL = -1,
    RING_OK = 0,
}   ring_stt_t;

typedef struct{
    uint32_t wr;  // Phần tử đầu
    uint32_t rd;  // Phần tử cuối
    uint32_t size;
    uint8_t *buf;
}   RINGBUF;

ring_stt_t RINGBUF_Init(RINGBUF *ring, uint8_t *buf, uint32_t max_size);
ring_stt_t RINGBUF_Put(RINGBUF *ring, uint8_t data);
ring_stt_t RINGBUF_Get(RINGBUF *ring, uint8_t *data);



#endif // RINGBUF_H_INCLUDED
