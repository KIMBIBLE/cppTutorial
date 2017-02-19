#ifndef __LIGHTFIXTURE_H__
#define __LIGHTFIXTURE_H__
#include<iostream>
using namespace std;
#include <string>

class LightFixture
{
public:
	void initLightFixture(string machineName, bool powerFlag = false); // 전등객체 초기화 함수 
	string getMachineName() const;  // machineName 멤버 값 반환 함수
	bool getPowerFlag() const; // powerFlag 멤버 값 반환 함수
	void setMachineName(string machineName);  // machineName 멤버 초기화 함수
	void setPowerFlag(bool powerFlag); // powerFlag 멤버 접근 함수 
								// member fucntion
	bool turnOn();         // 제품(전원)을 켜다
	bool turnOff();        // 제품(전원)을 끄다
	void stateView();      // 객체의 상태 출력
private:
	string machineName;    // 가전제품(전등)명
	bool powerFlag;        // 전원 on_off상태(on-ture, off-false)
};
#endif
