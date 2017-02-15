#include <iostream>
#include <string.h>
using namespace std;

int my_strlen(char *str, char ch = '\0');

int main()
{
	char str[100];
	cout << "문자열 입력 : ";
	cin >> str;
	cout << "문자열의 길이 : " << my_strlen(str) << endl;
	
	char ch;
	cout << "문자 입력 : ";
	cin >> ch;
	cout << ch << " 이전 까지의 길이 : " << my_strlen(str, ch) << endl;
	
}


int my_strlen(char *str, char ch)
{
	int len = strlen(str);
	for (int i = 0; i < len; i++)
	{
		if (str[i] == ch)
			return i;
	}
	return len;
}