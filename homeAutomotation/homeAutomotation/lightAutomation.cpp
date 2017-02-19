#include "lightAutomation.h"

void LightAutomation::initLightAutomation()
{
	for (auto i : this->lightArray)
	{
		i.setMachineName("");
		i.setPowerFlag(false);
	}
	this->lightCnt = 0;
}

LightFixture *LightAutomation::getLightArray()
{
	return lightArray;
}

int LightAutomation::getLightCnt() const
{
	return lightCnt;
}

bool LightAutomation::addAppliance(LightFixture &ap)
{
	if (lightCnt == LIGHT_MAX_CNT)
		return false;
	for (int i = 0; i < lightCnt; i++)
		if (lightArray[i].getMachineName() == ap.getMachineName())
			return false;

	lightArray[lightCnt] = ap;
	lightCnt++;
	return true;
}

int LightAutomation::searchMachine(string machineName)
{
	for (int i = 0; i < lightCnt; i++)
		if (lightArray[i].getMachineName() == machineName)
			return i;
	return -1;
}

bool LightAutomation::deleteAppliance(string machineName)
{

	for (int i = 0; i < lightCnt; i++)
		if (lightArray[i].getMachineName() == machineName)
		{
			LightFixture temp;
			for (int j = i; j < lightCnt - 1; j++)
			{
				temp = lightArray[i];
				lightArray[i] = lightArray[i + 1];
				lightArray[i + 1] = temp;
			}
			lightCnt--;
			return true;
		}
	return false;
}

void LightAutomation::listDisplayAppliance()
{
	for (int i = 0; i < lightCnt; i++)
		lightArray[i].stateView();
}

bool LightAutomation::controlAppliance(string machineName)
{
	int idx;
	if ((idx = searchMachine(machineName)) == -1)
	{
		cout << "** 해당하는 제품이 존재하지 않습니다." << endl;
		return false;
	}	
	
	else
	{
		if (lightArray[idx].getPowerFlag())
			lightArray[idx].turnOff();
		else
			lightArray[idx].turnOn();
	}

	return true;
}