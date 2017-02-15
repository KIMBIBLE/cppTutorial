#include <iostream>
#include <limits>
using namespace std;

typedef struct _Saving {
	int w500;
	int w100;
	int w50;
	int w10;
}Saving;

void init(Saving &s);
void input(int &unit, int &cnt);
void save(Saving &s, int unit, int cnt);
int total(Saving &s);
void flush();
void inputInt(char *message, int &num);

int main()
{
	Saving s;
	init(s);
	
	int unit, cnt;
	while (1)
	{
		input(unit, cnt);
		if (unit == -1)
			break;
		save(s, unit, cnt);
	}
	cout << "총 저금액 : " << total(s) << endl;
}

void init(Saving &s)
{
	s = { 0,0,0,0 };
}

void input(int &unit, int &cnt)
{
	while (1)
	{
		inputInt("동전의 금액 : ", unit);
		if (unit == 500 || unit == 100 || unit == 50 || unit == 10)
			break;
		else if (unit == -1)
			return;
	}

	while (1)
	{
		inputInt("동전의 갯수 : ", cnt);
		if (cnt >= 0)
			break;
	}
}
void save(Saving &s, int unit, int cnt)
{
	if (unit == 500)
		s.w500 += cnt;
	else if (unit == 100)
		s.w100 += cnt;
	else if (unit == 50)
		s.w50 += cnt;
	else if (unit == 10)
		s.w10 += cnt;
	else { ; }
}
int total(Saving &s)
{
	return s.w500 * 500 + s.w100 * 100 + s.w50 * 50 + s.w10 * 10;
}

void flush()
{
	cin.clear();
	//while (cin.get() != '\n') { ; }
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void inputInt(char *message, int &num)
{
	do{
		cout << message;
		cin >> num;
		flush();
	} while (cin.fail());
}