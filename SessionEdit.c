//Kelompok 16:
// M. Naufal Athallah (1906305373)
// Primayoga Budyprawira (1906379491)
// Rafif Fadhlah Ushaim (1906379421)

#include "SessionEdit.h"
#include "UserEdit.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

struct patient_data_session{
    int patient_id;
    char name[30];
    char tempat_lahir[14];
    int h_lahir;
    char b_lahir[10];
    int t_lahir;
    char phone[13];
} patient_s[200];

struct patient_session_s{
    int patient_id;
    int session_number;
    int doctor_id;
    char disease[30];
    int medicine_id[10];
    int room_id;
    int expense;
} session_s[200];

char doctor_s[10][100] = {"dr. Primayoga B", "dr. Naufal Athallah", "dr. Rafif F."};
char medicine_s[10][100] = {"Apriximol", "Selitol", "Bodrin", "Ligobi", "Maximl"};
int num_patient_s,num_session_s;

void view_d();
int search_session();
int sort_session();
int read_patient_s();
int read_session_s();


void Session_init(int x){
    read_patient_s();
    read_session_s();
    switch (x)
    {
    case 1:
        view_d();
        break;
    case 2:
        search_session();
        break;
    case 3:
        sort_session();
        break;
    default:
        break;
    }
    printf("Tekan Tombol Apapun untuk Lanjut !!");
    getch();
}
void view_d(){
    int pat_id,j,i,med_length;
    printf("Masukkan ID pasien : ");
    scanf("%d",&pat_id);
    system("cls");
    for(j=0;j<num_patient_s;j++){
        if (patient_s[j].patient_id==pat_id){
            printf("Patient Data: \n");
        	printf("\n====================================================================\n");
            printf("Patient ID\r\t\t\t: %d\n", patient_s[j].patient_id);
            printf("Name\r\t\t\t: %s\n",patient_s[j].name);
            printf("TTL\r\t\t\t: %s, %d %s %d\n", patient_s[j].tempat_lahir, patient_s[j].h_lahir, patient_s[j].b_lahir, patient_s[j].t_lahir);
            printf("Phone Number\r\t\t\t: %s\n", patient_s[j].phone);
            printf("====================================================================\n");
            printf("\n");
            break;
        }else if(j==num_patient_s-1){
        	printf("\n\nData Tidak Ditemukan!!\n\n");
		}
    }
    for(j=0;j<num_session_s;j++){
        if (session_s[j].patient_id==pat_id){
            printf("\n");
            printf("ID\r\t\t\t: %d\n", session_s[j].patient_id);
            printf("Sesi ke-%d\n",session_s[j].session_number+1);
            printf("Dokter\r\t\t\t: %s\n",doctor_s[session_s[j].doctor_id]);
            printf("Desease\r\t\t\t: %s\n",session_s[j].disease);
            printf("Medicine\r\t\t\t: ");
            med_length = sizeof(session_s[j].medicine_id)/sizeof(int);
            for(i=0;i<med_length;i++){
                if(session_s[j].medicine_id[i]==0){
                    break;
                }
                printf("%s, ",medicine_s[session_s[j].medicine_id[i]-1]);
            }
            printf("\nRoom ID\r\t\t\t: %d\n",session_s[j].room_id);
            printf("Expense\r\t\t\t: %d\n",session_s[j].expense);
        }
    }

}

