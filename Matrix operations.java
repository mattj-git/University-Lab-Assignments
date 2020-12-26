
public class Matrix {          //This entire file is based around making a matrix class and numerous methods that would be useful when working with them
	    
	private int[][]  matrixData;
	private int    rowsNum;	
	private int    colsNum;	
	
	public Matrix( int row, int col )   //This is a constructor which creates an empty matrix (filled with zeroes) with the defined size
	{   

		if (row > 0 && col > 0)    //Deals with the case where both numbers are greater than 0 
		{
			this.matrixData = new int[row][col];       //Since all the information given is valid the object is constructed with the given values
			this.rowsNum = row;		 				   //ie. The array is the requested length, and so are the values for number of columns and rows
			this.colsNum = col;
		}
		
		else if (row <= 0)                 //Deals with all cases where the number of rows is invalid
		{
			
			if (col <= 0)                //If the columns are also invalid then the number of rows and columns is set to 3 as instructed
			{
				this.matrixData = new int[3][3];
				this.rowsNum = 3;
				this.colsNum = 3;
			}
			else
			{
				this.matrixData = new int[3][col];   //If only the rows are invalid then the requested number of columns are created and the rows are set to 3
				this.rowsNum = 3;
				this.colsNum = col;
			}
		}
		
		else if (col <= 0)                //The exact same thing as before now just with the columns being an invalid number
		{			
			if (row <= 0)
			{
				this.matrixData = new int[3][3];
				this.rowsNum = 3;
				this.colsNum = 3;
			}
			else
			{
				this.matrixData = new int[row][3];
				this.rowsNum = row;
				this.colsNum = 3;
			}
		}

	}
	
	public Matrix( int[][] table)  //This is another constructor which creates a matrix object based off of a given array
	{	


		
		int i = 0;   //2 iterating variables
		int o = 0;
		
		this.matrixData = new int[table.length][table[1].length];     //Sets the length of the overall matrixdata array to the overall length of the table (the # of rows)
																	 //Sets the length of each array inside as the length of the inner arrays of the table (they all must be identical)
		for(i = 0; i < table.length; i++)      //Iterates through all the rows of table
		{
			for (o = 0; o < table[1].length; o ++)  //iterates through all the columns of table
			{
				this.matrixData[i][o] = table[i][o];   //Sets the value of matrixdata to the corresponding value in table
			}
		}
		
		
		this.rowsNum = table.length;                //Fills in the remaining necessary information in order to create the object
		this.colsNum = table[1].length;
	}
	
	public int getElement(int i, int j) throws IndexOutOfBoundsException  //This method returns the entry whose position is defined by the 2 given integers
	{ 	

		if (i >= this.rowsNum || i < 0 || j < 0 || j >= this.colsNum)                //Throws the exception if either i or j is too large and is not within the range of the matrix or if it is negative (as that wouldn't make sense on a matrix)
		{
			throw new IndexOutOfBoundsException("Invalid indexes.");
		}
		else
		{
			return this.matrixData[i][j];      //If the exception isn't present then it just return the requested value
		}
	}
        
    public boolean setElement(int x, int i, int j){  //This method sets the entry at the given address to the given value
            
    	if (i>= 0 && i < this.rowsNum && j < this.colsNum && j>= 0)        //only runs the code if the index is valid (not a negative number or not larger than the given matrix)         
    	{
    		this.matrixData[i][j] = x;   //Sets the value accordingly 
    		
    		return true;   //Return true if succesful
    	}
    	return false;  //If not the matrix is unchanged and it returns false
    } 

    public Matrix copy(){  //This function copies the matrix this method is applied to, to another matrix which occupies a different space in memory
        
		Matrix copy = new Matrix (this.matrixData);     //Defines a new matrix (copy) using the matrix data array of the "this/ current" matrix as a table for the function "matrix"
				
		
        return  copy;  //Returns that matrix
    }    
                
