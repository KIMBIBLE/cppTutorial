#include "lightAutomation.h"
#include "lightFixture.h"

void screen(LightAutomation &homeAuto);
int menu(char **menuList, int menuCnt);
void displayTitle(string title);
void listDisplayAppliance(LightAutomation &r);
void controlAppliance(LightAutomation &r);
void addAppliance(LightAutomation &r);
void deleteAppliance(LightAutomation &r);

int main()
{
	LightAutomation homeAuto;
	homeAuto.initLightAutomation();
	screen(homeAuto);
	return 0;
}


void screen(LightAutomation &homeAuto)
{
	cout << "------------------------------" << endl;
	cout << "   Ȩ ���� �ɾ� �ý��� ����" << endl;
	cout << "------------------------------" << endl << endl;

	char *menuList[] = { "1. ���� ���� Ȯ��\n", "2. ���� ����\n",
		"3. ���� ���\n", "4. ���� ����\n", "5. ����\n" };
	int menuNum = 0;
	while (1)
	{
		menuNum = menu(menuList, sizeof(menuList) / sizeof(menuList[0]));
		if (menuNum == 5) { break; }	// ����
		switch (menuNum)
		{
		case 1: listDisplayAppliance(homeAuto); break;
		case 2: controlAppliance(homeAuto); break;
		case 3: addAppliance(homeAuto); break;
		case 4: deleteAppliance(homeAuto); break;
		default:; break;
		}
	}

	cout << "------------------------------" << endl;
	cout << "   Ȩ ���� �ɾ� �ý��� ����" << endl;
	cout << "------------------------------" << endl << endl;
}

int menu(char **menuList, int menuCnt)
{
	cout << "=================================" << endl;
	for (int i = 0; i < menuCnt; i++)
		cout << menuList[i];
	cout << "=================================" << endl;
	
	int menuNum;
	while (1)
	{
		cout << "# �޴���ȣ�� �Է��ϼ��� : ";
		cin >> menuNum;
		if (menuNum == 1 || menuNum == 2 || menuNum == 3
			|| menuNum == 4 || menuNum == 5)
			break;	// 1,2,3,4,5 �̿��� �Է��� ���Է� �䱸
	} 

	return menuNum;
}

void displayTitle(string title)
{
	cout << "------------------------------" << endl;
	cout << title << endl;
	cout << "------------------------------" << endl << endl;
}

void listDisplayAppliance(LightAutomation &r)
{
	displayTitle("���� ���� ����");

	if (r.getLightCnt() == 0)
		cout << "��ϵ� ������ �����ϴ�" << endl << endl;
	else
		r.listDisplayAppliance();

	displayTitle("���� ���� ���� ����");
}

void controlAppliance(LightAutomation &r)
{
	displayTitle("���� ���� �ϱ�");

	if (r.getLightCnt() == 0)
		cout << "��ϵ� ������ �����ϴ�. ������ ���� ����ϼ���" << endl << endl;
	else
	{
		string machineName;
		cout << "* ������ ����� �Է� : ";
		cin >> machineName;

		if (r.controlAppliance(machineName))
			cout << "����� " << machineName << "�� ��� �Ϸ�Ǿ����ϴ�." << endl;
		else
			cout << "����� " << machineName << "�� ��� �����Ͽ����ϴ�." << endl;
	}
}

void addAppliance(LightAutomation &r)
{
	displayTitle("���� ��� �ϱ�");
	string machineName;
	cout << "��ǰ �� �Է�((��) �Ž�����, �ȹ�� ��) : ";
	cin >> machineName;

	LightFixture enroll;
	enroll.initLightFixture(machineName);

	if (r.addAppliance(enroll))
		cout << "����� " << machineName << "�� ����� �Ϸ�Ǿ����ϴ�." << endl;
	else
		cout << "����� " << machineName << "�� ����� �����Ͽ����ϴ�." << endl;
}

void deleteAppliance(LightAutomation &r)
{
	displayTitle("���� ���� �ϱ�");
	string machineName;
	cout << "��ǰ �� �Է�((��) �Ž�����, �ȹ�� ��) : ";
	cin >> machineName;

	if (r.deleteAppliance(machineName))
		cout << "����� " << machineName << "�� ������ �Ϸ�Ǿ����ϴ�." << endl;
	else
		cout << "����� " << machineName << "�� ������ �����Ͽ����ϴ�." << endl;
}