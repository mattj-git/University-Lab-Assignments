
public class SLLSet { //This class and all the methods defined in it are used to implement the idea of a linked list 
	
    private int size;  //This instance method represents how many entries are "in" the linked list
    private SLLNode head; //This defines the "head" or the first entry in the linked list

    public SLLSet() { //A constructor method that defines an empty linked list (ie. the size is 0 and the head does not exist
    	
    	this.size = 0;        //Sets the size to 0 (as there are no entries in the linked list)
    	this.head = null;    //Sets the pointer in head to null as the list shouldn't be "going/leading anywhere"
    	
    }

    public SLLSet(int[] sortedArray) { //Creates a linked list based on the given array (note: The values are in increasing order with no repetitions) 
        
    	this.size = sortedArray.length;          //Sets the size instance field to what it will be due to the array
    	
    	SLLNode last_node = new SLLNode(sortedArray[this.size - 1],null);  //Initializes the last node in the list. It points to nothing since its the last one in the list, and its the last value in the list at (index-1)
    	
    	int i = 0;
    	
    	for (i = this.size - 2; i > 0 ; i--)   //This for loop iterates for the last iteration of the linked list too the first (This is much easier as when creating the linked list you need the next entry available, technically the last entry is the only one you know as it points to nothing)
    	{                                      //For any other entry of the list you'd have the value but you'd have to point to something that you haven't made yet when filling in the next value, which makes this much more difficult to do from the beginning of the list 
    		last_node = new SLLNode(sortedArray[i], last_node);     //In this line you're always updating last_node to be one entry further to the beginning (with the appropriate value), while pointing back to the node you created last time
    	}
    	
    	this.head = new SLLNode (sortedArray[0], last_node);   //With the for loop I had set up, it was just easiest to deal with the head separately and that's what this line is doing (the value must be at index [0], and points to the very last last_node I made in the loop)
    	}
    	
    	

    public int getSize() { //This method returns the size of the linked list
    	
    	
    	return this.size ;   //This is fairly simple, I just returned the value that it needs (I realized this was pretty lazy and it made me write a few extra lines in later codes)
    }

	
    public SLLSet copy() { // This method returns a copy of the linked list this method is used on (a copy which does not occupy the same space in memory).
        
    	int i = 0;
    	
    	int values[] = new int[this.size];      //Created a list of values with the same size as linked list
    	
    	SLLNode temp = this.head;     //Created a node which I use to iterate through the linked list 
    	
    	for (i = 0; i < this.size; i ++)  //Makes sure I only iterate through the linked list the necessary amount of times
    	{
    		values[i] = temp.value;       //Sets the value in the list equal to the appropriate value
    		temp = temp.next;          // "Iterates" through the linked list by setting the node to its "next" value
    		
    	}
    	
    	
        return new SLLSet(values);         //Lastly I plug the list I created into the previous constructor to return the copy
    }

	
    public boolean isIn(int v) { //This method determines whether the given integer is in the linked list the method is used on
        
    	int i = 0; //2 iterating variables used to iterate through for loops
    	int a = 0;
    	
    	int values[] = new int[this.size];  
    	
    	SLLNode temp = this.head;
    	
    	for (i = 0; i < this.size; i ++)
    	{
    		values[i] = temp.value;
    		temp = temp.next;
    		
    	}                                  //Everything up until this point is finding a list of values like in the last method
    	
    	for (a = 0; a < this.size; a++)   //I then use a for loop to check if that value is in the list of values, if so it returns true, if not false
    	{
    		if( values[a] == v)           
    			return true;
    	}
        

        return false;
    }

    public void add(int v) { //This method adds an element to the linked list (while maintaining the ascending order).
    	if (isIn(v) == false)                 //First I check to see if the value is in the linked list, and if it isn't then the following code runs,and if not nothing happens
    	{
    		
    		SLLNode current = this.head;      //A node to "store" the info of the variable I'm currently iterating through
    		
    		SLLNode predecessor = this.head;  //A node to "store" the info of the variable I previously iterated through
    		
    		SLLNode new_node;            //A node that is used to insert the node that we want to add
    		
    		int original_size = this.size;  //I use the size of the list to check to see if I've made any additions 
    		
    		
    		if (this.head.value > v)     //This checks to see if the first value must be replaced (as you would put it "in" before the value greater than it, since the list is ordered)    
    		{
    			new_node = new SLLNode(v,this.head); //Creates a new node with value v, with a next value pointing to head
    			this.head = new_node;               //Sets the head to the node we just created
    			this.size += 1;                    //Adjusts the size of the list
    		}
    		
    		if (original_size == this.size)   //If the size didn't change then the following code will run
    		{
    		
	    		while (current.next != null) //While loop that iterates as long as the next value isn't null
	    		{
	    			if (current.value > v) // This checks to see if I should add in the value, as the list must be ordered
	    			{
	    				new_node = new SLLNode (v, current);  //Adds in the node the same way it was done on lines 97-98
	    				predecessor.next = new_node;
	    				this.size += 1;
	    				break;                    //The break is here to ensure that it doesn't add it in again (as every value after this would also satisfy the if statement on line 107
	    				
	    			}
	    			
	    			predecessor = current;    //The same way as in other methods I iterate through the linked list
	    			current = current.next;
	    			
	    		}
    		}
    		
    		if (original_size == this.size)      //The above while loop won't deal with the case where the added value is tacked on to the end
    		{                                   //On the above line it also checks to make sure the size wasn't changed, and therefore nothing had been added
    			new_node = new SLLNode (v,null); // Similarily to the past 2 cases I just add a node, but in this case the next value points to null as its the last in the list
    			current.next = new_node;
    			this.size += 1;
    		}
    	}
    }

