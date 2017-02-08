#include "stack.h"
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <assert.h>
/*--------------------------------------------------------------------------------------
함수명및기능: initStack() - 지정된 크기의 스택을 생성하는 함수
전달인자: sPtr -  스택의 주소
sSize - 스택의 크기
리턴값: 없음
--------------------------------------------------------------------------------------*/
void initStack(Stack *sPtr, size_t sSize, size_t dataSize)
{
	sPtr->stack = (void *)calloc(sSize, dataSize);  // 메모리 할당 & 0으로 초기화
	assert(sPtr->stack != NULL);
	sPtr->sSize = sSize;
	sPtr->top = 0;
}
/*--------------------------------------------------------------------------------------
함수명및기능: clearStack() - 스택 초기화 함수(모든 데이터 삭제 개념)
전달인자: sPtr - 스택의 주소
리턴값: 없음
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
함수명및기능: push() - 스택에 데이터 하나를 저장함
전달인자: sPtr - 스택의 주소
inData - 스택에 저장할 데이터
리턴값: 성공적으로 저장하면1, 실패하면0 리턴
--------------------------------------------------------------------------------------*/
int push(Stack *sPtr, void *pushData, size_t dataSize, void(*memCpy)(void *, void *))/* stack에 데이터 저장하기 */
{
	if (isStackFull(sPtr))  /* stack이 꽉 차있으면 */
		return 0;
	memCpy((char *)sPtr->stack + sPtr->top++ * dataSize, pushData);
	//sPtr->stack[sPtr->top++] = inData;
	//personPrint((char *)sPtr->stack + sPtr->top++ * dataSize);
	return 1;
}
/*--------------------------------------------------------------------------------------
함수명및기능: pop() - 스택에서 데이터 하나를 꺼냄
전달인자: sPtr - 스택의 주소
popData -  꺼낸 데이터를 저장할 기억공간의 주소
리턴값: 성공적으로 꺼내면1, 실패하면0 리턴
--------------------------------------------------------------------------------------*/
int pop(Stack *sPtr, void *popData, size_t dataSize, void(*memCpy)(void *, void *), void(*memFree)(void *))
{
	if (isStackEmpty(sPtr))  /* stack이 비어있으면 */
		return 0;

	memCpy(popData, (char *)sPtr->stack + (sPtr->top - 1) * dataSize);
	//*popData = sPtr->stack[--sPtr->top];
	memFree((char *)sPtr->stack + (sPtr->top - 1) * dataSize);
	--sPtr->top;

	return 1;
}
/*--------------------------------------------------------------------------------------
함수명및기능: printStack() - 스택의 모든 데이터를 출력 함
전달인자: sPtr -  스택의 주소
리턴값: 없음
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
함수명및기능: destroyStack() -  스택 소멸 함수
전달인자: sPtr -  스택의 주소
리턴값: 없음
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
함수명 및 기능 : isStackFull() - 스택이 꽉 차있는지 검사
전달인자 : sPtr - 스택의 주소
리턴값 : 스택이 꽉 차있으면 1, 아니면 0 리턴
-----------------------------------------------------------------------------------*/
int isStackFull(Stack *sPtr)
{
	if (sPtr->top == sPtr->sSize)  /* stack이 꽉 차있으면 */
		return 1;
	else
		return 0;
}
/*-----------------------------------------------------------------------------------
함수명 및 기능 : isStackEmpty() - 스택이 비어있는지 검사
전달인자 : sPtr - 스택의 주소
리턴값 : 스택이 비어있으면 1, 아니면 0 리턴
-----------------------------------------------------------------------------------*/
int isStackEmpty(Stack *sPtr)
{
	if (sPtr->top == 0)  /* stack이 비어있으면 */
		return 1;
	else
		return 0;
}

