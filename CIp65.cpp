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
	// ͳ�Ƽ������
	int idx = 0;
	for (int i = 0; i < oldest; ++i)
		for (int j = 0; j < cnt[i]; ++j)
			// i����ʾ���䣬�Ҵ�С����
			// cnt[i]����ʾ��������ֵĴ���
			// ��cnt[i] = len
			ages[idx++] = i;
	// �����������
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