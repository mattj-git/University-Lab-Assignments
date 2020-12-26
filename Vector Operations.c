 #include <stdio.h>
#include <stdlib.h>

#include<math.h>
#include "Questions.h"


void add_vectors(double vector1[],double vector2[],double vector3[],int size)  //This function adds 2 vectors and stores the sum in vector 3, given that both vectors have the same size
{
   
	int i = 0;
	double *vector1Ptr = &vector1[0];  //This and the next 2 lines are just used to initialize pointers for each input array
	double *vector2Ptr = &vector2[0];
	double *vector3Ptr = &vector3[0];


	for(i = 0; i< size; i++)          //This for loop iterates through the entire index of the array (from 0 the first index, to size-1 the last index)
	{
		*(vector3Ptr + i) = *(vector1Ptr + i) + *(vector2Ptr + i); //This line adds the value, i many times to the right of the first item, of the 1st and 2nd array to the item i many times to the right of the 3rd array
	}
	
}

double scalar_prod(double vector1[],double vector2[],int size)  //This function returns the scalar product of the 2 vectors, assuming they have the same size
{
	// this is the variable holding the scalar product of the two vectors
    double prod=0;

    double *vector1Ptr = &vector1[0];  //This and the next line just used to initialize pointers for each input array
    double *vector2Ptr = &vector2[0];
    int i = 0;
    for(i = 0; i < size; i++)   //This for loop iterates through the entire index of the array (from 0 the first index, to size-1 the last index)
    {
    	prod += (*(vector1Ptr + i))*(*(vector2Ptr + i));  //Using the same logic as the add function it multiplies the variables from the same index from both vectors then adds them to the total scalar product
    }
    

	
    return prod;
}

double norm2(double vector1[], int size) //This function takes the L2 norm of the given vector (the square root of the scalar product of the vector with itself)
{
	//this is the variable holding the L2 norm of the passed vector
    double L2;
	
    L2 = pow(scalar_prod(vector1,vector1,size),0.5);   //This just takes the square root of the scalar product of the vector with itself

   
	
    return L2;
}

void efficient(const int source[], int val[], int pos[], int size){  //This function takes a regular vector as an input and stores it using sparse vector representation
	                                                            //Val contains all the non-zero entries in the order that they appear
								   //Pos contains the index of where that entry is on the original array (the positions represents the value from the value array appearing in the same order)

	int i = 0;                    // Variable used to iterate through each item in the input array
	int output_index = 0;              // used to iterate through the output arrays
	for(i = 0; i < size; i++)     //Loop goes through the array
	{
		if (source[i] != 0)       // if statement which excludes zero entries
		{
			val[output_index] = source[i];     //If the entry is non zero it adds its position and value to their respective output arrays
			pos[output_index] = i;
			output_index += 1;                 //Only counts up in the output index if an entry is added to the output arrays
		}
	}
	

}

void reconstruct(int source[], int m, const int val[], const int pos[], int n){  //This function does the opposite of the previous function it converts the pos and val arrays to a regular vector
	                                                                        //n is the size of the val and pos arrays, m is the size of the regular array

	int i = 0;                     //Variable that iterates through the entire input array
	int output_index = 0;          //Variable used to iterate through the output array
	for (i = 0; i < m; i++ )    //Loop goes through the entire input array
	{
		if(i < pos[output_index])      //This if statement just detects if its at a place in the array before/between values (specifically the value at val[output_index]) and if so it places a 0 there
		{
			source[i] = 0;
		}
		else                           //This else statement takes into account if its at a place in the array where a value should be and places that value there (Same index as before)
		{
			source[i] = val[output_index];
			output_index += 1;         //Increments the index used to go through the "val" and "pos" arrays
		}
	}
}


void addEff(int val1[], int val2[], int val3[], int pos1[], int pos2[], int pos3[], int k1, int k2){ //This function adds the 2 sparsely represented vectors and stores the sum as the 3rd sparsely represented vector
	                                                                                            //Note we were given the restriction of not being able to allocate memory for any new array which is why the function is so complex

	int a = 0;                     // a and b used as iteration variables for later for loops
	int b = 0;
	int vector1_index = 0;         //Counters for each vector are used as I needed them to increment at different paces (not always all at once)
	int vector2_index = 0;
	int vector3_index = 0;
	while ( (vector1_index != k1) || (vector2_index != k2))   //This while loop keeps the code running as long as its not done processing one of the input sets (vector positions and values)
	{
		if( (vector1_index < k1) && (vector2_index < k2))     //This if statement is satisfied until one of the vector sets of info (pos and val, 1 or 2) is completely processed
		{
			if (pos1[vector1_index] < pos2[vector2_index])    //In this case if the un-processed position entry of vector 1 is less than and not equal to vector 2, so its value comes first in vector 3
			{
				pos3[vector3_index] = pos1[vector1_index];    //If this is the case it adds its value to the array and increments ONLY vector 3 and 1
				val3[vector3_index] = val1[vector1_index];
				vector3_index += 1;
				vector1_index += 1;
			}
			else if ( pos2[vector2_index] < pos1[vector1_index])  //This if statement is the opposite of the previous statement (when vector 2's un-processed position is before vector 1's)
			{
				pos3[vector3_index] = pos2[vector2_index];
				val3[vector3_index] = val2[vector2_index];
				vector3_index += 1;                          //Note: the index to count vector 3 is always indexed  whenever something is added to it whereas the vector 1 and 2 index is incremented based on the situation
				vector2_index += 1;
			}
			else if (pos1[vector1_index] == pos2[vector2_index])      //This is the case when their positions are the same and it has to add them
			{
				if (val1[vector1_index] + val2[vector2_index] != 0)       // If the value isn't equal to 0 then it adds them together, and increments every index (as information from both input array is used and an entry is added to the output)
				{
					pos3[vector3_index] = pos1[vector1_index];
					val3[vector3_index] = val1[vector1_index] + val2[vector2_index];
					vector3_index += 1;
					vector2_index += 1;
					vector1_index += 1;
				}
				else if (val1[vector1_index] + val2[vector2_index] == 0)  // If it does add up to 0 then the output array isn't changed at all (as a 0 value isn't recorded in pos or val)
				{
					vector2_index += 1;                            //Only the input indexes are incremented as nothing is added to the output list
					vector1_index += 1;
				}
			}
		}
		else													  //This else statement is when one of the input vectors has been completely processed and only one is left
		{														  //at this point whatever the position and value of the remaining vector is, is just added to the output vector
			if (vector1_index == k1)  //This is the case if vector 1 is processed (so the information from vector 2 is the one still being processed)
			{
				for (a = vector2_index; a < k2; a++)  //It only has to go through whats left so the for loop starts at whatever the vector index is at this point
				{
					pos3[vector3_index] = pos2[vector2_index];
					val3[vector3_index] = val2[vector2_index];
					vector3_index += 1;
					vector2_index += 1;
				}
			}
			else if (vector2_index == k2)    //The exact same as the last if statement but for when vector 2 is the one that's done being processed
			{
				for(b = vector1_index; b < k1; b++)
				{
					pos3[vector3_index] = pos1[vector1_index];
					val3[vector3_index] = val1[vector1_index];
					vector3_index += 1;
					vector1_index += 1;
				}
			}
		}
	}
}
