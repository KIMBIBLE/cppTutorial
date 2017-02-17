#include <iostream>
#include <string.h>
#include "Profile.h"
#include "Mystring.h"
using namespace std;

void userScreen(void);
char menu(void);
int proInput(Profile *, int);
int proUpdate(Profile *, int);
void proDisplay(Profile *, int);

int main()
{
	userScreen();
	return 0;
}
//----------------------------------------------------------------------------------------------
void userScreen()
{
	Profile  ary[20];   // ������ ���� ��ü �迭
	int profileCnt = 0;     // �Է� ���� �������� ���� ī��Ʈ ����
	char ch;          // �޴���ȣ ���� ���� 
	
	while (1)
	{
		ch = menu();        // �Էµ� �޴��� ��ȣ�� ch�� ���Ϲ���
		if (ch == '4') { break; }  // 4�� �����ϱ� �޴� �Է½� ���ѹݺ����� Ż��
		switch (ch)
		{
		case '1': profileCnt = proInput(ary, profileCnt); break;
		case '2': proUpdate(ary,profileCnt); break;
		case '3': proDisplay(ary, profileCnt); break;
		}
	}
}
//----------------------------------------------------------------------------------------------
char menu(void)
{
	char n = 0, i;
	char menulist[4][20] = { "������ �Է�", "������ ����", "������ ���","����" };

	for (i = 0; i<4; i++)   // �޴� ���ڿ��� ����ϴ� �ݺ���
	{
		cout << i + 1 << ". " << menulist[i] << endl;
	}

	while (n<'1' || n>'4') // ��ȿ�� ��ȣ�� �ƴϸ� �ٽ� �Է�
	{
		cout << "* Select menu No. : _\b";
		cin >> n;
	}
	return(n);
}
//--------------------------------------------------------------------------------------------
int proInput(Profile *ap, int cnt)
{
	char name[50];
	char addr[80];
	int age;
	double height;
	
	while (cnt < 20)
	{
		cout << "�̸��Է� : ";
		cin >> name;
		if (strcmp(name, "��") == 0) { break; }
		cout << "�ּ��Է� : ";		cin >> addr;
		cout << "�����Է� : ";		cin >> age;
		cout << "Ű�Է� : ";		cin >> height;

		ap[cnt] = Profile(name, addr, age, height); // �Է� ���� �����ͷ� ��ü �ʱ�ȭ
		cnt++;
	}
	return cnt;
}

int proUpdate(Profile *ap, int cnt)
{
	char name[50];
	char addr[80];
	int age;
	double height;
	int i;
	int edit;

	while (1)
	{
		cout << "������ ����� �̸� �Է� : ";
		cin >> name;
		if (name == "��") { break; }

		// �Է¹��� ������ ����� �̸��� ������ ��Ͽ� �ִ��� �˻�	
		for (i = 0; i < cnt; i++)
		{
			if (strcmp(ap[i].getName().getStr(), name) == 0)
			{
				cout << "���� �� profile : ";
				cout << ap[i].getName().getStr() << " / ";
				cout << ap[i].getAddr().getStr() << " / ";
				cout << ap[i].getAge() << " / ";
				cout << ap[i].getHeight() << endl;

				edit = 0;
				while (edit<1 || edit>4) // ��ȿ�� ��ȣ�� �ƴϸ� �ٽ� �Է�
				{
					cout << "���� �׸� ���� : 1.�̸� /2.�ּ� /3. ���� /4. ���� : ";
					cin >> edit;
				}

				// ���� �׸� ���� ������ ����
				if (edit == 1)
				{
					cout << "������ �̸� : ";
					cin >> name;
					MyString temp(name);
					ap[i].setName(temp);
				}
				else if (edit == 2)
				{
					cout << "������ �ּ� : ";
					cin >> addr;
					MyString temp(addr);
					ap[i].setAddr(temp);
				}
				else if (edit == 3)
				{
					cout << "������ ���� : ";
					cin >> age;
					ap[i].setAge(age);
				}
				else if (edit == 4)
				{
					cout << "������ Ű : ";
					cin >> height;
					ap[i].setHeight(height);
				}
				else { ; }
	
				// ���� �� ������ ���
				cout << "���� �� Profile : ";
				cout << ap[i].getName().getStr() << " / ";
				cout << ap[i].getAddr().getStr() << " / ";
				cout << ap[i].getAge() << " / ";
				cout << ap[i].getHeight() << endl;

				break;
			}
		}
		if (i == cnt)	// ������ ��Ͽ� ����ڰ� �Է��� �̸��� ���ٸ� menu()�� �̵�
		{
			cout << "������ ��Ͽ��� �ش� �̸��� ��ȸ�� �� �����ϴ�." << endl;
			break;
		}


		
	}
	return 0;
}

//---------------------------------------------------------------
void proDisplay(Profile *ap, int cnt)
{
	int i;
	for (i = 0; i<cnt; i++)
	{
		cout << i + 1 << ". " << ap[i].getName().getStr() << " : "
			<< ap[i].getAddr().getStr() << "/" << ap[i].getAge() << "��/"
			<< ap[i].getHeight() << "cm" << endl;
	}
}