#include <stdio.h>
#include "lib.h"

data_uart_handle_t data_uart_ptr = NULL;

void UART_Rx_Data(char *dataRx, int dataLen)
{
    data_uart_ptr(dataRx, dataLen);
}

void UART_Rx_Data_set_callback(data_uart_handle_t cb)
{
    if (cb)
    {
        data_uart_ptr = cb;
    }
}
