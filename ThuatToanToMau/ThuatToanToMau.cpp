#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#define MAX 100


int node[MAX][MAX];// mảng lưu các đỉnh cần tô màu
int amount; // số lượng đỉnh
int color = 0; // số màu cần tô
int colorednode = 0;//số đỉnh đã được tô
int result[MAX];//mảng lưu kết quả sau khi tô


void readfile(int node[MAX][MAX], int &amount);

#pragma region To mau 1

void fillcolor1(int node[MAX][MAX], int amount);
bool cancolor(int node[MAX][MAX], int amount, int currentnode, int color);

#pragma endregion

#pragma region To mau 2

struct Node
{
	int deg;//bậc của đỉnh
	int color; //màu cần tô
	int index;//chỉ số
};

Node nodes[MAX];

void sortnode(int node[MAX][MAX],Node nodes[MAX]);
void swap(Node &a, Node &b);
void fillcolor2(Node nodes[MAX], int amount, int node[MAX][MAX]);


#pragma endregion


int main()
{



	readfile(node, amount);
	//fillcolor1(node, amount);

	fillcolor2(nodes,amount,node);

	_getch();
	return 0;
}

void readfile(int node[MAX][MAX], int &amount)
{
	FILE* f = fopen("thuattoantomau.txt", "rt");
	if (f == NULL)
	{
		printf("Khong doc duoc file");
		return;
	}
	fscanf(f, "%d", &amount);
	printf("%d \n", amount);
	for (int i = 1; i <= amount; i++)
	{
		for (int j = 1; j <= amount; j++)
		{
			fscanf(f, "%d", &node[i][j]);
			printf("%6d", node[i][j]);
		}
		printf("\n");
	}

}

#pragma region To mau 1

bool cancolor(int node[MAX][MAX], int amount, int currentnode, int color)
{
	for (int i = 1; i < amount; i++)
	{
		//nếu có bất kì đỉnh kề nào của currentnode đã được tô màu color thì loại
		if (node[currentnode][i] != 0 && result[i] == color)
		{
			return false;
		}
	}
	return true;
}

void fillcolor1(int node[MAX][MAX], int amount)
{
	printf("\nThuat toan to mau 1");
	color = 1;
	do
	{
		for (int i = 1; i <= amount; i++)
		{
			if (result[i] == 0)
			{
				result[i] = color;
				colorednode++;
				printf("\nDinh %3d: %3d", i, color);
				for (int j = i + 1; j <= amount; j++)
				{
					//chưa tô và không kề i 
					if (result[j] == 0 && node[i][j] == 0)
					{
						if (cancolor(node, amount, j, color) == true)
						{
							result[j] = color;
							colorednode++;
							printf("\nDinh %3d: %3d", j, color);
						}
					}
				}
				color++;
			}

		}
	} while (colorednode < amount);
}


#pragma endregion

#pragma region To mau 2

void swap(Node &a, Node &b)
{
	int deg = a.deg;
	int index = a.index;

	a.deg = b.deg;
	a.index = b.index;

	b.deg = deg;
	b.index = index;


}
void sortnode(int node[MAX][MAX], Node nodes[MAX])
{
	//tính bậc của từng đỉnh
	for (int i = 1; i <= amount; i++)
	{
		for (int j = 1; j <= amount; j++)
		{
			nodes[i].index = i;
			if (node[i][j] == 1)
			{
				nodes[i].deg++;
			}
		}
	}

	//sap xep cac dinh co bac giam dan	
	for (int i = 1; i < amount; i++)
	{
		int min_index = i;
		for (int  j = i+1; j <= amount; j++)
		{
			if (nodes[min_index].deg < nodes[j].deg)
			{
				min_index = j;
			}
		}
		swap(nodes[i],nodes[min_index]);
	}
}

void fillcolor2(Node nodes[MAX], int amount, int node[MAX][MAX])
{
	sortnode(node,nodes);
	printf("\nThuat toan to mau 1");
	color = 1;
	do
	{
		for (int i = 1; i <= amount; i++)
		{
			if (nodes[i].color == 0)
			{
				result[i] = color;
				colorednode++;
				printf("\nDinh %3d: %3d", i, color);
				for (int j = i + 1; j <= amount; j++)
				{
					//chưa tô và không kề i 
					if (result[j] == 0 && node[i][j] == 0)
					{
						if (cancolor(node, amount, j, color) == true)
						{
							result[j] = color;
							colorednode++;
							printf("\nDinh %3d: %3d", j, color);
						}
					}
				}
				color++;
			}

		}
	} while (colorednode < amount);
}
#pragma endregion
