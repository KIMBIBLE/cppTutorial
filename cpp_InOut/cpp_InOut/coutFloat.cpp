#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	double dNum = 3.12345;
	cout << dNum << endl;

	cout << setprecision(3);
	cout << dNum << endl;

	cout << fixed;
	cout << setprecision(3);
	cout << dNum << endl;
	
	cout << fixed << dNum << endl;
	cout << scientific << dNum << endl;

	cout.unsetf(ios_base::scientific);
	dNum = 17500000000000000000001.123123;
	cout << dNum << endl;

	cout << setw(10) << dNum << endl;
	cout << dNum << endl;
}