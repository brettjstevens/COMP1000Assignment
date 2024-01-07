/* Author: Brett Stevens
File name: UI.c
Purpose: to handle all user input
Last modified: 23/10/19
*/
#include <stdio.h>

#include "UI.h"
#include "game.h"
#include "logs.h"

/* Function: menu
Purpose: handles user input to select appropriate functions/path; is called in tictactoe.c
*/
void menu(int *m, int *n, int *k, LinkedList* list)
{
	int input;
	
	do
	{
		printf("\n\tMAIN MENU:\n1. New game\n2. Display settings\n3. View current logs\n4. Save logs to file\n5. Exit\n");
		#ifdef Editor
		printf("6. Edit settings\n");
		#endif
		printf("\nSelect an option: ");
		scanf("%d", &input);
	
		switch(input)
		{
			case 1:
				newGame(m, n, k, list);
				break;
			
			case 2:
				displaySettings(m, n, k);
				break;
				
			case 3:
				viewLogs(m, n, k, list);
				break;
				
			#ifndef Secret
			case 4:
				saveLogs(m, n, k, list);
				break;
			#endif
				
			case 5:
				printf("\nExiting program....\n");
				break;
				
			#ifdef Editor
			case 6:
				edit(m, n, k);
				break;
			#endif
				
			default:
				printf("Please enter a valid input.\n");
				break;
		}
	}while(!(input == 5));
	
	return;
}

/* Function: insertCoordinate
Purpose: handles each players input coordinates and places them in the malloc'd board array; is called in game.c
*/
void insertCoordinate(int *m, int *n, char turn, char **board, int moveCount, LinkedList* list)
{
	int i, j;
	
	do
	{
		printf("\n%c's turn.\nEnter coordinates <x> <y>: ", turn);
		scanf("%d %d", &j, &i);
	}while(!(i < (*n)) || !(j < (*m)) || (board[i][j] == 'X') || (board[i][j] == 'O'));
	
	board[i][j] = turn;
	
	addLog(turn, board, moveCount, i, j, list);
	
	return;
}

/* Function: edit
Purpose: allows user to edit setting values
*/
void edit(int* m, int* n, int* k)
{
	printf("\nEnter M: ");
	scanf("%d", m);
	printf("\nEnter N: ");
	scanf("%d", n);
	printf("\nEnter K: ");
	scanf("%d", k);
	
	return;
}
