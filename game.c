/* Author: Brett Stevens
File name: game.c
Purpose: contains all functions that make the game function that dont require UI 
Last modified: 23/10/19
*/
#include <stdio.h>
#include <stdlib.h>

#include "game.h"
#include "UI.h"

/* Function: newGame
Purpose: imports setting values and list of logs to execute new games when called from UI.c
*/
void newGame(int *m, int *n, int *k, LinkedList* list)
{
	char** board;
	char p1 = 'X', p2 = 'O', turn = 'O';	/*sets to 'O' therefore first move is 'X's after switch*/
	int i, j, moveCount = 0;
	
	board = (char**)malloc((*m) * sizeof(char*));
	
	for(i = 0; i < *m; i++)
	{
		board[i] = (char*)malloc((*n) * sizeof(char));
	}
	
	for (i = 0; i < *m; i++)
	{
		for(j = 0; j < *n; j++)
		{
			board[i][j] = ' '; 				/*initially board is empty*/
		}
	}
	
	printBoard(m, n, board);				/*output empty board*/
	
	do
	{
		if(turn == p2)						/*if/else-if statements to switch turns*/
		{
			turn = p1;
			moveCount++;
			insertCoordinate(m, n, turn, board, moveCount, list);
		}
		else if(turn == p1)
		{
			turn = p2;
			moveCount++;
			insertCoordinate(m, n, turn, board, moveCount, list);
		}

		printBoard(m, n, board);
		
	}while((draw(moveCount, m, n) != 1) && (win(m, n, k, board) != 1));
	
	if(win(m, n, k, board) == 1)
	{
		printf("%c won. Woopdeedoo...\n", turn);
	}
	else if(draw(moveCount, m, n) == 1)
	{
		printf("\nDraw; you're both as bad as each other.\n");
	}
	
	for(i = 0; i < *m; i++) 				/*free all malloc'd space of board*/
	{
		free(board[i]);
	}
	
	free(board);
	
	return;
}

/* Function: printBoard
Purpose: is used to print board with appropriate characters saved in malloc'd board array
*/
void printBoard(int *m, int *n, char **board)
{
	int i, j;
	
	printf("\n");
	
	for(j = 0; j < *m; j++)
	{
		printf("-------");
	}
	
	printf("\n");
	
	for (i = 0; i < *n; i++)
	{
		for(j = 0; j < *m; j++)
		{
			printf("|  %c  |", board[i][j]);
		}
		
		printf("\n");
		
		for(j = 0; j < *m; j++)
		{
			printf("-------");
		}
		
		printf("\n");
	}
	
	return;
}

/* Function: draw
Purpose: used as a boolean function in newGame() to identify a draw
*/
int draw(int moveCount, int *m, int *n)
{
	int moves, draw = 0;
	
	moves = (*m) * (*n);
	
	if(moves == moveCount)
	{
		draw = 1;
	}
	
	return draw;
}

/* Function: win
Purpose: used as a boolean function in newGame() to identify a win
*/
int win(int *m, int *n, int *k, char** board)
{
	int won = 0;								/*boolean (0/1) to check for win*/
	
	if(checkHorizontalX(m, n, k, board) == 1)
	{
		won = 1;
	}
	else if(checkHorizontalO(m, n, k, board) == 1)
	{
		won = 1;
	}
	else if(checkVerticalX(m, n, k, board) == 1)
	{
		won = 1;
	}
	else if(checkVerticalO(m, n, k, board) == 1)
	{
		won = 1;
	}
	else if(checkDiagonalRightX(m, n, k, board) == 1)
	{
		won = 1;
	}
	else if(checkDiagonalRightO(m, n, k, board) == 1)
	{
		won = 1;
	}
	else if(checkDiagonalLeftX(m, n, k, board) == 1)
	{
		won = 1;
	}
	else if(checkDiagonalLeftO(m, n, k, board) == 1)
	{
		won = 1;
	}
	
	return won;
}

/*----------Functions from here are all called in win() and are all quite similar------------*/

