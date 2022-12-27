#include <iostream>
#include <conio.h>
using namespace std;

#define max 10

struct data_topskor
{
	string pemain;
	string klub;
	int goal;
	int asst;
	double prob;
};
data_topskor tops[max];

// data pemain
void datainput(struct data_topskor *tops)
{
	tops[0].klub = "Argentina";
	tops[0].pemain = "Messi";
	tops[0].goal = 17;
	tops[0].asst = 8;
	tops[0].prob;

	tops[1].klub = "Prancis ";
	tops[1].pemain = "Mbappe";
	tops[1].goal = 15;
	tops[1].asst = 5;
	tops[1].prob;

	tops[2].klub = "Portugal ";
	tops[2].pemain = "Ronaldo";
	tops[2].goal = 18;
	tops[2].asst = 6;
	tops[2].prob;

	tops[3].klub = "Brazil\t";
	tops[3].pemain = "Neymar";
	tops[3].goal = 15;
	tops[3].asst = 9;
	tops[3].prob;

	tops[4].klub = "England\t";
	tops[4].pemain = "Meguire";
	tops[4].goal = 13;
	tops[4].asst = 8;
	tops[4].prob;

	tops[5].klub = "Jepang\t";
	tops[5].pemain = "Yoshida";
	tops[5].goal = 12;
	tops[5].asst = 8;
	tops[5].prob;

	tops[6].klub = "Belgia\t";
	tops[6].pemain = "Lukaku";
	tops[6].goal = 15;
	tops[6].asst = 7;
	tops[6].prob;

	tops[7].klub = "Kroasia\t";
	tops[7].pemain = "Modric";
	tops[7].goal = 13;
	tops[7].asst = 7;
	tops[7].prob;

	tops[8].klub = "Maroko\t";
	tops[8].pemain = "Hakimi";
	tops[8].goal = 10;
	tops[8].asst = 5;
	tops[8].prob;

	tops[9].klub = "Brazil\t";
	tops[9].pemain = "GabJes";
	tops[9].goal = 11;
	tops[9].asst = 5;
	tops[9].prob;
}

// sorting menurut assist
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

// sortig menurut goal
void TopScorerWithBubbleSort(struct data_topskor *tops, int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (tops[j].goal < tops[j + 1].goal)
			{
				swap(tops[j].goal, tops[j + 1].goal);
				swap(tops[j].pemain, tops[j + 1].pemain);
				swap(tops[j].asst, tops[j + 1].asst);
				swap(tops[j].klub, tops[j + 1].klub);
			}
		}
	}
}

// Search Pemain
void searchPemain(data_topskor tops[], int n)
{
	string nama;
	int flag = 0;
	cout << "  Cari Pemain : ";
	cin >> nama;
	for (int i = 0; i < n; i++)
	{
		if (tops[i].pemain == nama)
		{
			cout << " ------------------------" << endl;
			cout << " Topscore ke " << i + 1 << endl;
			cout << " ------------------------" << endl;
			cout << " Nama     : " << nama << endl;
			cout << " Klub     : " << tops[i].klub << endl;
			cout << " Goal     : " << tops[i].goal << endl;
			cout << " Assist   : " << tops[i].asst << endl;
			cout << " ------------------------" << endl;
			flag++;
			break;
		}
	}
	if (flag == 0)
	{
		cout << "\n  Nama pemain " << nama << " tidak ada dalam jajaran topscore\n"
				 << endl;
	}
	else
	{
		cout << " " << nama << " ada dalam jajaran topscore" << endl;
	}
	cout << "\n\t\t\t TEKAN APAPUN UNTUK KEMBALI!\n";
	getch();
	system("cls");
}

// top player
void topplayer(struct data_topskor *tops, int n)
{
	int x;

	for (x = 0; x < n; x++)
	{
		tops[x].prob = tops[x].goal + tops[x].asst; // jumlah pertandingan
		tops[x].prob = tops[x].prob / 20;
	}

	for (int i = 0; i < n - 1; i++)
	{

		for (int j = 0; j < n - i - 1; j++)
		{
			if (tops[j].prob < tops[j + 1].prob)
			{
				swap(tops[j].prob, tops[j + 1].prob);
				swap(tops[j].goal, tops[j + 1].goal);
				swap(tops[j].pemain, tops[j + 1].pemain);
				swap(tops[j].asst, tops[j + 1].asst);
				swap(tops[j].klub, tops[j + 1].klub);
			}
		}
	}
}

// display
void display(data_topskor *tops, int n)
{

	cout << " +------+------------------------+---------------+---------------+---------------+\n";
	cout << " | No\t|\tKlub\t\t | \tPemain\t | \tGoal\t | \tAssist\t |\n";
	cout << " +------+------------------------+---------------+---------------+---------------+\n";
	for (int i = 0; i < n; i++)
	{
		cout << " | " << i + 1 << "\t|\t" << tops[i].klub << "\t | \t" << tops[i].pemain << "\t | \t" << tops[i].goal << "\t | \t" << tops[i].asst << "\t |\n";
	}
	cout << " +------+------------------------+---------------+---------------+---------------+\n";
	cout << "\n\t\t\t   TEKAN APAPUN UNTUK KEMBALI!\n";
	getch();
	system("cls");
}

int main()
{
	int menu, temp, i, j;
	int length = 10;
	char *cari;
	data_topskor tops[max];
	datainput(tops);

	// display(tops,max);
	do
	{
		cout << " ========================\n";
		cout << " ||  PROGRAM TOPSCORE  ||\n";
		cout << " ||     PIALA DUNIA    ||\n";
		cout << " ========================\n";
		cout << " |         MENU         |\n";
		cout << " +----------------------+\n";
		cout << " | 1. Display Player\t|\n | 2. Top 5 Goalscorer\t|\n | 3. Top 5 Assister\t|\n | 4. Searching\t\t|\n | 5. Top Player\t|\n | 6. exit\t\t| \n";
		cout << " ========================\n";
		cout << "  Masukkan pilihan -> ";
		cin >> menu;
		printf("\n");
		switch (menu)
		{
		case 1:
		{
			// DISPLAY SELURUH DATA TANPA SORTING
			cout << "\t\t\t\tGOALSCORER\n";
			datainput(tops);
			display(tops, max);

			break;
		}
		case 2:
		{
			// display top goal max 5 data teratas
			cout << "\t\t\t\tDATA TOPSCORE\n";
			TopScorerWithBubbleSort(tops, length);
			display(tops, 5);
			break;
		}
		case 3:
		{
			cout << "\t\t\t\tDATA TOP ASSIST\n";
			TopAssistWithShellSort(tops, length);
			display(tops, 5);
			break;
		}

		case 4:
		{
			// search
			searchPemain(tops, max);
			break;
		}
		case 5:
		{
			// top 3 pemain
			topplayer(tops, max);
			display(tops, 3);
			break;
		}

		case 6:
		{
			cout << " \n\t\t\tKELUAR PROGRAM\n\n";
			break;
		}
		default:
		{
			cout << " \t\t    MENU TIDAK TERSEDIA\n";
			cout << "\n\t\tTEKAN APAPUN UNTUK KEMBALI!\n";
			getch();
			system("cls");
			break;
		}
		}
	} while (menu != 6);
	return 0;
}
