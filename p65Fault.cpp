#include<iostream>
#include<string>
using namespace std;

void sortAges(int ages[], int length){
	if (ages == NULL || length <= 0)
		return;

	const int oldestAge = 9;
	int timesOfAge[oldestAge + 1];

	/*统计每个年龄出现的次数*/
	for (int i = 0; i <= oldestAge; ++i){
		timesOfAge[i] = 0;
		for (int i = 0; i < length; ++i){
			int age = ages[i];
			++ timesOfAge[age];
		}
	}

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
		cout << ages[i];
	cout << endl;

	//system("pause");
	return 0;
}