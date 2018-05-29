// homework6.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <iostream>
using namespace std;
bool isok(vector<vector<int>> &data, int index, int color)//判断是否冲突
{
	bool isok = true;
	int rows = data.size();
	int cols = data[0].size();
	int x = 1 + int(index / cols);
	int y =  int(index%cols);
	for (int i = 0; i < x; i++)
	{
		if (data[i][y] == color) return false;
	}
	for (int i = 0; i < y; i++)
	{
		if (data[x][i] == color) return false;
	}
	return isok;
}
void traceback(vector<vector<int>> &data, int index,int &result)//回溯结构
{
	int rows = data.size();
	int cols = data[0].size();
	int x = 1 + int(index /cols);
	int y = int(index%cols);
		for (int i = 1; i <= cols; i++)
		{
			
			if (isok(data, index, i))
			{
				data[x][y] = i;
				if (index < ((rows - 1)*((cols - 1))))
				{
					traceback(data, index +
						1, result);
				}
				else
				{
					result = result + 1;
				}			
			}
		}
}
int fac(int a)//计算阶乘
{
	if (a == 0) return 1;
	else return a*fac(a - 1);
}
int main()
{
	int m, n;
	cout << "input m:";
	cin >> m;
	cout << "input n:";
	cin >> n;
	vector<vector<int>> Metrix;//储存宝石排列信息
	int result=0;
	for (int i = 0; i < m; i++)
	{
		vector<int> tempv;
		for (int j = 0; j < n; j++)
		{
			tempv.push_back(0);
		}
		Metrix.push_back(tempv);

	}
	for (int i = 0; i < m; i++)
	{
		Metrix[i][0] = i;
	}
	for (int j = 0; j < n; j++)
	{
		Metrix[0][j] = j;
	}
	traceback(Metrix, 1, result);
	cout << "standard nums:" << result<<endl;
	int factor = fac(n)*fac(n - 1) / fac(n - m);
	result = result *factor ;
	cout <<"factor is ："<<factor<<endl<< "result:" << result;
	int wait;
	cin >> wait;
    return 0;
}

