#include "word.h"


void wordMemCpy(void *p1, void *p2)
{
	wordFree(p1);  // name멤버의 메모리 해제
	if (((Word *)p2)->wp != NULL)
	{
		((Word *)p1)->wp = (char *)calloc(strlen(((Word *)p2)->wp) + 1, sizeof(char));
		strcpy(((Word *)p1)->wp, ((Word *)p2)->wp);
	}


	((Word *)p1)->length = ((Word *)p2)->length;
}


void wordFree(void *p) // <<===  WordClear()함수임 !! Word구조체의 멤버에 속해있는 부가 메모리 해제하기
{
	if (((Word *)p)->wp != NULL)
		free(((Word *)p)->wp);
	((Word *)p)->wp = NULL;  // 메모리 해제 후 name멤버를 NULL 포인터로 변경해놓음
}

void wordPrint(void *p, int num)
{
	printf("%2d 번째 단어 : %-32s  단어길이 :%4d\n", num, ((Word *)p)->wp, ((Word *)p)->length);
}

int wordCompare(void *p1, void *p2)
{
	return strcmp(((Word *)p1)->wp, ((Word *)p2)->wp);
}

int wordLengthCompare(void *p1, void *p2)
{
	if (((Word *)p1)->length > ((Word *)p2)->length)
	{
		return 1;
	}
	else if (((Word *)p1)->length == ((Word *)p2)->length)
	{
		return 0;
	}
	else
	{
		return -1;
	}
}