/* Function: checkHorizontalX
Purpose: used as a boolean function in win() to identify a win for player X horizontally
*/
int checkHorizontalX(int *m, int *n, int *k, char** board)
{
	int won = 0;
	int i = 0, j = 0, match, count = 0;
	
	while((i < *n) && (count != *k))
	{
		count = 0;
		j = 0;
		
		while((j < *m) && (count != *k))
		{
			match = 1; 							/*boolean (0/1) to check for X*/
			
			if(board[i][j] != 'X')
			{
				match = 0;
				count = 0;
			}
			else if(board[i][j] == 'X')
			{
				count++;						/*count to compare with win value 'k'*/
			}
			
			j++;
		}
		
		i++;
	}
	
	won = match;
	
	if(count != *k)
	{
		won = 0;
	}
	
	return won;
}

/* Function: checkHorizontalO
Purpose: used as a boolean function in win() to identify a win for player O horizontally
*/
int checkHorizontalO(int *m, int *n, int *k, char** board)
{
	int won = 0;
	int i = 0, j = 0, match, count;
	
	while((i < *n) && (count != *k))
	{
		count = 0;
		j = 0;
		
		while((j < *m) && (count != *k))
		{
			match = 1; 							/*boolean (0/1) to check for O*/
			
			if(board[i][j] != 'O')
			{
				match = 0;
				count = 0;
			}
			else if(board[i][j] == 'O')
			{
				count++;						/*count to compare with win value 'k'*/
			}
			
			j++;
		}
		
		i++;
	}
	
	won = match;
	
	if(count != *k)
	{
		won = 0;
	}
	
	return won;
}

/* Function: checkVerticalX
Purpose: used as a boolean function in win() to identify a win for player X vertically
*/
int checkVerticalX(int *m, int *n, int *k, char** board)
{
	int won = 0;
	int i = 0, j = 0, match, count = 0;
	
	while((j < *m) && (count != *k))
	{
		count = 0;
		i = 0;
		
		while((i < *n) && (count != *k))
		{
			match = 1; 							/*boolean (0/1) to check for X*/
			
			if(board[i][j] != 'X')
			{
				match = 0;
				count = 0;
			}
			else if(board[i][j] == 'X')
			{
				count++;						/*count to compare with win value 'k'*/
			}
			
			i++;
		}
		
		j++;
	}
	
	won = match;
	
	if(count != *k)
	{
		won = 0;
	}
	
	return won;
}

/* Function: checkVerticalO
Purpose: used as a boolean function in win() to identify a win for player O vertically
*/
int checkVerticalO(int *m, int *n, int *k, char** board)
{
	int won = 0;
	int i = 0, j = 0, match, count = 0;
	
	while((j < *m) && (count != *k))
	{
		count = 0;
		i = 0;
		
		while((i < *n) && (count != *k))
		{
			match = 1; 							/*boolean (0/1) to check for X*/
			
			if(board[i][j] != 'O')
			{
				match = 0;
				count = 0;
			}
			else if(board[i][j] == 'O')
			{
				count++;						/*count to compare with win value 'k'*/
			}
			
			i++;
		}
		
		j++;
	}
	
	won = match;
	
	if(count != *k)
	{
		won = 0;
	}
	
	return won;
}

/* Function: checkDiagonalRightX
Purpose: used as a boolean function in win() to identify a win for player X on a right diagonal
*/
int checkDiagonalRightX(int *m, int *n, int *k, char** board)
{
	int won = 0;
	int i = 0, j = 0, ii, jj, count = 0;
	int stop = 0;								/*boolean (0/1) to stop iteration when diagonal ends*/
	
	while((i < *n - 1) && (count != *k - 1))
	{
		j = 0;
		
		while((j < *m - 1) && (count != *k - 1))
		{
			if(board[i][j] == 'X')
			{
				if(board[i][j] == board[i + 1][j + 1])
				{
					ii = i + 1;
					jj = j + 1;
					count++;
					
					while((count != *k - 1) && (stop = 0))
					{
						if(board[ii][jj] == board[ii + 1][jj + 1])
						{
							count++;
						}
						
						if(board[ii][jj] != board[ii + 1][jj + 1])
						{
							count = 0;
							stop = 1;
						}
						
						ii++;
						jj++;
						
					}
				}
			}
			
			j++;
		}
		
		i++;
	}
	
	if(count == *k - 1)
	{
		won = 1;
	}
	
	return won;
}

