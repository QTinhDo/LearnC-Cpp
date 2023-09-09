#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    char ten[30];
    char mssv[10];
    int tuoi;
} student_t;



void tinhnang(int *mode, student_t *sv, int *sopt, int *sumpt)
{
    printf("Cac tinh nang cua chuong trinh\n");
    printf("%-20s%-20s%-20s%-20s%-20s\n","Nhap sinh vien","In danh sach","Them","Xoa","Sua");
    printf("%-20s%-20s%-20s%-20s%-20s\n","1","2","3","4","5");
    printf("Chon tinh nang muon su dung: ");
    scanf("%d", mode);
    printf("---------------------------------------------------------------------------------\n");
    switch (*mode)
    {
        case 1:
            sv = nhap(sv,sopt,sumpt);
            break;
        case 2:
            xuat(sv,sumpt);
            break;
        case 3:
            them(sv,sumpt);
            break;
        case 4:
            break;
        case 5:
            xoa(sv,sumpt);
            break;
        case 6:
            break;
        break;
    }
    printf("---------------------------------------------------------------------------------\n");
}



void *nhap(student_t *sv1, int *count, int *tong)
{
    printf("Nhap so phan tu: ");
    scanf("%d", count);
    sv1 = calloc(*count, sizeof(student_t) );
    for (int i=0; i < *count; i++)
    {
        printf("NHAP THONG TIN SINH VIEN\n");
        printf("NHAP TEN: ");
        fflush(stdin);
        gets(sv1->ten);
        printf("NHAP MSSV: ");
        gets(sv1->mssv);
        fflush(stdin);
        printf("NHAP TUOI: ");
        scanf("%d", &sv1->tuoi);
        sv1++;
        (*tong)++;
    }
    sv1 = sv1 - *count - 1;
    return sv1;
}


void xuat(student_t *sv1, int *count)
{

    printf("%-10s%-15s%-10s\n","TEN","MSSV","TUOI");
    for (int i=0; i < (*count); i++)
    {
        printf("%-10s%-15s%-10d\n",sv1->ten,sv1->mssv,sv1->tuoi);
        sv1++;
    }
}

void them(int *str, int *count)
{
    int len;
    printf("Nhap so phan tu them: ");
    scanf("%d", &len);
    int *str2 = (int*) calloc( (*count) + len, sizeof(int));
    memcpy(str2, str, (*count) * sizeof(int));
    free(str);
    str2 = str2 + (*count);
    for (int i=0; i < len; i++)
    {
        printf("Nhap phan tu thu %d: ", i + 1 + (*count));
        scanf("%d", str2 + i);
    }
    str2 = str2 - (*count);
    *count += len;

    return str2;
}

void xoa(int *str, int *count)
{
    int len;
    int *str1;
    printf("Nhap index phan tu can xoa: ");
    scanf("%d", &len);
    for (int j= len-1; j < *count;j++)
    {
        str[j] = str[j+1];
    }
    (*count)--;
    str1 = calloc(*count, sizeof(int));
    memcpy(str1, str, (*count) * sizeof(int));
    free(str);

    return str1;
}


int main()
{
    student_t *s = calloc(10, sizeof(student_t));;
    int sopt, tn, tongpt = 0;;
    while (1)
    {
       tinhnang(&tn, s, &sopt, &tongpt);
    }
    return 0;
}
