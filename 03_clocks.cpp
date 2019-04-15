// 03_clocks.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include<cstring>
#include <iostream>
#include<vector>
using namespace std;
vector<int> results;
vector<int> minResult;
unsigned int MIN = 27;
void Move(int a[3][3], int i)
{
	switch (i)
	{
	case 1:
		a[0][0] = ++a[0][0] % 4;
		a[0][1] = ++a[0][1] % 4;
		a[1][0] = ++a[1][0] % 4;
		a[1][1] = ++a[1][1] % 4;
		results.push_back(1);
		break;
	case 2:
		a[0][0] = ++a[0][0] % 4;
		a[0][1] = ++a[0][1] % 4;
		a[0][2] = ++a[0][2] % 4;
		results.push_back(2);
		break;
	case 3:
		a[0][1] = ++a[0][1] % 4;
		a[0][2] = ++a[0][2] % 4;
		a[1][1] = ++a[1][1] % 4;
		a[1][2] = ++a[1][2] % 4;
		results.push_back(3);
		break;
	case 4:
		a[0][0] = ++a[0][0] % 4;
		a[1][0] = ++a[1][0] % 4;
		a[2][0] = ++a[2][0] % 4;
		results.push_back(4);
		break;
	case 5:
		a[0][1] = ++a[0][1] % 4;
		a[1][0] = ++a[1][0] % 4;
		a[1][1] = ++a[1][1] % 4;
		a[1][2] = ++a[1][2] % 4;
		a[2][1] = ++a[2][1] % 4;
		results.push_back(5);
		break;
	case 6:
		a[0][2] = ++a[0][2] % 4;
		a[1][2] = ++a[1][2] % 4;
		a[2][2] = ++a[2][2] % 4;
		results.push_back(6);
		break;
	case 7:
		a[1][0] = ++a[1][0] % 4;
		a[1][1] = ++a[1][1] % 4;
		a[2][0] = ++a[2][0] % 4;
		a[2][1] = ++a[2][1] % 4;
		results.push_back(7);
		break;
	case 8:
		a[2][0] = ++a[2][0] % 4;
		a[2][1] = ++a[2][1] % 4;
		a[2][2] = ++a[2][2] % 4;
		results.push_back(8);
		break;
	case 9:
		a[1][1] = ++a[1][1] % 4;
		a[1][2] = ++a[1][2] % 4;
		a[2][1] = ++a[2][1] % 4;
		a[2][2] = ++a[2][2] % 4;
		results.push_back(9);
		break;
	}
}
void adjustClocks(int a[3][3])
{
	int p[3][3];
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				
				//memcmp(p, a, sizeof(a));
				for (int m = 0; m < 3; m++)
				{
					for (int n = 0; n < 3; n++)
					{
						p[m][n] = a[m][n];
					}
				}
				
				int t1 = i;
				int t2 = j;
				int t3 = k;
				while (t1--)
				{
					Move(p, 1);
				}
				while (t2--)
				{
					Move(p, 2);
				}
				while (t3--)
				{
					Move(p, 3);
				}
				//A
				if (p[0][0] == 1)
				{
					Move(p, 4);
					Move(p, 4);
					Move(p, 4);
				}
				else if (p[0][0] == 2)
				{
					Move(p, 4);
					Move(p, 4);
				}
				else if (p[0][0] == 3)
				{
					Move(p, 4);
				}
				//B
				if (p[0][1] == 1)
				{
					Move(p, 5);
					Move(p, 5);
					Move(p, 5);
				}
				else if (p[0][1] == 2)
				{
					Move(p, 5);
					Move(p, 5);
				}
				else if (p[0][1] == 3)
				{
					Move(p, 5);
				}
				//C
				if (p[0][2] == 1)
				{
					Move(p, 6);
					Move(p, 6);
					Move(p, 6);
				}
				else if (p[0][2] == 2)
				{
					Move(p, 6);
					Move(p, 6);
				}
				else if (p[0][2] == 3)
				{
					Move(p, 6);
				}
				//D
				if (p[1][0] == 1)
				{
					Move(p, 7);
					Move(p, 7);
					Move(p, 7);
				}
				else if (p[1][0] == 2)
				{
					Move(p, 7);
					Move(p, 7);
				}
				else if (p[1][0] == 3)
				{
					Move(p, 7);
				}
				//G
				if (p[2][0] == 1)
				{
					Move(p, 8);
					Move(p, 8);
					Move(p, 8);
				}
				else if (p[2][0] == 2)
				{
					Move(p, 8);
					Move(p, 8);
				}
				else if (p[2][0] == 3)
				{
					Move(p, 8);
				}
				//E
				if (p[1][1] == 1)
				{
					Move(p, 9);
					Move(p, 9);
					Move(p, 9);
				}
				else if (p[1][1] == 2)
				{
					Move(p, 9);
					Move(p, 9);
				}
				else if (p[1][1] == 3)
				{
					Move(p, 9);
				}
				//FHI
				if (p[1][2] != 0 || p[2][1] != 0 || p[2][2] != 0)
				{
					//此路不通
					results.clear();
				}
				else
				{
					if (MIN >= results.size())
					{
						minResult.assign(results.begin(), results.end());
						MIN = results.size();
					}
					results.clear();
				}

			}
		}
	}
}
int main()
{
	int a[3][3];
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> a[i][j];
		}
	}
	adjustClocks(a);
	for (unsigned int i = 0; i < MIN; i++)
	{
		if (i != 0)
			cout << " ";
		cout << minResult.at(i);
	}
	cout << endl;
	return 0;
}
