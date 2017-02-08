#pragma once

#define MAX_PAGE_XPOS 80
#define MAX_PAGE_YPOS 24
#define LINE_STRING_SIZE 81	// 1 Byte for Null String

typedef struct _line
{
	char string[LINE_STRING_SIZE];
	int pageNumber;	//line�� ���� page ��ġ�� ����
}Line;

typedef  Line DataType;     // ��峻�� ������ ������ ���� ������ 

//-------------------------------------
//   Line ����ü ���� �Լ�
//-------------------------------------
void printLine(DataType *p);  // Line ����ü�� String�� ����ϴ� �Լ� 

