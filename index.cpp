#include <iostream>

using namespace std;

#define max 10

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
	tops[0].klub = "Persib";
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

void TopScoreWithBubble(struct data_topskor *tops, int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)
		for (j = 0; j < n - i - 1; j++)
			if (tops[j].goal > tops[j + 1].goal)
			{

				swap(tops[j].goal, tops[j + 1].goal);
				swap(tops[j].pemain, tops[j + 1].pemain);
				swap(tops[j].asst, tops[j + 1].asst);
				swap(tops[j].klub, tops[j + 1].klub);
			}
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

void printArray(struct data_topskor *tops, int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		cout << "Nama	: " << tops[i].pemain << endl;
		cout << "Club	: " << tops[i].klub << endl;
		cout << "Goal	: " << tops[i].goal << endl;
		cout << "Assist	: " << tops[i].asst << endl;
		cout << endl;
	}
}

int main()
{
	int menu, temp, i, j;
	int length = 10;
	char *cari;
	data_topskor tops[max];
	datainput(tops);

	printArray(tops, length);
	do
	{
		printf(" MENU\n");
		printf(" 1. Display Goal Scorrer \n 2. Display Sorted Goal \n 3. Display Sorted Assist \n 4. Penghargaan topskor\n 5. Searching\n 6. Exit\n\n");
		printf(" Masukkan pilihan -> ");
		scanf("%d", &menu);
		printf("\n");
		switch (menu)
		{
		case 1:
		{
			// DISPLAY SELURUH DATA TANPA SORTING
			datainput(tops);
			printArray(tops, length);

			break;
		}
		case 2:
		{
			TopScoreWithBubble(tops, length);
			printArray(tops, 5);

			break;
		}
		case 3:
		{
			TopAssistWithShellSort(tops, length);
			printArray(tops, 5);
			break;
		}
		case 4:
		{
			// search
		}
		case 5:
		{
			// exit
			break;
		}
		default:
		{
			system("cls");
			break;
		}
		}
	} while (menu != 5);
	return 0;
}
