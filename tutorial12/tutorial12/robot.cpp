#include "robot.h"


// private member func
void Robot::errPrn(char *message)
{
	cout << message << endl;
}


// constructor func
Robot::Robot()
{
	name = new char[1];
	strcpy(name, "");
	energy = 0;
}

Robot::Robot(char *name, int energy)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	this->energy = energy;
}

Robot::Robot(const Robot &r)
{
	name = new char[strlen(r.name) + 1];
	strcpy(name, r.name);
	energy = r.energy;
}

// public member func
void Robot::go()
{
	if (getEnergy() < 10)
	{
		cout << getName();
		errPrn(" not enough energy");
		return;
	}

	cout << " go" << endl;
	energy -= 10;
}

void Robot::back()
{
	if (getEnergy() < 20)
	{
		cout << getName();
		errPrn(" not enough energy");
		return;
	}

	cout << " back" << endl;
	energy -= 20;
}

void Robot::turn()
{
	if (getEnergy() < 30)
	{
		cout << getName();
		errPrn(" not enough energy");
		return;
	}

	cout << " turn" << endl;
	energy -= 30;
}

void Robot::jump()
{
	if (getEnergy() < 40)
	{
		cout << getName();
		errPrn(" not enough energy");
		return;
	}

	cout << " jump" << endl;
	energy -= 40;
}

void Robot::charge(int e)
{
	if (e < 0)
	{
		errPrn(" energy must be positive value");
		return;
	}
	cout << getName();
	cout << " 에너지 " << e << "충전" << endl;
	energy += e;
}

char *Robot::getName()
{
	return name;
}

void Robot::setName(char *n)
{
	name = new char[strlen(n) + 1];
	strcpy(name, n);
}

int Robot::getEnergy()
{
	return energy;
}

void Robot::setEnergy(int e)
{
	if (e < 0)
	{
		errPrn("energy must be positive value");
		return;
	}

	energy = e;
}
