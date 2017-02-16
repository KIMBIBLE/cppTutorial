#include "iostream"
using namespace std;
#include <string.h>

#include "robot.h"
#define NAME_BUF_SIZE 101

void input(int &cnt);
void input(Robot &r);
void inputInt(int &num, char *message);
void flush();
void work(Robot &r);



int main()
{
	Robot *rp;
	int cnt;
	int i;
	input(cnt);
	rp = new Robot[cnt];
	for (i = 0; i < cnt; i++)
	{
		cout << i + 1 << "번 ";
		input(rp[i]);
	}

	char nameBuf[NAME_BUF_SIZE];
	while (1)
	{
		cout << "# 로봇명 선택(";
		for (i = 0; i < cnt; i++)
			cout << rp[i].getName() << ' ';
		cout << ") : ";
		cin.getline(nameBuf, NAME_BUF_SIZE, '\n');
		if (nameBuf[0] == '\0')
			break;
		for (i = 0; i < cnt; i++)
			if (strcmp(nameBuf, rp[i].getName()) == 0)
			{
				work(rp[i]);
				break;
			}
		if (i == cnt)
			cout << "보유중인 로봇 이름이 아닙니다" << endl;
	}

	delete[] rp;
}


void work(Robot &r)
{
	int num, energy;
	while (1)
	{
		inputInt(num, "# 할 일 선택(1.전진/2.후진/3.회전/4.점프/5.충전) : ");
		if (1 <= num && num <= 5)
			break;
	}
	if (num == 1)
		r.go();
	else if (num == 2)
		r.back();
	else if (num == 3)
		r.turn();
	else if (num == 4)
		r.jump();
	else
	{
		inputInt(energy, "# 충전할 에너지 양 입력 : ");
		r.charge(energy);
	}
}

void input(int &cnt)
{
	while (1)
	{
		inputInt(cnt, "구입할 로봇 대수를 입력하시오 : ");
		if (cnt > 0)
			break;
	}
}

void input(Robot &r)
{
	int num;
	char nameBuf[NAME_BUF_SIZE];
	while (1)
	{
		cout << "로봇 명을 입력하시오(100자 이하) : ";
		cin.getline(nameBuf, NAME_BUF_SIZE, '\n');

		cout << nameBuf;
		inputInt(num, "의 에너지 양을 입력하시오 : ");
		if (num >= 0)
		{
			r.setName(nameBuf);
			r.setEnergy(num);
			break;
		}
		cout << "입력 실패 재입력" << endl;
	}
}


void inputInt(int &num, char *message)
{
	do {
		cout << message;
		cin >> num;
		flush();
	} while (cin.fail());
}

void flush()
{
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}