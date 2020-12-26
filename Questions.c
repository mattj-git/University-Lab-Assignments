
#include "Questions.h"



int Q1_for(){
	int sum = 0;
	
	// calculate your sum below..this has to use for loop
	int i;
	for (i=30;i<=1000;i++){
		if (i%4 == 0){
			sum = i + sum;
		}
	}
	
	
	// here, we return the calculated sum:
	return sum;
}
int Q1_while(){
	int sum = 0;


	// calculate your sum below..this has to use while loop
	int i=30;
	while(i<=1000){

		if (i%4 == 0){
			sum += i;
		}
		i += 1;}
	
	// here, we return the calcualted sum:
	return sum;
}
int Q1_do(){
	int sum = 0;
	
	// calculate your sum below..this has to use do-while loop
	int i = 30;
	do
	{
		if(i%4 == 0){
			sum += i;
		}
		i += 1;
	}
	while(i<=1000);

	// here, we return the calcualted sum:
	return sum;
}
//===============================================================================================
int Q2(int Q2_input){
	
	// this is the flag that is holding whether the input number is 5-digit or not
	int IsFiveDigit;
	
	// Do your coding below to check
	if( Q2_input < 0){
		Q2_input = (-1)*Q2_input;             //This is just to make sure its always a positive value, so my if statement can be simple.
	}

	if( Q2_input>=10000 && Q2_input<=99999 ){
		IsFiveDigit = 1;
	}
	else{
		IsFiveDigit = 0;
	}

	            
	
	//finally, we must return IsFiveDigit, which must be 1 is the number is five digits and 0 otherwise
	return IsFiveDigit;
}
//===============================================================================================
int Q3(float Q3_input){
	
	/* Question 3: 
	Write a program that takes a student's Q3_input as an input, which is a floating point value,
	and prints:
	4 if the Q3_input is in the range 90-100,
	3 if it is in the range 80-89, 
	2 if it is in the range 70-79,
	1 if it is in the range 60-69 and
	0 if the Q3_input is between 0 and 59.
	If the Q3_input is not in the range 0-100, the program should print a message to signal an invalid input.
*/	
	// this is the varaible that holds the out value to return
	float GPA;
	
	
	// Do your coding below to calculate the GPA variable value
	GPA = 0;
	if (Q3_input<=100 && Q3_input>=90){
		GPA = 4;
	}
	else if (Q3_input<=89 && Q3_input>=80){
		GPA = 3;
	}
	else if (Q3_input<=79 && Q3_input>=70){
		GPA = 2;
	}
	else if (Q3_input<=69 && Q3_input>=60){
		GPA = 1;
	}
	else if (Q3_input<=59 && Q3_input>=0){
		GPA = 0;
	}
	else{
		GPA = -1;
	}
	
	// finally, we return the GPA
	return GPA;	
}
//===============================================================================================
double Q4(int Q4_input){
	
	// this is the varaible that holds the pi value to return
	double pi=0;
	
	
	// Do your coding below to calculate the pi value
	int a = 0;                                 //just an incrementing variable
	float denominator = 1;
	for(a = 0;a < Q4_input; a++){
		if(a % 2 == 0){                       //Every even term of the approximation (including the 0th term) is positive so this compensates for those cases
			pi += 4/denominator;
		}
		else{                                 //Every odd case is negative so this compensates for all of those cases.
			pi += -4/denominator;
		}
		denominator += 2;                     //Increase the denominator By 2 each time
		}
	   
	
	// finally, we return the pi value
	return pi;	
}
//===============================================================================================
int Q5(){
	
	// this is the varaible that holds and the total number of triples to return at the end of the function
	int totNumTribles=0;
	
	
	/* Do your coding below
		Use a triple-nested for loop that simply tries all possibilities
		print each triple on a separate line, 
		and update the total number of triples if needed
	*/
	int i = 1;
	    int a = 0;                       // i,a,b are just variables I used to increment the for loops
	    int b = 0;
	    float side1 = 0;
	    float side2 = 0;
	    for(i = 0;i < 283; i++){         //Side 1 can be no larger than 282 as side 2 has to be greater than or equal to side 1 if you had both side 1 and 2 be 283 or larger then the hypotenuse would be larger than 400
	        side1 += 1;
	        for(a=0; a < 566 - side1; a++){  //This just allows side 2 to increment up by 1 all the way up to 283 when side1 is 283
	            side2 += 1;
	            for(b = 1; b <=400; b ++)    //I use this as a variable by which to compare side3 to the equation to make sure it's an integer
	            if((side1*side1 + side2*side2) == b*b && side1 <= side2){
	                totNumTribles +=1;
	            }
	        }
	        side2 = 0;}                     //this just resets side 2 so the value it reached in the previous loop iteration doesn't spill over into the next iteration






	//this is the format that you MUST print the found tribles..uncomment this line and fill in the missings to get it working correctly
	//printf("A triple found: side1=%d, side2=%d, side3=%d\n", ...)
	
	//finally you should return the total number of tribles.
	return totNumTribles;
}
//===============================================================================================
int Q6(int Q6_input, int perfect[]){
	
	
	
		//counts is teh variable that should hold the total number of found perfect numbers
		//you should update it within your code and return it at the end
	    int counts=0;
	    int num = 0;
	    int factor = 0;
	    int sum = 0;
	    int index = 0;
	    for(num = 2; num <= Q6_input; num++){     //This for loop iterates from 2 (as 0 and 1 aren't perfect numbers) up to that number
	    	sum = 0;
	    	for(factor = 1; factor < num; factor++){   //This loop iterates through all the possible factors of a number
	    		if(num % factor == 0){                // this determines what is a factor
	    			sum += factor;                    //This adds all the factors up together

	    		}
	    	}
	    	if(sum == num){							// if the factor is the number then it adds it to perfect array and tallies it with the counts variable
	    		perfect[index] = num;
	    		index += 1;
	    		counts += 1;


	    	}


		/*
		*
		*perfect is an array that you need to add into it any perfect number you find
		*which means at the end of this function, the perfect[] array should hold all the found perfect numbers in the range
		*you do not need to return perfect because as stated in lectures arrays are already passed by reference. so, modifying them will 
		*autmoatically reflect in the main calling function.
		*/
	    
		
		
		
		
	   }
	   return counts;

	
}
//===============================================================================================
int Q7a(int Q7_input){
	
	//this is the variable that holds the reversed int.
	int reversedInt=0;
	
	
	// Do your coding logic here
	//Hint: Use the division and remainder operators to separate the number into its individual digits.
	//in this part you can assume the knowledge of the number of digits: seven-digit positive integer
	int i = 0;
	int digit  = 0;
	int denominator = 1000000;
	int multiplier = 1;

	for(i = 0; i<7; i++)
	{
		digit = (Q7_input - (Q7_input % denominator)) / denominator; // In this line I do modulo division using a denominator that will return everything except the first/highest digit, then it subtracts that from the input then divides it by the same number, so it always returns the highest digit

		reversedInt += digit*multiplier;       //This then adds the digit found in the previous line to the correct tens column of the reversed number

		Q7_input -= (Q7_input - (Q7_input % denominator));  //This removes the digit I just found from the input

		denominator = denominator / 10;            //The next 2 lines just adjust the denominator and multiplier so that for the next iteration they're the correct value

		multiplier = multiplier*10;

	}

		return reversedInt;
}
int Q7b(int Q7b_input){
	
	//this is the variable that holds the reversed int.
	int reversedInt=0;
	
	

	// Do your coding logic here
	//Hint: Use the division and remainder operators to separate the number into its individual digits.
	//this part should be generalized for any number of allowed digits
	int digit = 0;

	while( Q7b_input > 0)             //Unlike my last bit of code this goes from the smallest digit up to the largest, and the process will eventually bring the input down to 0 once it hits the end so I made this my end condition
	{
        digit = Q7b_input % 10;      //Here I do modulo division which will always leave the smallest as the remainder
        reversedInt = digit + reversedInt*10; //I then add this to 10 times the previous iteration of the reversed number times 10 this assures that each digit is in the correct 10 column by constantly "bumping them up" each time the loop runs
        Q7b_input = Q7b_input / 10;   //This just then gets rid of the bottom digit as this is integer division and the decimal is just truncated off.
    }
	return reversedInt;

	
	//As a side note I realized the code I wrote for part a was not nearly flexible enough to be used for any amount of digits and I completely abandoned it for this much simpler method I created after
	
}
