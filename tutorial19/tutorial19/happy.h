#pragma once
#include <iostream>
using namespace std;
#include <string>

class Happy
{
private:
	string name;	//이름
	int money;	//잔액
	char *list[100];	//사용 내역을 저장하는 char *배열
	int index;	//사용내역 갯수

public:
	Happy(char *np = "", int money = 10000);
	Happy(Happy &r);
	~Happy();
	Happy &operator=(Happy &r);
	void use(char *lp, int n);
	Happy &winner(Happy &r);
	void setName(string &name);
	string &getName();
	void setMoney(int money);
	int getMoney();
	char **getList();
	int getIndex();
};