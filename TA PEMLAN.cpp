#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#define max 10

struct data_topskor
{
	char* pemain;
	char* klub;
	int goal;
	int asst;
};
data_topskor tops[max];

void datainput(struct data_topskor* tops)
{
	tops[0].klub = "Persib\t";
	tops[0].pemain = "Messi";
	tops[0].goal = 19;
	tops[0].asst = 26;
	
	tops[1].klub = "Persita ";
	tops[1].pemain = "Mbappe";
	tops[1].goal = 28;
	tops[1].asst = 10;
	
	tops[2].klub = "Persegres ";
	tops[2].pemain = "Lautaro";
	tops[2].goal = 12;
	tops[2].asst = 8;
	
	tops[3].klub = "AS Roma ";
	tops[3].pemain = "Boaz";
	tops[3].goal = 30;
	tops[3].asst = 21;
	
	tops[4].klub = "Persija ";
	tops[4].pemain = "Ronaldi";
	tops[4].goal = 20;
	tops[4].asst = 5;
	
	tops[5].klub = "Man Utd ";
	tops[5].pemain = "Dedik S";
	tops[5].goal = 26;
	tops[5].asst = 3;
	
	tops[6].klub = "Deltras ";
	tops[6].pemain = "Halland";
	tops[6].goal = 29;
	tops[6].asst = 15;
	
	tops[7].klub = "Persis\t";
	tops[7].pemain = "Benzema";
	tops[7].goal = 16;
	tops[7].asst = 7;
	
	tops[8].klub = "Persik\t";
	tops[8].pemain = "M Salah";
	tops[8].goal = 24;
	tops[8].asst = 18;
	
	tops[9].klub = "Persija ";
	tops[9].pemain = "Nunez";
	tops[9].goal = 47;
	tops[9].asst = 17;
}


int main()
{
	int menu,temp,i,j;
	char* cari;
	data_topskor tops[max];
	datainput(tops);
	
	do
	{
		printf(" MENU\n");
		printf(" 1. Display Goal Scorrer \n 2. Display Top skor/Assist\n 3. Penghargaan topskor\n 4. Searching\n 5. Exit\n\n");
		printf(" Masukkan pilihan -> "); scanf("%d",&menu);
		printf("\n");
		switch(menu)
		{
			case 1:
				{
					//DISPLAY TANPA SORTING
					printf(" +------+------------------------+---------------+---------------+---------------+\n");
					printf(" | No\t|\tKlub\t\t | \tPemain\t | \tGoal\t | \tAssist\t |\n");
					printf(" +------+------------------------+---------------+---------------+---------------+\n");
					for(i=0;i<max;i++)
					{
						printf(" | %d\t|\t%s\t | \t%s\t | \t%d\t | \t%d\t |\n",i+1,tops[i].klub,tops[i].pemain,tops[i].goal,tops[i].asst);
					}
					printf(" +------+------------------------+---------------+---------------+---------------+\n");
					getch(); system("cls");
					break;
				}
			case 2:
				{
					//sorting top skor/assist
					int top;
					printf("\n\n Display \n 1. Top Skor\n 2. Top Assist\n");
					printf(" Masukkan pilihan -> "); scanf("%d",&top);
					if(top == 1)//sorting topskor
					{
								
					}
					else if(top == 2)//sorting top assist
					{
						
					}
					else 
					{
						system("cls");
					}
					getch(); system("cls");
					break;
				}
			case 3:
				{
					
					//penghargaan topskor
					break;
				}
			case 4:
				{
					//search
				}
			case 5:
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
