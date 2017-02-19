#pragma once
#include <iostream>
using namespace std;

class Save
{
private:
	char name[20];			// �̸�
	int capital;			// ����
	int profit;			// ���ڼҵ�
	int tax;				// ����
	int tot;				// �ѱݾ�
	static double ratio;	// ����(�⺻ ����: ������ 20%)

public:
	static double tax_ratio;	// ����(�⺻ ����: 10%)
	Save(const char *np = "�ƹ���", int n = 0);
	void calculate();	// �ѱݾ�

	friend ostream &operator<<(ostream &os, Save &br);
	static void set_ratio(double r);	// ratio(����) ������ ���� �Լ�
};

ostream &operator<<(ostream &os, Save &br);