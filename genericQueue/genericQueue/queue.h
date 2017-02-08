#pragma once 
#pragma warning(disable:4996)
#include "datatype.h"
enum { FALSE, TRUE };

#define QUEUE_SIZE 5
#define BUF_SIZE 100

typedef struct _queue {
	void *queue;
	int qSize;
	int front, rear;
}Queue;

void initQueue(Queue * qPtr, int qSize, int dataSize); // ť ���� �� �ʱ�ȭ �Լ�
int enqueue(Queue * qPtr, void *inData, int dataSize, void (*dataCpy)(void *, void *));   // ť�� ������ �ϳ��� ������
int dequeue(Queue * qPtr, void *getData, int dataSize, void(*dataCpy)(void *, void *), void (*memFree)(void *));  // ť���� ������ �ϳ��� ����
void printQueue(const Queue * qPtr, int dataSize, void(*print)(void *));  // ť ���� ��� �����͸� ���(dequeue�ϴ� ���� �ƴ�)
void destroyQueue(Queue * qPtr, int dataSize, void (*memFree)(void *));  // ť �Ҹ� �Լ�
int isQueueEmpty(const Queue *qPtr); // ť�� ������ ����ִ°� �˻�
int isQueueFull(const Queue *qPtr); // ť�� �����ִ°� �˻�
