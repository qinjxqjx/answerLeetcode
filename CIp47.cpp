#include<iostream>
#include<string>
using namespace std;

void Replaceblack(char string[], int length){
	if (string == NULL || length <= 0) return;

	int originlength = 0;
	int numberofblanck = 0;
	int i = 0;
	while (string[i] != '\0'){
		if (string[i]==' ') ++numberofblanck;
		++i;
		++originlength;
	}
	int newlength = originlength + numberofblanck * 2;
	if (newlength > length) return;

	int indexoforiginal = originlength;
	int indexofnew = newlength;
	while (indexoforiginal >= 0 && indexofnew != indexoforiginal){
		if (string[indexoforiginal] == ' '){
			string[indexofnew--] = '0';
			string[indexofnew--] = '2';
			string[indexofnew--] = '%';
		}
		else
		{
			string[indexofnew--] = string[indexoforiginal];
		}
		--indexoforiginal;
	}
	
}
int main() {

	char s[30] = "we are happy";//�˴�Ҫ�ر�ע�⣬���дΪ��[]ϵͳ����ʾ������������ת���ո�֮���ַ����䳤���±곬����Χ��
	cout << s << endl;
	Replaceblack(s, 30);
	cout << s << endl;

	//system("pause");
	return 0;
}