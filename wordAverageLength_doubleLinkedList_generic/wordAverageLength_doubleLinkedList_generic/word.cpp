#include "word.h"


void wordMemCpy(void *p1, void *p2)
{
	wordFree(p1);  // name����� �޸� ����
	if (((Word *)p2)->wp != NULL)
	{
		((Word *)p1)->wp = (char *)calloc(strlen(((Word *)p2)->wp) + 1, sizeof(char));
		strcpy(((Word *)p1)->wp, ((Word *)p2)->wp);
	}


	((Word *)p1)->length = ((Word *)p2)->length;
}


void wordFree(void *p) // <<===  WordClear()�Լ��� !! Word����ü�� ����� �����ִ� �ΰ� �޸� �����ϱ�
{
	if (((Word *)p)->wp != NULL)
		free(((Word *)p)->wp);
	((Word *)p)->wp = NULL;  // �޸� ���� �� name����� NULL �����ͷ� �����س���
}

void wordPrint(void *p, int num)
{
	printf("%2d ��° �ܾ� : %-32s  �ܾ���� :%4d\n", num, ((Word *)p)->wp, ((Word *)p)->length);
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
