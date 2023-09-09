#include <stdio.h>

int mang0[] ={10,20,30,40,50};
int mang1[] ={11,22,33,44,55};
int mang2[] ={12,23,34,45,56};

int main()
{
    int *pt[3];
    pt[0]= mang1;
    int n = 5;

    // Nhap mang
    for (int i=0;i < 1;i++)
    {
        for (int j=0;j < n;j++)
        {
            printf("Phan tu thu %d: ",j+1);
            scanf("%d", *pt+j);
        }
    }




    // Sap xep mang
    for (int i=0;i < 1;i++)
    {
        for (int j=0;j<n;j++)
        {
            for (int h=j+1;h<n;h++)
            {
               if (pt[i][j] > pt[i][h])
                {
                int temp = pt[i][j];
                pt[i][j] = pt[i][h];
                pt[i][h] = temp;
                }
            }
        }
    }




    // In mang
    for (int i=0;i < 1;i++)
    {
        for (int j=0;j<n;j++)
        {
            printf("%d ",pt[i][j]);
        }
    }
}
