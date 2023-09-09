#include <stdio.h>

typedef void (*func_t) (int, int);


void config(int *tn, func_t *mode)
{
    int a,b;
    printf("Nhap so can tinh:\n");
    printf("a = ");
    scanf("%d", &a);
    printf("b = ");
    scanf("%d", &b);
    printf("%-10s%-10s%-10s%-10s\n","Cong","Tru","Nhan","Chia");
    printf("%-10s%-10s%-10s%-10s\n","1","2","3","4");
    printf("Chon phep tinh: ");
    scanf("%d", tn);
    mode[*tn - 1](a,b);
}



void cong(int x, int y)
{
    printf("x + y = %d\n", x+y);
}

void tru(int x, int y)
{
    printf("x - y = %d\n", x-y);
}

void nhan(int x, int y)
{
    printf("x * y = %d\n", x*y);
}

void chia(int x, int y)
{
    printf("x / y = %d\n", x/y);
}


int main()
{
    func_t func[4] =
    {
        cong,
        tru,
        nhan,
        chia
    };
    int tinhnang;
    while(1)
    {
        config(&tinhnang, func);
    }
}
