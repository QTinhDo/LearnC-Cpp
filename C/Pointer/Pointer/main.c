#include <stdio.h>
#include <conio.h>
#include "lib.h"


void xulydulieuUART1(char *data, int len)
{
    printf("Data UART: %s", data);
}

void xulydulieuUART2(char *data, int len)
{
    printf("Data dai: %d", len);
}

int main()
{
    UART_Rx_Data_set_callback(xulydulieuUART2);
    UART_Rx_Data("TOGGLE", 6);
    return 0;
}
