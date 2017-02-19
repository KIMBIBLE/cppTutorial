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
	cout << "   홈 조명 케어 시스템 시작" << endl;
	cout << "------------------------------" << endl << endl;

	char *menuList[] = { "1. 전등 상태 확인\n", "2. 전등 제어\n",
		"3. 전등 등록\n", "4. 전등 삭제\n", "5. 종료\n" };
	int menuNum = 0;
	while (1)
	{
		menuNum = menu(menuList, sizeof(menuList) / sizeof(menuList[0]));
		if (menuNum == 5) { break; }	// 종료
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
	cout << "   홈 조명 케어 시스템 종료" << endl;
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
		cout << "# 메뉴번호를 입력하세요 : ";
		cin >> menuNum;
		if (menuNum == 1 || menuNum == 2 || menuNum == 3
			|| menuNum == 4 || menuNum == 5)
			break;	// 1,2,3,4,5 이외의 입력은 재입력 요구
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
	displayTitle("전등 상태 보기");

	if (r.getLightCnt() == 0)
		cout << "등록된 전등이 없습니다" << endl << endl;
	else
		r.listDisplayAppliance();

	displayTitle("전등 상태 보기 종료");
}

void controlAppliance(LightAutomation &r)
{
	displayTitle("전등 제어 하기");

	if (r.getLightCnt() == 0)
		cout << "등록된 전등이 없습니다. 전등을 먼저 등록하세요" << endl << endl;
	else
	{
		string machineName;
		cout << "* 제어할 전등명 입력 : ";
		cin >> machineName;

		if (r.controlAppliance(machineName))
			cout << "전등명 " << machineName << "의 제어가 완료되었습니다." << endl;
		else
			cout << "전등명 " << machineName << "의 제어가 실패하였습니다." << endl;
	}
}

void addAppliance(LightAutomation &r)
{
	displayTitle("전등 등록 하기");
	string machineName;
	cout << "제품 명 입력((예) 거실전등, 안방등 등) : ";
	cin >> machineName;

	LightFixture enroll;
	enroll.initLightFixture(machineName);

	if (r.addAppliance(enroll))
		cout << "전등명 " << machineName << "의 등록이 완료되었습니다." << endl;
	else
		cout << "전등명 " << machineName << "의 등록이 실패하였습니다." << endl;
}

void deleteAppliance(LightAutomation &r)
{
	displayTitle("전등 삭제 하기");
	string machineName;
	cout << "제품 명 입력((예) 거실전등, 안방등 등) : ";
	cin >> machineName;

	if (r.deleteAppliance(machineName))
		cout << "전등명 " << machineName << "의 삭제가 완료되었습니다." << endl;
	else
		cout << "전등명 " << machineName << "의 삭제가 실패하였습니다." << endl;
}