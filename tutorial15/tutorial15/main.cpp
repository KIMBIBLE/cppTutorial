#include <iostream>
using namespace std;

#include <limits>
#include "fitness.h"

#define MAX_MEMBER_NUM 100

void enrollMember(Fitness **fp, int &memberCnt);
void printAllMember(Fitness **fp, const int memberCnt);
void searchPrintMember(Fitness **fp, const int memberCnt);
void deleteMember(Fitness **fp, int &memberCnt);
void specialManagement(Fitness **fp, const int memberCnt);

void swap(Fitness &a, Fitness &b);

int getInt(const char *message, const int min, const int max);
void flush();

int main()
{
	int menu;
	int memberCnt = 0;	// ��ü ȸ�� ��
	Fitness *fary[100];

	while (1)
	{
		cout << "1. ȸ�����" << endl;
		cout << "2. ȸ����ü����" << endl;
		cout << "3. ȸ�������˻�" << endl;
		cout << "4. ȸ��Ż��" << endl;
		cout << "5. Ư������ ȸ��" << endl;
		cout << "6. ����" << endl;
		menu = getInt("�޴��� �Է��ϼ��� : ", 1, 6);

		// ���� �� �����Ҵ� ���� Fitness ��ü�� ����
		if (menu == 6) { 
			for (int i = 0; i < memberCnt; i++)
				delete fary[i];
			break; 
		}

		switch (menu)
		{
		case 1:
			enrollMember(fary, memberCnt); 
			break;
		case 2:
			printAllMember(fary, memberCnt); 
			break;
		case 3:
			searchPrintMember(fary, memberCnt); 
			break;
		case 4:
			deleteMember(fary, memberCnt); 
			break;
		case 5:
			specialManagement(fary, memberCnt);
			break;
		}

	}
}


void enrollMember(Fitness **fp, int &memberCnt)
{
	char name[101];
	double weight;
	double height;

	if (memberCnt == MAX_MEMBER_NUM)
	{
		cout << "�ִ� ȸ���� �ʰ��� ���� ��� ����" << endl;
		return;
	}

	cout << "<ȸ�� ��� ������ �Է��Ͻÿ�>" << endl;
	fp[memberCnt] = new Fitness;
	fp[memberCnt]->setNum(memberCnt);

	
	cout << "ȸ�� ��(�ִ� 100��) : ";
	cin >> name;
	flush();
	fp[memberCnt]->setName(name);

	weight = getInt("������ : ", 0, 10000);
	fp[memberCnt]->setWeight(weight);

	height = getInt("Ű : ", 0, 10000);
	fp[memberCnt]->setHeight(height);

	memberCnt++;
}

void printAllMember(Fitness **fp, const int memberCnt)
{
	for (int i = 0; i < memberCnt; i++)
	{
		cout << "ȸ����ȣ : " << i << endl;
		cout << "���� : " << fp[i]->getName() << endl;
		cout << "������ : " << fp[i]->getWeight() << endl;
		cout << "���� : " << fp[i]->getHeight() << endl << endl;
	}
}

void searchPrintMember(Fitness **fp, const int memberCnt)
{
	char name[101];
	cout << "�˻��� ȸ�� ���� �Է��Ͻÿ� : ";
	cin >> name;
	for (int i = 0; i < memberCnt; i++)
	{
		if (strcmp(fp[i]->getName(), name) == 0)
		{
			cout << "ȸ����ȣ : " << i << endl;
			cout << "���� : " << fp[i]->getName() << endl;
			cout << "������ : " << fp[i]->getWeight() << endl;
			cout << "���� : " << fp[i]->getHeight() << endl << endl;
		}
	}
}
void deleteMember(Fitness **fp, int &memberCnt)
{
	int num = getInt("������ ȸ�� ��ȣ�� �Է��Ͻÿ� : ", 0, MAX_MEMBER_NUM);
	delete fp[num];
	for (int i = num; i < memberCnt - 1; i++)
		swap(fp[i], fp[i + 1]);
	memberCnt--;
}

void specialManagement(Fitness **fp, const int memberCnt)
{
	for (int i = 0; i < memberCnt; i++)
	{
		if (fp[i]->bmi() >= 25.0)
		{
			cout << "ȸ����ȣ : " << i << endl;
			cout << "���� : " << fp[i]->getName() << endl;
			cout << "������ : " << fp[i]->getWeight() << endl;
			cout << "���� : " << fp[i]->getHeight() << endl << endl;
		}
	}
}

void swap(Fitness &a, Fitness &b)
{
	Fitness temp;
	temp = a;
	a = b;
	b = temp;
}

int getInt(const char *message, const int min, const int max)
{
	int num;
	while (1)
	{
		cout << message;
		cin >> num;
		if (cin.fail())
			flush();
		else
			if (min <= num && num <= max)
				return num;
	}
}
void flush()
{
	cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
