// homework5.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int main()
{
	cout << "��������:";
	int num; //�ļ���Ŀ����
	vector<int> vl;//�洢�ļ����ʴ���
	vector<int> rl;//�洢���
	int wait;
	int total = 0;
	int direction = 1;
	float cost = 0;
	//��������
	cin >> num;
	cout << "��ĿΪ��" << num << " �Ĵ���"<<endl;
	int midle = int(num / 2);
	for (int i = 0; i < num; i++)
	{
		int temp = 0;
		cin >> temp;
		rl.push_back(0);
		vl.push_back(temp);
	}
	//���ļ����ʽ�������
	sort(vl.begin(), vl.end());
	for (int j = 0; j < num; j++)
	{
		total = total + vl[j];
	}
	//�Դŵ����а���
	for (int j = 0; j < num; j++)
	{
		int index = midle+abs(int((j+1)/2))*direction;
		rl[index] = vl[num-1-j];
		direction = -direction;
	}
	cout << "����˳��Ϊ��" << endl;
	//�������
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
		{
			cost = float(rl[i])*float(rl[j])*abs(i - j)+cost;
		}
	
		cout << rl[i]<<" ";
	}
	cost = cost / float(total*total*2);
	//������
	cout <<endl<<"���ۣ�"<<endl<< cost;
	cin >> wait;
    return 0;
}

