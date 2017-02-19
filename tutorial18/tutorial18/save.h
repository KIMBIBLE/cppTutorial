#pragma once
#include <iostream>
using namespace std;

class Save
{
private:
	char name[20];			// 이름
	int capital;			// 원금
	int profit;			// 이자소득
	int tax;				// 세금
	int tot;				// 총금액
	static double ratio;	// 이율(기본 이율: 원금의 20%)

public:
	static double tax_ratio;	// 세율(기본 세율: 10%)
	Save(const char *np = "아무개", int n = 0);
	void calculate();	// 총금액

	friend ostream &operator<<(ostream &os, Save &br);
	static void set_ratio(double r);	// ratio(이율) 수정을 위한 함수
};

ostream &operator<<(ostream &os, Save &br);