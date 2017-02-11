#include <iostream>

using namespace std;

void cinFlush();

int main()
{
	int num;
	cin >> num;
	while (cin.fail())
	{
		cinFlush();
		cin >> num;
	}
	cout << "num = " << num << endl;
}

void cinFlush()
{
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	//if(cin.get() != '\n')
	//	while (cin.get() != '\n') { ; }
	//while (cin.get() != '\n') { ; }
	//cin.clear();
}