#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 50

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
		printf(" 1. Input Data\n 2. Display Topskor\n 3. Display Top Assist\n 4. Pemain Terbaik\n 5. Searching\n 6. Exit\n\n");
		printf(" Masukkan pilihan -> "); scanf("%d",&menu);
		printf("\n");
		switch(menu)
		{
			case 1:
				{
          //input data
					break;
				}
			case 2:
				{
					//sorting topskor
					break;
				}
			case 3:
				{
					//sorting top assist
					break;
				}
			case 4:
				{
					//pemain terbaik
					break;
				}
			case 5:
				{
					//searching
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
