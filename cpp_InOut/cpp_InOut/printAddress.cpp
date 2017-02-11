#include <iostream>

using namespace std;

int main()
{
	int intArray[5] = { 1,3,5,7,9 };
	char charArray[10] = "apple";

	cout << intArray << endl;	// 주소 출력
	cout << charArray << endl;	// 문자열 출력
	cout << (void *)charArray << endl;	// 주소 출력

	int len = sizeof(intArray) / sizeof(intArray[0]);
	for (int i = 0; i < len; i++)
		cout << "intAry[" << i << "] = " << intArray[i] << endl;
}