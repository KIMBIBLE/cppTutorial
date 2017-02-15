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
	MoneyBox a;
	MoneyBox b("홍길동");
	MoneyBox c("이순신", 500);
	cout << endl;

	MoneyBox d1 = b;
	MoneyBox d2(b);
	cout << endl;

	MoneyBox *mp1 = new MoneyBox("홍길동");
	MoneyBox *mp2 = new MoneyBox(c);
	cout << endl;

	MoneyBox e = func(c);
	cout << endl;

	cout << "[ 비교 ]" << endl;
	cout << "-> value" << endl;
	func(c);
	cout << "-> reference" << endl;
	func(c, 0);

	cout << endl << "delete" << endl;
	delete mp1;
	delete mp2;
	cout << endl;
}

MoneyBox func(MoneyBox m)
{
	return m;
}

MoneyBox &func(MoneyBox &m, int temp)
{
	return m;
}