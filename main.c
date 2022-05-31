//Kelompok 16:
// M. Naufal Athallah (1906305373)
// Primayoga Budyprawira (1906379491)
// Rafif Fadhlah Ushaim (1906379421)
// Jalankan Program dari main.c dan pastikan semua file ada dalam 1 folder


#include "SessionEdit.h"
#include "UserEdit.h"

int main(){
	system("color F4");
    int choice;
	while(choice!=611){
		system("cls");
		printf("\n==========================================================");
		printf("\nSELAMAT DATANG DI SISTEM ADMINISTRASI KLINIK SEHAT MAKMUR");
		printf("\n==========================================================");
		printf("\n\n\n");
		printf("===============\n");
		printf("**Pilih Mode**\n===============\n1. Tambah Data Pasien\n2. Lihat Data Pasien\n3. Cari Data Pasien\n4. Edit Data Pasien\n5. Lihat Data Sesi Pasien\n6. Cari Sesi Pasien\n7. Urutkan Sesi Berdasarkan Pengeluaran\n8. Tambah Data Antrean Pengobatan (LINKED LIST)\n9. Lihat Data Antrean Pengobatan(LINKED LIST)\n10. Delete Data Antrean (LINKED LIST)\n11. Mencari data pasien berdasarkan pasien ID menggunakan binary tree search (BINARY TREE)\n12. Lihat data dengan struktur binary tree (BINARY TREE)\n13. Keluar\n\nOpsi = ");
		
		scanf("%d",&choice);
		fflush(stdin);
		if(choice==1)
		{
			system("cls");
			User_init(1);
		}
		else if(choice==2){
			system("cls");
			User_init(2);
		}
		else if(choice==3)
		{
			system("cls");
			User_init(3);
		}
		else if(choice==4)
		{
			system("cls");
			User_init(4);
		}
		else if(choice==5)
		{
			system("cls");
			Session_init(1);     
		}
		else if(choice==6)
		{
			system("cls");
			Session_init(2);         
		}
		else if(choice==7)
		{
			system("cls");
			Session_init(3);   
		}
		else if(choice==8){
			system("cls");
			User_init(5);
		}
		else if(choice==9)
		{
			system("cls");
			User_init(6);   
		}
		else if(choice==10)
		{
			system("cls");
			User_init(7);   
		}
		else if(choice==12)
		{
			system("cls");
			User_init(8);   
		}
		else if(choice==11)
		{
			system("cls");
			User_init(9);   
		}
		else if(choice==13)
		{
			system("cls");
			return 0;           
		}
		else
		{
			system("cls");
			printf("\n\nError!! , Input Salah");
		}
		printf("\n\n");
	}
}



