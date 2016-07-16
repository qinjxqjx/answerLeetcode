#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>
using namespace std;


bool search(const string &str, vector<string>&word)
{
	for (vector<string>::iterator it = word.begin(); it != word.end(); it++)
	{
		if (str == *it)
		{
			return true;
		}
	}

	return false;
}


int main()
{

	char str[300];
	vector<string> words;

	for (int i = 0; i <300; i++)
	{
		str[i] = '#';
	}
	cin.getline(str, 300);

	int index = 0;
	string w;

	while (str[index] != '#')
	{
		if (str[index] == ' ' || str[index] == ',' || str[index] == '.')
		{
			if (w != "")
			{
				if (search(w, words) == false)
				{
					words.push_back(w);
				}
			}
			w = "";
		}
		else
		{
			w += str[index];
		}

		index++;

	}

	if (w != "")
	{
		if (search(w, words) == false)
		{
			words.push_back(w);
		}
	}

	for (int i = 0; i <words.size(); i++)
	{
		cout << words[i] << ends;
	}
	system("pause");
	return 0;
}
