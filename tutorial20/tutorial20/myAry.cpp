#include "myAry.h"

MyArray::MyArray(int s)
{
	size = s;
	ary = new int[s];
}

MyArray::MyArray(const MyArray &br)
{
	size = br.size;
	ary = new int[size];
	for (int i = 0; i < size; i++)
		ary[i] = br.ary[i];
}

MyArray & MyArray::operator=(const MyArray &br)
{
	if (this == &br) return (MyArray)0;

	size = br.size;
	ary = new int[size];
	for (int i = 0; i < size; i++)
		ary[i] = br.ary[i];

	return *this;
}

bool MyArray::put(int index, int val)
{
	if (index >= size)	return false;
	
	ary[index] = val;
	return true;
}

bool MyArray::get(int index, int &getdata)
{
	if (index >= size)	return false;
	getdata = ary[index];

	return true;
}

int MyArray::getSize()
{
	return size;
}

int *MyArray::getAry()
{
	return ary;
}