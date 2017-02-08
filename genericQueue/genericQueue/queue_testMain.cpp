#include "queue.h" 
#include <stdio.h> 
#include <string.h>
int menu(char **, int);
void myFlush();
void input(Queue *);
void myDelete(Queue *);
//--------------------------------------------------------------------------------
//   main() 
//--------------------------------------------------------------------------------
int main()
{
	Queue que; /* 큐생성*/
	char *menuList[] = { "입력하기", "삭제하기", "출력하기", "종료" }; /* 메뉴리스트*/
	int menuCnt; /* 메뉴개수 저장 변수*/
	int menuNum; /* 메뉴번호 저장 변수*/

	initQueue(&que, QUEUE_SIZE, sizeof(Person)); /* 크기가 5인 큐 생성 및 초기화*/

	menuCnt = sizeof(menuList) / sizeof(menuList[0]); /* 메뉴 개수 계산 하기*/
	while (1)
	{
		menuNum = menu(menuList, menuCnt);
		if (menuNum == menuCnt) /* 종료메뉴 선택 시 반복문 탈출 하기*/
		{
			break;
		}
		switch (menuNum)
		{
		case 1: input(&que); break;
		case 2: myDelete(&que); break;
		case 3: printQueue(&que, sizeof(Person), personPrint); /* queue내의 모든 데이터 출력 하기*/
		}
	}
	destroyQueue(&que, sizeof(Person), personFree);
	return 0;
}
/*--------------------------------------------------------------------------------------------------------
함수명및기능: input() - 큐에 데이터를 반복적으로 입력 함
전달인자: qPtr - 큐의 주소
리턴값: 없음
----------------------------------------------------------------------------------------------------------*/
void input(Queue *qPtr)
{
	Person data;
	char buf[BUF_SIZE];

	while (1) {
		printf("# 이름을 입력하세요(엔터 입력시 종료) : ");
		myFlush();
		fgets(buf, BUF_SIZE, stdin);
		if (buf[0] == '\n')
			break;
		buf[strlen(buf) - 1] = NULL;

		data.name = (char *)calloc(1, strlen(buf) + 1);
		strcpy(data.name, buf);

		printf("# 나이을 입력하세요 : ");
		scanf("%d", &data.age);

		printf("# 전화번호를 입력하세요 : ");
		scanf("%s", data.phoneNumber);

		if (!enqueue(qPtr, &data, sizeof(Person), personMemCpy))
			printf("put(enqueue) 실패!!\n");

		free(data.name);
	}
}
/*------------------------------------------------------------------------------------------------------------
함수명 및 기능: myDelete() - 큐에 데이터를 반복적으로 꺼냄
전달인자: qPtr - 큐의 주소
리턴값: 없음
------------------------------------------------------------------------------------------------------------*/
void myDelete(Queue *qPtr)
{
	int i;
	int cnt; /* get할 횟수를 입력 받아 저장할 변수*/
	Person getData = { NULL, 0, ""}; /* get한 데이터를 저장할 변수*/
	int res; /* get()함수의 리턴값을 저장할 변수*/
	printf("Queue에서 데이터를 get할 회수를 입력하시오: ");
	scanf("%d", &cnt);
	for (i = 0; i<cnt; i++) {
		res = dequeue(qPtr, &getData, sizeof(Person), personMemCpy, personFree);
		if (res == 1) /* 성공적으로 get 작업을 수행 했으면*/
		{
			personPrint(&getData);
		}
		else
			printf("get(dequeue) 실패!\n");
	}
}
/*------------------------------------------------------------------------------------------------------------
함수명 및 기능: menu() - 메뉴를 출력하고 메뉴번호를 입력 받아 리턴 함
전달인자: menuLIst - 메뉴 출력할 문자열
menuCnt - 메뉴 개수
리턴값: 선택된 메뉴번호
------------------------------------------------------------------------------------------------------------*/
int menu(char **menuList, int menuCnt)
{
	int i;
	int menuNum = 0; /* 입력된 메뉴번호 저장 변수*/
	int res; /* scanf()함수의 리턴값 저장 변수*/
	for (i = 0; i<menuCnt; i++)
	{
		printf("%d. %s\n", i + 1, menuList[i]);
	}
	while (menuNum<1 || menuNum>menuCnt) /* 메뉴번호 범위의 번호가 입력시 까지 반복*/
	{
		printf("# 메뉴번호를 입력하세요 : ");
		res = scanf("%d", &menuNum);
		if (res != 1) /* 정수가 입력되지 않았으면*/
		{
			myFlush(); /* 입력버퍼 비우기*/
			continue;
		}
	}
	return menuNum;
}

/*------------------------------------------------------------------------------------------------------------
함수명 및 기능: myFlush() - 입력버퍼 지우기
전달인자: 없음
리턴값: 없음
------------------------------------------------------------------------------------------------------------*/
void myFlush()
{
	while (getchar() != '\n')
	{
		;
	}
}
