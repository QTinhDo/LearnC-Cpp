#include "ringbuf.h"

RINGSTT RINGBUF_Init(RINGBUF *ring, uint8_t *buf, uint32_t max_size)
{
    if (!buf || max_size == 0)
        return RING_FAIL;
    ring->write = 0;
    ring->read = 0;
    ring->buf = buf;
    ring->size = max_size;

    return RING_OK;
}

RINGSTT RINGBUF_Put(RINGBUF *ring, uint8_t *data, uint32_t len)
{
    uint32_t temp = ring->write;
    temp++;
    if (temp >= ring->size)
        temp = 0;
    if (temp == ring->read)
        return RING_FAIL;

    memcpy(ring->buf[ring->write].arr, data, len * sizeof(uint8_t));
    ring->buf[ring->write].len = len;
    ring->write = temp;

    return RING_OK;
}

RINGSTT RINGBUF_Get(RINGBUF *ring, uint8_t *data, uint32_t *len)
{
    if(ring->read == ring->write)
        return RING_FAIL;

    *len = ring->buf[ring->read].len;
    memcpy(data, ring->buf[ring->read].arr, *len * sizeof(uint8_t));
    ring->read++;
    if (ring->read >= ring->size)
        ring->read = 0;

    return RING_OK;
}
