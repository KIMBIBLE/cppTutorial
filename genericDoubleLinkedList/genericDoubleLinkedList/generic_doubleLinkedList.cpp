#include <stdio.h>
#include <assert.h>
#include <malloc.h>
#include <string.h>
#include "generic_doublelinkedlist.h"
/*--------------------------------------------------------------------------------------
�Լ��� �� ���: create() - ��ũ�帮��Ʈ �ʱ�ȭ
��������:  lp - ��ũ�帮��Ʈ ���� ����ü�� �ּ�
���ϰ�: ����
--------------------------------------------------------------------------------------*/
void create(LinkedList * lp, size_t size)
{
	lp->head = (Node *)calloc(1, sizeof(Node) + size); //��� ��� ����
	assert(lp->head != NULL);
	lp->tail = (Node *)calloc(1, sizeof(Node) + size); //���� ��� ����
	assert(lp->tail != NULL);
	/*head node�� tail node�� ���� ��*/
	lp->head->prev = lp->head;
	lp->head->next = lp->tail;
	lp->tail->prev = lp->head;
	lp->tail->next = lp->tail;
	lp->cur = NULL; //cur�� NULL pointer�� �ʱ�ȭ
	lp->length = 0; //������ ����� ������ 0���� �ʱ�ȭ

	return;
}
/*--------------------------------------------------------------------------------------
�Լ��� �� ���: makeNode() - �� ��� ���� �Լ�
��������:  dataPtr - �� ��忡 ������ ������ ������ �ּ�
prev - �� ����� �� ����� �ּ�
next - �� ����� �� ����� �ּ�
���ϰ�: ������ ����� �ּ�
--------------------------------------------------------------------------------------*/
Node * makeNode(void *dataPtr, Node *prev, Node *next, size_t size, void(*myMemCpy)(void *, void *))
{
	Node *np;
	np = (Node *)calloc(1, sizeof(Node) + size); //���ο� ��� ����
	assert(np != NULL);
	np->prev = prev;
	np->next = next;

	//myMemCpy((char*)np+8, dataPtr) ����ǥ��
	myMemCpy(np + 1, dataPtr);
	if (prev != NULL)
		prev->next = np;
	if (next != NULL)
		next->prev = np;
	return np;
}
/*--------------------------------------------------------------------------------------
�Լ��� �� ���: appendFromHead() - ����� �ڿ� �� ��� �߰�(���� ����)
��������: lp - ��ũ�帮��Ʈ ���� ����ü�� �ּ�
dataPtr - �� ��忡 ������ ������ ������ �ּ�
���ϰ�: �߰��� ����� �ּ�
--------------------------------------------------------------------------------------*/
Node * appendFromHead(LinkedList *lp, void *dataPtr, size_t size, void(*myMemCpy)(void *, void *))
{
	lp->cur = makeNode(dataPtr, lp->head, lp->head->next, sizeof(Node) + size, myMemCpy);  //���ο� ��� ����
	assert(lp->cur != NULL);
	lp->length++; //�����Ͱ��� 1 ����

	return lp->cur;
}
/*--------------------------------------------------------------------------------------
�Լ��� �� ���: appendFromTail() - ���ϳ�� �տ� �� ��� �߰�(���� ����)
��������: lp - ��ũ�帮��Ʈ ���� ����ü�� �ּ�
dataPtr - �� ��忡 ������ ������ ������ �ּ�
���ϰ�: �߰��� ����� �ּ�
--------------------------------------------------------------------------------------*/
Node * appendFromTail(LinkedList *lp, void *dataPtr, size_t size, void(*myMemCpy)(void *, void *))
{
	lp->cur = makeNode(dataPtr, lp->tail->prev, lp->tail, sizeof(Node) + size, myMemCpy);  //���ο� ��� ����
	assert(lp->cur != NULL);
	lp->length++; //�����Ͱ��� 1 ����

	return lp->cur;
}
/*--------------------------------------------------------------------------------------
�Լ��� �� ���: display() - ����Ʈ���� ��� ������ ��� ���
��������: lp - ��ũ�帮��Ʈ ���� ����ü�� �ּ�
print - ��� �� data���� ����� ���� �����Լ��� �����ּ�
���ϰ�: ����
--------------------------------------------------------------------------------------*/
void display(LinkedList *lp, void(*print)(void *))
{
	lp->cur = lp->head->next;

	while (lp->cur != lp->tail)
	{
		print(lp->cur+1);
		lp->cur = lp->cur->next;
	}
	return;
}
/*--------------------------------------------------------------------------------------
�Լ��� �� ���: searchUnique() - ���޵� �����Ϳ� ��ġ�ϴ� ��� �˻� �Լ�
��������: lp - ��ũ�帮��Ʈ ���� ����ü�� �ּ�
dataPtr - �˻��� �����Ͱ� ����� ������ �ּ�
compare - data���� �񱳸� ���� �����Լ��� �����ּ�
���ϰ�: ã�� ����� �ּ� ����/���� �� NULL pointer ����
--------------------------------------------------------------------------------------*/
Node * searchUnique(LinkedList *lp, void *dataPtr, int(*compare)(void *, void *))
{
	lp->cur = lp->head->next;  // ù ������ ��带 ����Ű�� �ϰ�
	while (lp->cur != lp->tail) // �� �� ������ �˻�
	{
		if (compare(lp->cur + 1, dataPtr) == 0) //�����Ͱ� ������ ���� ��ġ ����
		{
			return lp->cur;
		}
		lp->cur = lp->cur->next; //��ġ�� �������� �ű�
	}
	return NULL; //�����Ͱ� ������ NULL ����
}
/*--------------------------------------------------------------------------------------
�Լ��� �� ���: searchDuplicate() - ���޵� �����Ϳ� ��ġ�ϴ� ��� ��带 ���� �˻��ϴ� �Լ�
��������: lp - ��ũ�帮��Ʈ ���� ����ü�� �ּ�
searchCnt - ã�� ����� ������ ������ ������ �ּ�
dataPtr - �˻��� �����Ͱ� ����� ������ �ּ�
compare - data���� �񱳸� ���� �����Լ��� �����ּ�
���ϰ�: ã�� ����� �ּҸ�Ϲ迭�� ���� �ּ� ����/���� �� NULL pointer ����
--------------------------------------------------------------------------------------*/
Node ** searchDuplicate(LinkedList *lp, int *searchCnt, void *dataPtr, int(*compare)(void *, void *)) // dataPtr�� ��ġ�ϴ� ����� �ּҸ� ��� �ִ� Node *�迭�� �����ּ� ����/���� �� NULL pointer ����
{
	Node **searchPtr;
	int i = 0;
	*searchCnt = 0; // ã�� ����� ������ count�� ������ 0���� �ʱ�ȭ

	lp->cur = lp->head->next;  // ù ������ ��带 ����Ű�� �ϰ�
	while (lp->cur != lp->tail) // �� �� ������ �˻�
	{
		if (compare(lp->cur + 1, dataPtr) == 0) // ã������
		{
			++*searchCnt;  // �ش� ��带 ã�� �� ���� count�� ����
		}
		lp->cur = lp->cur->next; // ��ġ�� �������� �ű�
	}

	if (*searchCnt == 0) // ã�� ��尡 �Ѱǵ� ������
		return NULL; //�����Ͱ� ������ NULL ����

	searchPtr = (Node **)calloc(*searchCnt, sizeof(Node *));

	lp->cur = lp->head->next;  // ù ������ ��带 ����Ű�� �ϰ�
	while (lp->cur != lp->tail) // �� �� ������ �˻�
	{
		if (compare(lp->cur + 1, dataPtr) == 0) // ã������
		{
			searchPtr[i] = lp->cur;  // ã�� ����� �ּҸ� �迭�� ����
			i++;
		}
		lp->cur = lp->cur->next; //��ġ�� �������� �ű�
	}
	return searchPtr;
}
/*--------------------------------------------------------------------------------------
�Լ��� �� ���: deleteNode() - ����Ʈ������ target ��� ����
��������: lp - ��ũ�帮��Ʈ ���� ����ü�� �ּ�
target - ������ ����� �����ּ�
���ϰ�: ����
--------------------------------------------------------------------------------------*/
void deleteNode(LinkedList *lp, Node *target, void (*dataFree)(void *))
{
	if (target == NULL)
		return;
	//������ �������� ��,�� ��带 �����Ŵ
	target->prev->next = target->next;
	target->next->prev = target->prev;
	dataFree(target + 1);
	free(target);       // target��� ����
	lp->length--;       // ������ ���� 1 ����
}
/*--------------------------------------------------------------------------------------
�Լ��� �� ���: destroy() - ����Ʈ������ ��� ��� ����(head, tail ��� ����)
��������: lp - ��ũ�帮��Ʈ ���� ����ü�� �ּ�
���ϰ�: ����
--------------------------------------------------------------------------------------*/
void destroy(LinkedList *lp, void(*dataFree)(void *))
{
	while (lp->head->next != lp->tail) // ������ ��尡 �ִٸ� ����
	{
		deleteNode(lp, lp->head->next, dataFree); // head ��� �ٷ� �� ��带 ����
	}
	dataFree(lp->head + 1);
	free(lp->head); // head ��� ����
	dataFree(lp->tail + 1);
	free(lp->tail); // tail ��� ����
	lp->head = lp->cur = lp->tail = NULL; //��� �����͸� NULL�� �ʱ�ȭ
	lp->length = 0; //�����Ͱ��� 0���� �ʱ�ȭ
	return;
}
/*--------------------------------------------------------------------------------------
�Լ��� �� ���: sortList() - ����Ʈ���� ��带 �����Լ��� ���ش�� �����ϴ� �Լ�
��������: lp - ��ũ�帮��Ʈ ���� ����ü�� �ּ�
compare - data���� �񱳸� ���� �����Լ��� �����ּ�
���ϰ�: ����
--------------------------------------------------------------------------------------*/
void sortList(LinkedList *lp, int(*compare)(void *, void *), void (*myMemCpy)(void *, void *), void (*dataFree)(void *))  // ��� ����
{
	Node *tp;
	Node *target;
	DataType temp;  // swap�� �ӽú��� 

	temp.name = (char *)malloc(sizeof(char) * 20);
	assert(temp.name != NULL);
	
	lp->cur = lp->head->next;  // ù ������ ��带 ����Ű�� �ϰ�
	while (lp->cur != lp->tail) // �� �� ������ �˻�
	{
		target = lp->cur;
		tp = lp->cur->next; // cur�� ���� ��带 ����Ű�� ��
		while (tp != lp->tail)
		{
			if (compare(target+1, tp+1) > 0)
			{
				target = tp;
			}
			tp = tp->next;
		}
		myMemCpy(&temp, lp->cur + 1);
		myMemCpy(lp->cur + 1, target + 1);
		myMemCpy(target + 1, &temp);

		lp->cur = lp->cur->next;
	}
	return;
}
