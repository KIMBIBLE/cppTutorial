#pragma once

#include "iostream"
using namespace std;
#include <string.h>

#define NAME_BUF_SIZE 101

class Robot
{
private:
	char *name;
	int energy;
	void errPrn(char *message);	//에너지 부족 - 에러메세지 출력

public:
	// Constructor
	Robot();		// name은 Null String, energy = 0 으로 초기화
	Robot(char *name, int energy = 0);
	Robot(const Robot &r);

	// Destructor
	~Robot()
	{
		delete[] name;
	}

	// Member Func
	void go();			// 전진 메시지 출력 후 에너지 10 감소
	void back();			// 후진 메시지 출력 후 에너지 20 감소
	void turn();			// 턴 메시지 출력 후 에너지 30 감소
	void jump();			// 점프 메시지 출력 후 에너지 40 감소
	void charge(int e);		//e 값 만큼 충전
	char *getName();		//name 멤버의 값 리턴
	void setName(char *);	//name 멤버의 값을 전달된 문자열로 재 초기화
	int getEnergy();		//energy 멤버의 값 리턴
	void setEnergy(int);	//energy 멤버의 값을 전달된 숫자로 재 초기화
};
