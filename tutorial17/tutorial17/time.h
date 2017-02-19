#include <Iostream>
using namespace std;

class Time
{
private:
	int hour;
	int min;
	double time;	//실수 형태 시간 저장
	static int mode;	// 출력 모드 지정(integer, real)
	enum { integer, real };

public:
	/* Constructor, Destructor */
	Time();			// 0시 0분으로 초기화
	Time(int, int);	// 전달인자의 시간, 분으로 초기화
	Time(double);		// 시간을 실수 값으로 초기화
	Time(const Time &r);

	/* Setter, Getter Func */
	void setHour(int hour);	// hour 멤버의 값을 전달인자로 수정하는 함수
	int getHour();			// hour 멤버의 값을 리턴하는 함수
	void setMin(int min);	// min 멤버의 값을 전달인자로 수정하는 함수
	int getMin();			// min 멤버의 값을 리턴하는 함수

	/* Operator Overloading Func */
	friend ostream &operator<<(ostream &os, const Time &br);

	/* Time Class Member Func */
	Time plus(const Time &tr);
	static void mode_change();	// mode 변경 함수
};