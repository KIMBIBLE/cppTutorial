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
	Profile  ary[20];   // 프로필 저장 객체 배열
	int profileCnt = 0;     // 입력 받은 프로필의 개수 카운트 변수
	char ch;          // 메뉴번호 저장 변수 
	
	while (1)
	{
		ch = menu();        // 입력된 메뉴의 번호를 ch에 리턴받음
		if (ch == '4') { break; }  // 4번 종료하기 메뉴 입력시 무한반복문을 탈출
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
	char menulist[4][20] = { "프로필 입력", "프로필 수정", "프로필 출력","종료" };

	for (i = 0; i<4; i++)   // 메뉴 문자열을 출력하는 반복문
	{
		cout << i + 1 << ". " << menulist[i] << endl;
	}

	while (n<'1' || n>'4') // 유효한 번호가 아니면 다시 입력
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
		cout << "이름입력 : ";
		cin >> name;
		if (strcmp(name, "끝") == 0) { break; }
		cout << "주소입력 : ";		cin >> addr;
		cout << "나이입력 : ";		cin >> age;
		cout << "키입력 : ";		cin >> height;

		ap[cnt] = Profile(name, addr, age, height); // 입력 받은 데이터로 객체 초기화
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
		cout << "수정할 사람의 이름 입력 : ";
		cin >> name;
		if (name == "끝") { break; }

		// 입력받은 수정할 사람의 이름이 프로필 목록에 있는지 검사	
		for (i = 0; i < cnt; i++)
		{
			if (strcmp(ap[i].getName().getStr(), name) == 0)
			{
				cout << "수정 전 profile : ";
				cout << ap[i].getName().getStr() << " / ";
				cout << ap[i].getAddr().getStr() << " / ";
				cout << ap[i].getAge() << " / ";
				cout << ap[i].getHeight() << endl;

				edit = 0;
				while (edit<1 || edit>4) // 유효한 번호가 아니면 다시 입력
				{
					cout << "수정 항목 선택 : 1.이름 /2.주소 /3. 나이 /4. 신장 : ";
					cin >> edit;
				}

				// 수정 항목에 대해 프로필 수정
				if (edit == 1)
				{
					cout << "수정할 이름 : ";
					cin >> name;
					MyString temp(name);
					ap[i].setName(temp);
				}
				else if (edit == 2)
				{
					cout << "수정할 주소 : ";
					cin >> addr;
					MyString temp(addr);
					ap[i].setAddr(temp);
				}
				else if (edit == 3)
				{
					cout << "수정할 나이 : ";
					cin >> age;
					ap[i].setAge(age);
				}
				else if (edit == 4)
				{
					cout << "수정할 키 : ";
					cin >> height;
					ap[i].setHeight(height);
				}
				else { ; }
	
				// 수정 후 프로필 출력
				cout << "수정 후 Profile : ";
				cout << ap[i].getName().getStr() << " / ";
				cout << ap[i].getAddr().getStr() << " / ";
				cout << ap[i].getAge() << " / ";
				cout << ap[i].getHeight() << endl;

				break;
			}
		}
		if (i == cnt)	// 프로필 목록에 사용자가 입력한 이름이 없다면 menu()로 이동
		{
			cout << "프로필 목록에서 해당 이름을 조회할 수 없습니다." << endl;
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
			<< ap[i].getAddr().getStr() << "/" << ap[i].getAge() << "세/"
			<< ap[i].getHeight() << "cm" << endl;
	}
}