#include<iostream>
#include<string>
using namespace std;

int main(){
	string input, t, output;
	getline(cin, input);
	int i, pos, sz, f;

	pos = input.find(',');//将，替换为空格
	while (pos >= 0){
		input.erase(pos, 1);
		input.insert(pos, " ");
		pos = input.find(',');
	}

	pos = input.find('.');//将.替换为空格
	while (pos >= 0){
		input.erase(pos, 1);
		input.insert(pos, " ");
		pos = input.find('.');
	}
	//sz = input.size();
	input.append(" ");
	//sz = input.size();

	pos = input.find(' ');//将空格作为单词分界符号

	while (pos >= 0){
		t = input.substr(0, pos + 1);
		f = output.find(t);
		if (f<0)
			output.append(t);
		else input.erase(0, pos + 1);
		pos = input.find(' ');
	}
	output = output + input;
	cout << output << endl;
	return 0;
}