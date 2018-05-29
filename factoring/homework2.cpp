// homework2.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
using namespace std;
#include <iostream>
#include<vector>
#include<fstream>
#include <io.h>
#include <math.h>
#include <map>
#include "BasicDataDeal.h"
long const MAX_NUM = 2000000000;
void findPrimeNum(vector<long> &primeNums,int maxnum)
{
	long maxPrimenum = 2;
	primeNums.push_back(2);
	int size = 1;
	int tempnum = 1;
	int isprime = 1; 
	int continu = 1;
	int maxprime;
	maxprime = int(sqrt(double(maxnum)));
	for (long i = 2; i <maxnum; i++)
	{
		isprime = 1;
		size = primeNums.size();
		continu = 1;
		for (int j = 0; (j < size)&&continu; j++)
		{
			tempnum = primeNums[j];
			if ((i%tempnum) == 0)
			{
				continu = 0;
				isprime = 0;
			}
			if (j >maxprime)
			{
				continu = 0;
				isprime = 1;
			}
		}
		if (isprime == 1)
		{
			primeNums.push_back(i);
		}
	}	
}


void findMinNums(map<long, long> &data,map<long,vector<long>> & result,vector<long>& primefactors, long minnum, long maxnum, int value = 1)//��������P�ļ���E
{
	map<long, long> localmap;
	localmap = data;
	int tempvalue;
	long  prime;
	long  count;
	//result.insert(pair<long, vector<long>>(value,primefactors));
	map<long, long>::iterator iter;
	for (iter = localmap.begin(); iter != localmap.end(); iter++)
		{
			vector<long> tempprimenums;
			tempprimenums = primefactors;
			prime = iter->first;
			count = iter->second;
			if (count > 0)
			{
				map<long, long> newmap;
				newmap = data;
				tempvalue = value*prime;
				if (tempvalue <= maxnum)
				{
					tempprimenums.push_back(prime);
					if (tempvalue >=minnum)
					{
						result.insert(pair<long, vector<long>>(tempvalue, tempprimenums));
					}
					newmap[prime]= count - 1;
					findMinNums(newmap, result, tempprimenums, minnum, maxnum, tempvalue);
				}
			}
		}
}
void printMap(map<long, long> m)
{
	cout << "�����ֽ�:" << endl;
	map<long, long>::iterator iter;
	for (iter = m.begin(); iter != m.end(); iter++)
	{
		cout << iter->first << " : " << iter->second << "\t";
	}
	cout << endl;

}
void printVector(vector<long> data)//��ӡ������
{
	int size = data.size();
	int value=0;
	for (int i = 0; i < size; i++)
	{
		value = data[i];
		cout << value << "\t";
	}
}
void printFinalResult(vector< vector <long>> result)//��ӡ���
{
	int width = result.size();
	
	for (int i = 0; i < width; i++)
	{
		vector<long> data = result[i];
		int height = data.size();
		for (int j = 0; j < height; j++)
		{
			cout << data[j] << "\t";
		}
		cout << endl;
	}
}
void printReslutMap(map <long, vector<long>> m)//��ӡmap
{
	cout << "Pֵ����:" << endl;
	for (auto iter = m.begin(); iter != m.end(); iter++)
	{
		vector<long> factors;
		cout << iter->first << " : ";
		factors = iter->second;
		for (auto tv = factors.begin(); tv != factors.end(); tv++)
		{
			cout << *tv << "\t";
		}
		cout << endl;
	}
}
void transform(vector <long> &data, map<long, long> &result)//������ͳ�Ƴ�map,����ͳ�������ָ���ֵ�ĸ�������<ֵ������>����map�С�
{
	int size = data.size();
	for (int i = 0; i < size; i++)
	{
		int key = data[i];
		if (result.count(key) > 0)
		{
			result[key] = result[key] + 1;
		}
		else
		{
			result.insert(pair<long, long>(key, 1));
		}
	}
}
void permutation(map<long, long> &data, map<long, long> &tempresult, vector<vector <long>> &result,int size)//��ͳ�Ƶõ���map������������ϡ��������ӽ���������ϡ�
{

	map<long, long>::iterator iter;
	long key;
	long value;
	if (tempresult.size() == 0)
	{
		for (int i = 0; i < size; i++)
		{
			tempresult.insert(pair<long, long>(i, 0));
		}
	}
	if (size>0 )
	{
		iter = data.begin();
		{
			key = iter->first;
			value = iter->second;
			int tempsize = tempresult.size();
			int begin = 0;
			int availablesize = 0;
			vector<long> availuable;
			for (int i = 0; i < tempsize; i++)
			{
				if (key == tempresult[i]) begin = i + 1;
			}
			for (int i = begin; i < tempsize; i++)
			{
				if (tempresult[i] == 0) availuable.push_back(i);
			}
			availablesize = availuable.size ()+ 1 -value;
			for (int i = 0; i < availablesize; i++)
			{
				int tempkey = availuable[i];
				map<long, long> tempdata = data;
				if (value > 1)
				{
					tempdata[key] = tempdata[key] - 1;
				}
				else
				{
					tempdata.erase(key);
				}
				map<long,long> newresult;
				newresult= tempresult;
				newresult[tempkey
				] = key;
				permutation(tempdata, newresult, result,size-1);
			}
			
		}
	}
	else
	{
		vector<long> tempr;
		for (int i = 0; i < tempresult.size(); i++)
		{
			tempr.push_back(tempresult[i]);
		}
		result.push_back(tempr);
	}
}
//��n���������ֽ⡣numΪ���ֽ������primenums�洢�������� result�洢�������<����������>�Ե�ͼ��
void analysis(long num, vector<long> &primenums, map<long, long> &result)
{
	int size = primenums.size();
	long data = num;
	long tempprime = 2;
	long count = 0;
	int isprime = 1;
	for (int i = 0; (i < size)&&(tempprime<=data); i++)
	{
		count = 0;
		tempprime = primenums[i];
		while ((data%tempprime)==0)
		{
			count = count + 1;
			data = data / tempprime;
		}
		if (count > 0)
		{
			isprime = 0;
			result.insert(pair<long, long>(tempprime, count));
		}
	}
	if (isprime)
	{
		result.insert(pair<long, long>(num, 1));
	}
}

