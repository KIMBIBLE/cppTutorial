#include <iostream>
using namespace std;
#include "Profile.h"

// 전역 함수
/*
ostream &operator<<(ostream &os, Profile &pr)
{
	// 방법 1 : getter() 이용
	
	//cout << pr.getName() << " / ";
	//cout << pr.getAddr() << " / ";
	//cout << pr.getAge() << " / ";
	//cout << pr.getHeight() << endl;
	

	// 방법 2 : 전역함수에서 클래스 Member 출력해주는 메소드 만들어서 호출
	pr << os;

	return os;
}
*/

// 방법 3 : friend 함수로 등록해서 private 멤버에 자유롭게 접근
ostream &operator<<(ostream &os, Profile &pr)
{

	os << pr.name << " / ";
	os << pr.addr << " / ";
	os << pr.age << " / ";
	os << pr.height << endl;

	return os;
}

// Profile Class Member Func 
void Profile:: operator<<(ostream &os)
{
	os << this->name << " / ";
	os << this->addr << " / ";
	os << this->age << " / ";
	os << this->height << endl;
}


Profile::Profile() : name(), addr(), age(0), height(0)
{ }
//-----------------------------------------------------------------------------------
Profile::Profile(const char *np, const char *ap, int a, double h)
	: name(np), addr(ap), age(a), height(h)
{ }
//-----------------------------------------------------------------------------------
bool Profile::operator>(const Profile &br)
{
	if (height>br.height) return true;
	else return false;
}
//----------------------------------------------------------------------------------
string Profile::getName()
{
	return name;
}
//----------------------------------------------------------------------------------
string Profile::getAddr()
{
	return addr;
}
//----------------------------------------------------------------------------------
int Profile::getAge()
{
	return age;
}
//----------------------------------------------------------------------------------
double Profile::getHeight()
{
	return height;
}
//----------------------------------------------------------------------------------
void Profile::setName(string &br)
{
	name = br;
}
//----------------------------------------------------------------------------------
void Profile::setAddr(string &br)
{
	addr = br;
}
//----------------------------------------------------------------------------------
void Profile::setAge(int a)
{
	age = a;
}
//----------------------------------------------------------------------------------
void Profile::setHeight(double h)
{
	height = h;
}