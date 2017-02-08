#include "stack.h"
#include <stdio.h>

int menu(char **, int);
void myFlush();
void input(Stack *);
void myDelete(Stack *);

int main()
{
	Stack stk;   /* 스택생성*/
	char *menuList[] = { "입력하기", "삭제하기", "출력하기", "종료" }; /* 메뉴 리스트*/
	int menuCnt;   /* 메뉴개수 저장변수*/
	int menuNum;   /* 메뉴번호 저장변수*/

	initStack(&stk, 5, sizeof(Person)); /* 스택 초기화*/
	menuCnt = sizeof(menuList) / sizeof(menuList[0]);  /* 메뉴 개수 계산하기*/

	while (1)
	{
		menuNum = menu(menuList, menuCnt);
		if (menuNum == menuCnt)  /* 종료메뉴 선택 시 반복문 탈출하기*/
		{
			break;
		}
		switch (menuNum)
		{
		case 1: input(&stk);  break;
		case 2: myDelete(&stk); break;
		case 3: printStack(&stk, sizeof(Person), personPrint); /* stack내의 모든 데이터 출력하기*/
		}
	}
	destroyStack(&stk, sizeof(Person), personFree);
	return 0;
}
/*--------------------------------------------------------------------------------------
함수명및기능: input() - 스택에 데이터를 반복적으로 입력함
전달인자: sPtr - 스택의 주소
리턴값: 없음
--------------------------------------------------------------------------------------*/
void input(Stack *sPtr)
{
	Person data;
	char buf[BUF_SIZE];

	while (1) {
		printf("# 이름을 입력하세요(끝 입력시 종료) : ");
		scanf("%s", buf);
		if (strcmp(buf, "끝") == 0) // "끝"입력시 종료
			break;

		data.name = (char *)calloc(1, strlen(buf) + 1);
		strcpy(data.name, buf);

		printf("# 나이을 입력하세요 : ");
		scanf("%d", &data.age);

		printf("# 전화번호를 입력하세요 : ");
		scanf("%s", data.phoneNumber);

		if (push(sPtr, &data, sizeof(Person), personMemCpy) != 1)
			printf("push 실패!\n");
		free(data.name);
	}
}
/*--------------------------------------------------------------------------------------
함수명및기능: myDelete() - 스택의 데이터를 반복적으로 꺼냄
전달인자: sPtr - 스택의 주소
리턴값: 없음
--------------------------------------------------------------------------------------*/
void myDelete(Stack *sPtr)
{
	int i;
	int cnt;  /* pop할 횟수를 입력받아 저장할 변수*/
	Person popData = { NULL, 0, ""}; /* pop한 데이터를 저장할 변수*/
	int res;     /* pop()함수의 리턴값을 저장할 변수*/

	printf("Stack에서 데이터를 pop할회수를입력하시오: ");
	scanf("%d", &cnt);
	for (i = 0; i<cnt; i++) {
		res = pop(sPtr, &popData, sizeof(Person), personMemCpy, personFree);
		if (res == 1)  /* 성공적으로 pop 작업을수행했으면*/
		{
			personPrint(&popData);
		}
		else
			personPrint(&popData);
	}
}
/*--------------------------------------------------------------------------------------
함수명및기능: menu() - 메뉴를 출력하고 메뉴번호를 입력받아 리턴함
전달인자: menuLIst - 메뉴출력할 문자열
menuCnt  - 메뉴개수
리턴값: 선택된메뉴번호
--------------------------------------------------------------------------------------*/
int menu(char **menuList, int menuCnt)
{
	int i;
	int menuNum = 0; /* 입력된메뉴번호저장변수*/
	int res;       /* scanf()함수의리턴값저장변수*/
	for (i = 0; i<menuCnt; i++)
	{
		printf("%d. %s\n", i + 1, menuList[i]);
	}

	while (menuNum<1 || menuNum>menuCnt)  /* 메뉴번호 범위내의 번호가 입력될때 까지 반복*/
	{
		printf("# 메뉴번호를 입력하세요 : ");
		res = scanf("%d", &menuNum);
		if (res != 1)  /* 정수가 입력되지 않았으면*/
		{
			myFlush();  /* 입력버퍼 비우기*/
			continue;
		}
	}
	return menuNum;
}
/*--------------------------------------------------------------------------------------
함수명 및 기능: myFlush() - 입력버퍼 지우기
전달인자: 없음
리턴값: 없음
--------------------------------------------------------------------------------------*/
void myFlush()
{
	while (getchar() != '\n')
	{
		;
	}
}