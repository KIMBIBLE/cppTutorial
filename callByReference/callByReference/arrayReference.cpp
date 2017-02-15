#include <iostream>
using namespace std;

void prn(char (&chr)[10]);
void prn(int(&aaa)[3][4]);

int main()
{
	char str[10] = "str";
	//char str2[20] = "Moon";
	int ary[3][4] = { 1,2,3,4,5,6,7,8,9,10,11,12 };

	prn(str);
	prn(ary);
	cout << "after : " << ary[2][3] << endl;
}

void prn(char(&chr)[10])	// 배열의 크기 다르면 못받는 단점
{
	cout << chr << endl;
	cout << sizeof(chr) << endl;
	strcpy(chr, "Dream");
}

void prn(int(&aaa)[3][4])	// 행, 열의 갯수도 정확히 일치해야 하는 단점
{
	cout << aaa[2][3] << endl;
	cout << sizeof(aaa) << endl;
	aaa[2][3] = 20;
}