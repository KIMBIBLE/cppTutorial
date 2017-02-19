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
	cout << "�̸� : " << br.name << endl;
	cout << "���� : " << br.capital << endl;
	cout << "���ڼҵ� : " << br.profit << endl;
	cout << "���� : " << br.tax << endl;
	cout << "�ѱݾ� : " << br.tot << endl;
	cout << "���� : " << br.ratio << endl;
	cout << "���� : " << br.tax_ratio <<endl;
	cout << endl;

	return os;
}