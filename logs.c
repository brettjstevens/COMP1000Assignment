/* Author: Brett Stevens
File name: logs.c
Purpose: handles logs, saving/printing
Last modified: 23/10/19
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "logs.h"

/* Function: addLog
Purpose: to add a new log struct to the linkedlist; is called in UI.c
*/
void addLog(char player, char** board, int moveCount, int i, int j, LinkedList* list)
{
	log* newLog;
	
	newLog = (log*)malloc(sizeof(log));
	
	newLog->turn = moveCount;
	newLog->player = player;
	newLog->locX = j;
	newLog->locY = i;
	
	insertLast(list, newLog); 				/*inserts struct newLog into linkedlist*/
	
	return;
}

/* Function: displaySettings
Purpose: to display current settings
*/
void displaySettings(int *m, int *n, int *k)
{
	printf("\nSettings:\n\tM: %d\n\tN: %d\n\tK: %d\n", *m, *n, *k);
	return;
}

/* Function: viewLogs
Purpose: to iterate through the linked list and display settings and logs of each game to screen; is called from UI.c
*/
void viewLogs(int *m, int *n, int *k, LinkedList* list)
{
	int gameCount = 1;
	log* currLog;
	int turn;
	char player;
	int x;
	int y;
	LinkedListNode *currNode;
	
	currNode = list->head;
	
	displaySettings(m, n, k);

    while(currNode != NULL)
    {
        currLog = (log*)(currNode->data);
		
		turn = currLog->turn;
		player = currLog->player;
		x = currLog->locX;
		y = currLog->locY;
		
		if((turn == 1) && (gameCount > 1))
		{
			printf("\n\t...\n\nGAME %d:", gameCount);
			gameCount++;
		}
		else if(turn == 1)
		{
			printf("\nGAME %d:", gameCount);
			gameCount++;
		}
	
		printf("\n\tTurn: %d\n\tPlayer: %c\n\tLocation: %d, %d\n", turn, player, x, y);
		
        currNode = currNode->next;
    }
	
	return;
}

/* Function: saveLogs
Purpose: to iterate through the linked list and save settings and logs of each game to file; is called from UI.c
*/
void saveLogs(int *m, int *n, int *k, LinkedList* list)
{
	FILE *outFile;
	char* filename = (char*)malloc(26 * sizeof(char));
	int hours, mins, month, day;
	int gameCount = 1;
	LinkedListNode* currNode;
	
	getTime(&hours, &mins, &month, &day);
	sprintf(filename, "MNK_%d-%d-%d_%d-%d_%d-%d.log", *m, *n, *k, hours, mins, day, month);
	
	outFile = fopen(filename, "w");
	fprintf(outFile, "Settings:\n\tM: %d\n\tN: %d\n\tK: %d\n", *m, *n, *k);
	
    currNode = list->head;

    while(currNode != NULL)
    {
        fprintLog(currNode->data, outFile, &gameCount);
        currNode = currNode->next;
    }
	
	printf("\nSaved to %s....\n", filename);
	
	fclose(outFile);
	free(filename);
	
	return;
}

/* Function: getTime
Purpose: function used to get current date and time for output file
*/
void getTime(int *hours, int *mins, int *month, int *day)
{
	time_t now;
	struct tm *local;
	
	time(&now);
	local = localtime(&now);
	
	*hours = local->tm_hour;
	*mins = local->tm_min;
	*month = local->tm_mon + 1;
	*day = local->tm_mday;
	
	return;
}

/* Function: fprintLog
Purpose: to iterate through the linked list and print settings and logs of each game to file
*/
void fprintLog(void* data, FILE* filename, int* gameCount)
{
	log* currLog = (log*)data;
	int turn;
	char player;
	int x;
	int y;
	
	turn = currLog->turn;
	player = currLog->player;
	x = currLog->locX;
	y = currLog->locY;
	
	if((turn == 1) && (*gameCount > 1))
	{
		fprintf(filename, "\n\t...\n\nGAME %d:", *gameCount);
		(*gameCount)++;
	}
	else if(turn == 1)
	{
		fprintf(filename, "\nGAME %d:", *gameCount);
		(*gameCount)++;
	}
	
	fprintf(filename, "\n\tTurn: %d\n\tPlayer: %c\n\tLocation: %d, %d\n", turn, player, x, y);
	
	return;
}