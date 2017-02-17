#include <string>
#include "fitness.h"

// Constructor, Destructor Func()
Fitness::Fitness()	// (default) ȸ����ȣ 0, ���� null string, ������ 0kg, ���� 0cm���� �ʱ�ȭ
{
	this->num = 0;
	char *s = "";
	this->name = new char[strlen(s) + 1];
	strcpy(this->name, s);
	this->weight = 0.0;
	this->height = 0.0;
}

Fitness::Fitness(int num, char *name, double weight, double height)
{
	this->num = num;
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	this->weight = weight;
	this->height = height;
}

Fitness::Fitness(Fitness &r)
{
	if (this == &r) { return; }

	this->num = r.num;

	delete[] this->name;
	new char[strlen(r.name) + 1];
	strcpy(this->name, r.name);

	this->weight = weight;
	this->height = height;
}

Fitness::~Fitness()	// �����Ҵ�� �޸�(name) ����
{
	delete[] this->name;
}

// Operator Overloading Func()
Fitness & Fitness::operator=(Fitness &r)
{
	if (this == &r) { return *this; }

	this->num = r.num;

	delete[] this->name;
	new char[strlen(r.name) + 1];
	strcpy(this->name, r.name);

	this->weight = weight;
	this->height = height;

	return *this;
}

bool Fitness::operator==(Fitness &r)
{
	if (this->name == r.name)
		return true;
	return false;
}

// Setter Func()
void Fitness::setNum(int num)			// num ��� �ʱ�ȭ �Լ�
{
	this->num = num;
}

void Fitness::setName(char *name)		// name ��� �ʱ�ȭ �Լ�
{
	delete[] this->name;
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

void Fitness::setWeight(double weight)	// weight ��� �ʱ�ȭ �Լ�
{
	this->weight = weight;
}
void Fitness::setHeight(double height)	// height ��� �ʱ�ȭ �Լ�
{
	this->height = height;
}

// Getter Func()
int Fitness::getNum()			// num ��� �� ���� �Լ�
{
	return num;
}

char * Fitness::getName()		// name ��� �� ���� �Լ�
{
	return name;
}

double Fitness::getWeight()		// weight ��� �� ���� �Լ�
{
	return weight;
}

double Fitness::getHeight()		// height ��� �� ���� �Լ�
{
	return height;
}

// etc Func()
double Fitness::bmi()	// �ش� ȸ���� bmi ����Ͽ� �����ϴ� �Լ�
{
	return weight / (height / 100) / (height / 100);
}