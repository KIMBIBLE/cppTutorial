#include <iostream>
#include <string.h>
using namespace std;

int my_strlen(char *str, char ch = '\0');

int main()
{
	char str[100];
	cout << "���ڿ� �Է� : ";
	cin >> str;
	cout << "���ڿ��� ���� : " << my_strlen(str) << endl;
	
	char ch;
	cout << "���� �Է� : ";
	cin >> ch;
	cout << ch << " ���� ������ ���� : " << my_strlen(str, ch) << endl;
	
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