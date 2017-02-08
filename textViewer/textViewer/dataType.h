#pragma once

#define MAX_PAGE_XPOS 80
#define MAX_PAGE_YPOS 24
#define LINE_STRING_SIZE 81	// 1 Byte for Null String

typedef struct _line
{
	char string[LINE_STRING_SIZE];
	int pageNumber;	//line이 속한 page 위치를 저장
}Line;

typedef  Line DataType;     // 노드내의 데이터 영역의 형명 재지정 

//-------------------------------------
//   Line 구조체 보조 함수
//-------------------------------------
void printLine(DataType *p);  // Line 구조체의 String을 출력하는 함수 

