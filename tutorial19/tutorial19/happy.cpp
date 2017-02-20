#include "happy.h"

Happy::Happy(char *np, int money) :name(np), money(money), index(0)
{
	for (int i = 0; i < 100; i++)
		list[i] = NULL;
}

Happy::Happy(Happy &r)
{
	name = r.getName();
	money = r.getMoney();
	index = r.getIndex();
	for (int i = 0; i < index; i++)
	{
		list[i] = new char[strlen(r.getList()[i]) + 1];
		strcpy(list[i], r.getList()[i]);
	}
		
}

Happy::~Happy()
{
	for (int i = 0; i < index; i++)
	{
		delete[] list[i];
		list[i] = NULL;
	}
}

Happy & Happy::operator=(Happy &r)
{
	for (int i = 0; i < index; i++)
	{
		delete[] list[i];
		list[i] = NULL;
	}
	
	name = r.getName();
	money = r.getMoney();
	index = r.getIndex();


	for (int i = 0; i < index; i++)
	{
		list[i] = new char[strlen(r.getList()[i]) + 1];
		strcpy(list[i], r.getList()[i]);
	}

	return *this;
}

void Happy::use(char *lp, int n)
{
	if (money < n)
		return;

	list[index] = new char[strlen(lp) + 1];
	strcpy(list[index++], lp);
	money -= n;
}

Happy & Happy::winner(Happy &r)
{
	if (money > r.money)
		return *this;
	else 
		return r;
		
}

void Happy::setName(string &name)
{
	name = name;
}

string & Happy::getName()
{
	return name;
}

void Happy::setMoney(int money)
{
	money = money;
}

int Happy::getMoney()
{
	return money;
}

char ** Happy::getList()
{
	return list;
}

int Happy::getIndex()
{
	return index;
}