void discouple(map<long, long> &primenums, vector<long> &result, vector< vector<long> > &totalresult, long min, long num)
{
	long tempMinNum, tempNum;
	map <long, vector <long>> tempMins;
	map<long, long> tempPrimes;
	vector<long> tempResult;
	vector<long> tempfactors;
	long maxprimes = long(sqrt(double(num)));
	tempPrimes = primenums;
	tempResult = result;
	tempResult.push_back(num);
	totalresult.push_back(tempResult);
	findMinNums(tempPrimes, tempMins, tempfactors, min, maxprimes);
	printReslutMap(tempMins);
	for (auto iter = tempMins.begin(); iter != tempMins.end(); iter++)
	{
		vector<long> factors;
		map<long, long> newPrimes;
		newPrimes = primenums;
		tempMinNum = iter->first;
		factors = iter->second;
		if (tempMinNum >= min)
		{
			tempNum = num / tempMinNum;
			vector<long> newresult;
			newresult = result;
			newresult.push_back(tempMinNum);
			for (auto cv = factors.begin(); cv != factors.end(); cv++)
			{
				newPrimes[*cv] = newPrimes[*cv] - 1;
			}
			discouple(newPrimes, newresult, totalresult, tempMinNum, tempNum);
		}
	}
}

//���ݷֽ������map(primenums)��totalresult�洢���ӵ����vector��p1,p2,p3...������������Ϊ���ӵĴ���Ĳ�ͬ�����µĲ�ͬ�����numΪ���ֽ������
void discompose(map<long, long> &primenums,  vector< vector<long> > &totalresult, long num)
{
	vector<long> tempvector;
	discouple(primenums, tempvector, totalresult, 1,num);

}
void getfinalreslut(vector<vector <long>> &data, vector<vector <long>> &result)//��discouple�õ����У�p1,p2,p3...)����������ϡ�dataΪ����ĸ�������ϣ�result�洢�����
{
	int size = data.size();
	for (int i = 0; i < size; i++)
	{
		vector<long> tempvector;
		int length;
		tempvector= data[i];
		length = tempvector.size();
		vector<long> tempresult;
		map<long, long> tempdata;
		map<long, long> tempdata1;
		transform(tempvector, tempdata);
		permutation(tempdata, tempdata1,result,length);
	}
}
int main()
{
	string primeNumFile = "prime.txt";//�洢�����ļ�
	string inputFilename = "input.txt";
	string outputFilename = "output.txt";
	vector<long> primedata;//������
	BasicDataDeal<long> bdd(primeNumFile);//���ڴ������ݴ洢
	map<long, long> analysisMap;//�洢�����ֽ������
	map <long, vector<long>> minNumsMap;//�洢p���Ӽ���E
	vector<long> tempvector;
	vector<long> tempresult;
	int maxnum;
	int maxprime;
	long testnum = 56;
	vector<vector<long>> finalresult;//���ظ�������
	vector<vector<long>> factors;//������������ϵĽ����
	maxprime = int(sqrt(double(MAX_NUM)));//�洢��������

	//��������ļ����ڣ����ȡ������������㡣
	if (_access(primeNumFile.c_str(),0)==-1)
	{
		findPrimeNum(primedata, maxprime);
		bdd.writedata(primedata,20);
		cout << "prime.txt not exist!"<<endl;
	}
	else
	{
		cout << "prime.txt exist!"<<endl;
		bdd.readData(primedata);
	}
	cout << "������Ҫ�ֽ��n:" << endl;
	cin >> testnum;
	//��n���зֽ���������
	maxnum= int(sqrt(double(testnum)));
	analysis(testnum, primedata, analysisMap);
	printMap(analysisMap);

	//��ò��ظ������ӡ�
	//discouple(analysisMap, tempresult, finalresult, 1, testnum);
	discompose(analysisMap, finalresult, testnum);
	cout << "������Ͻ��" << endl;
	printFinalResult(finalresult);
	//printReslutMap(minNumsMap);
	getfinalreslut(finalresult, factors);
	cout << "����������Ͻ����" << endl;
	printFinalResult(factors);
	//�洢���ս����
	bdd.setFileUrl(outputFilename);
	bdd.writeVector2(factors);

	int wait;
	cin >> wait;
    return 0;
}

