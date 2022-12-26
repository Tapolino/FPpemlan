#include <iostream>
#include <conio.h>
using namespace std;

#define max 15

struct data_topskor
{
	string pemain;
	string klub;
	int goal;
	int asst;
};
data_topskor tops[max];

void datainput(struct data_topskor *tops)
{
	tops[0].klub = "Persib\t";
	tops[0].pemain = "Messi";
	tops[0].goal = 15;
	tops[0].asst = 26;

	tops[1].klub = "Persita ";
	tops[1].pemain = "Mbappe";
	tops[1].goal = 27;
	tops[1].asst = 12;

	tops[2].klub = "Selangor FA";
	tops[2].pemain = "Lautaro";
	tops[2].goal = 12;
	tops[2].asst = 8;

	tops[3].klub = "AS Roma ";
	tops[3].pemain = "Boaz";
	tops[3].goal = 19;
	tops[3].asst = 14;

	tops[4].klub = "Persija ";
	tops[4].pemain = "Ronaldi";
	tops[4].goal = 14;
	tops[4].asst = 5;

	tops[5].klub = "Persipura";
	tops[5].pemain = "Neymar";
	tops[5].goal = 11;
	tops[5].asst = 16;

	tops[6].klub = "Martapura FC";
	tops[6].pemain = "Halland";
	tops[6].goal = 21;
	tops[6].asst = 15;

	tops[7].klub = "Persis Solo";
	tops[7].pemain = "Benzema";
	tops[7].goal = 16;
	tops[7].asst = 7;

	tops[8].klub = "Persik Kediri";
	tops[8].pemain = "Salah";
	tops[8].goal = 18;
	tops[8].asst = 13;

	tops[9].klub = "Persija ";
	tops[9].pemain = "Nunez";
	tops[9].goal = 26;
	tops[9].asst = 10;
}

void TopAssistWithShellSort(struct data_topskor *tops, int n)
{
	int i, j, k;
	for (i = n / 2; i > 0; i = i / 2)
	{
		for (j = i; j < n; j++)
		{
			for (k = j - i; k >= 0; k = k - i)
			{
				if (tops[k + i].asst <= tops[k].asst)
				{
					break;
				}
				else
				{
					swap(tops[k].asst, tops[k + 1].asst);
					swap(tops[k].goal, tops[k + 1].goal);
					swap(tops[k].klub, tops[k + 1].klub);
					swap(tops[k].pemain, tops[k + 1].pemain);
				}
			}
		}
	}
}

void TopScorerWithBubbleSort(struct data_topskor *tops, int n)
{
	int i, j;
	for (i=0;i < n - 1;i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (tops[j].goal < tops[j+1].goal)
			{
			swap(tops[j].goal, tops[j + 1].goal);
			swap(tops[j].pemain, tops[j +1].pemain);
			swap(tops[j].asst, tops[j + 1].asst);
			swap(tops[j].klub, tops[j + 1].klub);
					
			}
		}
	}
}

void Adddata(struct data_topskor *tops)
{	
			int size = 0;
   				
		for (int i = 0; i < max; i++) {
		  if (tops[i].pemain.empty()) {
		    break;
		  }
		  size++;
		}
		cout << "Jumlah pemain sekarang : " << size << endl;
		
			cout << " ==++Data Pemain Baru++==" << endl;
			cout << " Klub: ";
			cin>>tops[size].klub;
		
			cout << " Pemain: ";
			cin>>tops[size].pemain;
		
			cout << " Goal: ";
			cin >> tops[size].goal;
			
			cout << " Asst: ";
			cin >> tops[size].asst;
		
			cout << endl;
				
			cout << tops[size].klub <<" dengan para pemain " << tops[size].pemain;
			cout << " dengan goal yang tercetak " << tops[size].goal <<" memiliki asst " << tops[size].asst <<" dalam pertandingan " << endl;
}

void searchPemain(data_topskor tops[], int  n)
{
	string nama;
	int flag=0;
			cout<<"  Cari Pemain : "; cin>>nama;
			for(int i=0;i<n;i++)
			{
				if(tops[i].pemain == nama)
				{
					cout<<" ------------------------"<<endl; 
					cout<<" Topscore ke "<<i+1<<endl;
					cout<<" ------------------------"<<endl; 
					cout<<" Nama     : "<<nama<<endl;
					cout<<" Klub     : "<<tops[i].klub<<endl;
					cout<<" Goal     : "<<tops[i].goal<<endl;
					cout<<" Assist   : "<<tops[i].asst<<endl;
					cout<<" ------------------------"<<endl;
					flag++;
					break;
				}	
			}
			if(flag==0)
			{
				cout<< "\n  Nama pemain "<<nama<<" tidak ada dalam jajaran topscore\n"<<endl;
			}
			else
			{
				cout<<" "<<nama<<" ada dalam jajaran topscore"<<endl;
			}
			cout<<"\n\t\t\t TEKAN APAPUN UNTUK KEMBALI!\n";
	getch();system("cls");
}

void display(data_topskor *tops,int n)
{
	
	cout<<" +------+------------------------+---------------+---------------+---------------+\n";
	cout<<" | No\t|\tKlub\t\t | \tPemain\t | \tGoal\t | \tAssist\t |\n";
	cout<<" +------+------------------------+---------------+---------------+---------------+\n";
	for(int i=0;i<n;i++)
	{
		cout<<" | "<<i+1<<"\t|\t"<<tops[i].klub<<"\t | \t"<<tops[i].pemain<<"\t | \t"<<tops[i].goal<<"\t | \t"<<tops[i].asst<<"\t |\n";
	}
	cout<<" +------+------------------------+---------------+---------------+---------------+\n";
	cout<<"\n\t\t\t   TEKAN APAPUN UNTUK KEMBALI!\n";
	getch(); system("cls");
}

int main()
{
	int menu, temp, i, j;
	int length = 10;
	char *cari;
	data_topskor tops[max];
	datainput(tops);

	//display(tops,max);
	do
	{
		
		cout<<" ========================\n";
		cout<<" |         MENU         |\n";
		cout<<" +----------------------+\n";
		cout<<" | 1. Display Player\t|\n | 2. Top 5 Goalscorer\t|\n | 3. Top 5 Assister\t|\n | 4. Add Data\t|\n | 5. Searching\t\t|\n | 6. Exit\t\t|\n";
		cout<<" ========================\n";
		cout<<"  Masukkan pilihan -> "; cin>>menu;
		printf("\n");
		switch (menu)
		{
		case 1:
		{
			// DISPLAY SELURUH DATA TANPA SORTING
			cout<<"\t\t\t\tGOALSCORER\n";
			datainput(tops);
			display(tops,max);

			break;
		}
		case 2:
		{
			//display top goal max 5 data teratas
			cout<<"\t\t\t\tDATA TOPSCORE\n";
			TopScorerWithBubbleSort(tops, length);
			display(tops,5);
			break;
		}
		case 3:
		{
			cout<<"\t\t\t\tDATA TOP ASSIST\n";
			TopAssistWithShellSort(tops, length);
			display(tops,5);
			break;
		}
		case 4:
		{
			//menambahkan menu data
			cout<<"\t\t\t\tAdd data\n";
			Adddata(tops);
			display(tops,max);
			break;
		}
		case 5:
		{
			//search
			searchPemain(tops,max);
			break;
		}
		case 6:
			{
				cout<<" \n\t\t\tKELUAR PROGRAM\n\n";
			}
		default:
		{
			system("cls");
			break;
		}
		}
	} while (menu != 6);
	return 0;
}
