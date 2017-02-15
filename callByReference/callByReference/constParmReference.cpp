#include <iostream>
using namespace std;

int sub(const int &num);

int main()
{
	int res;
	res = sub(10 + 20);
	cout << res << endl;
}

int sub(const int &num)
{
	return num * num;
}