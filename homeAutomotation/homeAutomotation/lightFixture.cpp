#include "lightFixture.h"

void LightFixture::initLightFixture(string machineName, bool powerFlag)
{
	this->machineName = machineName;
	this->powerFlag = powerFlag;
}

string LightFixture::getMachineName() const
{
	return machineName;
}

bool LightFixture::getPowerFlag() const
{
	return powerFlag;
}

void LightFixture::setMachineName(string machineName)
{
	this->machineName = machineName;
}

void LightFixture::setPowerFlag(bool powerFlag)
{
	this->powerFlag = powerFlag;
}

bool LightFixture::turnOn()
{
	this->powerFlag = true;
	return true;
}

bool LightFixture::turnOff()
{
	this->powerFlag = false;
	return true;
}

void LightFixture::stateView()
{
	cout << "Α¦Η°Έν : " << this->machineName << "(" 
		<< boolalpha << this->powerFlag << ")" << endl;
}