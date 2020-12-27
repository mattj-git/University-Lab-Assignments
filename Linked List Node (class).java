
class SLLNode { //This is used to  implement a linked list as a class, and each entry/ "node" is defined as this class
    int value; //In a linked list each entry has avalue represented by this instance variable
    SLLNode next; //This instance variable is a pointer pointing to the next node/entry in the linked list

    SLLNode(int i, SLLNode n) { //This method is a constructor for the node.
        this.value = i;
        this.next = n;
    }
}



//There's not much in this class file but this class is used to implement the linked list class in the "linked list (class)" file