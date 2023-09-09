#ifndef LIB_H_INCLUDED
#define LIB_H_INCLUDED

typedef void (*data_uart_handle_t) (char *,int);

void UART_Rx_Data_set_callback(data_uart_handle_t cb);


#endif // LIB_H_INCLUDED
