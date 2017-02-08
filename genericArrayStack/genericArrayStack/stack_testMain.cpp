#include "stack.h"
#include <stdio.h>

int menu(char **, int);
void myFlush();
void input(Stack *);
void myDelete(Stack *);

int main()
{
	Stack stk;   /* ���û���*/
	char *menuList[] = { "�Է��ϱ�", "�����ϱ�", "����ϱ�", "����" }; /* �޴� ����Ʈ*/
	int menuCnt;   /* �޴����� ���庯��*/
	int menuNum;   /* �޴���ȣ ���庯��*/

	initStack(&stk, 5, sizeof(Person)); /* ���� �ʱ�ȭ*/
	menuCnt = sizeof(menuList) / sizeof(menuList[0]);  /* �޴� ���� ����ϱ�*/

	while (1)
	{
		menuNum = menu(menuList, menuCnt);
		if (menuNum == menuCnt)  /* ����޴� ���� �� �ݺ��� Ż���ϱ�*/
		{
			break;
		}
		switch (menuNum)
		{
		case 1: input(&stk);  break;
		case 2: myDelete(&stk); break;
		case 3: printStack(&stk, sizeof(Person), personPrint); /* stack���� ��� ������ ����ϱ�*/
		}
	}
	destroyStack(&stk, sizeof(Person), personFree);
	return 0;
}
/*--------------------------------------------------------------------------------------
�Լ���ױ��: input() - ���ÿ� �����͸� �ݺ������� �Է���
��������: sPtr - ������ �ּ�
���ϰ�: ����
--------------------------------------------------------------------------------------*/
void input(Stack *sPtr)
{
	Person data;
	char buf[BUF_SIZE];

	while (1) {
		printf("# �̸��� �Է��ϼ���(�� �Է½� ����) : ");
		scanf("%s", buf);
		if (strcmp(buf, "��") == 0) // "��"�Է½� ����
			break;

		data.name = (char *)calloc(1, strlen(buf) + 1);
		strcpy(data.name, buf);

		printf("# ������ �Է��ϼ��� : ");
		scanf("%d", &data.age);

		printf("# ��ȭ��ȣ�� �Է��ϼ��� : ");
		scanf("%s", data.phoneNumber);

		if (push(sPtr, &data, sizeof(Person), personMemCpy) != 1)
			printf("push ����!\n");
		free(data.name);
	}
}
/*--------------------------------------------------------------------------------------
�Լ���ױ��: myDelete() - ������ �����͸� �ݺ������� ����
��������: sPtr - ������ �ּ�
���ϰ�: ����
--------------------------------------------------------------------------------------*/
void myDelete(Stack *sPtr)
{
	int i;
	int cnt;  /* pop�� Ƚ���� �Է¹޾� ������ ����*/
	Person popData = { NULL, 0, ""}; /* pop�� �����͸� ������ ����*/
	int res;     /* pop()�Լ��� ���ϰ��� ������ ����*/

	printf("Stack���� �����͸� pop��ȸ�����Է��Ͻÿ�: ");
	scanf("%d", &cnt);
	for (i = 0; i<cnt; i++) {
		res = pop(sPtr, &popData, sizeof(Person), personMemCpy, personFree);
		if (res == 1)  /* ���������� pop �۾�������������*/
		{
			personPrint(&popData);
		}
		else
			personPrint(&popData);
	}
}
/*--------------------------------------------------------------------------------------
�Լ���ױ��: menu() - �޴��� ����ϰ� �޴���ȣ�� �Է¹޾� ������
��������: menuLIst - �޴������ ���ڿ�
menuCnt  - �޴�����
���ϰ�: ���õȸ޴���ȣ
--------------------------------------------------------------------------------------*/
int menu(char **menuList, int menuCnt)
{
	int i;
	int menuNum = 0; /* �Էµȸ޴���ȣ���庯��*/
	int res;       /* scanf()�Լ��Ǹ��ϰ����庯��*/
	for (i = 0; i<menuCnt; i++)
	{
		printf("%d. %s\n", i + 1, menuList[i]);
	}

	while (menuNum<1 || menuNum>menuCnt)  /* �޴���ȣ �������� ��ȣ�� �Էµɶ� ���� �ݺ�*/
	{
		printf("# �޴���ȣ�� �Է��ϼ��� : ");
		res = scanf("%d", &menuNum);
		if (res != 1)  /* ������ �Էµ��� �ʾ�����*/
		{
			myFlush();  /* �Է¹��� ����*/
			continue;
		}
	}
	return menuNum;
}
/*--------------------------------------------------------------------------------------
�Լ��� �� ���: myFlush() - �Է¹��� �����
��������: ����
���ϰ�: ����
--------------------------------------------------------------------------------------*/
void myFlush()
{
	while (getchar() != '\n')
	{
		;
	}
}