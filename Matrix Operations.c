#include <stdio.h>
#include <stdlib.h>

#include "Questions.h"
#include "math.h"

double fabs();

int is_diag_dom(int mat[][N2]){

    //this is the flag that is returned to tell whether the mat is diagonally
	int isDiag=0;
	
	//write your code below
	//Return 1 if the matrix is diagonally dominant and 0 otherwise
	
	int row = 0; 					// 	row and column are just variables that I use to iterate through the respective sections of the matrix
	int column = 0;
	int non_diagonal = 0;          // These next 2 values just store the total for values on or off the diagonal
	int diagonal = 0;
	for (row = 0; row < N2; row ++)
	{
		for(column = 0 ; column < N2; column ++)             //The loop iterates through every single entry of the matrix
		{
			if (column != row)                              //This statement is true for everything off of the diagonal so if the entry is off the diagonal it adds it to the non_diagonal total
			{
				non_diagonal += fabs(mat[row][column]);
			}
			else                                            //This is the same as the previous statement except for everything on the diagonal
			{
				diagonal += fabs(mat[row][column]);
			}
		}
		if (non_diagonal > diagonal)                        //This last step just checks after every single row to make sure the non_diagonal elements aren't larger and returns 0 if they are
		{  													//If this condition isn't met the loop keeps running through the matrix
			return isDiag = 0;
		}
		non_diagonal = 0;                                   //These next 2 lines just make sure that the sums dont carry over to succesive rows
		diagonal = 0;
	}

	


    return isDiag = 1;
}
