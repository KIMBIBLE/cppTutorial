#include <iostream>
using namespace std;

class Time
{
private:
	int hour;
	int min;

public:
	Time(int h = 0, int m = 0);

	Time operator+(const Time &br);
	Time operator-();
	Time &operator++();
	Time operator++(int);
	Time operator*(int n);
	void operator<<(ostream &os);
	void operator >> (istream &is);

	void show();
};

Time::Time(int h, int m)
{
	hour = h;
	min = m;
}

Time Time::operator+(const Time &br)
{
	int h, m;
	h = hour + br.hour;
	m = min + br.min;
	if (m >= 60)
	{
		h += m / 60;
		m = m % 60;
	}
	Time res(h, m);
	return res;
}

Time Time::operator-()
{
	Time temp(-hour, -min);
	return temp;
}

Time &Time::operator++()
{
	min++;
	if (min == 60)
	{
		hour++;
		min = 0;
	}
	return *this;
}

Time Time::operator++(int)
{
	Time temp(hour, min);
	min++;
	if (min == 60)
	{
		hour++;
		min = 0;
	}
	return temp;
}

Time Time::operator*(int n)
{
	int h, m;
	h = hour*n;
	m = min*n;
	if (m >= 60)
	{
		h += m / 60;
		m = m % 60;
	}
	return Time(h, m);
}

void Time::operator<<(ostream &os)
{
	os << hour << "�ð�" << min << "��" << endl;
}

void Time::operator >> (istream &is)
{
	is >> hour >> min;
}

void Time::show()
{
	cout << hour << "�ð�" << min << "��" << endl;
}


void func(Time &br);
Time operator*(int n, Time &a);
ostream &operator<<(ostream &os, Time &br);
istream &operator >> (istream &is, Time &br);

int main()
{
	Time a(5, 50), b(3, 30), c;
	
	c = -b + a;
	a.show();
	b.show();
	c.show();

	c = ++a + b;
	a.show();
	b.show();
	c.show();

	c = a + b++;
	a.show();
	b.show();
	c.show();

	func(++a);
	a.show();

	func(a++);
	a.show();

	Time d(2, 30), e;
	e = a * 3;
	e.show();

	e = 3 * a;
	e.show();

	cin >> a >> b;
	cout << a << b;

	return 0;
}

void func(Time &br)
{
	br++;
}

Time operator*(int n, Time &a)
{
	return a*n;
}


ostream &operator<<(ostream &os, Time &br)
{
	br << os;
	return os;
}

istream &operator >> (istream &is, Time &br)
{
	br >> is;
	return is;
}