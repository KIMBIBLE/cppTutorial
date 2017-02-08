#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <conio.h>
#include "textViewer.h"

void rewindCurp(LinkedList *lp)
{
	int nowPage = lp->cur->prev->data.pageNumber;

	lp->cur = lp->cur->prev;
	while (lp->cur->data.pageNumber == nowPage)
		lp->cur = lp->cur->prev;
	lp->cur = lp->cur->next;
}

// ��� : cur �����ͼ���
void pageUp(LinkedList *lp)
{
	if (lp->cur->prev->data.pageNumber == 0)
	{
		while (lp->cur->prev != lp->head)
			lp->cur = lp->cur->prev;
	}
	else if (lp->cur->prev->data.pageNumber == 1)
	{
		rewindCurp(lp);
		while (lp->cur->prev != lp->head)
			lp->cur = lp->cur->prev;
	}
	else
	{
		rewindCurp(lp);
		rewindCurp(lp);
	}

}

// ��� : cur �����ͼ���
void pageDown(LinkedList *lp)
{
	int nowPage = lp->cur->prev->data.pageNumber;

	// ������ �������� �ƴ� ��� cur ����
	if (lp->cur->next != lp->tail)
		return;

	// ������ �������� ��� cur ������ ���� ��� �������� �ǵ���
	// ���� ��� ���� ������� ����
	rewindCurp(lp);
}

int menu()
{
	char userChoice;

	while (1) // �޴���ȣ�� ��ȿ���� ���� ���� �ݺ�
	{
		//menuNum = getch();
		printf(": ");
		scanf("%c", &userChoice);
		if(getchar() != '\n')
			while (getchar() != '\n') { ; }

		if (userChoice == 'e' || userChoice == 'w' || userChoice == 's')
			return userChoice;
	}

	
}

void displayPage(LinkedList *lp, void(*print)(DataType *))
{
	int endCondition = lp->cur->data.pageNumber + 1;

	while (lp->cur->data.pageNumber < endCondition)
	{
		if (lp->cur == lp->tail)
			break;

		print(&lp->cur->data);
		lp->cur = lp->cur->next;
	}

}

FILE* fileOpen(char *fileName, char *mode)
{
	FILE *fp;
	fp = fopen(fileName, mode);
	assert(fp != NULL);

	return fp;
}

void dataFileLoad(LinkedList *lp)
{
	FILE *fp;
	fp = fileOpen("c:\\data\\flower.txt", "rt");
	DataType eachLine;
	eachLine.pageNumber = 0;

	while (fgets(eachLine.string, sizeof(eachLine.string), fp))
	{
		eachLine.string[strlen(eachLine.string) - 1] = NULL;
		eachLine.pageNumber = lp->length / MAX_PAGE_YPOS;
		appendFromTail(lp, &eachLine);
	}

	fclose(fp);
}