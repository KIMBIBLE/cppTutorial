#include "smartAry.h"

bool SmartArray::put(int index, int val)
{
	if (max < val)
		max = val;
	return MyArray::put(index, val);
}

int SmartArray::getMax()
{
	return max;
}

bool SmartArray::operator>(const SmartArray &br)
{
	if (max > br.max)
		return true;
	else
		return false;
}