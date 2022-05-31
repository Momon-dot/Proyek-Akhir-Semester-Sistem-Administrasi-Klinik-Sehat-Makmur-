//Kelompok 16:
// M. Naufal Athallah (1906305373)
// Primayoga Budyprawira (1906379491)
// Rafif Fadhlah Ushaim (1906379421)

#include "UserEdit.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>

struct patient_data{
    int patient_id;
    char name[30];
    char tempat_lahir[14];
    int h_lahir;
    char b_lahir[10];
    int t_lahir;
    char phone[13];
} patient[200];

struct patient_session{
    int patient_id;
    int session_number;
    int doctor_id;
    char desease[30];
    int medicine_id[10];
    int room_id;
    int expense;
} session[200];

struct patient_data_linked_list * headAddressa = NULL; // langkah 3
struct patient_data_linked_list * nextAddressa = NULL;
struct patient_data_linked_list * iteratorPtr;
struct patient_data_linked_list * TmpPtr;


struct patient_data_linked_list{
    int patient_id;
    char name[30];
    char tempat_lahir[14];
    int h_lahir;
    char b_lahir[10];
    int t_lahir;
    char phone[13];
    int urutan;
    struct patient_data_linked_list * next;
};


char doctor[10][100] = {"dr. Primayoga B", "dr. Naufal Athallah", "dr. Rafif F."};
char medicine[10][100] = {"Apriximol", "Selitol", "Bodrin", "Ligobi", "Maximl"};
int num_patient,num_session;
int queue;

struct patient_data_linked_list * node_baru(int patient_id, char * name, char * tempat_lahir, int h_lahir, char * b_lahir, int t_lahir, char * phone, struct patient_data_linked_list * next){
    struct patient_data_linked_list * tmpAddress = malloc(sizeof(struct patient_data_linked_list));
    tmpAddress->patient_id = patient_id;
    strcpy(tmpAddress->name,name);
    strcpy(tmpAddress->tempat_lahir,tempat_lahir);
    tmpAddress->h_lahir = h_lahir;
    strcpy(tmpAddress->b_lahir,b_lahir);
    tmpAddress->t_lahir = t_lahir;
    strcpy(tmpAddress->phone, phone);
    tmpAddress->urutan = 0;
    tmpAddress->next = next;
    return tmpAddress;
}
int add();
void view();
int search();
int edit();
int read_patient();
int read_session();
void write_patient();
void write_session();
int delete_linked_list();
int view_linked_list();
int add_queue();
void bin_tree();
void search_bt();

void User_init(int x){
    read_patient();
    read_session();
    switch (x)
    {
    case 1:
        add();
        break;
    case 2:
        view();
        break;
    case 3:
        search();
        break;
    case 4:
        edit();
        break;
    case 5:
        add_queue();
        break;
    case 6:
        view_linked_list();
        break;
    case 7:
        delete_linked_list();
        break;
    case 8:
        bin_tree();
        break;
    case 9:
        search_bt();
        break;
    default:
        break;
    }
    printf("Tekan Tombol Apapun untuk Lanjut !!");
    getch();
}

////////////////////////////////////////////////////////////////////////////////Binary Tree//////////////////////////////////////////////////////////
struct treeNode {
    struct treeNode *leftPtr;
    int data;
    char name[30];
    char tempat_lahir[14];
    int h_lahir;
    char b_lahir[10];
    int t_lahir;
    char phone[13];
    struct treeNode *rightPtr;
};

typedef struct treeNode TreeNode;
typedef TreeNode *TreeNodePtr;
int insertNode(TreeNodePtr *treePtr, int value, char * name, char * tempat, int h_lahir, char * b_lahir, int t_lahir, char * phone);

struct Trunk
{
    struct Trunk *prev;
    char str[10];
};

typedef struct Trunk Trunk; 
// Helper function to print branches of the binary tree
void showTrunks(Trunk *p)
{
    if (p == NULL) {
        return;
    }
 
    showTrunks(p->prev);
    printf ("%s",p->str);
}
 
void printTree(TreeNodePtr root, Trunk *prev, int isLeft)
{
    if (root == NULL) {
        return;
    }
    
    char prev_str[10] = "     ";
    Trunk *trunk = (Trunk*)malloc(sizeof(Trunk));
    trunk->prev = prev;
    strcpy( trunk->str, prev_str );
    printTree(root->rightPtr, trunk, 1);
 
    if (!prev == 1) {
        strcpy(trunk->str,"---");
    }
    else if (isLeft==1)
    {
        strcpy(trunk->str , ".---");
        strcpy(prev_str , "    |");
    }
    else {
        strcpy(trunk->str , "`---");
        strcpy(prev->str , prev_str);
    }
 
    showTrunks(trunk);
    printf("%d\n", root->data);
    if (prev) {
        strcpy(prev->str, prev_str);
    }
    strcpy(trunk->str , "    |");
 
    printTree(root->leftPtr, trunk, 0);
}

