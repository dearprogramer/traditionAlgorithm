#pragma once
using namespace std;
#include <vector>
#include <iostream>
#include <fstream>
template <typename type>class BasicDataDeal
{
private:
	int cols;
	
public:
	string fileurl;
	BasicDataDeal(string url)
	{
		fileurl = url;
	};
	void setFileUrl(string url)
	{
		fileurl = url;
	}
	bool writeVector2(vector<vector<type>> data)
	{
		ofstream fout(fileurl);
		int size = data.size();
		type tempvalue;
		if (fout.is_open())
		{
			for (int i = 0; i < size; i++)
			{ 
				vector <type> tempvector;
				tempvector = data[i];
				for (int j = 0; j < tempvector.size(); j++)
				{
					tempvalue = tempvector[j];
					fout << tempvalue << "\t";
				}
				 fout << "\n";
			}
			fout.close();
			return true;
		}
		else return false;
	}
	int readData(vector<type> &data)
	{
		ifstream fin(fileurl);
		type tempvalue;
		int size = 0;
			if (fin.is_open())
			{
				while (!fin.eof())
				{
					fin >> tempvalue;
					data.push_back(tempvalue);
					size = size + 1;
					
				}
				fin.close();
				return size;
			}
			else return -1;
	};
	int readData(type &data,int index=0)
	{
		ifstream fin(fileurl);
		type tempvalue;
		int size = 0;
		if (fin.is_open())
		{
			while ((!fin.eof())&&(size<=index))
			{
				fin >> tempvalue;
				data = tempvalue;
				size = size + 1;

			}
			fin.close();
			return 1;
		}
		else return -1;
	};
	bool writedata(vector<type> &data, int cols)
	{
		{
			ofstream fout(fileurl);
			int size = data.size();
			type tempvalue;
			if (fout.is_open())
			{
				for (int i = 0; i < size; i++)
				{
					tempvalue = data[i];
					fout << tempvalue << "\t";
					if (((i + 1) % cols) == 0) fout <<"\n";
				}
				fout.close();
				return true;
			}
			else return false;
		}
	};
	~BasicDataDeal()
	{
	};
	
};