int search_session(){
    int h,pat_id,j,i,med_length;
    printf("Metode pencarian data pasien: \n");
    printf("1.Obat\n2.Penyakit\n3.RoomID\n4.Dokter\n5.Kembali\n\nOption = ");
    scanf("%d",&h);

    printf("Masukkan ID pasien : ");
    scanf("%d",&pat_id);
    system("cls");
    for(j=0;j<num_patient_s;j++){
        if (patient_s[j].patient_id==pat_id){
            printf("patient_s Data: \n");
        	printf("\n====================================================================\n");
            printf("patient_s ID\r\t\t\t: %d\n", patient_s[j].patient_id);
            printf("Name\r\t\t\t: %s\n",patient_s[j].name);
            printf("TTL\r\t\t\t: %s, %d %s %d\n", patient_s[j].tempat_lahir, patient_s[j].h_lahir, patient_s[j].b_lahir, patient_s[j].t_lahir);
            printf("Phone Number\r\t\t\t: %s\n", patient_s[j].phone);
            printf("====================================================================\n");
            printf("\n");
            break;
        }else if(j==num_patient_s-1){
        	printf("\n\nData Tidak Ditemukan!!\n\n");
		}
    }
    if (h==1){
        char medicine_name[30];
        printf("Masukkan nama obat yang akan dicari: ");
        scanf("%s", medicine_name);
        for(j=0;j<num_session_s;j++){
            if (session_s[j].patient_id==pat_id){
                med_length = sizeof(session_s[j].medicine_id)/sizeof(int);
                for(i=0;i<med_length;i++){
                    if(strcmp(medicine_s[session_s[j].medicine_id[i]-1],medicine_name)==0){
                        printf("\n");
                        printf("ID\r\t\t\t: %d\n", session_s[j].patient_id);
                        printf("session_s ke-%d\n",session_s[j].session_number+1);
                        printf("Dokter\r\t\t\t: %s\n",doctor_s[session_s[j].doctor_id]);
                        printf("Desease\r\t\t\t: %s\n",session_s[j].disease);
                        printf("medicine_s\r\t\t\t: ");
                        med_length = sizeof(session_s[j].medicine_id)/sizeof(int);
                        for(i=0;i<med_length;i++){
                            if(session_s[j].medicine_id[i]==0){
                                break;
                            }
                            printf("%s, ",medicine_s[session_s[j].medicine_id[i]-1]);
                        }
                        printf("\nRoom ID\r\t\t\t: %d\n",session_s[j].room_id);
                        printf("Expense\r\t\t\t: %d\n",session_s[j].expense);
                        break;
                    };
                }
            }
        }
    }
    else if (h==2){
        char desease_s[30];
        printf("Masukkan nama penyakit yang akan dicari: ");
        fflush(stdin);
        fgets(desease_s, 30, stdin);
        desease_s[strcspn(desease_s, "\n")] = 0;
        for(j=0;j<num_session_s;j++){
            if (session_s[j].patient_id==pat_id){
                if(strcmp(session_s[j].disease,desease_s)==0){
                    printf("\n");
                    printf("ID\r\t\t\t: %d\n", session_s[j].patient_id);
                    printf("session_s ke-%d\n",session_s[j].session_number+1);
                    printf("Dokter\r\t\t\t: %s\n",doctor_s[session_s[j].doctor_id]);
                    printf("Desease\r\t\t\t: %s\n",session_s[j].disease);
                    printf("medicine_s\r\t\t\t: ");
                    med_length = sizeof(session_s[j].medicine_id)/sizeof(int);
                    for(i=0;i<med_length;i++){
                        if(session_s[j].medicine_id[i]==0){
                            break;
                        }
                        printf("%s, ",medicine_s[session_s[j].medicine_id[i]-1]);
                    }
                    printf("\nRoom ID\r\t\t\t: %d\n",session_s[j].room_id);
                    printf("Expense\r\t\t\t: %d\n",session_s[j].expense);
                };
            }
        }
    }
    else if (h==3){
        int room_s;
        printf("Masukkan nama id ruang yang akan dicari: ");
        scanf("%d", &room_s);
        for(j=0;j<num_session_s;j++){
            if (session_s[j].patient_id==pat_id){
                if(session_s[j].room_id==room_s){
                    printf("\n");
                    printf("ID\r\t\t\t: %d\n", session_s[j].patient_id);
                    printf("session_s ke-%d\n",session_s[j].session_number+1);
                    printf("Dokter\r\t\t\t: %s\n",doctor_s[session_s[j].doctor_id]);
                    printf("Desease\r\t\t\t: %s\n",session_s[j].disease);
                    printf("medicine_s\r\t\t\t: ");
                    med_length = sizeof(session_s[j].medicine_id)/sizeof(int);
                    for(i=0;i<med_length;i++){
                        if(session_s[j].medicine_id[i]==0){
                            break;
                        }
                        printf("%s, ",medicine_s[session_s[j].medicine_id[i]-1]);
                    }
                    printf("\nRoom ID\r\t\t\t: %d\n",session_s[j].room_id);
                    printf("Expense\r\t\t\t: %d\n",session_s[j].expense);
                };
            }
        }
    }
    else if (h==4){
        int doctor_ids;
        printf("Data Dokter: \n");
        printf ("ID\tNama\n");
        for (i=0;i<3;i++){
            printf("%d\t%s\n", i, doctor_s[i]);
        }
        printf("Masukkan id dokter: ");
        scanf("%d", &doctor_ids);
        for(j=0;j<num_session_s;j++){
            if (session_s[j].patient_id==pat_id){
                if(session_s[j].doctor_id==doctor_ids){
                    printf("\n");
                    printf("ID\r\t\t\t: %d\n", session_s[j].patient_id);
                    printf("session_s ke-%d\n",session_s[j].session_number+1);
                    printf("Dokter\r\t\t\t: %s\n",doctor_s[session_s[j].doctor_id]);
                    printf("Desease\r\t\t\t: %s\n",session_s[j].disease);
                    printf("medicine_s\r\t\t\t: ");
                    med_length = sizeof(session_s[j].medicine_id)/sizeof(int);
                    for(i=0;i<med_length;i++){
                        if(session_s[j].medicine_id[i]==0){
                            break;
                        }
                        printf("%s, ",medicine_s[session_s[j].medicine_id[i]-1]);
                    }
                    printf("\nRoom ID\r\t\t\t: %d\n",session_s[j].room_id);
                    printf("Expense\r\t\t\t: %d\n",session_s[j].expense);
                };
            }
        }
    }
    else{
        return 0;
    }
}
void swap(int *xp, int *yp, int *x_in, int *y_in)
{
    int temp = *xp;
    int temp_in = *x_in;
    *xp = *yp;
    *x_in = *y_in;
    *yp = temp;
    *y_in = temp_in;
}
  
