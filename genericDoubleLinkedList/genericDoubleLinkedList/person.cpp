#include "person.h"

void personMemCpy(void *p1, void *p2)
{
	int len;

	if (((Person*)p2)->name != NULL)
	{
		if (((Person*)p1)->name != NULL)
			free(((Person*)p1)->name);	// dest 해지

		// 재할당
		len = strlen(((Person*)p2)->name) + 1;
		((Person*)p1)->name = (char *)malloc(sizeof(char) * len);
		strcpy(((Person*)p1)->name, ((Person*)p2)->name);
	}

	// 값 복사
	((Person*)p1)->age = ((Person*)p2)->age;
	strcpy(((Person*)p1)->phoneNumber, ((Person*)p2)->phoneNumber);
}

void personClear(void *p)
{
	if (((Person*)p)->name != NULL) {
		memset(((Person*)p)->name, 0, strlen(((Person*)p)->name));
		free(((Person*)p)->name);
		((Person*)p)->name = NULL;
	}
	((Person*)p)->age = 0;
	memset(((Person*)p)->phoneNumber, 0, sizeof(((Person*)p)->phoneNumber));

	return;
}

void personPrint(void *p)
{
	printf("이름 : %s\n", ((Person *)p)->name);
	printf("나이 : %d\n", ((Person *)p)->age);
	printf("전화번호 : %s\n", ((Person *)p)->phoneNumber);
	puts("");
}

int personNameCompare(void *p1, void *p2)
{
	return (strcmp(((Person *)p1)->name, ((Person *)p2)->name));  // strcmp()함수의 리턴값을 바로 리턴
}

int personAgeCompare(void *p1, void *p2)
{
	if (((Person *)p1)->age > ((Person *)p2)->age) return 1;
	else if (((Person *)p1)->age == ((Person *)p2)->age) return 0;
	else return -1;
}


int personCompare(void *p1, void *p2)
{
	if (personNameCompare(p1, p2))
		return -1;
	if (personAgeCompare(p1, p2))
		return -1;

	return 0;
}