    public void remove(int v) {// This method removes the given value from the linked list
    	
    	if (this.isIn(v))        //Checks to see if the value it wants to remove is in the Linked list
    	{
    		SLLNode current = this.head;     //Next 2 lines create storage nodes similar to the last method
    		
    		SLLNode predecessor = this.head;
    		    		    		
    		if (this.head.value == v)             //Checks the case if the first value is the first one that must be removed
    		{
    			this.head = this.head.next;       //"Removes" the head from the loop by making the value after head the new head
    			this.size -= 1;                  //Also shrinks the size by one as one entry is removed
    		}
    		
    		else           //Deals with all other cases where the removed value isn't the head
    		{
    			while(current != null)         //Iterates through the entire list similar to the last method
    			{
    				if (current.value == v)     //Checks to see if the current value is the value that must be removed
    				{
    					predecessor.next = current.next; //Removes it in the same way it was removed earlier in this method
    					this.size -= 1;
    				}
    				predecessor = current;  //iterates through the list the same way as before
    				current = current.next;
    			}
    		}
    	}
        
    }

    public SLLSet union(SLLSet s) { //This method returns a linked list which represents the union of the linked list given to the method, and the linked list the method is used on
	                           //The union contains all values within both the lists
    	
    	if (this.size == 0 || s.size == 0)   //If either LL is empty than this would take care of that case
    	{
    		if (this.size == 0) //If "this" is empty than that means union is just the values in s, so I return a copy of s
    		{
    			return s.copy();
    		}
    		else   //Likewise if s is empty than I return a copy of "this"
    		{
    			return this.copy();
    		}
    	}
    	
    	SLLNode node = this.head; //Node used to iterate through the LL
    	
    	while ( node != null) //While loop that iterates through the LL
    	{
    		s.add(node.value); //Adds every value from this to s, so that everything is in the list s (but won't add repetitions due to how the add method works)
    		node = node.next; //Iterates through the nodes as done before
    	}

        return s.copy(); //Returns a copy of s (which now represents the union of "this" and s)
    }

    public SLLSet intersection(SLLSet s) { //This method returns a linked list which represents the intersection of the linked list given to the method, and the linked list the method is used on
	                                  //The intersection contains all values that are within both the linked lists
    	
    	SLLNode current = s.head; //Node used to iterate through the LL
    	    	
    	while (current != null) //While loop that iterates to the LL
    	{
    		if(this.isIn(current.value) == false) //Checks to see if the currently iterated through value is in "this" LL 
    		{
    			s.remove(current.value); //If it isn't than it removes it from s
    			
    		}             //So by the end of the while loop only values that are in both will be lift in s
    		
    		current = current.next; //Used to iterate through the LL as i've done before
    	}
    	    	    	
        return s; //Returns s
    }

    public SLLSet difference(SLLSet s) {  //This method returns the difference of the linked list the method is used on and the linked list given to the method
	    				 //The difference is all the values which are in the linked list the method is used on, and NOT in the linked list given to the method (in brackets)
        
    	SLLNode current = this.head; //Node used to iterate through the linked list
    	
    	while ( current != null) // While loop that goes through the LL
    	{
    		if (s.isIn(current.value) == true)
    		{
    			this.remove(current.value); //If the values are in both lists then it removes them from "this"
    		}
    		                               //By the end you will only be left with values in "this" that are not in s
    		current = current.next;        //Iterates through the LL
    	}
    	
    
    	
        return this;   //Returns this linked list
    }

    public static SLLSet union(SLLSet[] sArray) {   //This method returns a linked list representing the union of every linked list in the array
        SLLSet ss = new SLLSet();
        
        int i = 0;     //Iterating variable
        
        for ( i = 0; i < sArray.length; i ++)  //For loop that iterates through the entire array of sets
        {
        	ss = sArray[i].union(ss); //Constantly unions the ss variable with itself and the next set in the array
        }
        

        return ss; //Returns the final set
    }

    public String toString() { //This method returns a string representation of the linked list 
    	String output = new String();          //Creates a new empty output string
    	 
    	int i  = 0;         //Iterating variable           
    	
    	SLLNode temp = this.head;     //Node to iterate through the LL
    	
    	for (i = 0; i < this.size; i++) //For loop that goes through the entire LL
    	{
    		if (i == this.size-1)    //This only applies for the last entry in the LL
    		{
    			output = output + temp.value;  //In this case you dont want a comma and a space at the end, so just the variable is added
    			return output;    //Then it's returned
    		}
    		output = output + temp.value + ", ";     //If its not the last case then variable is added along with the comma and space
    		temp = temp.next;    //Iterates through LL
    	}
    	
		return output; 
    	
    	
    }
}
