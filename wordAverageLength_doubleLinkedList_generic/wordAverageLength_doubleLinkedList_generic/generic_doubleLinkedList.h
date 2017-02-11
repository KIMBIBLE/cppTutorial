#pragma once
#pragma warning(disable:4996) /* VS2005 �̻󿡼� �߻��ϴ� �ܼ� �Լ� ��� ���� */
#include "word.h"

typedef struct _node Node;    // ����ü ��� ����������

struct _node {         // �����͸� ������ ���(�ڱ����� ����ü)
	Node *prev;               // �� ��带 ����Ű�� ���
	Node *next;               // �� ��带 ����Ű�� ���
};
// ������ ������ ������ ��� �ÿ� ���� �޸� �Ҵ�޾� ���

typedef struct _linkedList {   // ����Ʈ ���� ����ü
	Node *head;               // ��������� (����� ����Ŵ)
	Node *cur;                // Ư�� �۾� �� ��带 ����Ű�� ���� ������
	Node *tail;               // ���������� (���ϳ�� ����Ŵ)
	int length;               // ���� �����ͳ���� ����
}LinkedList;

//-------------------------------------------------------------------------------------------
//                                 ��ũ�帮��Ʈ ���� �Լ� 
//-------------------------------------------------------------------------------------------
void create(LinkedList * lp, size_t size);   // ��ũ�帮��Ʈ �ʱ�ȭ
Node * makeNode(void *dataPtr, Node *prev, Node *next, size_t size, void(*myMemCpy)(void *, void *));
Node * appendFromHead(LinkedList *lp, void *dataPtr, size_t size, void(*myMemCpy)(void *, void *));      // ����� �ڿ� �� ��� �߰�(���� ����)
Node * appendFromTail(LinkedList *lp, void *dataPtr, size_t size, void(*myMemCpy)(void *, void *));      // ���ϳ�� �տ� �� ��� �߰�(���� ����)
void display(LinkedList *lp, void(*print)(void *, int num));       // ����Ʈ���� ��� ������ ��� ���
void deleteNode(LinkedList *lp, Node *target, void(*dataFree)(void *));                // target��� ����
Node * searchUnique(LinkedList *lp, void *dataPtr, int(*compare)(void *, void *)); // dataPtr�� ��ġ�ϴ� ����� �ּ� ����/���� �� NULL pointer ����
Node ** searchDuplicate(LinkedList *lp, int *searchCnt, void *dataPtr, int(*compare)(void *, void *)); // dataPtr�� ��ġ�ϴ� ����� �ּҸ� ��� �ִ� Node *�迭�� �����ּ� ����/���� �� NULL pointer ����
void sortList(LinkedList *lp, int(*compare)(void *, void *), void(*myMemCpy)(void *, void *), void(*dataFree)(void *));  // ��� ����
void destroy(LinkedList *lp, void(*dataFree)(void *));                                   // ����Ʈ���� ��� ��带 ����