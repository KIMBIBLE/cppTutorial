#include <iostream>
using namespace std;
#include "Profile.h"

// ���� �Լ�
/*
ostream &operator<<(ostream &os, Profile &pr)
{
	// ��� 1 : getter() �̿�
	
	//cout << pr.getName() << " / ";
	//cout << pr.getAddr() << " / ";
	//cout << pr.getAge() << " / ";
	//cout << pr.getHeight() << endl;
	

	// ��� 2 : �����Լ����� Ŭ���� Member ������ִ� �޼ҵ� ���� ȣ��
	pr << os;

	return os;
}
*/

// ��� 3 : friend �Լ��� ����ؼ� private ����� �����Ӱ� ����
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