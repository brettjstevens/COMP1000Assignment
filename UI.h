#ifndef UI_H
#define UI_H
	#include "LinkedList.h"

	void menu(int *m, int *n, int *k, LinkedList* list);
	void displaySettings();
	void insertCoordinate(int *m, int *n, char turn, char **board, int moveCount, LinkedList* list);
	void edit(int* m, int* n, int* k);
#endif