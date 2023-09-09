#include <stdio.h>
#include <string.h>
#include <stdint.h>

typedef struct
{
    char ten[30];
    char gioitinh[10];
    int tuoi;
    int toan;
    int ly;
    int hoa;
    float dtb;
} student_t;



void tinhnang(int *mode, student_t *sv, int *sopt, int *sumpt)
{
    printf("Cac tinh nang cua chuong trinh\n");
    printf("%-20s%-20s%-20s%-20s%-20s%-20s\n","Nhap sinh vien","In danh sach","Sap xep","Xep loai","Xoa","Tim");
    printf("%-20s%-20s%-20s%-20s%-20s%-20s\n","1","2","3","4","5","6");
    printf("Chon tinh nang muon su dung: ");
    scanf("%d", mode);
    printf("---------------------------------------------------------------------------------\n");
    switch (*mode)
    {
        case 1:
            nhapthongtin(sv,sopt,sumpt);
            break;
        case 2:
            tinhtrungbinh(sv,sumpt);
            inthongtin(sv,sumpt);
            break;
        case 3:
            tinhtrungbinh(sv,sumpt);
            sapxep(sv,sumpt);
            break;
        case 4:
            tinhtrungbinh(sv,sumpt);
            xeploai(sv,sumpt);
            break;
        case 5:
            xoa(sv,sumpt);
            break;
        case 6:
            tim(sv,sumpt);
            break;
        break;
    }
    printf("---------------------------------------------------------------------------------\n");
}


void nhapthongtin(student_t *sv1, int *sopt1, int *count)
{
    //static uint8_t vitri = 0;
    sv1 = sv1 + (*count);
    printf("So phan tu muon nhap: ");
    scanf("%d", sopt1);
    for (int i=0; i < *sopt1; i++)
    {
        printf("NHAP THONG TIN SINH VIEN\n");
        printf("NHAP TEN: ");
        fflush(stdin);
        gets(sv1->ten);
        printf("NHAP GIOI TINH: ");
        gets(sv1->gioitinh);
        fflush(stdin);
        printf("NHAP TUOI: ");
        scanf("%d", &sv1->tuoi);
        printf("NHAP DIEM TOAN: ");
        scanf("%d", &sv1->toan);
        printf("NHAP DIEM LY: ");
        scanf("%d", &sv1->ly);
        printf("NHAP DIEM HOA: ");
        scanf("%d", &sv1->hoa);
        sv1++;
        (*count)++;
    }
    //*count = vitri;
}



void inthongtin(student_t *sv1, int *count)
{
    printf("%-10s%-15s%-10s%-10s%-10s%-10s%-10s\n","TEN","GIOI TINH","TUOI","TOAN","LY","HOA","DTB");
    for (int i=0; i < (*count); i++)
    {
        printf("%-10s%-15s%-10d%-10d%-10d%-10d%-10.02f\n",sv1->ten,sv1->gioitinh,sv1->tuoi,sv1->toan,sv1->ly,sv1->hoa,sv1->dtb);
        sv1++;
    }
}


void tinhtrungbinh(student_t *sv1, int *count)
{
    for (int i=0; i < (*count); i++)
    {
        sv1->dtb = (float) (sv1->toan + sv1->ly + sv1->hoa) / 3;
        sv1++;
    }
}


void sapxep(student_t *sv1, int *count)
{
    student_t temp;
    for (int i=0; i < (*count); i++)
    {
        for (int j = i+1; j < *count;j++)
        {
            if (sv1[i].dtb >= sv1[j].dtb)
            {
                temp = sv1[i];
                sv1[i] = sv1[j];
                sv1[j] = temp;
            }
        }
    }
    printf("%s\n","Diem trung binh: ");
    printf("%-10s%-15s%-10s%-10s\n","TEN","GIOI TINH","TUOI","DTB");
    for (int i=0; i < (*count); i++)
    {
        printf("%-10s%-15s%-10d%-10.02f\n",sv1->ten,sv1->gioitinh,sv1->tuoi,sv1->dtb);
        sv1++;
    }
}


void xeploai(student_t *sv1, int *count)
{
    printf("%-10s%-15s%-10s%-10s%-10s%-10s%-10s%-10s\n","TEN","GIOI TINH","TUOI","TOAN","LY","HOA","DTB","LOAI");
    for (int i=0; i < (*count); i++)
    {
        printf("%-10s%-15s%-10d%-10d%-10d%-10d%-10.02f",sv1->ten,sv1->gioitinh,sv1->tuoi,sv1->toan,sv1->ly,sv1->hoa,sv1->dtb);
        if (sv1->dtb >= 8)
             printf("%-10s\n","GIOI");
        else if (sv1->dtb >= 7 && sv1->dtb < 8)
            printf("%-10s\n","GIOI");
        else if (sv1->dtb >= 5 && sv1->dtb < 7)
            printf("%-10s\n","TRUNG BINH");
        else
            printf("%-10s\n","YEU");

        sv1++;
    }
}


void xoa(student_t *sv1, int *count)
{
    char name[30];
    printf("NHAP TEN CAN XOA: ");
    fflush(stdin);
    gets(name);
    for (int i=0; i < *count; i++)
    {
        if (strstr(sv1[i].ten, name))
        {
            for (int j=i;j < (*count)-1; j++)
            {
                sv1[j] = sv1[j+1];
            }
        }
    }
    (*count)--;
}


void tim(student_t *sv1, int *count)
{
    char name[30];
    printf("NHAP TEN CAN TIM: ");
    fflush(stdin);
    gets(name);
    for (int i=0; i < *count; i++)
    {
        if (strstr(sv1[i].ten, name))
        {
            printf("%-10s%-15s%-10s%-10s%-10s%-10s%-10s\n","TEN","GIOI TINH","TUOI","TOAN","LY","HOA","DTB");
            printf("%-10s%-15s%-10d%-10d%-10d%-10d%-10.02f\n",sv1[i].ten,sv1[i].gioitinh,sv1[i].tuoi,sv1[i].toan,sv1[i].ly,sv1[i].hoa,sv1[i].dtb);
        }
    }
}

int main()
{
    student_t s[1000];
    int sopt, tn, tongpt = 0;
    while (1)
    {
       tinhnang(&tn, s, &sopt, &tongpt);
    }
    return 0;
}

