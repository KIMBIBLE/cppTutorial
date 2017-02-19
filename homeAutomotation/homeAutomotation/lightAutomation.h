#ifndef __LIGHTAUTOMATION_H__
#define	__LIGHTAUTOMATION_H__

#include "LightFixture.h"
#define LIGHT_MAX_CNT 5 // �ִ� ��� ������ ������ ����

class LightAutomation
{
public:

	void initLightAutomation(); // lightArray�� �޸� ������ ��� 0���� �ʱ�ȭ �ϰ�, lightCnt�� 0���� �ʱ�ȭ

						   // getter, setter member function
	LightFixture * getLightArray(); // lightArray ��� �� ��ȯ �Լ�
	int getLightCnt() const;       // lightCnt ��� �� ��ȯ �Լ�

							 // member function
	bool addAppliance(LightFixture &ap);	      // parameter�� ���ü�� ��Ͽ� �߰�. ������ �̸��� ���ü�� ��ϵ��� �ʵ��� ��
	int searchMachine(string machineName);    // ����� �ش��ϴ� ������ ã�Ƽ� �迭�� index����/���� �� -1 ����
	bool deleteAppliance(string machineName);  // ����� �ش��ϴ� ������ ��Ͽ��� �����ϴ�
	void listDisplayAppliance();               // ��ϵ� ���� ��ü ��� �� On.Off ���¸� Ȯ��(���)�ϴ�
	bool controlAppliance(string machineName); // �ش� ������ ���¸� �����Ѵ�. (On->Off, Off->On ���� ����)
private:
	LightFixture lightArray[LIGHT_MAX_CNT];   // ��ϵ� ���� ��ü�� ���� ���� �迭
	int lightCnt; // ��ϵ� ���ü�� ���� ���� 
};
#endif