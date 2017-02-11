#pragma once
#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <string.h>

typedef struct _word
{
	char *wp;
	int length;
}Word;

typedef Word DataType;
//-------------------------------------
//   Word 구조체 보조 함수
//-------------------------------------

void wordMemCpy(void *p1, void *p2);
void wordFree(void *p);
void wordPrint(void *p, int num);
int wordCompare(void *p1, void *p2);
int wordLengthCompare(void *p1, void *p2);