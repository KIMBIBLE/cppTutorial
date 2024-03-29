#pragma once
#pragma warning(disable:4996) /* VS2005 이상에서 발생하는 콘솔 함수 경고 제거 */
#include "word.h"

typedef struct _node Node;    // 구조체 노드 형명재지정

struct _node {         // 데이터를 보관할 노드(자기참조 구조체)
	Node *prev;               // 앞 노드를 가리키는 멤버
	Node *next;               // 뒷 노드를 가리키는 멤버
};
// 생략된 데이터 영역은 사용 시에 동적 메모리 할당받아 사용

typedef struct _linkedList {   // 리스트 관리 구조체
	Node *head;               // 헤드포인터 (헤드노드 가리킴)
	Node *cur;                // 특정 작업 시 노드를 가리키기 위한 포인터
	Node *tail;               // 테일포인터 (테일노드 가리킴)
	int length;               // 실제 데이터노드의 갯수
}LinkedList;

//-------------------------------------------------------------------------------------------
//                                 링크드리스트 관리 함수 
//-------------------------------------------------------------------------------------------
void create(LinkedList * lp, size_t size);   // 링크드리스트 초기화
Node * makeNode(void *dataPtr, Node *prev, Node *next, size_t size, void(*myMemCpy)(void *, void *));
Node * appendFromHead(LinkedList *lp, void *dataPtr, size_t size, void(*myMemCpy)(void *, void *));      // 헤드노드 뒤에 새 노드 추가(역순 저장)
Node * appendFromTail(LinkedList *lp, void *dataPtr, size_t size, void(*myMemCpy)(void *, void *));      // 테일노드 앞에 새 노드 추가(정순 저장)
void display(LinkedList *lp, void(*print)(void *, int num));       // 리스트내의 모드 데이터 노드 출력
void deleteNode(LinkedList *lp, Node *target, void(*dataFree)(void *));                // target노드 삭제
Node * searchUnique(LinkedList *lp, void *dataPtr, int(*compare)(void *, void *)); // dataPtr과 일치하는 노드의 주소 리턴/없을 시 NULL pointer 리턴
Node ** searchDuplicate(LinkedList *lp, int *searchCnt, void *dataPtr, int(*compare)(void *, void *)); // dataPtr과 일치하는 노드의 주소를 담고 있는 Node *배열의 시작주소 리턴/없을 시 NULL pointer 리턴
void sortList(LinkedList *lp, int(*compare)(void *, void *), void(*myMemCpy)(void *, void *), void(*dataFree)(void *));  // 노드 정렬
void destroy(LinkedList *lp, void(*dataFree)(void *));                                   // 리스트내의 모든 노드를 삭제