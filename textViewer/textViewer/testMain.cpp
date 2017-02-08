#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include "doubleLinkedList.h"
#include "dataType.h"
#include "textViewer.h"

int main()
{
	LinkedList pageList;
	char menuRes;

	/*
	for (int i = 0; i < 24; i++)
		for (int j = 1; j <= 80; j++)
			printf("%c", 'A' + i);
	*/
	create(&pageList);
	dataFileLoad(&pageList);
	pageList.cur = pageList.head->next;
	//display(&pageList, printLine);
	while (1)
	{
		displayPage(&pageList, printLine);
		menuRes = menu();
		
		if (menuRes == 'e')
			break;
		else if (menuRes == 'w')
			pageUp(&pageList);
		else if (menuRes == 's')
			pageDown(&pageList);
		else;

		system("cls");
	}

	
	
	//getch();
	system("cls");
	//getch();

	destroy(&pageList);
	return 0;
}
