#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "dataType.h"
#include "doubleLinkedList.h"



//-------------------------------------
//   Line 구조체 보조 함수
//-------------------------------------
void printLine(DataType *p)
{
	printf("%s\n", p->string);
}