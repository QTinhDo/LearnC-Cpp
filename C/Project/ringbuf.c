#include "ringbuf.h"

ring_stt_t RINGBUF_Init(RINGBUF *ring, uint8_t *buf, uint32_t max_size)
{
    if(!buf || max_size == 0)
        return RING_FAIL;
    ring->wr = 0;
    ring->rd = 0;
    ring->buf = buf;
    ring->size = max_size;
    return RING_OK;
}

ring_stt_t RINGBUF_Put(RINGBUF *ring, uint8_t data)
{
    uint16_t temp = ring->wr;
    temp++;

    if(temp >= ring->size)
    {
        temp = 0;
    }

    if(temp == ring->rd)    // full
    {
        return RING_FAIL;
    }

    ring->buf[ring->wr] = data;
    ring->wr = temp;
    return RING_OK;
}

ring_stt_t RINGBUF_Get(RINGBUF *ring, uint8_t *data)
{
    if(ring->wr == ring->rd)    // empty
    {
        return RING_FAIL;
    }
    *data = ring->buf[ring->rd];
    ring->rd++;
    if(ring->rd >= ring->size)
    {
        ring->rd = 0;
    }
    return RING_OK;
}
