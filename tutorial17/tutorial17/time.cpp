#include "time.h"
#include <iomanip>

enum { integer, real };
int Time::mode = integer;

/* Constructor, Destructor */
Time::Time() :hour(0), min(0), time(0.0) { ; }
Time::Time(int hour, int min) : hour(hour), min(min)
{
	this->time = hour + (double)min / 60;
}
Time::Time(double t)
{
	this->time = t;
	this->hour = t;
	t -= this->hour;
	this->min = t * 60;
}
Time::Time(const Time &r) :hour(r.hour), min(r.min), time(r.time) { ; }

/* Setter, Getter Func */
void Time::setHour(int hour)
{
	this->hour = hour;
}

int Time::getHour()
{
	return this->hour;
}

void Time::setMin(int min)
{
	this->min = min;
}

int Time::getMin()
{
	return this->min;
}

/* Operator Overloading Func */
ostream &operator<<(ostream &os, const Time &br)
{
	if (br.mode == integer)
		os << br.hour << "시간 " << br.min << "분";
	else
		os << br.time << "시간";
		

	return os;
}

/* Time Class Member Func */
Time Time::plus(const Time &tr)
{
	Time temp;
	temp.time = this->time + tr.time;

	temp.hour = this->hour + tr.hour;
	temp.min = this->min + tr.min;
	if (temp.min >= 60)
	{
		temp.min -= 60;
		temp.hour++;
	}

	return temp;
}

void Time::mode_change()
{
	if (mode == integer)
		mode = real;
	else
		mode = integer;
}