/* Function: checkDiagonalRightO
Purpose: used as a boolean function in win() to identify a win for player O on a right diagonal
*/
int checkDiagonalRightO(int *m, int *n, int *k, char** board)
{
	int won = 0;
	int i = 0, j = 0, ii, jj, count = 0;
	int stop = 0;								/*boolean (0/1) to stop iteration when diagonal ends*/
	
	while((i < *n - 1) && (count != *k - 1))
	{
		j = 0;
		
		while((j < *m - 1) && (count != *k - 1))
		{
			if(board[i][j] == 'O')
			{
				if(board[i][j] == board[i + 1][j + 1])
				{
					ii = i + 1;
					jj = j + 1;
					count++;
					
					while((count != *k - 1) && (stop = 0))
					{
						if(board[ii][jj] == board[ii + 1][jj + 1])
						{
							count++;
						}
						
						if(board[ii][jj] != board[ii + 1][jj + 1])
						{
							count = 0;
							stop = 1;
						}
						
						ii++;
						jj++;
					}
				}
			}
			
			j++;
		}
		
		i++;
	}
	
	if(count == *k - 1)
	{
		won = 1;
	}
	
	return won;
}

/* Function: checkDiagoalLeftX
Purpose: used as a boolean function in win() to identify a win for player X on aleft diagonal
*/
int checkDiagonalLeftX(int *m, int *n, int *k, char** board)
{
	int won = 0;
	int i = 0, j = 1, ii, jj, count = 0;
	int stop = 0;								/*boolean (0/1) to stop iteration when diagonal ends*/
	
	while((i < *n - 1) && (count != *k - 1))
	{
		j = 1;
		
		while((j < *m) && (count != *k - 1))
		{
			if(board[i][j] == 'X')
			{
				if(board[i][j] == board[i + 1][j - 1])
				{
					ii = i + 1;
					jj = j - 1;
					count++;
					
					while((count != *k - 1) && (stop = 0))
					{
						if(board[ii][jj] == board[ii + 1][jj - 1])
						{
							count++;
						}
						
						if(board[ii][jj] != board[ii + 1][jj - 1])
						{
							count = 0;
							stop = 1;
						}
						
						ii++;
						jj--;
					}
				}
			}
			
			j++;
		}
		
		i++;
	}
	
	if(count == *k - 1)
	{
		won = 1;
	}
	
	return won;
}

/* Function: checkDiagoalLeftO
Purpose: used as a boolean function in win() to identify a win for player O on aleft diagonal
*/
int checkDiagonalLeftO(int *m, int *n, int *k, char** board)
{
	int won = 0;
	int i = 0, j = 1, ii, jj, count = 0;
	int stop = 0;								/*boolean (0/1) to stop iteration when diagonal ends*/
	
	while((i < *n - 1) && (count != *k - 1))
	{
		j = 1;
		
		while((j < *m) && (count != *k - 1))
		{
			if(board[i][j] == 'O')
			{
				if(board[i][j] == board[i + 1][j - 1])
				{
					ii = i + 1;
					jj = j - 1;
					count++;
					
					while((count != *k - 1) && (stop = 0))
					{
						if(board[ii][jj] == board[ii + 1][jj - 1])
						{
							count++;
						}
						
						if(board[ii][jj] != board[ii + 1][jj - 1])
						{
							count = 0;
							stop = 1;
						}
						
						ii++;
						jj--;
					}
				}
			}
			
			j++;
		}
		
		i++;
	}
	
	if(count == *k - 1)
	{
		won = 1;
	}
	
	return won;
}