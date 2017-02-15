#include <iostream>
#include <string.h>
using namespace std;

/* class MoneyBox */
class MoneyBox {
private:
	char *name;
	int sum;

public:
	/* constructor */
	MoneyBox();	//default constructor
	MoneyBox(const char *np, int m = 0);	//overloaded constructor
	MoneyBox(const MoneyBox &br);	//copy constructor
	MoneyBox &operator = (const MoneyBox &br);

							/* destructor */
	~MoneyBox()
	{
		cout << "destructor call~~" << this->name << endl;
		delete[] this->name;
	}

	/* MoneyBox interface */
	void save(int m);
	void use(int m);
	void prn();
};

/* MoneyBox member func */
MoneyBox::MoneyBox()
{
	char *n = "someone";
	char size = strlen(n) + 1;
	this->name = new char[size];
	strcpy(this->name, n);
	this->sum = 0;
	cout << "default constructor call~~" << this->name << endl;
}

MoneyBox::MoneyBox(const char *np, int m)
{
	char size = strlen(np) + 1;
	this->name = new char[size];
	strcpy(this->name, np);
	this->sum = m;
	cout << "overloaded constructor call~~" << this->name << endl;
}

MoneyBox::MoneyBox(const MoneyBox &br)
{
	char size = strlen(br.name) + 1;
	this->name = new char[size];
	strcpy(this->name, br.name);
	this->sum = br.sum;
	cout << "copy constructor call~~" << this->name << endl;
}

MoneyBox &MoneyBox::operator=(const MoneyBox &br)
{
	if (this == &br)
		return *this;
	delete[] name;
	name = new char[strlen(br.name) + 1];
	strcpy(name, br.name);
	sum = br.sum;
	return *this;
}

/* MoneyBox interface*/
void MoneyBox::save(int m)
{
	if (m >= 0)
		this->sum += m;
}

void MoneyBox::use(int m)
{
	if (m > 0 && m < this->sum)
		this->sum -= m;
}

void MoneyBox::prn()
{
	cout << "name : " << this->name << endl;
	cout << "account : " << this->sum << endl;
}


/* other func */
MoneyBox func(MoneyBox m);
MoneyBox &func(MoneyBox &m, int temp);

int main()
{
	MoneyBox a("Ã¶ÀÌ", 100), b("¸ÞÅÚ", 500), temp;
	a.prn();
	b.prn();
	temp = a;
	a = b;
	b = temp;
	a.prn();
	b.prn();

	a = b = temp;
	a = a;

}

MoneyBox func(MoneyBox m)
{
	return m;
}

MoneyBox &func(MoneyBox &m, int temp)
{
	return m;
}