#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void letter_freq(const char word[], int freq[]){  //This functions takes in a string and returns a string "freq" which returns displays how many times each letter appeared in the word
						 //The array "freq" contains integers in the position respective to that letters position in the alphabet (ie. a/A is index 0, b/B is index 1). 
	
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

void string_copy(const char source[], char destination[], int n){ //This  functions copies the input string "source" to the output string "destination"

	int i = 0;                    //Used to iterate through the entire array
	for(i = 0; i < n-1; i++)      //Goes through the entire array except for the very last character (reserved for the null character)
	{
		destination[i] = source[i];   //Copies each entry from source to destination
	}
	destination[n-1] = '\0';          //Adds the null character to the end of each string
}


char *my_strcat(const char * const str1, const char * const str2){  //This function concactenates the 2 strings and assigns new memory to hold the concactenated string

	char *z = NULL;
	

	int str1_length = strlen(str1);         //Next 2 lines are variables that store the length of each string
	int str2_length = strlen(str2);

	int i = 0;         //Iterating variables for, for loops
	int a = 0;

	z = malloc((str1_length + str2_length - 1)*4);       //This assigns the pointer z the required amount of bytes each char is 4 bytes so in total its both bytes added together (subtracted 1 as we only need space for 1 null character not 2) and then multiplied by 4

	for (i = 0; i < (str1_length); i++)          //This for loop goes through all of str1
	{
		*(z + i) = str1[i];                      //It adds it to z starting at the beginning (which is what z is pointing to) and
	}

	for (a = 0; a < (str2_length); a++)          //This for loop goes through all of str2
	{
		*(z + i + a) = str2[a];                 //But it has to start where the first string ended so I added i as well as a

	}

	*(z + i + a ) = '\0' ;                   //This just adds the null character to the very end of the string



	return z;
	
}
