#include<iostream>
#include<string>
using namespace std;

void sortAges(int ages[], int length){
	if (ages == NULL || length <= 0)
		return;

	const int oldestAge = 99;
	int timesOfAge[oldestAge + 1] = { 0 };


	/*统计每个年龄出现的次数*/
	/*for (int i = 0; i <= oldestAge; ++i){
		
		for (int j = 0; j < length; ++j){
			int age = ages[i];
			++ timesOfAge[age];
		}
	}*/ 
	/*错误发生在本部分，其中，olestAges*length >length 所以会出现
	下表计算超出设定限.更正程序如下所示*/

	for (int i = 0; i < length; ++i)
		++timesOfAge[ages[i]];

	/*从小到大将年龄写入到原来的存储数字ages中*/
	int index = 0;
	for (int i = 0; i <= oldestAge; ++i){
		for (int j = 0; j < timesOfAge[i]; ++j){
			ages[index] = i;
			++index;
		}
	}

}
int main() {

	int ages[] = { 1, 2, 1, 1, 2, 3, 4, 5, 6, 7, 8, 9, 4, 3, 5, 2, 3, 2, 7 };
	int length = sizeof(ages) / sizeof(ages[0]);
	sortAges(ages, length);
	cout << "the ages is  ";
	for (int i = 0; i < length; ++i)
		cout << ages[i]<<' ';
	cout << endl;

	//system("pause");
	return 0;
}