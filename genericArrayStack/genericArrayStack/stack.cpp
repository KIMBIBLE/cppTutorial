#include "stack.h"
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <assert.h>
/*--------------------------------------------------------------------------------------
�Լ���ױ��: initStack() - ������ ũ���� ������ �����ϴ� �Լ�
��������: sPtr -  ������ �ּ�
sSize - ������ ũ��
���ϰ�: ����
--------------------------------------------------------------------------------------*/
void initStack(Stack *sPtr, size_t sSize, size_t dataSize)
{
	sPtr->stack = (void *)calloc(sSize, dataSize);  // �޸� �Ҵ� & 0���� �ʱ�ȭ
	assert(sPtr->stack != NULL);
	sPtr->sSize = sSize;
	sPtr->top = 0;
}
/*--------------------------------------------------------------------------------------
�Լ���ױ��: clearStack() - ���� �ʱ�ȭ �Լ�(��� ������ ���� ����)
��������: sPtr - ������ �ּ�
���ϰ�: ����
--------------------------------------------------------------------------------------*/
void clearStack(Stack *sPtr, size_t sSize, size_t dataSize)
{
	while (sPtr->top != 0)
	{
		memset((char *)sPtr->stack + sPtr->top * dataSize, 0, dataSize);
		sPtr->top--;
		//memset(&sPtr->(char *)stack[--sPtr->top], 0, dataSize);
	}
}
/*--------------------------------------------------------------------------------------
�Լ���ױ��: push() - ���ÿ� ������ �ϳ��� ������
��������: sPtr - ������ �ּ�
inData - ���ÿ� ������ ������
���ϰ�: ���������� �����ϸ�1, �����ϸ�0 ����
--------------------------------------------------------------------------------------*/
int push(Stack *sPtr, void *pushData, size_t dataSize, void(*memCpy)(void *, void *))/* stack�� ������ �����ϱ� */
{
	if (isStackFull(sPtr))  /* stack�� �� �������� */
		return 0;
	memCpy((char *)sPtr->stack + sPtr->top++ * dataSize, pushData);
	//sPtr->stack[sPtr->top++] = inData;
	//personPrint((char *)sPtr->stack + sPtr->top++ * dataSize);
	return 1;
}
/*--------------------------------------------------------------------------------------
�Լ���ױ��: pop() - ���ÿ��� ������ �ϳ��� ����
��������: sPtr - ������ �ּ�
popData -  ���� �����͸� ������ �������� �ּ�
���ϰ�: ���������� ������1, �����ϸ�0 ����
--------------------------------------------------------------------------------------*/
int pop(Stack *sPtr, void *popData, size_t dataSize, void(*memCpy)(void *, void *), void(*memFree)(void *))
{
	if (isStackEmpty(sPtr))  /* stack�� ��������� */
		return 0;

	memCpy(popData, (char *)sPtr->stack + (sPtr->top - 1) * dataSize);
	//*popData = sPtr->stack[--sPtr->top];
	memFree((char *)sPtr->stack + (sPtr->top - 1) * dataSize);
	--sPtr->top;

	return 1;
}
/*--------------------------------------------------------------------------------------
�Լ���ױ��: printStack() - ������ ��� �����͸� ��� ��
��������: sPtr -  ������ �ּ�
���ϰ�: ����
--------------------------------------------------------------------------------------*/
void printStack(const Stack* sPtr, size_t dataSIze, void(*print)(void *))
{
	int i = sPtr->top;
	while (i != 0)
	{
		print((char *)sPtr->stack + --i * dataSIze);
	}
	printf("\n");
}
/*--------------------------------------------------------------------------------------
�Լ���ױ��: destroyStack() -  ���� �Ҹ� �Լ�
��������: sPtr -  ������ �ּ�
���ϰ�: ����
--------------------------------------------------------------------------------------*/
void destroyStack(Stack *sPtr, size_t dataSIze, void(*memFree)(void *))
{
	void *delPos = (char *)sPtr->stack + (sPtr->top - 1) * dataSIze;

	for (int i = 0; i < sPtr->sSize; i++)
	{
		memFree(delPos);
		delPos = (char *)delPos - dataSIze;
	}

	free(sPtr->stack);
	sPtr->stack = NULL;
	sPtr->sSize = 0;
	sPtr->top = 0;
}
/*-----------------------------------------------------------------------------------
�Լ��� �� ��� : isStackFull() - ������ �� ���ִ��� �˻�
�������� : sPtr - ������ �ּ�
���ϰ� : ������ �� �������� 1, �ƴϸ� 0 ����
-----------------------------------------------------------------------------------*/
int isStackFull(Stack *sPtr)
{
	if (sPtr->top == sPtr->sSize)  /* stack�� �� �������� */
		return 1;
	else
		return 0;
}
/*-----------------------------------------------------------------------------------
�Լ��� �� ��� : isStackEmpty() - ������ ����ִ��� �˻�
�������� : sPtr - ������ �ּ�
���ϰ� : ������ ��������� 1, �ƴϸ� 0 ����
-----------------------------------------------------------------------------------*/
int isStackEmpty(Stack *sPtr)
{
	if (sPtr->top == 0)  /* stack�� ��������� */
		return 1;
	else
		return 0;
}

