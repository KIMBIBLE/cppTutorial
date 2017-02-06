#include <stdio.h>
#include "person.h"

void *find(void *begin, void *end, void *value, size_t size, int(*compareData)(void *, void *));

int main()
{
	Person source[] = { {"����", 10, "01011112222"},
					{"������", 11, "01022223333"},
					{"������", 12, "01033334444"},
					{"�ڹڹ�", 13, "01011112223"} };

	int *ip = NULL;
	char *cp = NULL;
	int aryLen;

	/*	test value for more test!!	*/
	int testAge = 13;
	char *testName = "�ڹڹ�";
	/////////////////////////////////////

	aryLen = sizeof(source) / sizeof(source[0]);

	ip = (int *)find(source, source + aryLen, &testAge, sizeof(Person), compareAge);
	if (ip == (int *)(source + aryLen))
		printf("cannot find...\n");
	else
		printf("find data = %d\n", ((Person*)ip)->age);
	
	cp = (char *)find(source, source + aryLen, testName, sizeof(Person), compareName);
	if(cp == (char *)(source + aryLen))
		printf("cannot find...\n");
	else
		printf("find data = %s\n", ((Person*)cp)->name);

	return 0;
}

void *find(void *begin, void *end, void *value, size_t size, int(*compareData)(void *, void *))
{
	while (begin != end)
	{
		//find success
		if (compareData(begin, value) == 0)
			return begin;

		// move next
		begin = (char *)begin + size;
	}

	// find failure
	return begin;
}
