#include <stdio.h>
#include "doubleLinkedList.h"

void rewindCurp(LinkedList *lp);
void pageUp(LinkedList *lp);
void pageDown(LinkedList *lp);
int menu();
void displayPage(LinkedList *lp, void(*print)(DataType *));
FILE* fileOpen(char *fileName, char *mode);
void dataFileLoad(LinkedList *lp);
