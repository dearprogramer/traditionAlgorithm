// homework5.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int main()
{
	cout << "输入总数:";
	int num; //文件数目多少
	vector<int> vl;//存储文件访问次数
	vector<int> rl;//存储结果
	int wait;
	int total = 0;
	int direction = 1;
	float cost = 0;
	//输入数据
	cin >> num;
	cout << "数目为：" << num << " 的代价"<<endl;
	int midle = int(num / 2);
	for (int i = 0; i < num; i++)
	{
		int temp = 0;
		cin >> temp;
		rl.push_back(0);
		vl.push_back(temp);
	}
	//对文件概率进行排序
	sort(vl.begin(), vl.end());
	for (int j = 0; j < num; j++)
	{
		total = total + vl[j];
	}
	//对磁道进行安排
	for (int j = 0; j < num; j++)
	{
		int index = midle+abs(int((j+1)/2))*direction;
		rl[index] = vl[num-1-j];
		direction = -direction;
	}
	cout << "排列顺序为：" << endl;
	//计算代价
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
		{
			cost = float(rl[i])*float(rl[j])*abs(i - j)+cost;
		}
	
		cout << rl[i]<<" ";
	}
	cost = cost / float(total*total*2);
	//输出结果
	cout <<endl<<"代价："<<endl<< cost;
	cin >> wait;
    return 0;
}

