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
        //使用while循环更好一点
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
        /*此时更改了for循环的内容，可以发现就是用while实现的，
	      此外，上一版本中有个问题，if语句中的*begin应该判断是否为空格而不是结尾符号*/
	for (; *begin != '\0'; ){
		if (*begin == ' '){
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