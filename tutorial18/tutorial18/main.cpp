#include "save.h"

int main()
{
	Save a("ö��", 1000000);
	a.calculate();
	cout << a << endl;
	Save::tax_ratio = 0.15;
	Save::set_ratio(0.25);
	
	Save b("����", 2000000);
	b.calculate();
	cout << b << endl;
}