#pragma once
#include <string.h>

typedef struct _person
{
	char name[20];
	int age;
	char phoneNumber[15];
}Person;

int compareAge(void *vp1, void *vp2);
int compareName(void *vp1, void *vp2);