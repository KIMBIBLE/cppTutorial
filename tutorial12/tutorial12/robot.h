#pragma once

#include "iostream"
using namespace std;
#include <string.h>

#define NAME_BUF_SIZE 101

class Robot
{
private:
	char *name;
	int energy;
	void errPrn(char *message);	//������ ���� - �����޼��� ���

public:
	// Constructor
	Robot();		// name�� Null String, energy = 0 ���� �ʱ�ȭ
	Robot(char *name, int energy = 0);
	Robot(const Robot &r);

	// Destructor
	~Robot()
	{
		delete[] name;
	}

	// Member Func
	void go();			// ���� �޽��� ��� �� ������ 10 ����
	void back();			// ���� �޽��� ��� �� ������ 20 ����
	void turn();			// �� �޽��� ��� �� ������ 30 ����
	void jump();			// ���� �޽��� ��� �� ������ 40 ����
	void charge(int e);		//e �� ��ŭ ����
	char *getName();		//name ����� �� ����
	void setName(char *);	//name ����� ���� ���޵� ���ڿ��� �� �ʱ�ȭ
	int getEnergy();		//energy ����� �� ����
	void setEnergy(int);	//energy ����� ���� ���޵� ���ڷ� �� �ʱ�ȭ
};
