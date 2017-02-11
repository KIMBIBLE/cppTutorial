#include <iostream>

using namespace std;
void myFlush();

int main()
{
	int intNumber;
	double doubleNumber;
	char ch;
	char str[100];

	cout << "정수값 입력";
	cin >> intNumber;

	cout << "실수값 입력";
	cin >> doubleNumber;

	cout << "문자 입력";
	cin >> ch;

	cout << "문자열 입력";
	cin >> str;

	cout << "intNumber = " << intNumber << endl;
	cout << "doubleNumber = " << doubleNumber << endl;
	cout << "ch = " << ch << endl;
	cout << "str = " << str << endl;

	myFlush();

	cout << "중간에 여백있는 문자열을 입력하시오";

	cin.getline(str, sizeof(str), '#');
	cout << "입력 받은 문자열 : " << str << endl;

	cout << "여백문자를 입력하세요(space, tab, enter) : ";
	ch = cin.get();
	cout << "입력한 여백문자의 아스키 코드 값 " << (int)ch << endl;

	return 0;
}

void myFlush()
{
	while (cin.get() != '\n') { ; }
}