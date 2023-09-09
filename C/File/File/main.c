#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int mssv;
    char ho[20];
    char tendem[30];
    char ten[20];
    int tuoi;
    float toan;
    float van;
    float anh;
    float dtb;
} student_t;


void menu(int *tn, student_t *sv, int *count, int *sump)
{
    int sort;
    printf("Cac tinh nang cua chuong trinh\n");
    printf("%-20s%-20s%-20s%-20s%-20s\n","Them sinh vien","In danh sach","Sap xep","Tim kiem","Exit");
    printf("%-20s%-20s%-20s%-20s%-20s\n","1","2","3","4","5");
    printf("Chon tinh nang muon su dung: ");
    scanf("%d", tn);
    printf("---------------------------------------------------------------------------------\n");
    switch (*tn)
    {
        case 1:
            nhapthongtin(sv,count,sump);
            break;
        case 2:
            tinhtrungbinh(sv,sump);
            inthongtin(sv,sump);
            break;
        case 3:
            tinhtrungbinh(sv,sump);
            printf("%-25s%-25s\n","Theo ten","Theo diem trung binh");
            printf("%-25s%-20s%\n","1","2");
            printf("Chon tinh nang muon su dung: ");
            scanf("%d", &sort);
            if (sort == 1)
                sapxepten(sv,sump);
            else if (sort == 2)
                sapxepdtb(sv,sump);
            else ;

            break;
        case 4:
            tim(sv,sump);
            break;
        case 5:
            tinhtrungbinh(sv,sump);
            luudanhsach(sv,sump);
            break;
        break;
    }
    printf("---------------------------------------------------------------------------------\n");

}

void nhapthongtin(student_t *sv1, int *sopt1, int *count)
{
    sv1 = sv1 + (*count);
    printf("So phan tu muon nhap: ");
    scanf("%d", sopt1);
    for (int i=0; i < *sopt1; i++)
    {
        printf("NHAP THONG TIN SINH VIEN\n");
        printf("NHAP MSSV: ");
        scanf("%d", &sv1->mssv);
        fflush(stdin);
        printf("NHAP HO: ");
        gets(sv1->ho);
        printf("NHAP TEN DEM: ");
        gets(sv1->tendem);
        printf("NHAP TEN: ");
        gets(sv1->ten);
        fflush(stdin);
        printf("NHAP TUOI: ");
        scanf("%d", &sv1->tuoi);
        printf("NHAP DIEM TOAN VAN ANH: ");
        scanf("%f %f %f", &sv1->toan, &sv1->van, &sv1->anh);

        sv1++;
        (*count)++;
    }
}


void inthongtin(student_t *sv1, int *count)
{
    printf("%-10s%-10s%-10s%-10s%-10s%-10s%-10s%-10s%-10s\n","MSSV","HO","TEN DEM","TEN","TUOI","TOAN","VAN","ANH","DTB");
    for (int i=0; i < (*count); i++)
    {
        printf("%-10d%-10s%-10s%-10s%-10d%-10.02f%-10.02f%-10.02f%-10.02f\n",sv1->mssv,sv1->ho,sv1->tendem,sv1->ten
               ,sv1->tuoi,sv1->toan,sv1->van,sv1->anh,sv1->dtb);
        sv1++;
    }
}

void tinhtrungbinh(student_t *sv1, int *count)
{
    for (int i=0; i < (*count); i++)
    {
        sv1->dtb = (sv1->toan + sv1->van + sv1->anh) / 3;
        sv1++;
    }
}


void sapxepten(student_t *sv1, int *count)
{
    student_t temp;
    for (int i=0; i < (*count); i++)
    {
        for (int j = i+1; j < *count;j++)
        {
            if ( strcmp(sv1[j].ten,sv1[i].ten) )
            {
                temp = sv1[i];
                sv1[i] = sv1[j];
                sv1[j] = temp;
            }
        }
    }
}


void sapxepdtb(student_t *sv1, int *count)
{
    student_t temp;
    for (int i=0; i < (*count); i++)
    {
        for (int j = i+1; j < *count;j++)
        {
            if (sv1[i].dtb <= sv1[j].dtb)
            {
                temp = sv1[i];
                sv1[i] = sv1[j];
                sv1[j] = temp;
            }
        }
    }
}


void tim(student_t *sv1, int *count)
{
    char Fname[30];
    char Lname[30];
    printf("NHAP TEN CAN TIM: ");
    fflush(stdin);
    gets(Lname);
    printf("NHAP HO CAN TIM: ");
    fflush(stdin);
    gets(Fname);
    printf("%-10s%-10s%-10s%-10s%-10s%-10s%-10s%-10s%-10s\n","MSSV","HO","TEN DEM","TEN","TUOI","TOAN","VAN","ANH","DTB");
    for (int i=0; i < *count; i++)
    {
        if (strstr(sv1[i].ten, Lname) && strstr(sv1[i].ho, Fname))
        {
            printf("%-10d%-10s%-10s%-10s%-10d%-10.02f%-10.02f%-10.02f%-10.02f\n",sv1[i].mssv,sv1[i].ho,sv1[i].tendem,sv1[i].ten
                    ,sv1[i].tuoi,sv1[i].toan,sv1[i].van,sv1[i].anh,sv1[i].dtb);
        }
    }
}

void luudanhsach(student_t *sv1, int *count)
{
    FILE *fptr;
    fptr = fopen("D:\\Learn C-C++\\File\\File\\SV.txt","w+");
    fprintf(fptr,"%d\n",*count);
    for (int i=0;i<*count;i++)
    {
       fprintf(fptr,"%d %s %s %s %d %.02f %.02f %.02f %.02f\n",sv1[i].mssv,sv1[i].ho,sv1[i].tendem,sv1[i].ten
                    ,sv1[i].tuoi,sv1[i].toan,sv1[i].van,sv1[i].anh,sv1[i].dtb);
    }
    fclose(fptr);
}

void laydanhsach(student_t *sv1, int *count)
{
    FILE *fptr;
    fptr = fopen("D:\\Learn C-C++\\File\\File\\SV.txt","a+");
    fscanf(fptr,"%d", count);
    for (int i=0; i < *count;i++)
    {
       fscanf(fptr,"%d", &sv1[i].mssv);
       fscanf(fptr,"%s", sv1[i].ho);
       fscanf(fptr,"%s", sv1[i].tendem);
       fscanf(fptr,"%s", sv1[i].ten);
       fscanf(fptr,"%d", &sv1[i].tuoi);
       fscanf(fptr,"%f", &sv1[i].toan);
       fscanf(fptr,"%f", &sv1[i].van);
       fscanf(fptr,"%f", &sv1[i].anh);
       fscanf(fptr,"%f", &sv1[i].dtb);
    }
    fclose(fptr);
}

int main()
{
    student_t s[100];

    int tinhnang, tongsv, sosv;
    laydanhsach(s, &tongsv);
    while (1 && tinhnang !=5)
    {
        menu(&tinhnang,s,&sosv,&tongsv);
    }

    return 0;
}
