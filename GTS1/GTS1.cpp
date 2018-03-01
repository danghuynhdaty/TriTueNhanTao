#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int city[1000][1000], visit[1000];
int citynumber;
int tour[1000];

void readfile(int city[1000][1000], int &citynumber);
int selectnextcity(int city[1000][1000], int citynumber, int currentcity);
void GTS1(int city[1000][1000], int citynumber, int startcity);

int main()
{
	readfile(city, citynumber);
	printf("Nhap vao thanh pho bat dau ");
	int startcity = 0;
	scanf("%d", &startcity);
	GTS1(city, citynumber, startcity);
	_getch();
	return 1;
}

void readfile(int city[1000][1000], int &citynumber)
{
	FILE* f = fopen("GTS1.txt", "rt");
	if (f == NULL)
	{
		printf("File khong ton tai");
		return;
	}

	fscanf(f, "%d", &citynumber);

	for (int i = 1; i <= citynumber; i++)
	{
		for (int j = 1; j <= citynumber; j++)
		{
			fscanf(f, "%d", &city[i][j]);
		}
	}

	printf("n = %10d \n", citynumber);

	for (int i = 1; i <= citynumber; i++)
	{
		for (int j = 1; j <= citynumber; j++)
		{
			printf("%10d", city[i][j]);
		}
		printf("\n");
	}
}

int selectnextcity(int city[1000][1000], int citynumer, int currentcity)
{
	int selectedcity = INT_MAX;
	int mincost = INT_MAX;

	for (int i = 1; i <= citynumber; i++)
	{
		if (visit[i] == 0 && city[currentcity][i] < mincost)
		{
			mincost = city[currentcity][i];
			selectedcity = i;
		}
	}
	return selectedcity;
}

void GTS1(int city[1000][1000], int citynumber, int startcity)
{
	int cost = 0;
	int tourindex = 1;
	tour[tourindex] = startcity;
	visit[startcity] = 1;
	int currentcity = startcity;
	int selectedcity = 0;
	printf("%3d ->", startcity);
	for (int i = 1; i < citynumber; i++)
	{
		selectedcity = selectnextcity(city, citynumber, currentcity);
		tour[++tourindex] = selectedcity;
		printf("%3d ->", selectedcity);
		visit[selectedcity] = 1;
		cost += city[currentcity][selectedcity];
		currentcity = selectedcity;
	}
	printf("%3d", startcity);
	cost += city[currentcity][startcity];
	printf("\nquang duong ngan nhat la: %6d", cost);
}