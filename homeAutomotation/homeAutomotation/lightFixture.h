#ifndef __LIGHTFIXTURE_H__
#define __LIGHTFIXTURE_H__
#include<iostream>
using namespace std;
#include <string>

class LightFixture
{
public:
	void initLightFixture(string machineName, bool powerFlag = false); // ���ü �ʱ�ȭ �Լ� 
	string getMachineName() const;  // machineName ��� �� ��ȯ �Լ�
	bool getPowerFlag() const; // powerFlag ��� �� ��ȯ �Լ�
	void setMachineName(string machineName);  // machineName ��� �ʱ�ȭ �Լ�
	void setPowerFlag(bool powerFlag); // powerFlag ��� ���� �Լ� 
								// member fucntion
	bool turnOn();         // ��ǰ(����)�� �Ѵ�
	bool turnOff();        // ��ǰ(����)�� ����
	void stateView();      // ��ü�� ���� ���
private:
	string machineName;    // ������ǰ(����)��
	bool powerFlag;        // ���� on_off����(on-ture, off-false)
};
#endif
