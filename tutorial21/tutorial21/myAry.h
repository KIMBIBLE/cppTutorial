#pragma once

#include <iostream>
using namespace std;

class MyArray
{
private:
	int *ary;
	int size;

public:
	MyArray() { ary = 0; size = 0; }
	MyArray(int s);
	MyArray(const MyArray &br);
	~MyArray() { delete[] ary; }
	MyArray &operator=(const MyArray &br);
	bool put(int index, int val);			// val ���� index�濡 ����, return > ���� : true, ���� : false
	bool get(int index, int &getdata);		// �迭��� �� index���� ���� getdata�� ����, return > ���� : true, ���� : false

	int getSize();
	int *getAry();
};