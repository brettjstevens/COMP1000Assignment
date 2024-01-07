/* Author: Brett Stevens
File name: tictactoe.c
Purpose: to act as main funtion for program
Last modified: 23/10/19
*/
#include <stdio.h>

#include "fileReader.h"
#include "UI.h"

int main(int argc, char* argv[])
{
	int m, n, k;
	LinkedList* list;
	
	readFile(&m, &n, &k, argv[1]);
	
	if((m <= 0) || (n <= 0) || (k <= 0))		/*additional error checking*/
	{
		printf("SHUTTING DOWN....\n");
	}
	else
	{
		list = createLinkedList();				/*creates linkedlist to store logs*/
		menu(&m, &n, &k, list);
	}
	
	freeLinkedList(list, freeLog);
	printf("\nBye.\n");
	
	return 0;
}