	public void addTo( Matrix m ) throws ArithmeticException //This method adds 2 matrices together (the matrix that the method is applied too is the one that stores the sum, not the matrix the method is given)
	{
		
		
		
		if (this.colsNum != m.colsNum || this.rowsNum != m.rowsNum)  //Throws the exception if the matrices aren't the exact same dimensions
		{
			throw new ArithmeticException ("Invalid operation");
		}
		
		int i = 0;
		int o = 0;
		
		for(i = 0; i < this.rowsNum; i++)              //if they are then the next 2 loops iterate through each entry of each row and column and adds them together changing the original "this" matrix
		{
			for (o = 0; o < this.matrixData[i].length; o ++)
			{
				this.matrixData[i][o] += m.matrixData[i][o];
			}
		}
	
	}
	
    public Matrix subMatrix(int i, int j) throws ArithmeticException{   // This method returns a matrix which is a submatrix of the original. The submatrix covers the original matrix up until row i, and up until column j.
        
    	
		Matrix subM = new Matrix (i+1,j+1);                   //Defines a new matrix with the requested size
				
		if (0<= i && this.rowsNum >= i && this.colsNum >= j && 0<= j)          // Only runs the code if the values i and j are less than or equal to the dimensions of the original matrix as a sub matrix can't be larger than the original one
		{																	   //The values of i and j must also be positive
			int a = 0;            
			int b = 0;
			
			for(a = 0; a <= i; a++)                    //iterates from 0 up to the desired row
			{
				for (b = 0; b <= j; b++)              //iterates from 0 up to the desired column
				{
					subM.matrixData[a][b] = this.matrixData[a][b];  //Creates subM matrix with all the entries in that section of the original matrix
				}
			}
		}
		
		else
		{
			throw new ArithmeticException ("Submatrix not defined");  //Throws the exception case if the i and j are too large of a value
		}

        return  subM; 
        
    }
        
    public int getsizeofrows(){   //Returns the number of rows (this is just in case we might want to use this class in another project as all the instance fields are private and this would be the only way to access them)
           
		return this.rowsNum;  //Returns the number of rows
    }
        
    public int getsizeofcols(){ //identical to the last method just with the columns
		
        return this.colsNum;   //Returns the number of columns
    }
        
    public boolean isUpperTr(){  //This method returns a boolean indicating whether the matrix is upper triangular or not.
            
    	int i = 0;  
		int o = 0;
				
		for(i = 0; i < this.rowsNum; i++)  //Iterates through each row
		{
			for (o = 0; o < this.colsNum; o ++)  //Iterates through each column
			{
				if( i > o )            //This condition ensures that the following code only looks at entries that are below the diagonal (not including the diagonal)
				{
					if (this.matrixData[i][o] != 0)  // If any of the values below the diagonal are not 0 then it returns false (as this is a must in order to be uppertriangular)
					{
						return false;
					}
				}
			}
		}
    	
    	
        return true;    //Returns true if it doesn't find anything thats not 0 below the diagonal
	}
        
    public static Matrix sum(Matrix[] matArray) throws ArithmeticException{ //This method takes in an array of matrices and returns the sum of all of them
            
            
        Matrix superMatrix = new Matrix (matArray[0].rowsNum,matArray[0].colsNum);  //Creates a supermatrix with the same dimensions as the entries (stores the sum of all the matrices)
        
        
        int i = 0;
        
        for( i = 0; i < matArray.length; i++) //For loop that iterates through each matrix with matArray
        {
        	if(superMatrix.rowsNum != matArray[i].rowsNum || superMatrix.colsNum != matArray[i].colsNum) //Throws the exception case if one of the entries is not the correct size
        	{
        		throw new ArithmeticException("Invalid operation");
        	}
        	superMatrix.addTo(matArray[i]);  //Adds the 2 matrices together (the supermatrix with whatever entry in matArray we are currently at) using the previous method
        }
            
        return superMatrix; 
    }
        
	public String toString(  )    //This method returns a string representing the content of the matrix
	{
		String output = new String(); 
        
		int i = 0;
		int o = 0;
		
		for(i = 0; i < this.rowsNum; i++)   //2 for loops that iterate through each entry (each row and each columns)
		{
			for (o = 0; o < this.matrixData[i].length; o ++)
			{
				output = output + this.matrixData[i][o] + " ";  //Concactenates output with that value with a space at the end
			}
			output += "\n";   //At the end of each row it starts a new line using the new line character
		}
		
		return output;
	}
    
}
