#include <iostream>
using namespace std;

class Time
{
private:
	int hour;
	int min;

public:
	// ������
	Time();	// 0�� 0������ �ʱ�ȭ. ����Ʈ ������
	Time(int, int);	// �ð�, ������ �ʱ�ȭ. �����ε�� ������
	Time(double);	//�ð��� �Ǽ������� �ʱ�ȭ. �����ε�� ������
	Time(const Time &tr);	//���� ������

	// �Ҹ���
	~Time() {}

	// ����Լ�
	Time plus(const Time &tr);	// �� ��ü�� �ð��� ���Ͽ� ����
	void setHour(int);	//Hour ����� ���� �������ڷ� ����
	int getHour();	//Hour ����� ���� ����
	void setMin(int); //Min ����� ���� �������ڷ� ����
	int getMin();	//Min ����� ���� ����
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
		cout << "�ùٸ��� ���� �ð��� �ʱ�ȭ�� �� �����ϴ�. hour = 0 ���� �ڵ� �ʱ�ȭ" << endl;
		hour = 0;
	}
	else
		hour = h;
	if (m < 0 || m > 60)
	{
		cout << "�ùٸ��� ���� ���� �ʱ�ȭ�� �� �����ϴ�. min = 0 ���� �ڵ� �ʱ�ȭ" << endl;
		min = 0;
	}
	else
		min = m;
}

// double t : �ð� ��(���� : ��)
Time::Time(double t)
{
	if (t < 0 || t > 60 * 24)
	{
		cout << "�ùٸ��� ���� �ʱ�ȭ ���Դϴ�. hour = 0, min = 0���� �ڵ� �ʱ�ȭ" << endl;
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
		cout << "�ùٸ��� ���� �ʱ�ȭ ���Դϴ�. �ð��� ������ �̷������ �ʾҽ��ϴ�." << endl;
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
		cout << "�ùٸ��� ���� �ʱ�ȭ ���Դϴ�. �� �� ������ �̷������ �ʾҽ��ϴ�." << endl;
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
	cout << a.getHour() << "�ð�" << a.getMin() << "��" << endl;
	b.setHour(4);
	b.setMin(42);
	cout << b.getHour() << "�ð�" << b.getMin() << "��" << endl;

	Time res = a.plus(b);
	cout << "�� �ð��� ���ϸ� : " << res.getHour() << "�ð�" << res.getMin() << "��" << endl << endl;

	cout << a.getHour() << "�ð�" << a.getMin() << "��" << endl;
	cout << b.getHour() << "�ð�" << b.getMin() << "��" << endl;
}