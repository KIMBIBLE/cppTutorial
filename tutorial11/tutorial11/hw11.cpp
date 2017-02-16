#include <iostream>
using namespace std;

class Time
{
private:
	int hour;
	int min;

public:
	// 생성자
	Time();	// 0시 0분으로 초기화. 디폴트 생성자
	Time(int, int);	// 시간, 분으로 초기화. 오버로디드 생성자
	Time(double);	//시간을 실수값으로 초기화. 오버로디드 생성자
	Time(const Time &tr);	//복사 생성자

	// 소멸자
	~Time() {}

	// 멤버함수
	Time plus(const Time &tr);	// 두 객체의 시간을 더하여 리턴
	void setHour(int);	//Hour 멤버의 값을 전달인자로 수정
	int getHour();	//Hour 멤버의 값을 리턴
	void setMin(int); //Min 멤버의 값을 전달인자로 수정
	int getMin();	//Min 멤버의 값을 리턴
};

Time::Time()
{
	hour = 0;
	min = 0;
}

Time::Time(int h, int m)
{
	if (h < 0 || h > 24)
	{
		cout << "올바르지 않은 시간을 초기화할 수 없습니다. hour = 0 으로 자동 초기화" << endl;
		hour = 0;
	}
	else
		hour = h;
	if (m < 0 || m > 60)
	{
		cout << "올바르지 않은 분을 초기화할 수 없습니다. min = 0 으로 자동 초기화" << endl;
		min = 0;
	}
	else
		min = m;
}

// double t : 시간 값(단위 : 분)
Time::Time(double t)
{
	if (t < 0 || t > 60 * 24)
	{
		cout << "올바르지 않은 초기화 값입니다. hour = 0, min = 0으로 자동 초기화" << endl;
		hour = 0;
		min = 0;
	}
	hour = t / 24;
	min = t - hour * 24;
}

Time::Time(const Time &r)
{
	hour = r.hour;
	min = r.min;
}

Time Time::plus(const Time &tr)
{
	Time res;
	res.min = min + tr.min;
	if (res.min >= 60)
	{
		res.min -= 60;
		res.hour += 1;
	}
	res.hour += hour + tr.hour;

	return res;
}

void Time::setHour(int h)
{
	if (h < 0 || h > 24)
	{
		cout << "올바르지 않은 초기화 값입니다. 시간값 변경이 이루어지지 않았습니다." << endl;
		return;
	}
		
	hour = h;
}

int Time::getHour()
{
	return hour;
}

void Time::setMin(int m)
{
	if (m < 0 || m > 60)
	{
		cout << "올바르지 않은 초기화 값입니다. 분 값 변경이 이루어지지 않았습니다." << endl;
		return;
	}

	min = m;
}

int Time::getMin()
{
	return min;
}

int main()
{
	Time a(3, 20), b;
	cout << a.getHour() << "시간" << a.getMin() << "분" << endl;
	b.setHour(4);
	b.setMin(42);
	cout << b.getHour() << "시간" << b.getMin() << "분" << endl;

	Time res = a.plus(b);
	cout << "두 시간을 더하면 : " << res.getHour() << "시간" << res.getMin() << "분" << endl << endl;

	cout << a.getHour() << "시간" << a.getMin() << "분" << endl;
	cout << b.getHour() << "시간" << b.getMin() << "분" << endl;
}