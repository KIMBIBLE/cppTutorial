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
	bool put(int index, int val);			// val 값을 index방에 저장, return > 성공 : true, 실패 : false
	bool get(int index, int &getdata);		// 배열요소 중 index방의 값을 getdata에 저장, return > 성공 : true, 실패 : false

	int getSize();
	int *getAry();
};