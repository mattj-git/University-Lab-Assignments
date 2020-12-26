#include <stdio.h>
#include <stdlib.h>

#include "math.h"

double fabs();

int is_diag_dom(int mat[][N2]){ //This function determines if the given matrix (a square matrix) is diagonally dominant (ie.if the absolute value of the diagonal element on each row is greater 
	                       //than the sum of the absolute values of the rest of the elements on that row, for each row, then the matrix is diagonally dominant).

	int isDiag=0;
	
	//Returns 1 if the matrix is diagonally dominant and 0 otherwise
	
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


void diag_scan(int mat [][N3], int arr []){  //This function constructs an array of all elements in a matrix in a diagonal scan order starting at the top left corner
					    //eg. if the matrix was { {1,12,13,49}, {5,16,17,81}, {9,10,11,20}, {2,45,19,14} }, the array returned would be {1,5,12,9,16,13,2,10,17,49,45,11,81,19,20,14}
						  
						   //When working on this question I realized that you're essentially listing a changing diagonal which moves from left to right like a "wave"
	int i = 0;                                // (cont.) the coordinates of all the entries on the diagonal always add up to a constant value eg.first wave all coordinates add to 0 (only top left entry), the second wave they all added too 1 so 2 entries ([1,0] and [0,1])
	
	int column = 0;							  //(cont.) the i variable iterates from the first "wave" to (wave zero) all the way up to wave 2(N3-1)
	
	int row = 0;                     //The variable rows goes through the rows, and column iterates through the columns
	
	int index = 0;                   //This is used as an index for the output array
	for (i = 0; i <= (N3-1)*2 ; i++)          //This for loop repeats the code for each "wave"
	{
		for (column = 0; column < N3; column++)   //This for loop iterates through each column
		{
			for (row = 0; row < N3; row++)        //This for loop iterates through the columns
			{
				if ( (column + row) == i)         //This if statement adds every entry found on the wave (the entries whose coordinates add up to that "wave's" constant value (i)
				{
					arr[index ++] = mat[row][column];
				}
			}
		}
	}
}



