#include <iostream>
#include <string.h>
using namespace std;

void str_prn(char *str, char ch = '\n');

int main()
{
	char str[80];
	cout << "문장 입력 : ";
	cin.getline(str, sizeof(str));
	
	char ch;
	cout << "문자 입력 : ";
	cin >> ch;
	str_prn(str);
	str_prn(str, ch);
}

void str_prn(char *str, char ch)
{
	int len = strlen(str);
	for (int i = 0; i < len; i++)
		if (str[i] != ch)
			cout << str[i];
		else
			break;
			
	cout << endl;
}