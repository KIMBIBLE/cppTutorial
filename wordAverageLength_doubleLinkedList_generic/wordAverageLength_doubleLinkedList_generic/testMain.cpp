#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <malloc.h>
#include "generic_doublelinkedlist.h"

#define BUFFER_SIZE 1000
#define NEWL puts("")

char *inputFileName(const char *message);
FILE *openFile(const char *fileName, const char *mode);
void closeFile(FILE *fp, char *fileName);
void fileToList(LinkedList *lp, FILE *fp);
void flush();
int getAverage(LinkedList *lp);
void displayResult(LinkedList *lp, int average);

int main()
{
	FILE *fp = NULL;
	char *fileName = NULL;
	LinkedList wordList;
	int average = 0;

	fileName = inputFileName("파일명을 입력 : ");
	fp = openFile(fileName, "rt");

	create(&wordList, sizeof(Word));	
	fileToList(&wordList, fp);
	average = getAverage(&wordList);
	display(&wordList, wordPrint);
	NEWL;
	displayResult(&wordList, average);

	destroy(&wordList, wordFree);
	closeFile(fp, fileName);

	return 0;
}



char *inputFileName(const char *message)
{
	char *fileName;
	char buf[BUFFER_SIZE];
	printf("%s", message);

	scanf("%s", buf);
	flush();

	fileName = (char *)malloc(strlen(buf) + 1);
	assert(fileName != NULL);
	strncpy(fileName, buf, strlen(buf) +1);

	return fileName;
}

FILE* openFile(const char *fileName, const char *mode)
{
	FILE *fp;
	fp = fopen(fileName, mode);
	assert(fp != NULL);

	return fp;
}

void closeFile(FILE *fp, char *fileName)
{
	fclose(fp);
	free(fileName);
}

void fileToList(LinkedList *lp, FILE *fp)
{
	Word inData;
	Node *resp;

	char buf[BUFFER_SIZE] = { NULL, };
	while (fscanf(fp, " %s ", buf) != EOF)
	{
		inData.wp = (char *)malloc(strlen(buf) + 1);
		strcpy(inData.wp, buf);
		inData.length = strlen(buf);

		if ((resp = searchUnique(lp, &inData, wordCompare)) == NULL)
			appendFromTail(lp, &inData, sizeof(Word), wordMemCpy);
	}
}

void flush()
{
	if(getchar() != '\n')
		while (getchar() != '\n') { ; }
}


int getAverage(LinkedList *lp)
{
	int sum = 0;

	lp->cur = lp->head->next;

	while (lp->cur != lp->tail)
	{
		sum += ((Word *)(lp->cur + 1))->length;
		lp->cur = lp->cur->next;
	}

	return sum / lp->length;
}

void displayResult(LinkedList *lp, int average)
{
	printf("전체 단어의 개수 : %4d\t\t평균 단어의 길이 : %4d\n", 
		lp->length, average);
}