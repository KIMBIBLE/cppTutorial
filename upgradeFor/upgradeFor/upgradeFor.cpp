#include <iostream>
using namespace std;
int main()
{

	int data[10];
	for (auto t : data) {
		cout << t << ' ';
	}
	
	/*
	int data2[10][10];
	for (auto &row : data)
		for (auto each : row)
			cout << each << ' ';
	cout << endl;
	*/
}