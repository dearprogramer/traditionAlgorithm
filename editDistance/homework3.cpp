// homework3.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
using namespace std;
#include <iostream>
#include <vector>
#include <sstream>
const int maxsize = 10000;
int min(int a, int b, int c)//�ҵ�����ֵ����С��һ��
{
	int r=a;
	if (a > b)
	{
			r = b;
	}
	if (r > c) r = c;
	return r;

}
int main()
{
	//��ʼ����������
	string b = "";
	string a = "";
	int m = 0;
	int n =0; 
	vector<vector <int>> d;//�洢�������
	//���룺
	cout << "please enter value of a:" <<endl;
	getline(cin, a);
	cout << "please enter value of b:"<< endl;
	getline(cin, b);
	//��ʼ��d��ֵ���Լ��߽�����
	 m = a.length();
	 n = b.length();
	for (int i = 0; i<=m; i++)
	{
		vector<int> temp;
		for (int j = 0; j <= n; j++)
		{
			temp.push_back(0);
		}
		d.push_back(temp);
	}
	for (int j = 0; j <= m; j++)
	{
		d[j][0] = j;
	}
	for (int i = 0; i <=n; i++)
	{
		d[0][i] = i;
	}
	//�������
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			int temp = a[i - 1] == b[j - 1] ? 0 : 1;
			d[i][j] = min(d[i - 1][j] + 1, d[i][j - 1] + 1, temp + d[i-1][j-1]);
		}
		
	}
	//������:
	cout <<"the result is:"<<endl<< d[m][n];
	int wait;
	cin >> wait;
    return 0;
}

