#include <stdio.h>
#include <stdlib.h>
#include "min.h"

struct min_context min;

typedef enum {
    SET,
    GET,
    REQ,
    RESP,
    ACK
}   min_id_t;


void min_application_handler(uint8_t min_id, uint8_t const *min_payload, uint8_t len_payload, uint8_t port)
{
    printf("-----------------------------------------------------------------\n");
    printf("ID: %d\n", min_id);
    printf("Length: %d\n", len_payload);
    printf("Payload: ");
    for (int i=0;i<len_payload;i++)
    {
        printf("0x0%-2d", min_payload[i]);
    }
}

int main()
{
    uint8_t payload[5] = {1,2,3,4,5};

    uint8_t min_recv[] = {0xaa, 0xaa, 0xaa, 0x00, 0x05, 0x01, 0x02, 0x03, 0x04, 0x05, 0x4c, 0x88, 0x20, 0x20, 0x55};
    uint8_t min_recv_1[] = {0xaa, 0xaa, 0xaa, 0x00, 0x05, 0x01, 0x02, 0x03, 0x04, 0x05, 0x4c, 0x88, 0x20, 0x24, 0x55};
    min_init_context(&min, 0);
    //min_send_frame(&min, SET, payload, 5);
    while (1)
    {
        min_poll(&min, min_recv, sizeof(min_recv));
        min_poll(&min, min_recv_1, sizeof(min_recv_1));
        break;
    }
    return 0;
}
