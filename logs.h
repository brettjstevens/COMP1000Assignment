#ifndef LOGS_H
#define LOGS_H
	#include "LinkedList.h"

	typedef struct		/*struct log to be used to store each move's information in a the linkedlist*/
	{
		int turn;
		char player;
		int locX;
		int locY;
	}log; 
	
	void addLog(char turn, char** board, int moveCount, int i, int j, LinkedList* list);
	void viewLogs(int *m, int *n, int *k, LinkedList* list);
	void getTime(int *hours, int *mins, int *month, int *day);
	void saveLogs(int *m, int *n, int *k, LinkedList* list);
	void fprintLog(void* data, FILE* filename, int* gameCount);
#endif