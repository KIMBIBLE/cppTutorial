#include <iostream>
using namespace std;
#include <string.h>

class Wow
{
private :
	char name[20];
	int age;
public:
	Wow(char * = "noname", int = 0);
	~Wow() {};

	void update(char *, int);
	void output();
};

Wow::Wow(char *p, int n) : age(n)
{
	strcpy(name, p);
}

void Wow::update(char *p, int n)
{
	strcpy(name, p);
	age = n;
}

void Wow::output()
{
	cout << "이름 : " << name << endl;
	cout << "나이 : " << age << endl;
}

int main()
{
	Wow person1;
	Wow person2("King", 20);
	Wow person3 = person2;
	Wow person4(person3);

	person1.output();
	person2.output();
	person3.update("King Kong", 77);
	person3.output();
	person4.output();
}