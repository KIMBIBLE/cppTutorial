#pragma once
#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <string.h>

typedef struct _person
{
	char *name;
	int age;
	char phoneNumber[15];
}Person;


//-------------------------------------
//   Person 구조체 보조 함수
//-------------------------------------

void personMemCpy(void *p1, void *p2);
void personFree(void *p);
void personPrint(void *p);
int personNameCompare(void *p1, void *p2);
int personAgeCompare(void *p1, void *p2);
int personCompare(void *p1, void *p2);
