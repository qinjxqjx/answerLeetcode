#include <iostream>  
using namespace std;

void reverse(char *str,int len){
	//
	if (str == NULL||len<=0) return;
	
	int first = 0;
	int last = len - 1;
	while (first < last){
		char temp = str[first];
		str[first] = str[last];
		str[last] = temp;
		++first;
		--last;
	}

}

void main(){
	char str[8] = "abc def";
	int len = strlen(str);
	reverse(str,len);
	
	char *iter = str;
	char *begin = str, *end = str;
	/*while(*end!='\0'){
		if (*begin == ' '){
			++begin;
			++end;
		}
		else if (*end == ' '||*end=='\0'){
			int voc = end - begin;
			reverse(begin, voc);
			begin = end;
		}
		 else ++end;
	}*/

	for (; *iter != '\0'; ++iter){
		if (*begin == '\0'){
			++begin;
			++end;
		}
		else if (*end == '\0' || *end == ' '){
			int voc = end - begin;
			reverse(begin, voc);
			begin = end;
		}
		else ++end;
	}
	cout << str << endl;

	system("pause");

}