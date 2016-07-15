#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;

void SortAges(int ages[], int len)
{
	if (ages == NULL || len <= 0)
		return;
	const int oldest = 99;
	int cnt[oldest] = { 0 };
	for (int i = 0; i < len; ++i)
		++cnt[ages[i]];
	// 统计计数完毕
	int idx = 0;
	for (int i = 0; i < oldest; ++i)
		for (int j = 0; j < cnt[i]; ++j)
			// i：表示年龄，且从小到大
			// cnt[i]：表示该年龄出现的次数
			// ∑cnt[i] = len
			ages[idx++] = i;
	// 不排序而排序
}




int randint(int s, int e)
{
	return rand() % (e - s) + s;
}

int main( )
{
	const int N = 100;
	int ages[N];
	for (int i = 0; i < N; ++i)
		ages[i] = randint(20, 100);
	SortAges(ages, N);
	copy(ages, ages + N, ostream_iterator<int>(cout, " "));
	cout << endl;
	return 0;
}