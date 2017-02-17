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
	int memberCnt = 0;	// 전체 회원 수
	Fitness *fary[100];

	while (1)
	{
		cout << "1. 회원등록" << endl;
		cout << "2. 회원전체보기" << endl;
		cout << "3. 회원정보검색" << endl;
		cout << "4. 회원탈퇴" << endl;
		cout << "5. 특별관리 회원" << endl;
		cout << "6. 종료" << endl;
		menu = getInt("메뉴를 입력하세요 : ", 1, 6);

		// 종료 시 동적할당 받은 Fitness 객체들 해제
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
		cout << "최대 회원수 초과로 인한 등록 실패" << endl;
		return;
	}

	cout << "<회원 등록 정보를 입력하시오>" << endl;
	fp[memberCnt] = new Fitness;
	fp[memberCnt]->setNum(memberCnt);

	
	cout << "회원 명(최대 100자) : ";
	cin >> name;
	flush();
	fp[memberCnt]->setName(name);

	weight = getInt("몸무게 : ", 0, 10000);
	fp[memberCnt]->setWeight(weight);

	height = getInt("키 : ", 0, 10000);
	fp[memberCnt]->setHeight(height);

	memberCnt++;
}

void printAllMember(Fitness **fp, const int memberCnt)
{
	for (int i = 0; i < memberCnt; i++)
	{
		cout << "회원번호 : " << i << endl;
		cout << "성명 : " << fp[i]->getName() << endl;
		cout << "몸무게 : " << fp[i]->getWeight() << endl;
		cout << "신장 : " << fp[i]->getHeight() << endl << endl;
	}
}

void searchPrintMember(Fitness **fp, const int memberCnt)
{
	char name[101];
	cout << "검색할 회원 명을 입력하시오 : ";
	cin >> name;
	for (int i = 0; i < memberCnt; i++)
	{
		if (strcmp(fp[i]->getName(), name) == 0)
		{
			cout << "회원번호 : " << i << endl;
			cout << "성명 : " << fp[i]->getName() << endl;
			cout << "몸무게 : " << fp[i]->getWeight() << endl;
			cout << "신장 : " << fp[i]->getHeight() << endl << endl;
		}
	}
}
void deleteMember(Fitness **fp, int &memberCnt)
{
	int num = getInt("삭제할 회원 번호을 입력하시오 : ", 0, MAX_MEMBER_NUM);
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
			cout << "회원번호 : " << i << endl;
			cout << "성명 : " << fp[i]->getName() << endl;
			cout << "몸무게 : " << fp[i]->getWeight() << endl;
			cout << "신장 : " << fp[i]->getHeight() << endl << endl;
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
