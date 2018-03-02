#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int city[1000][1000], visit[1000];
int citynumber, bestcost = INT_MAX;
int tour[1000], besttour[1000];
int visitcity;
int listcity[1000];
void readfile(int city[1000][1000], int &citynumber);
int selectnextcity(int city[1000][1000], int citynumber, int currentcity);
void GTS1(int city[1000][1000], int citynumber, int startcity);
void GTS2(int city[1000][1000], int citynumber);

int main()
{
	readfile(city, citynumber);
	GTS2(city, citynumber);
	_getch();
	return 1;
}

void readfile(int city[1000][1000], int &citynumber)
{
	FILE* f = fopen("GTS2.txt", "rt");
	if (f == NULL)
	{
		printf("Khong doc duoc file");
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
}

int selectnextcity(int city[1000][1000], int citynumber, int currentcity)
{
	int mincost = INT_MAX;
	int selectedcity = 0;
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
	int currentcity = startcity;
	visit[startcity] = 1;
	int selectedcity = 0;
	for (int i = 1; i < citynumber; i++)
	{
		selectedcity = selectnextcity(city, citynumber, currentcity);
		tour[++tourindex] = selectedcity;
		cost += city[currentcity][selectedcity];
		visit[selectedcity] = 1;
		currentcity = selectedcity;
	}
	cost += city[currentcity][startcity];
	if (cost < bestcost)
	{
		bestcost = cost;
		for (int i = 1; i <= citynumber; i++)
		{
			besttour[i] = tour[i];
		}
	}
}

void GTS2(int city[1000][1000], int citynumber)
{
	printf("Nhap vao so thanh pho can di chuyen ");
	int amount;
	scanf("%d", &amount);
	printf("Nhap vao nhung thanh pho di chuyen ");
	int citytovisit = 0;
	for (int i = 0; i < amount; i++)
	{
		scanf("%d", &citytovisit);
		GTS1(city, citynumber, citytovisit);
		for (int i = 0; i <= citynumber; i++)
		{
			tour[i] = 0;
			visit[i] = 0;
		}
	}
	printf("Best cost %d \n", bestcost);
	for (int i = 1; i <= citynumber; i++)
	{
		printf("%d -> ", besttour[i]);
	}
	printf("%d", besttour[1]);
}