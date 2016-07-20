#include <iostream>  
#include <string>  
#include <vector>  
#include <stdlib.h>  
using namespace std;

/**计算大数乘法**/  /* http://blog.csdn.net/myweaven/article/details/38724015 */
/*先选中你要注释的代码行，按Ctrl+k再按Ctrl+c即可把选中的代码行注释掉,如果要取消注释的话，那么可以按Ctrl+k再按Ctrl+u即可去掉//*/
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
	int c = 0;//定义进位
	for (unsigned int i = 0; i<result_num.size(); i++)//处理进位  
	{
		result_num[i] += c;
		c = result_num[i] / 10;
		result_num[i] = result_num[i] % 10;
	}
	if (c != 0)
	{   //判断最高位是否存在进位
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



///*优化之后的代码,优化后时间复杂度不变，但节省了空间，代码更简洁。*/
//#include <iostream>  
//#include <string>  
//#include <vector>  
//#include <stdlib.h>  
//#include <assert.h>  
//using namespace std;
//
//struct bigcheng2
//{
//	string a;
//	string b;
//	string result_str;
//};
//void reverse_data(string &data);//字符串反转  
//void multiply2(bigcheng2 &tempcheng2);//字符串模拟相乘  
//
//void reverse_data(string &data)
//{
//	char temp = '0';
//	int start = 0;
//	int end = data.size() - 1;
//	assert(data.size() && start <= end);
//	while (start < end)
//	{
//		temp = data[start];
//		data[start++] = data[end];
//		data[end--] = temp;
//	}
//}
//
//void multiply2(bigcheng2 &tempcheng2)
//{
//	reverse_data(tempcheng2.a);//字符串反转  
//	reverse_data(tempcheng2.b);
//	int c = 0;
//	string temp(tempcheng2.a.size() + tempcheng2.b.size(), '0');//将temp全部初始化为0字符  
//	for (unsigned int i = 0; i < tempcheng2.a.size(); i++)
//	{
//		unsigned int j;
//		for (j = 0; j < tempcheng2.b.size(); j++)
//		{
//			c += temp[i + j] - '0' + (tempcheng2.a[i] - '0')*(tempcheng2.b[j] - '0');//注意temp[i+j]可能保存有上一次计算的结果  
//			temp[i + j] = (c % 10) + '0';//将结果转换为字符  
//			c = c / 10;
//		}
//		while (c)
//		{
//			temp[i + j++] += c % 10;//temp里已存字符  
//			c = c / 10;
//		}
//	}
//	for (int i = temp.size() - 1; i >= 0; i--)
//	{
//		if (temp[i] != '0')
//			break;
//		else
//			temp.pop_back();
//	}
//	reverse_data(temp);//结果?字á?符¤?串ä?反¤¡ä转áa  
//	tempcheng2.result_str = temp;
//}
//
//int main(){
//	bigcheng2 tempcheng2;
//	string a, b;
//	cin >> a >> b;
//	tempcheng2.a = a;
//	tempcheng2.b = b;
//	multiply2(tempcheng2);
//	cout << tempcheng2.result_str << endl;
//	system("pause");
//	return 0;
//}
//		
//	