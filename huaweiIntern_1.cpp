#include<iostream>
#include<string>
using namespace std;

void main()
{
	string input, str, rep;
	cin >> str >> rep;
	int i = 0, m = str.find(rep), l = rep.size();
	while (m >= 0)
	{
		str.erase(m, l);
		i += 1;
		m = str.find(rep);
	}
	cout << i << endl;
	system("pause");
}