void selectionSort(int arr[], int arr_in[], int n)
{
    int i, j, min_idx;
    for (i = 0; i < n-1; i++)
    {
        min_idx = i;
        for (j = i+1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        swap(&arr[min_idx], &arr[i], &arr_in[min_idx], &arr_in[i]);
    }
}

int sort_session(){
    int pat_id,j,in=0,i=0;
    int expense[100];
    int expense_index[100];
    printf("Masukkan ID pasien : ");
    scanf("%d",&pat_id);
    system("cls");
    for(j=0;j<num_patient_s;j++){
        if (patient_s[j].patient_id==pat_id){
            printf("Patient Data: \n");
        	printf("\n====================================================================\n");
            printf("patient_s ID\r\t\t\t: %d\n", patient_s[j].patient_id);
            printf("Name\r\t\t\t: %s\n",patient_s[j].name);
            printf("TTL\r\t\t\t: %s, %d %s %d\n", patient_s[j].tempat_lahir, patient_s[j].h_lahir, patient_s[j].b_lahir, patient_s[j].t_lahir);
            printf("Phone Number\r\t\t\t: %s\n", patient_s[j].phone);
            printf("====================================================================\n");
            printf("\n");
            break;
        }else if(j==num_patient_s-1){
        	printf("\n\nData Tidak Ditemukan!!\n\n");
		}
    }
    for(j=0;j<num_session_s;j++){
        if (session_s[j].patient_id==pat_id){
            expense[in]=session_s[j].expense;
            expense_index[in]=j+1;
            in++;
        }
    }
    if (expense_index[0]==0){
        printf("Masih Belum ada Sesi");
        return 0;
    }
    selectionSort(expense, expense_index, in);
    int k, med_length, index;
    for(k=0;k<in;k++){
        index = expense_index[k]-1;
        printf("\n");
        printf("ID\r\t\t\t: %d\n", session_s[index].patient_id);
        printf("Sesi ke-%d\n",session_s[index].session_number+1);
        printf("Dokter\r\t\t\t: %s\n",doctor_s[session_s[index].doctor_id]);
        printf("Desease\r\t\t\t: %s\n",session_s[index].disease);
        printf("Medicine\r\t\t\t: ");
        med_length = sizeof(session_s[index].medicine_id)/sizeof(int);
        for(i=0;i<med_length;i++){
            if(session_s[index].medicine_id[i]==0){
                break;
            }
            printf("%s, ",medicine_s[session_s[index].medicine_id[i]-1]);
        }
        printf("\nRoom ID\r\t\t\t: %d\n",session_s[index].room_id);
        printf("Expense\r\t\t\t: %d\n",session_s[index].expense);
    }
    return 0;
}

int read_patient_s(){
    FILE *fp = fopen("patient.txt","r");
    if(fp == NULL)
    {
        fp = fopen("patient.txt","w");
        fclose(fp);
        printf("File does not exist, I JUST CREATED IT, exiting...\n\n\n");
        return 0;
    }

    num_patient_s = fread(patient_s, sizeof(struct patient_data_session),100, fp);
    fclose(fp);
    return 0;
}

int read_session_s(){
    FILE *fp = fopen("patient_session.txt","r");
    if(fp == NULL)
    {
        fp = fopen("patient_session.txt","w");
        fclose(fp);
        printf("File does not exist, I JUST CREATED IT, exiting...\n\n\n");
        return 0;
    }

    num_session_s = fread(session_s, sizeof(struct patient_session_s),200, fp);
    fclose(fp);
    return 0;
}

