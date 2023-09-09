#include <stdio.h>
#include <string.h>

char *strstr1(char *str, char *value)
{
    while (*str)
    {
        if (*str == *value)
            return str;
        str++;
    }
    return NULL;
}


void nhaphang(int *h)
{
    printf("Nhap hang muon cat: ");
    scanf("%d", h);
}

void cathang(char s[][40], int h)
{
    for (int i = h; i < 5;i++)
    {
        if (i + 1 >= 5)
            strcpy(s[i],"");
        else
            strcpy(s[i],s[i+1]);

    }
}


int main()
{
    int a;
    char str[5][40] =
    {
        "Nguoi dan toc Viet Nam",
        "Deviot",
        "Siginx",
        "KTXBachKhoa",
        "SinhvienNam5"
    };
    for (int i=0; i < 5; i++)
    {
        printf("%s\n",str[i]);
    }

    nhaphang(&a);
    cathang(str, a);
    printf("-----------------------------------------------------------------------------\n");
    for (int i=0; i < 5; i++)
    {
        printf("%s\n",str[i]);
    }
    return 0;
}
