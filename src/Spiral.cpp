/*
Write a program to generate elements of a matrix in spiral order.
Store the generated elements in single dimensional array and return that array.

Directions for Spiral are : Go Right ,Go Down ,Go Left, Go Up
Ex:

Matrix:
1	2	3
4	5	6
7	8	9

Spiral order:
1	2	3	6	9	8	7	4	5

Given matrix is a two dimensional array(input_array) with dimensions rows, columns.
If rows, columns are invalid then return NULL.
If input_array is NULL then return NULL.

Example Input :
int board[2][3]={
				 {4,6,7},
				 {1,3,8}
				};
spiral(2,2,(int **)board); // Rows followed by columns followed by board

Example Output : Return an array consisting of {4,6,7,8,3,1};

Note : Check the function Parameters ,Its a double pointer .

*/


#include "stdafx.h"
#include<stdlib.h>

int *spiral(int rows, int columns, int **input_array)
{
	if (input_array == NULL||rows<=0||columns<=0)
		return NULL;
	int count=0, size, rowmin=0, rowmax=rows-1, colmin=0, colmax=columns-1;
	size = rows*columns;
	int *array;
	array = (int*)malloc(size*sizeof(int));
	while (count < size)
	{
		for (int i = colmin; i < columns; i++)
		{
			array[count] = input_array[rowmin][i];
			count++;
			if (count == size)
				break;
		}
		for (int j = rowmin + 1; j < rows; j++)
		{
			array[count] = input_array[j][columns-1];
			count++;
		}
		if (count == size)
			break;
		for (int r = columns - 2; r > colmin; r--)
		{
			array[count] = input_array[rows-1][r];
			count++;
		}
		if (count == size)
			break;
		for (int r = rows - 1; r > rowmin; r--)
		{
			array[count] = input_array[r][colmin];
			count++;
		}
		rowmin++;
		colmin++;
		rows--;
		columns--;

	}
	return array;
	
}
