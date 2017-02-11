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
	cout << "main() 에서 출력하는 lecto namespace의 number = "
		<< lecto::number << endl;
	lecto::print();
	
	cout << "main() 에서 출력하는 lecto namespace의 number = " << number << endl;
	print();

	cout << "main() 에서 출력하는 bbkim namespace의 number = "
		<< bbkim::number << endl;
	bbkim::print();
}