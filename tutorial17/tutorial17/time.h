#include <Iostream>
using namespace std;

class Time
{
private:
	int hour;
	int min;
	double time;	//�Ǽ� ���� �ð� ����
	static int mode;	// ��� ��� ����(integer, real)
	enum { integer, real };

public:
	/* Constructor, Destructor */
	Time();			// 0�� 0������ �ʱ�ȭ
	Time(int, int);	// ���������� �ð�, ������ �ʱ�ȭ
	Time(double);		// �ð��� �Ǽ� ������ �ʱ�ȭ
	Time(const Time &r);

	/* Setter, Getter Func */
	void setHour(int hour);	// hour ����� ���� �������ڷ� �����ϴ� �Լ�
	int getHour();			// hour ����� ���� �����ϴ� �Լ�
	void setMin(int min);	// min ����� ���� �������ڷ� �����ϴ� �Լ�
	int getMin();			// min ����� ���� �����ϴ� �Լ�

	/* Operator Overloading Func */
	friend ostream &operator<<(ostream &os, const Time &br);

	/* Time Class Member Func */
	Time plus(const Time &tr);
	static void mode_change();	// mode ���� �Լ�
};