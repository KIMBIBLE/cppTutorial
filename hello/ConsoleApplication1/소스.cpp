#include <iostream>

namespace A {
	void Add() {
		printf("A의 Add() 호출!\n");
		std::cout << "cout too!!!" << std::endl;
	}

	int k;
}


namespace B {
	void Add() {
		printf("B의 Add() 호출!\n");
	}
}

namespace C {
	void Add() {
		std::cout << "C의 Add() 호출!" << std::endl;
	}

	void Minus() {
		std::cout << "C의 Minus() 호출!" << std::endl;
	}

	int c;
	double d;
}

using namespace std;
using namespace C;
using A::k;

int Sum(int num1, int num2) 
{
	return num1 + num2;
}

double Sum(double num1, double num2) 
{
	return num1 + num2;
}


int main()
{
	char *key = "Myname";
	char name[10];

	cout << "hello" << endl;

	std::cout << "input your name : ";
	std::cin >> name;

	std::cout << "hello, world!" << std::endl;
	std::cout << "hello, world!" << std::endl;
	std::cout << "Hey " << key << " is " << name << std::endl;

	A::Add();
	B::Add();

	Add();
	Minus();
	c = 10;
	d = 3.0;
	k = -3;

	int num1, num2;
	double num3, num4;

	std::cout << c << "\t" << k << "\t" << d << std::endl;

	std::cout << "intput number(int type) : ";
	std::cin >> num1;
	std::cin >> num2;

	std::cout << "input number(double type) : ";
	std::cin >> num3;
	std::cin >> num4;

	std::cout << num1 << " + " << num2 << " = " << Sum(num1, num2) << std::endl;
	std::cout << num3 << " + " << num4 << " = " << Sum(num3, num4) << std::endl;

	return 0;
}