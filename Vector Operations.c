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

void efficient(const int source[], int val[], int pos[], int size){

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

void reconstruct(int source[], int m, const int val[], const int pos[], int n){

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
