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

// 기능 : cur 포인터세팅
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

// 기능 : cur 포인터세팅
void pageDown(LinkedList *lp)
{
	int nowPage = lp->cur->prev->data.pageNumber;

	// 마지막 페이지가 아닌 경우 cur 유지
	if (lp->cur->next != lp->tail)
		return;

	// 마지막 페이지인 경우 cur 포인터 이전 출력 지점으로 되돌림
	// 이전 출력 내용 재출력을 위함
	rewindCurp(lp);
}

int menu()
{
	char userChoice;

	while (1) // 메뉴번호가 유효하지 않을 동안 반복
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