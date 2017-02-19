#include "save.h"
#include <string>

double Save::ratio = 0.2;
double Save::tax_ratio = 0.1;

Save::Save(const char *np, int n)
{
	strncpy(this->name, np, sizeof(this->name));
	this->capital = n;
	this->profit = 0;
	this->tax = 0;
	this->tot = 0;
}

void Save::calculate()
{
	this->profit = this->capital * this->ratio;
	this->tax = this->profit * this->tax_ratio;
	this->tot = this->capital + this->profit - this->tax;
}

void Save::set_ratio(double r)
{
	ratio = r;
}

ostream &operator<<(ostream &os, Save &br)
{
	cout << "이름 : " << br.name << endl;
	cout << "원금 : " << br.capital << endl;
	cout << "이자소득 : " << br.profit << endl;
	cout << "세금 : " << br.tax << endl;
	cout << "총금액 : " << br.tot << endl;
	cout << "이율 : " << br.ratio << endl;
	cout << "세율 : " << br.tax_ratio <<endl;
	cout << endl;

	return os;
}