int len_old = 0; 
void shuffle(int *array, size_t n)
{
    if (n > 1) 
    {
        size_t i;
        for (i = 0; i < n - 1; i++) 
        {
          size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
          int t = array[j];
          array[j] = array[i];
          array[i] = t;
        }
    }
}

TreeNodePtr binary_tree(){
    int i,j;
    int item, flag, test;
    int la[200];
    TreeNodePtr rootPtr = NULL;

    for (i = 0; i <num_patient; i++){
        la[i] = patient[i].patient_id;
    }
    shuffle(la,num_patient);
    for (i = 0; i <num_patient; i++){
        item = la[i];
        for(j=0; j<num_patient;j++){
            if(item==patient[j].patient_id){
                flag = insertNode(&rootPtr, item, patient[j].name, patient[j].tempat_lahir, patient[j].h_lahir, patient[j].b_lahir, patient[j].t_lahir, patient[j].phone);
            }
        }
        
    }
    return rootPtr;
}

int insertNode (TreeNodePtr *treePtr, int value, char * name, char * tempat, int h_lahir, char * b_lahir, int t_lahir, char * phone){
    if (*treePtr == NULL){
        *treePtr = malloc(sizeof(TreeNode));

        if(*treePtr != NULL){
            (*treePtr)->data = value;
            strcpy((*treePtr)->name , name);
            strcpy((*treePtr)->tempat_lahir , tempat);
            (*treePtr)->h_lahir = h_lahir;
            strcpy((*treePtr)->b_lahir , b_lahir);
            (*treePtr)->t_lahir = t_lahir;
            strcpy((*treePtr)->phone, phone);
            (*treePtr)->leftPtr = NULL;
            (*treePtr)->rightPtr = NULL;
        }else{
            printf("%d not inserted, No memory available.\n", value);
        }
        return 0;
    }else{
        if (value < (*treePtr)->data){
            insertNode(&((*treePtr)->leftPtr),value, name, tempat, h_lahir, b_lahir, t_lahir, phone);
        }else if(value > (*treePtr)->data){
            insertNode(&((*treePtr)->rightPtr), value, name, tempat, h_lahir, b_lahir, t_lahir, phone);
        }else{
            return 2;
        }
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void bin_tree(){
    printf("===============================================================================================\n");
    printf("Penampilan struktur binary tree dari data pasien\n");
    printf("===============================================================================================\n");
    printf("\n");
    TreeNodePtr rootPtr= binary_tree();
    printf("Struktur Binary yang dibentuk dari data:\n\n\n");
    printTree(rootPtr, NULL, 0);
    printf("\n\n\nCatatan : Struktur Binary dibentuk menggunakan key dari data id pasien yang diacak\n\n\n");
}

TreeNodePtr search_bin_tree(TreeNodePtr rootPtr, int key)
{
    // Base Cases: root is null or key is present at root
    if (rootPtr == NULL || rootPtr->data == key)
       return rootPtr;
    
    // Key is greater than root's key
    if (rootPtr->data < key)
       return search_bin_tree(rootPtr->rightPtr, key);
 
    // Key is smaller than root's key
    return search_bin_tree(rootPtr->leftPtr, key);
}

void search_bt(){
    int s;
    printf("===============================================================================================\n");
    printf("Pencarian data pasien menggunakan algoritma binary tree search\n");
    printf("===============================================================================================\n");
    printf("\n");
    printf("Masukkan ID Pasien yang ingin dicari:");
    scanf("%d", &s);
    TreeNodePtr result;
    TreeNodePtr rootPtr= binary_tree();
    result = search_bin_tree(rootPtr, s);
    if (result==NULL){
        printf("Data tidak ditemukan");
    }else{
        printf("\n");
        printf("===============================================================================================\n");
        printf("ID");
        printf("\r\tNama Pasien");
        printf("\r\t\t\t\tNo Telp");
        printf("\r\t\t\t\t\t\tTTL");
        printf("\r\t\t\t\t\t\t\t\t\tUrutan");
        printf("\n===============================================================================================");
        printf("\n");
    
        printf("\n");
        printf("%d",result->data);
        printf("\r\t%s",result->name);
        printf("\r\t\t\t\t%s",result->phone);
        printf("\r\t\t\t\t\t\t%s, %d %s %d\t\t",result->tempat_lahir,result->h_lahir,result->b_lahir,result->t_lahir);
        printf("\n\n");

    }
}
int view_linked_list()
{
    printf("===============================================================================================\n");
    printf("Penampilan data antrean (linked-list)\n");
    printf("===============================================================================================\n");
    printf("\n");
    int i = 1;
    if (headAddressa==NULL){
        printf("Belum ada data antrean\n");
        return 0;
    }
    printf("\nData Antrean: \n");
    printf("\n");
    printf("===============================================================================================\n");
    printf("ID");
    printf("\r\tNama Pasien");
    printf("\r\t\t\t\tNo Telp");
    printf("\r\t\t\t\t\t\tTTL");
    printf("\r\t\t\t\t\t\t\t\t\tUrutan");
    printf("\n===============================================================================================");
    printf("\n");
    iteratorPtr = headAddressa;
    while (1){
        if(iteratorPtr->next == NULL){
            printf("\n");
            printf("%d",iteratorPtr->patient_id);
            printf("\r\t%s",iteratorPtr->name);
            printf("\r\t\t\t\t%s",iteratorPtr->phone);
            printf("\r\t\t\t\t\t\t%s, %d %s %d\t\t",iteratorPtr->tempat_lahir,iteratorPtr->h_lahir,iteratorPtr->b_lahir,iteratorPtr->t_lahir);
            printf("\r\t\t\t\t\t\t\t\t\t%d",iteratorPtr->urutan);
            printf("\n\n");
            iteratorPtr = (*iteratorPtr).next;
            break;
        }else{
            printf("\n");
            printf("%d",iteratorPtr->patient_id);
            printf("\r\t%s",iteratorPtr->name);
            printf("\r\t\t\t\t%s",iteratorPtr->phone);
            printf("\r\t\t\t\t\t\t%s, %d %s %d\t\t",iteratorPtr->tempat_lahir,iteratorPtr->h_lahir,iteratorPtr->b_lahir,iteratorPtr->t_lahir);
            printf("\r\t\t\t\t\t\t\t\t\t%d",iteratorPtr->urutan);
            printf("\n\n");
            iteratorPtr = (*iteratorPtr).next;
        }
    }
    return 0;
}

int add_queue(){
    printf("===============================================================================================\n");
    printf("Penambahan data antrean (linked-list)\n");
    printf("===============================================================================================\n");
    printf("\n");

    int s,i,p,u, flag = 0, j = 1;
    printf("Masukkan ID pasien yang akan ditambahkan: ");
    scanf("%d",&s);
    for(i=0;i<num_patient;i++){
        if(patient[i].patient_id==s)
        {
            printf("\nData Pasien: \n");
            printf("===============================================\n");
            printf("ID\r\t\t: %d\n",s);
            printf("Nama\r\t\t: ");
            printf("%s\n", patient[i].name);
            printf("No Telp\r\t\t: %s\n",patient[i].phone);
            printf("TTL\r\t\t: %s, %d %s %d",patient[i].tempat_lahir,patient[i].h_lahir,patient[i].b_lahir,patient[i].t_lahir);
            printf("\n===============================================\n");
            printf("\n");
            flag = 1;
            break;
        }
    }
    if (flag == 0){
        printf("\n\nNot Found\n\n");
        return 0;}
    printf("Masukkan letak input antrean :\n");
    printf("1. Awal\n");
    printf("2. Tengah\n");
    printf("3. Akhir\n\n");
    printf("Input: ");
    scanf("%d",&p);
    if (p==1){
        headAddressa = node_baru(patient[i].patient_id,patient[i].name,patient[i].tempat_lahir,patient[i].h_lahir,patient[i].b_lahir,patient[i].t_lahir,patient[i].phone,headAddressa);
    }else if(p==3){
        iteratorPtr = headAddressa;
        nextAddressa = node_baru(patient[i].patient_id, patient[i].name, patient[i].tempat_lahir, patient[i].h_lahir, patient[i].b_lahir, patient[i].t_lahir, patient[i].phone, NULL);
        while(1){
            if(headAddressa==NULL){
                headAddressa = nextAddressa;
                break;
            }
            else if ((*iteratorPtr).next == NULL){
                (*iteratorPtr).next = nextAddressa;
                break;
            }
            else{
                iteratorPtr = (*iteratorPtr).next;
            }
        }
    }else{
        printf("\nData Antrean Lama: \n");
        printf("\n");
        printf("===============================================================================================\n");
        printf("ID");
        printf("\r\tNama Pasien");
        printf("\r\t\t\t\tNo Telp");
        printf("\r\t\t\t\t\t\tTTL");
        printf("\r\t\t\t\t\t\t\t\t\tUrutan");
        printf("\n===============================================================================================");
        printf("\n");
        iteratorPtr = headAddressa;
        while (1){
            if(iteratorPtr->next == NULL){
                printf("\n");
                printf("%d",iteratorPtr->patient_id);
                printf("\r\t%s",iteratorPtr->name);
                printf("\r\t\t\t\t%s",iteratorPtr->phone);
                printf("\r\t\t\t\t\t\t%s, %d %s %d\t\t",iteratorPtr->tempat_lahir,iteratorPtr->h_lahir,iteratorPtr->b_lahir,iteratorPtr->t_lahir);
                printf("\r\t\t\t\t\t\t\t\t\t%d",j);
                printf("\n\n");
                iteratorPtr->urutan = j;
                j++;
                iteratorPtr = (*iteratorPtr).next;
                break;
            }else{
                printf("\n");
                printf("%d",iteratorPtr->patient_id);
                printf("\r\t%s",iteratorPtr->name);
                printf("\r\t\t\t\t%s",iteratorPtr->phone);
                printf("\r\t\t\t\t\t\t%s, %d %s %d\t\t",iteratorPtr->tempat_lahir,iteratorPtr->h_lahir,iteratorPtr->b_lahir,iteratorPtr->t_lahir);
                printf("\r\t\t\t\t\t\t\t\t\t%d",j);
                printf("\n\n");
                iteratorPtr->urutan = j;
                j++;
                iteratorPtr = (*iteratorPtr).next;
            }
        }
        printf("Masukkan id pasien di depan lokasi yang diinginkan (input akan dimasukkan setelah id ini) :");
        scanf("%d",&u);

        iteratorPtr = headAddressa;
        nextAddressa = node_baru(patient[i].patient_id, patient[i].name, patient[i].tempat_lahir, patient[i].h_lahir, patient[i].b_lahir, patient[i].t_lahir, patient[i].phone, NULL);
        while(1){
            if ((*iteratorPtr).patient_id == u){
                nextAddressa->next = iteratorPtr->next;
                (*iteratorPtr).next = nextAddressa;
                break;
            }else if((*iteratorPtr).next==NULL){
                printf("ID tidak ditemukan");
                break;
            }
            else{
                iteratorPtr = (*iteratorPtr).next;
            }
        }
    }
    j=1;
    printf("\nData Antrean Baru: \n");
    printf("\n");
    printf("===============================================================================================\n");
    printf("ID");
    printf("\r\tNama Pasien");
    printf("\r\t\t\t\tNo Telp");
    printf("\r\t\t\t\t\t\tTTL");
    printf("\r\t\t\t\t\t\t\t\t\tUrutan");
    printf("\n===============================================================================================");
    printf("\n");
    iteratorPtr = headAddressa;
    while (1){
        if(iteratorPtr->next == NULL){
            printf("\n");
            printf("%d",iteratorPtr->patient_id);
            printf("\r\t%s",iteratorPtr->name);
            printf("\r\t\t\t\t%s",iteratorPtr->phone);
            printf("\r\t\t\t\t\t\t%s, %d %s %d\t\t",iteratorPtr->tempat_lahir,iteratorPtr->h_lahir,iteratorPtr->b_lahir,iteratorPtr->t_lahir);
            printf("\r\t\t\t\t\t\t\t\t\t%d",j);
            printf("\n\n");
            iteratorPtr->urutan = j;
            j++;
            iteratorPtr = (*iteratorPtr).next;
            break;
        }else{
            printf("\n");
            printf("%d",iteratorPtr->patient_id);
            printf("\r\t%s",iteratorPtr->name);
            printf("\r\t\t\t\t%s",iteratorPtr->phone);
            printf("\r\t\t\t\t\t\t%s, %d %s %d\t\t",iteratorPtr->tempat_lahir,iteratorPtr->h_lahir,iteratorPtr->b_lahir,iteratorPtr->t_lahir);
            printf("\r\t\t\t\t\t\t\t\t\t%d",j);
            printf("\n\n");
            iteratorPtr->urutan = j;
            j++;
            iteratorPtr = (*iteratorPtr).next;
        }
    }
    return 0;
}

int delete_linked_list(){
    printf("===============================================================================================\n");
    printf("Penghapusan data antrean (linked-list)\n");
    printf("===============================================================================================\n");
    printf("\n");
    if (headAddressa==NULL){
        printf("Belum ada data antrean\n");
        return 0;
    }
    int s,i,p,u, flag = 0, j = 1;
    printf("\nData Antrean Lama: \n");
    printf("\n");
    printf("===============================================================================================\n");
    printf("ID");
    printf("\r\tNama Pasien");
    printf("\r\t\t\t\tNo Telp");
    printf("\r\t\t\t\t\t\tTTL");
    printf("\r\t\t\t\t\t\t\t\t\tUrutan");
    printf("\n===============================================================================================");
    printf("\n");
    iteratorPtr = headAddressa;
    while (1){
        if(iteratorPtr->next == NULL){
            printf("\n");
            printf("%d",iteratorPtr->patient_id);
            printf("\r\t%s",iteratorPtr->name);
            printf("\r\t\t\t\t%s",iteratorPtr->phone);
            printf("\r\t\t\t\t\t\t%s, %d %s %d\t\t",iteratorPtr->tempat_lahir,iteratorPtr->h_lahir,iteratorPtr->b_lahir,iteratorPtr->t_lahir);
            printf("\r\t\t\t\t\t\t\t\t\t%d",j);
            printf("\n\n");
            iteratorPtr->urutan = j;
            j++;
            iteratorPtr = (*iteratorPtr).next;
            break;
        }else{
            printf("\n");
            printf("%d",iteratorPtr->patient_id);
            printf("\r\t%s",iteratorPtr->name);
            printf("\r\t\t\t\t%s",iteratorPtr->phone);
            printf("\r\t\t\t\t\t\t%s, %d %s %d\t\t",iteratorPtr->tempat_lahir,iteratorPtr->h_lahir,iteratorPtr->b_lahir,iteratorPtr->t_lahir);
            printf("\r\t\t\t\t\t\t\t\t\t%d",j);
            printf("\n\n");
            iteratorPtr->urutan = j;
            j++;
            iteratorPtr = (*iteratorPtr).next;
        }
    }
    j=1;
    printf("Masukkan ID pasien yang ingin dihapus: ");
    scanf("%d",&s);
    for(i=0;i<num_patient;i++){
        if(patient[i].patient_id==s)
        {
            printf("\nData Pasien: \n");
            printf("===============================================\n");
            printf("ID\r\t\t: %d\n",s);
            printf("Nama\r\t\t: ");
            printf("%s\n", patient[i].name);
            printf("No Telp\r\t\t: %s\n",patient[i].phone);
            printf("TTL\r\t\t: %s, %d %s %d",patient[i].tempat_lahir,patient[i].h_lahir,patient[i].b_lahir,patient[i].t_lahir);
            printf("\n===============================================\n");
            printf("\n");
            flag = 1;
            break;
        }
    }
    if (flag == 0){
        printf("\n\nNot Found\n\n");
        return 0;}

    iteratorPtr = headAddressa;
    if (headAddressa==NULL){
        printf("\n\nAntrean tidak ditemukan");
        return 0;
    }
    while(1){
        if((*iteratorPtr).patient_id == s && iteratorPtr==headAddressa){
            headAddressa = iteratorPtr->next;
            free(iteratorPtr);
            break;
        }else if ((*iteratorPtr).patient_id == s){
            TmpPtr->next = iteratorPtr->next;
            free(iteratorPtr);
            break;
        }else if((*iteratorPtr).next==NULL){
            printf("Antrean tidak ditemukan");
            break;
        }else{
            TmpPtr = iteratorPtr;
            iteratorPtr = (*iteratorPtr).next;
        }
    }
    printf("\nData Antrean Baru: \n");
    printf("\n");
    printf("===============================================================================================\n");
    printf("ID");
    printf("\r\tNama Pasien");
    printf("\r\t\t\t\tNo Telp");
    printf("\r\t\t\t\t\t\tTTL");
    printf("\r\t\t\t\t\t\t\t\t\tUrutan");
    printf("\n===============================================================================================");
    printf("\n");
    if (headAddressa==NULL){
        printf("Belum ada data antrean\n");
        return 0;
    }
    iteratorPtr = headAddressa;
    while (1){
        if(iteratorPtr->next == NULL){
            printf("\n");
            printf("%d",iteratorPtr->patient_id);
            printf("\r\t%s",iteratorPtr->name);
            printf("\r\t\t\t\t%s",iteratorPtr->phone);
            printf("\r\t\t\t\t\t\t%s, %d %s %d\t\t",iteratorPtr->tempat_lahir,iteratorPtr->h_lahir,iteratorPtr->b_lahir,iteratorPtr->t_lahir);
            printf("\r\t\t\t\t\t\t\t\t\t%d",j);
            printf("\n\n");
            iteratorPtr->urutan = j;
            j++;
            iteratorPtr = (*iteratorPtr).next;
            break;
        }else{
            printf("\n");
            printf("%d",iteratorPtr->patient_id);
            printf("\r\t%s",iteratorPtr->name);
            printf("\r\t\t\t\t%s",iteratorPtr->phone);
            printf("\r\t\t\t\t\t\t%s, %d %s %d\t\t",iteratorPtr->tempat_lahir,iteratorPtr->h_lahir,iteratorPtr->b_lahir,iteratorPtr->t_lahir);
            printf("\r\t\t\t\t\t\t\t\t\t%d",j);
            printf("\n\n");
            iteratorPtr->urutan = j;
            j++;
            iteratorPtr = (*iteratorPtr).next;
        }
    }
    return 0;
}

void view()
{
    int i;
    printf("\n");
    printf("===============================================================================================\n");
    printf("ID");
    printf("\r\tNama Pasien");
    printf("\r\t\t\t\tNo Telp");
    printf("\r\t\t\t\t\t\tTTL");
    printf("\n===============================================================================================");
    printf("\n");
    for(i=0; i<num_patient; i++)
    {
        printf("\n");
        printf("%d",patient[i].patient_id);
        printf("\r\t%s",patient[i].name);
        printf("\r\t\t\t\t%s",patient[i].phone);
        printf("\r\t\t\t\t\t\t%s, %d %s %d\t\t",patient[i].tempat_lahir,patient[i].h_lahir,patient[i].b_lahir,patient[i].t_lahir);
        printf("\n\n");
    }
}

int add(){
    int choice, num_obat;
    printf("\n\n");
    printf("Jumlah data pasien : %d\n\n",num_patient);
    printf("===============\n");
    printf("**Pilih Mode**\n===============\n1.Tambah Data Diri Pasien Baru\n2.Tambah Sesi Berobat Baru\n3.Kembali ke Menu Awal\nPilihan: ");
    scanf("%d",&choice);
    if (choice == 1){
        int sum = 0, i, n, flag;
        printf("\nMasukkan jumlah data yang akan dimasukkan : ");
        scanf("%d",&n);
        sum=n+num_patient;
        for(i=num_patient;i<sum ; i++ )
		{
            printf("\n");
            printf("Masukkan nama pasien = ");
            fflush(stdin);
            fgets(patient[i].name, 30, stdin);
            patient[i].name[strcspn(patient[i].name, "\n")] = 0;
            printf("Masukkan tempat dan tanggal lahir = ");
            scanf("%s",patient[i].tempat_lahir);
            scanf("%d",&patient[i].h_lahir);
            scanf("%s",patient[i].b_lahir);
            scanf("%d",&patient[i].t_lahir);
            printf("Masukkan no telpon = ");
            scanf("%s",patient[i].phone);
            printf("\n");
            patient[i].patient_id = 123456+num_patient;
            num_patient++;
        }

        printf("=====================================\n");
        printf("Data Pasien Baru:\n");
        printf("=====================================\n");
        for(i=num_patient-n;i<sum ; i++ )
		{
            printf("\n");
            printf("ID\r\t\t: %d\n",patient[i].patient_id);
            printf("Nama Pasien\r\t\t: ");
            printf("%s\n",patient[i].name);
            printf("No. Telp\r\t\t: 0%s\n",patient[i].phone);
            printf("TTL\r\t\t: %s, %d %s %d",patient[i].tempat_lahir,patient[i].h_lahir,patient[i].b_lahir,patient[i].t_lahir);
            printf("\n\n");
        }
        printf("\n\nMasukkan 1 bila ingin menyimpan dan 0 untuk kembali ke menu utama: ");
        scanf("%d", &flag);
        if (flag==1){
            write_patient();
            write_session();
        }
    
    }else if (choice == 2){
        int n, sum, i, j, id, p = 0;
        printf("\nMasukkan jumlah data yang akan dimasukkan : ");
        scanf("%d",&n);
        sum=n+num_session;
        for(j = num_session ; j<sum ; j++){
            printf("Masukkan no. ID pasien :");
            fflush(stdin);
            scanf("%d",&id);
            if (id-123456<num_patient){
            	system("cls");
            	printf("=====================================\n");
                printf("Data Pasien :\n");
                printf("=====================================\n");
                printf("\n");
                printf("ID\r\t\t: %d\n",id);
                printf("Nama Pasien\r\t\t: ");
                printf("%s\n",patient[id-123456].name);
                printf("No. Telp\r\t\t: 0%s\n",patient[id-123456].phone);
                printf("TTL\r\t\t: %s, %d %s %d",patient[id-123456].tempat_lahir,patient[id-123456].h_lahir,patient[id-123456].b_lahir,patient[id-123456].t_lahir);
                printf("\n\n");
            }else{
            	printf("Error Data ID: %d Tidak Ditemukan!!\n",id);
            	printf("Tekan apapun untuk kembali");
            	getch();
            	break;
			}
            system("cls");
            session[j].patient_id=id;
            for(i=0;i<num_session;i++){
                if (session[i].patient_id == id){
                    p++;
                }
            }
            session[j].session_number = p;
            printf("Dokter yang tersedia: \n");
            printf ("ID\tNama\n");
            for (i=0;i<3;i++){
                printf("%d\t%s\n", i, doctor[i]);
            }
            printf("Masukkan id dokter: ");
            scanf("%d", &session[j].doctor_id);
            system("cls");
            printf("Obat yang tersedia: \n");
            printf ("ID\tNama\n");
            for (i=0;i<5;i++){
                printf("%d\t%s\n", i+1, medicine[i]);
            }
            printf("Masukkan jumlah obat: ");
            scanf("%d", &num_obat);
            for (i=0; i<num_obat; i++){
                printf("Masukkan id obat ke-%d: ", i+1);
                scanf("%d", &session[j].medicine_id[i]);
            }
            system("cls");
            printf("Masukkan penyakit: ");
            fflush(stdin);
            fgets(session[j].desease, 30, stdin);
            session[j].desease[strcspn(session[j].desease, "\n")] = 0;
            printf("Masukkan id kamar: ");
            scanf("%d", &session[j].room_id);
            printf("Masukkan Tagihan: ");
            scanf("%d", &session[j].expense);
            num_session++;
            
        }write_session();
    }else if(choice == 3){
    	return 0;
	}
    return 0;   
}

int edit(){
    view();
    int q,p,i,flag;
    fflush(stdin);
    printf("Masukkan ID Pasien: ");
    scanf("%d",&p);
    for(i=0;i<num_patient;i++){
        if(patient[i].patient_id==p){
            printf("\n");
            printf("ID\r\t\t: %d\n",p);
            printf("Nama\r\t\t: ");
            printf("%s\n", patient[p-123456].name);
            printf("No Telp\r\t\t: %s\n",patient[p-123456].phone);
            printf("TTL\r\t\t: %s, %d %s %d",patient[p-123456].tempat_lahir,patient[p-123456].h_lahir,patient[p-123456].b_lahir,patient[p-123456].t_lahir);
            printf("\n\n");
            printf("Data yang ingin diubah: \n");
            printf("Enter your option\n");
            printf("1.Nama\n2.TTL\n3.No Telp\n4.Kembali\n");
            printf("Opsi = ");
            scanf("%d",&q);
            if(q<=5)
            {
                if(q==1)
                {
                    fflush(stdin);
                    printf("Masukkan nama yang baru = ");
                    fflush(stdin);
                    fgets(patient[p-123456].name, 30, stdin);
                    patient[p-123456].name[strcspn(patient[p-123456].name, "\n")] = 0;
                }
                else if(q==2)
                {
                    fflush(stdin);
                    printf("Masukkan TTL yang baru = ");
                    scanf("%s",patient[p-123456].tempat_lahir);
                    scanf("%d",&patient[p-123456].h_lahir);
                    scanf("%s",patient[p-123456].b_lahir);
                    scanf("%d",&patient[p-123456].t_lahir);
                }

                else if(q==3)
                {
                    fflush(stdin);
                    printf("Masukkan No Telp yang baru = ");
                    scanf("%s",patient[p-123456].phone);
                }
                printf("=====================================\n");
                printf("Data Pasien Baru:\n");
                printf("=====================================\n");

                printf("\n");
                printf("ID\r\t\t: %d\n",patient[p-123456].patient_id);
                printf("Nama Pasien\r\t\t: ");
                printf("%s\n",patient[p-123456].name);
                printf("No. Telp\r\t\t: %s\n",patient[p-123456].phone);
                printf("TTL\r\t\t: %s, %d %s %d",patient[p-123456].tempat_lahir,patient[p-123456].h_lahir,patient[p-123456].b_lahir,patient[p-123456].t_lahir);
                printf("\n\n");

                printf("\n\nMasukkan 1 bila ingin menyimpan dan 0 untuk kembali ke menu utama: ");
                scanf("%d", &flag);
                if (flag==1){
                    write_patient();
                    write_session();
                } 
            }
            else
            {
                printf("\n\nInvalid option\nTry Again!!\n\n");
            }break;
        }else if(i==num_patient-1){
            printf("Data Tak ditemukan!!");
        }
    }
}

int search(){
    int h,i, flag = 0;
    printf("Metode pencarian data pasien: \n");
    printf("1.ID\n2.Nama\n3.No Telp\n4.Kembali\n\nOption = ");
    scanf("%d",&h);
    if(h==1)
    {
        int s;
        printf("Masukkan ID pasien = ");
        scanf("%d",&s);
        for(i=0;i<num_patient;i++){
            if(patient[i].patient_id==s)
            {
            	printf("\nData Pasien: \n");
                printf("===============================================\n");
                printf("ID\r\t\t: %d\n",s);
                printf("Nama\r\t\t: ");
                printf("%s\n", patient[i].name);
                printf("No Telp\r\t\t: %s\n",patient[i].phone);
                printf("TTL\r\t\t: %s, %d %s %d",patient[i].tempat_lahir,patient[i].h_lahir,patient[i].b_lahir,patient[i].t_lahir);
                printf("\n===============================================\n");
                printf("\n");
                flag = 1;
                break;
            }
        }
        if (flag == 0){
        printf("\n\nNot Found\n\n");
        return 0;
    }
    }

    else if(h==2)
    {
        int f=1, g;
        char u[100]; 
        fflush(stdin);
        printf("Masukkan nama pasien = ");
        fflush(stdin);
        fgets(u, 30, stdin);
        u[strcspn(u, "\n")] = 0;
        fflush(stdin);
        for(g=0; g<num_patient; g++)
        {
            if(strcmp(strlwr(u),strlwr(patient[g].name))==0)
            {
        		printf("\nData Pasien: \n");
                printf("===============================================\n");
                printf("ID\r\t\t: %d\n",g + 123456);
                printf("Nama\r\t\t: %s\n",patient[g].name);
                printf("No Telp\r\t\t: %s\n",patient[g].phone);
                printf("TTL\r\t\t: %s, %d %s %d",patient[g].tempat_lahir,patient[g].h_lahir,patient[g].b_lahir,patient[g].t_lahir);
                printf("\n===============================================\n");
				printf("\n\n");
                f=0;
            }
        }
        if(f==1)
            printf("\nNot Found\n");



    }
    else if(h==3)
    {
        char f[12];
        int g;
        printf("Masukan no telp pasien = ");
        scanf("%s",f);
        for(g=0; g<num_patient; g++)
        {
            if(strcmp(f,patient[g].phone)==0)
            {
                printf("\nData Pasien: \n");
                printf("===============================================\n");
                printf("ID\r\t\t: %d\n",g + 123456);
                printf("Nama\r\t\t: %s\n",patient[g].name);
                printf("No Telp\r\t\t: %s\n",patient[g].phone);
                printf("TTL\r\t\t: %s, %d %s %d",patient[g].tempat_lahir,patient[g].h_lahir,patient[g].b_lahir,patient[g].t_lahir);
                printf("\n===============================================\n");
				printf("\n\n");
            }

        }
    }
    else if (h == 4){
    	return 0;
	}
    else
        printf("\n\nInvalid input\n\n");
}

int read_patient(){
    FILE *fp = fopen("patient.txt","r");
    if(fp == NULL)
    {
        fp = fopen("patient.txt","w");
        fclose(fp);
        printf("File does not exist, I JUST CREATED IT, exiting...\n\n\n");
        return 0;
    }

    num_patient = fread(patient, sizeof(struct patient_data),100, fp);
    fclose(fp);
    return 0;
}

int read_session(){
    FILE *fp = fopen("patient_session.txt","r");
    if(fp == NULL)
    {
        fp = fopen("patient_session.txt","w");
        fclose(fp);
        printf("File does not exist, I JUST CREATED IT, exiting...\n\n\n");
        return 0;
    }

    num_session = fread(session, sizeof(struct patient_session),200, fp);
    fclose(fp);
    return 0;
}

void write_patient(){
    FILE *fp = fopen("patient.txt","w");
    if(fp == NULL)
    {
        printf("Error");
        exit(1);
    }
    fwrite(patient, sizeof(struct patient_data),num_patient, fp);

    fclose(fp);
}

void write_session(){
    FILE *fla = fopen("patient_session.txt","w");
    if(fla == NULL)
    {
        printf("Error");
        exit(1);
    }
    fwrite(session, sizeof(struct patient_session),num_session, fla);

    fclose(fla);
}

