#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 10

typedef struct
{
	char pemain[50];
	char klub[25];
	int goal;
	int asst;
}data_topskor;
data_topskor tops[MAX];


int main()
{
	int menu;
	do
	{
		printf(" MENU\n");
		printf(" 1. Input Data\n 2. Display Pencetak goal\n 3. Display Top Skor/Assist\n 4. Topskor \n 5. Searching\n 6. Exit\n\n");
		printf(" Masukkan pilihan -> "); scanf("%d",&menu);
		printf("\n");
		switch(menu)
		{
			case 1:
				{
         				 //input data nama pemain, nama klub, jumlah goal, jumlah assist
					// max 10 data
					break;
				}
			case 2:
				{
					//display semua data pencetak goal tanpa sorting
					break;
				}
			case 3:
				{
					//display top skor/assist dengan 2 metode sorting yang berbeda
					if(topskor)
					{
						//display top skor descending max 5 data
					}
					else if(topassist)
					{
						//display top assist descending max 5 data
					}
					else
					break;
				}
			case 4:
				{
					//dsiplay 1 data topskor dengan goal terbanyak
					break;
				}
			case 5:
				{
					//searching nama pemain
					break;
				}
			case 6:
				{
					//exit
					break;
				}
			default:
				{
					system("cls");
					break;
				}
		}
	}while(menu!=6);
	return 0;
}
