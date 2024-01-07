/* Author: Brett Stevens
File name: fileReader.c
Purpose: to handle all file reading of the input file
Last modified: 23/10/19
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "fileReader.h"

/* Function: readFile
Purpose: handles all file input for settings; is called in game.c
*/
void readFile(int *m, int *n, int *k, char *filename)
{
	FILE *inFile = fopen(filename, "r");
	char ch;
	int value;				
	int adCount = 0;									/*additional element count*/
	*m = 0, *n = 0, *k = 0;								/*set elements to zero for error checking*/
	
	if(inFile == NULL)
    {
        perror("Error opening file");
    }
	else
	{
		do
		{
			fscanf(inFile, "%c=%d", &ch, &value);
			
			if(ch == 'm' || ch == 'M')
			{
				if((*m == 0) && (adCount < 1))
				{
					*m = value;
				}
				else
				{
					adCount++;
				}
			}
			else if(ch == 'n' || ch == 'N')
			{
				if((*n == 0) && (adCount < 1))
				{
					*n = value;
				}
				else
				{
					adCount++;
				}
			}
			else if(ch == 'k' || ch == 'K')
			{
				if((*k == 0) && (adCount < 1))
				{
					*k = value;
				}
				else
				{
					adCount++;
				}
			}
			
			if(ferror(inFile))
			{
				perror("Error reading from file");
			}
			
		}while(!(feof(inFile)));
		
		if(*m <= 0)											/*error checking*/
		{
			printf("Error: setting \'M\' is of invalid format.\n");
		}
		else if(*n <= 0)
		{
			printf("Error: setting \'N\' is of invalid format.\n");
		}
		else if(*k <= 0)
		{
			printf("Error: setting \'K\' is of invalid format.\n");
		}
		else if(adCount > 0)								/*handles and informs the user of any input files with additional settings*/
		{
			printf("%d additional element(s) found in \'%s\'. \nPragram will continue with the first three positive non-zero elements entered.\n", adCount, filename);
		}
	}
	
	fclose(inFile);
	
	return;
}
