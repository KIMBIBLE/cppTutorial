#include <stdio.h> 
#include <malloc.h> 
#include <assert.h> 
#include "queue.h" 

/*--------------------------------------------------------------------------------------
�Լ���ױ�� : initQueue() - ť �ʱ�ȭ �Լ�
�������� : qPtr - ť ����ü�� �ּ�
size - ť�� ũ��
���ϰ� : ����
--------------------------------------------------------------------------------------*/
void initQueue(Queue * qPtr, int qSize, int dataSize)
{
	qPtr->qSize = qSize;
	qPtr->front = 0;
	qPtr->rear = 0;
	qPtr->queue = (void *)calloc(qPtr->qSize, dataSize);
}
/*--------------------------------------------------------------------------------------
�Լ���ױ�� : enqueue() - ť�� ������ �ϳ��� ������
�������� : qPtr - ť ����ü�� �ּ�
inData - ť�� ������ ������
���ϰ� : ���������� �����ϸ� TRUE, �����ϸ� FALSE ����
--------------------------------------------------------------------------------------*/
int enqueue(Queue * qPtr, void *inData, int dataSize, void(*dataCpy)(void *, void *))
{
	if (isQueueFull(qPtr)) // queue�� ���������� enqueue �Ұ� 
	{
		return FALSE;
	}

	dataCpy((char *)qPtr->queue + qPtr->rear * dataSize, inData);
	//qPtr->queue[qPtr->rear] = inData;
	qPtr->rear = (qPtr->rear + 1) % qPtr->qSize;
	return TRUE;

}
/*--------------------------------------------------------------------------------------
�Լ��� �� ��� : dequeue() - ť���� ������ �ϳ��� ����
�������� : qPtr - ť ����ü�� �ּ�
getData - ���� �����͸� ������ �������� �ּ�
���ϰ� : ���������� ������ TRUE, �����ϸ� FALSE ����
--------------------------------------------------------------------------------------*/
int dequeue(Queue * qPtr, void *getData, int dataSize, void(*dataCpy)(void *, void *), void(*memFree)(void *))
{
	if (isQueueEmpty(qPtr)) // ť�� ��������� dequeue �Ұ� 
	{
		return FALSE;
	}

	dataCpy(getData, (char *)qPtr->queue + qPtr->front * dataSize);
	//*getData = qPtr->queue[qPtr->front];
	memFree((char *)qPtr->queue + qPtr->front * dataSize);
	qPtr->front = (qPtr->front + 1) % qPtr->qSize;

	return TRUE;
}
/*--------------------------------------------------------------------------------------
�Լ���ױ�� : printQueue() - ť ���� ��� �����͸� ��� ��
�������� : qPtr - ť ����ü�� �ּ�
print -  DataType�� ������ ����ϴ� ��� ���� �Լ�
���ϰ� : ����
--------------------------------------------------------------------------------------*/
void printQueue(const Queue * qPtr, int dataSize, void(*print)(void *))
{
	if (isQueueEmpty(qPtr) == TRUE)
	{
		printf("Queue�� ����ֽ��ϴ�!!\n");
		return;
	}
	for (int i = qPtr->front; i != qPtr->rear; i = (i + 1) % qPtr->qSize)
	{
		print((char *)qPtr->queue + i *dataSize);
		//print(&qPtr->queue[i]);
	}
	printf("\n");
}
/*--------------------------------------------------------------------------------------
�Լ���ױ�� : destroyQueue() - ť �Ҹ� �Լ�
�������� : qPtr - ť ����ü�� �ּ�
���ϰ� : ����
--------------------------------------------------------------------------------------*/
void destroyQueue(Queue * qPtr, int dataSize, void(*memFree)(void *))
{
	for (int i = qPtr->front; i != qPtr->rear; i = (i + 1) % qPtr->qSize)
		memFree((char *)qPtr->queue + i * dataSize);

	qPtr->qSize = 0;
	free(qPtr->queue);
	qPtr->queue = NULL;
}
/*--------------------------------------------------------------------------------------
�Լ��� �� ���: isQueueEmpty() - ť�� ����ִ°� �˻�
��������: qPtr - ť ����ü�� �ּ�
���ϰ�: ������ ��������� TRUE ����, ������� ������ FALSE ����
--------------------------------------------------------------------------------------*/
int isQueueEmpty(const Queue *qPtr)
{
	if (qPtr->front == qPtr->rear)
		return TRUE;
	else
		return FALSE;
}
/*--------------------------------------------------------------------------------------
�Լ��� �� ���: isQueueFull() - ť�� �����ִ°� �˻�
��������: qPtr - ť ����ü�� �ּ�
���ϰ�: ���� ������ TRUE ����, �ƴϸ� FALSE ����
--------------------------------------------------------------------------------------*/
int isQueueFull(const Queue *qPtr)
{
	if (qPtr->front == (qPtr->rear + 1) % qPtr->qSize)
		return TRUE;
	else
		return FALSE;
}