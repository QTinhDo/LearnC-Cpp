#include <stdio.h>
#include <string.h>
#include <stdint.h>

#define PASSWORD "SIGINX"

char *strcpy1(char *str1, char *str2)
{
    while ( *str1++=*str2++)
        ;
}

char * strcat1(char *str1, char *str2)
{
    while (*str1++)
        ;
    while ( *str1++ = *str2++)
        ;
}

void strremovChar(char *str, char* value)
{
    while (*str)
    {
        if (*str == *value)
        {
            char *ptr = str;
            while ( *str = *(str+1))
                str++;
            str = ptr;
        }
        str++;
    }

}

int main() {
  uint8_t a;
  uint16_t b = 600;

  a =  b;

  printf("val = %d\n", a);

  return 0;
}

