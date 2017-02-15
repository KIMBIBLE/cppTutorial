#include <iostream>
using namespace std;
#include <time.h>

typedef struct _Goods 
{
	char item[50];
	int price;
	int year;
	int moon;
	int day;
	int discount;
}Goods;

void input(Goods &s);
void selling_price(Goods &s);
void prn(const Goods &s);
double getTime(const Goods &s);

int main()
{
	Goods s;
	input(s);
	selling_price(s);
	prn(s);

}

double getTime(const Goods &s)
{
	time_t startTime;
	time_t endTime;

	// ������� ����
	struct tm userStime;
	userStime.tm_year = s.year - 1900;
	userStime.tm_mon = s.moon - 1;
	userStime.tm_mday = s.day;
	userStime.tm_hour = 0;
	userStime.tm_min = 0;
	userStime.tm_sec = 0;
	userStime.tm_isdst = 0;
	startTime = mktime(&userStime);
	
	// ���� �ð�
	time(&endTime);

	return difftime(startTime, endTime);
}

void input(Goods &s)
{
	cout << "ǰ�� �Է� : ";
	cin.getline(s.item, 50, '\n');

	cout << "���� �Է� : ";
	cin >> s.price;

	cout << "������� �Է� : ";
	cin >> s.year >> s.moon >> s.day;
}

void selling_price(Goods &s)
{
	auto diffTime = getTime(s);
	int tmDay = diffTime / (60 * 60 * 24);
	if (0 <= tmDay && tmDay <= 3)
		s.discount = 50;
	else if (4 <= tmDay && tmDay <= 10)
		s.discount = 20;
	else
		s.discount = 0;
}

void prn(const Goods &s)
{
	cout << "ǰ�� : " << s.item << endl;
	cout << "�ǸŰ� : " << s.price * (100 - s.discount) / 100 << endl;
	cout << "������� : " << s.year << "-" << s.moon << "-" << s.day << endl;
	cout << "������ : " << s.discount << "%" << endl;
}
