#ifndef GAME_H
#define GAME_H
	#include "LinkedList.h"
	
	void newGame(int *m, int *n, int *k, LinkedList* list);
	void printBoard(int *m, int *n, char **board);
	int draw(int moveCount, int *m, int *n);
	int win(int *m, int *n, int *k, char** board);
	int checkHorizontalX(int *m, int *n, int *k, char** board);
	int checkHorizontalO(int *m, int *n, int *k, char** board);
	int checkVerticalX(int *m, int *n, int *k, char** board);
	int checkVerticalO(int *m, int *n, int *k, char** board);
	int checkDiagonalRightX(int *m, int *n, int *k, char** board);
	int checkDiagonalRightO(int *m, int *n, int *k, char** board);
	int checkDiagonalLeftX(int *m, int *n, int *k, char** board);
	int checkDiagonalLeftO(int *m, int *n, int *k, char** board);
#endif