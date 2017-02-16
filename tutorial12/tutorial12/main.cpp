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
		cout << i + 1 << "�� ";
		input(rp[i]);
	}

	char nameBuf[NAME_BUF_SIZE];
	while (1)
	{
		cout << "# �κ��� ����(";
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
			cout << "�������� �κ� �̸��� �ƴմϴ�" << endl;
	}

	delete[] rp;
}


void work(Robot &r)
{
	int num, energy;
	while (1)
	{
		inputInt(num, "# �� �� ����(1.����/2.����/3.ȸ��/4.����/5.����) : ");
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
		inputInt(energy, "# ������ ������ �� �Է� : ");
		r.charge(energy);
	}
}

void input(int &cnt)
{
	while (1)
	{
		inputInt(cnt, "������ �κ� ����� �Է��Ͻÿ� : ");
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
		cout << "�κ� ���� �Է��Ͻÿ�(100�� ����) : ";
		cin.getline(nameBuf, NAME_BUF_SIZE, '\n');

		cout << nameBuf;
		inputInt(num, "�� ������ ���� �Է��Ͻÿ� : ");
		if (num >= 0)
		{
			r.setName(nameBuf);
			r.setEnergy(num);
			break;
		}
		cout << "�Է� ���� ���Է�" << endl;
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