#include <iostream>

using namespace std;

int main()
{
	int intArray[5] = { 1,3,5,7,9 };
	char charArray[10] = "apple";

	cout << intArray << endl;	// �ּ� ���
	cout << charArray << endl;	// ���ڿ� ���
	cout << (void *)charArray << endl;	// �ּ� ���

	int len = sizeof(intArray) / sizeof(intArray[0]);
	for (int i = 0; i < len; i++)
		cout << "intAry[" << i << "] = " << intArray[i] << endl;
}