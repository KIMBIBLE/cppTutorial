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

	// 유통기한 세팅
	struct tm userStime;
	userStime.tm_year = s.year - 1900;
	userStime.tm_mon = s.moon - 1;
	userStime.tm_mday = s.day;
	userStime.tm_hour = 0;
	userStime.tm_min = 0;
	userStime.tm_sec = 0;
	userStime.tm_isdst = 0;
	startTime = mktime(&userStime);
	
	// 현재 시간
	time(&endTime);

	return difftime(startTime, endTime);
}

void input(Goods &s)
{
	cout << "품목 입력 : ";
	cin.getline(s.item, 50, '\n');

	cout << "정가 입력 : ";
	cin >> s.price;

	cout << "유통기한 입력 : ";
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
	cout << "품명 : " << s.item << endl;
	cout << "판매가 : " << s.price * (100 - s.discount) / 100 << endl;
	cout << "유통기한 : " << s.year << "-" << s.moon << "-" << s.day << endl;
	cout << "할인율 : " << s.discount << "%" << endl;
}
