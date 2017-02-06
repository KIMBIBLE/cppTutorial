#include <iostream>

using namespace std;

int main()
{
	int* ptr1 = new int;
	int* ptr2 = new int[10];

	delete[]ptr1;
	delete[]ptr2;


	return 0;
}