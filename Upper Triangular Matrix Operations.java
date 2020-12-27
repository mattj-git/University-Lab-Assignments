public class UpperTriangularMatrix { //This class is used to represent upper triangular matrices and uses some of the methods defined in the "matrix operations" file.
    private int n;
    private int[] array;
    
    public UpperTriangularMatrix(int n){  //This counstructor creates an empty (all zero) upper triangular matrix with the given size (or a size of 1 if a negative number is given)
        
    	if (n <= 0)                    //If the dimension value is invalid it is changed to 1 as instructed
    	{
    		this.n = 1;
    	}
    	
    	else   //If it is valid then it is changed to the necessary  value
    	{
    		this.n = n;
    	}
    	
    	this.array = new int [(this.n*(this.n + 1))/2];  //The size of the array is defined by the equation
        
    }
    
    public UpperTriangularMatrix(Matrix upTriM) throws IllegalArgumentException{ //This method creates an UpperTriangularMatrix object from a Matrix object (If the matrix is upper triangular)
    
    if (upTriM.isUpperTr() == true) //Checks to see if the input matrix is upper triangular
    {
    	int i = 0;                  //i and o are iterating variables
    	int o = 0;
    	int counter = 0;  //Used to index the value of the final array
    	
    	this.array = new int [(upTriM.getsizeofcols())*(upTriM.getsizeofcols() + 1 )/2]; //Defines the array with the necesssary space, and sets all values to 0
    	
    	for (i = 0; i < upTriM.getsizeofrows(); i++)  // the next 2 loops run through the all entries of the input matrix
    	{
    		for (o = 0; o < upTriM.getsizeofcols(); o++)
    		{
    			if ( i < o || i == o)          //This condition ensures that only entries on and above the diagonal are added 
    			{
    				this.array[counter] = upTriM.getElement(i, o); //sets the values of the input array to the corresponding position
    				counter += 1;  //I use this to count where the value should go as it should only increment when a value is added, as opposed to at the end of one of the for loops
    			}
    		}
    	}
    	
    	this.n = upTriM.getsizeofcols();           //Sets the n value to what it should be (it could've also been the size of the rows since their square I just chose this arbitrarily)
    }
   
    else
    {
    	throw new IllegalArgumentException("Not an upper triangular Matrix");  //Throws the exception case if the matrix isn't square
    }
        
    }    
        
    public int getDim(){  //A method that returns the dimensions of the matrix
        
		
        return this.n;   //Just returns the dimension
    }
    
    public int getElement(int i, int j) throws IndexOutOfBoundsException{ //A method that takes in the location of an entry and returns the value of that entry
		
		
    	if ( i < 0 || this.n <= i || this.n <= j || j < 0)               //Throws the exception case if the values of i and j are too large, or below 0
    		throw new IndexOutOfBoundsException("Invalid indexes");
    	
    	else
    	{
    		if ( i < j || i == j)          //This condition deals with all the cases that it's one of the values listed (above or on the diagonal)        
    		{
    			int a = 0;
    			int tracker = 0;
    			for( a = 0; a < i; a ++)    //I use this loop and the variable tracker to track how many values there are up until the end of the row the question is asking for
    			{
    				tracker += this.n - a;
    			}
    			return this.array[tracker + (j - i)];  // I add j and subtract i to get the exact placement of the variable on the array (the whole process just converts i,j values to the index of the array)
    		}
    		else         //if the value is below the diagonal then it must be zero
    		{
    			return 0;
    		}
    	}
    }
    
    public void setElement(int x, int i, int j) throws IndexOutOfBoundsException,IllegalArgumentException{ //Takes in the location of an entry and sets the value of that entry to x
       
    	if ( 0>i || this.n <= i || this.n <= j || 0>j)                    //These 2 if statements throw the necessary exception cases
    		throw new IndexOutOfBoundsException("Invalid indexes");   //This one if i and j are invalid
    	
    	if (i > j && x != 0 )  //and this one if it's trying to assign a non zero number to something below the diagonal
    	{
    		throw new IllegalArgumentException("Incorrect argument");
    	}
    	
    	else     //If neither case is met then the below code runs
    	{
    		int a = 0;
    		int tracker = 0;
    		for( a = 0; a < i; a ++)
   			{
   				tracker += this.n - a;
    		}
   			this.array[tracker + (j - i)] = x;   //uses the same counting method as the last question but instead of returning it, it alters the value
    	}
    }
    
    public Matrix fullMatrix(){  //Converts the UpperTriangularMatrix the method is used on to an object of type Matrix 

        Matrix full= new Matrix(this.n,this.n); //Assigns the matrix as the square size defined by n
       
        int i = 0; //Iterating variables
        int o = 0;
        int counter = 0;  //Used to iterate through the array of the Upper triangular object
        
     	   for (i = 0; i <this.n; i++)  //The next 2 loops runs through each entry of the output matrix in the same "order" as the upper triangular array
     	   {
     		   for(o = 0; o < this.n; o++)
     		   {
     			   if (i < o || i == o)   //If that entry is on or above the diagonal than the code below runs
     			   {
     				   full.setElement(this.array[counter], i, o);   //Using counter to select which value, it assigns that value to the entry defined by the for loops
     				   counter += 1;  //Counter only iterates when a value is above or on the diagonal as otherwise none of the information from the uppertriangular array was processed and there's no need to iterate this variable
     			   }
     		   }
     	   }
     	   
     	   return full; //Returns the matrix
        
       
    }
    
   
      
    public String toString(){  //Returns a string representation of the UpperTriangularMatrix this method is used on
       String output= "";
        
       int i = 0;        //i and o are iterating variables
       int o = 0;
       int counter = 0;  //Used to iterate through the uppertriangle array in the same way as the last question
       int tracker = 0;  //This variable is used to track where a newline character should be (not the same as the other questions where I used it)
       
    	   for (i = 0; i <this.n; i++)       //These 2 for loops iterate through each entry that the input object represents      
    	   {
    		   
    		   for(o = 0; o < this.n; o++)
    		   {
    			   if (i < o || i == o)   //If that entry would be above or on the diagonal the below code runs
    			   {
    				   output = output + this.array[counter] + " ";   //Using the counter to determine which value is concactenated, it concactenates the necessary value along with a space after it
    				   counter += 1; //Used to iterate only when a variable is added to the string from the array
    				   tracker += 1; //Goes up whenever a variable is place 
    			   }
    			   
    			   else
    			   {
    				   output = output + "0" + " ";  //if the value would be below the diagonal it adds a zero and a space
    				   tracker += 1; //This is iterated as a variable is added and this determines whether a row is finnished, counter is not as this value is not from the array (it's below the diagonal)
    			   }
    			   if (tracker == this.n)  //The row is "finished" if tracker is the same as the row length (which is the same as the dimension)
    			   {
    				   output = output + "\n"; //Starts a new line and resets tracker when that happens
    				   tracker = 0;
    			   }
    		   }
    	   }
       
       
       
       return output;
    }
    
    public int getDet(){    //This method returns the determinant of the UpperTriangularMatrix the method is used on
        
    	int a = 0;
		int tracker = 0; //Tracker used in the same way as getelement and setelement methods
		int determinant = this.array[0];        //My code doesn't account for the first entry on the diagonal so I just set the determinant to this initially and multiply in the rest when needed
		
		for( a = 0; a < this.n-1; a ++) 
		{	
			tracker += this.n - a;  //Same as before this finds the position of the diagonal based on the index used by the uppertriangular list
			
			determinant *= this.array[tracker];	 //it then multiplies the entry on the diagonal (along with any previous entries) by the current entry to find the determinant
		}					
		return determinant;
    }
    
}
