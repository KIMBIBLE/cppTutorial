#include <iostream>
#include "bbkim.h"
#include "lecto.h"

using namespace std;

//using lecto::number;
//using lecto::print;
using namespace lecto;
//using namespace bbkim;

int main()
{
	cout << "main() ���� ����ϴ� lecto namespace�� number = "
		<< lecto::number << endl;
	lecto::print();
	
	cout << "main() ���� ����ϴ� lecto namespace�� number = " << number << endl;
	print();

	cout << "main() ���� ����ϴ� bbkim namespace�� number = "
		<< bbkim::number << endl;
	bbkim::print();
}