#include <iostream>  
#include <string>  
#include <vector>  
#include <stdlib.h>  
using namespace std;
struct bigcheng
{
	vector<int> a;
	vector<int> b;
	string result_str;
};
void chartonum(string a, string b, bigcheng &tempcheng);//字符串转换为数字并反转  
void multiply(bigcheng &tempchengh, vector<int> &result_num);//逐位相乘,处理进位消除多余的0  
void numtochar(bigcheng &tempcheng, vector<int> &result_num);//将计算结果转换为字符串并反转


void chartonum(string a, string b, bigcheng &tempcheng)
{
	int size_a = a.size();
	int size_b = b.size();
	for (int i = size_a - 1; i >= 0; i--)
	{
		tempcheng.a.push_back(a[i] - '0');
	}
	for (int i = size_b - 1; i >= 0; i--)
	{
		tempcheng.b.push_back(b[i] - '0');
	}
}

void multiply(bigcheng &tempcheng, vector<int> &result_num)
{
	for (unsigned int i = 0; i<tempcheng.a.size(); i++)
	{
		for (unsigned int j = 0; j<tempcheng.b.size(); j++)
		{
			result_num[i + j] += (tempcheng.a[i])*(tempcheng.b[j]);
		}
	}
	for (int i = result_num.size() - 1; i >= 0; i--)
	{
		if (result_num[i] != 0)
		{
			break;
		}
		else
			result_num.pop_back();
	}
	int c = 0;
	for (unsigned int i = 0; i<result_num.size(); i++)//处理进位  
	{
		result_num[i] += c;
		c = result_num[i] / 10;
		result_num[i] = result_num[i] % 10;
	}
	if (c != 0)
	{
		result_num.push_back(c);
	}
}


void numtochar(bigcheng &tempcheng, vector<int> &result_num)
{
	int size = result_num.size();
	for (unsigned int i = 0; i<result_num.size(); i++)
	{
		tempcheng.result_str.push_back(char(result_num[size - 1 - i] + '0'));
	}
}


int main()
{
	bigcheng tempcheng;
	string a, b;
	cin >> a >> b;
	chartonum(a, b, tempcheng);
	vector<int> resultnum(a.size() + b.size(), 0);
	multiply(tempcheng, resultnum);
	numtochar(tempcheng, resultnum);
	cout << tempcheng.result_str << endl;
	system("pause");
	return 0;
}