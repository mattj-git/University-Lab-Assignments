 #include <stdio.h>
#include <stdlib.h>

#include<math.h>
#include "Questions.h"



void add_vectors(double vector1[],double vector2[],double vector3[],int size)
{
    /*vector3 should store the sum of vector1 and vector2. 
	You may assume that all three arrays have the size equal to n
	*/
	//write your code below
	int i = 0;
	double *vector1Ptr = &vector1[0];  //This and next 2 Lines just used to initialize pointers for each input array
	double *vector2Ptr = &vector2[0];
	double *vector3Ptr = &vector3[0];


	for(i = 0; i< size; i++)          //This for loop iterates through the entire index of the array (from 0 the first index, to size-1 the last index)
	{
		*(vector3Ptr + i) = *(vector1Ptr + i) + *(vector2Ptr + i); //This line adds the value, i many times to the right of the first item, of the 1st and 2nd array to the item i many times to the right of the 3rd array
	}
	
}

double scalar_prod(double vector1[],double vector2[],int size)
{
	// this is the variable holding the scalar product of the two vectors
    double prod=0;

	//write your code below to calculate the prod value
    double *vector1Ptr = &vector1[0];  //This and the next line just used to initialize pointers for each input array
    double *vector2Ptr = &vector2[0];
    int i = 0;
    for(i = 0; i < size; i++)   //This for loop iterates through the entire index of the array (from 0 the first index, to size-1 the last index)
    {
    	prod += (*(vector1Ptr + i))*(*(vector2Ptr + i));  //Using the same logic as the add function it multiplies the variables from the same index from both vectors then adds them to the total scalar product
    }
    

	
	// return the result
    return prod;
}

double norm2(double vector1[], int size)
{
	//this is the variable holding the L2 norm of the passed vector
    double L2;
	
    L2 = pow(scalar_prod(vector1,vector1,size),0.5);   //This just takes the square root of the scalar product of the vector with itself

    
	//write your code here
	// you should call function scalar_prod().
	
	//finally, return the L2 norm 
    return L2;
}
