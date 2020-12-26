#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Questions.h"

void letter_freq(const char word[], int freq[]){
	int i = 0; 		                               // i is used to iterate through each entry of the string
	int letter = 0;                                //This variable iterates through ASCII letters
	while (word[i] != '\0')   //While loop which repeats until it hits the null character at the end of the string
	{
		for( letter = 65; letter <= 90; letter++)   //Here the letter variable goes through all the capital letters using ASCII
			{
				if(letter ==  word[i] || letter + 32 ==  word[i])      //This condition considers if the entry is a capital letter (the first condition) or a lowercase letter (32 more than its respective uppercase letter)
				{
					freq[letter - 65] += 1;      //If the condition is satisfied it adds 1 to the counter (frequency) of that letter, which is indexed at the ASCII value minus 65
				}
			}
		i++;                 //Increments to the next entry in the string at the end of each loop iteration
	}

   
}
