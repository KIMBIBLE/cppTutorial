#include <string>
#include "fitness.h"

// Constructor, Destructor Func()
Fitness::Fitness()	// (default) 회원번호 0, 성명 null string, 몸무게 0kg, 신장 0cm으로 초기화
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

Fitness::~Fitness()	// 동적할당된 메모리(name) 해제
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
void Fitness::setNum(int num)			// num 멤버 초기화 함수
{
	this->num = num;
}

void Fitness::setName(char *name)		// name 멤버 초기화 함수
{
	delete[] this->name;
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

void Fitness::setWeight(double weight)	// weight 멤버 초기화 함수
{
	this->weight = weight;
}
void Fitness::setHeight(double height)	// height 멤버 초기화 함수
{
	this->height = height;
}

// Getter Func()
int Fitness::getNum()			// num 멤버 값 리턴 함수
{
	return num;
}

char * Fitness::getName()		// name 멤버 값 리턴 함수
{
	return name;
}

double Fitness::getWeight()		// weight 멤버 값 리턴 함수
{
	return weight;
}

double Fitness::getHeight()		// height 멤버 값 리턴 함수
{
	return height;
}

// etc Func()
double Fitness::bmi()	// 해당 회원의 bmi 계산하여 리턴하는 함수
{
	return weight / (height / 100) / (height / 100);
}