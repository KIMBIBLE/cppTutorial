#pragma once
#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <string.h>

#define BUF_SIZE 100

typedef struct _person
{
	char *name;
	int age;
	char phoneNumber[15];
}Person;

// half generic������ ���
//typedef  Person DataType;     // ��峻�� ������ ������ ���� ������ 

//-------------------------------------
//   Person ����ü ���� �Լ�
//-------------------------------------

void personMemCpy(void *p1, void *p2);
void personFree(void *p);
void personPrint(void *p);
int personNameCompare(void *p1, void *p2);
int personAgeCompare(void *p1, void *p2);
int personCompare(void *p1, void *p2);
