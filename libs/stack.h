/*
A stack which uses a singly-linked list ADT is implemented in this file using template classes
Created by -- Sowmya Gade: sgade@andrew.cmu.edu
*/




#include <iostream>
#define SIZE_LIMIT 500

// Linked-list element of the stack
template <class T>
class Element
{
	public:

		// Pointer to the data in the linked list node
		T *data;

		// Pointer to the next element in the stack
		Element<T> *prev;
};

// Stack class
template <class T>
class Stack
{
	private:

		// Top element in the stack
		Element<T> *top;

		// Size of the stack
		int stackSize;
		
	public:

		// Constructor for Stack 
		// Creates a Stack object and initializes values of the member variables 
		Stack();

		// Push a new element onto the stack
		bool push(T *newData);

		// Pop the top element of the stack
		T *pop();

		// Returns the value of the top element of the stack
		T *peek();

		// Returns 1 if stack is empty and 0 if stack is not empty
		bool isEmpty();

		// Returns the value for the number of elements in the stack
		int numElements();

		// Returns the size of the stack
		int Size();

		// Free elements in the stack
		void clearStack();

};


/* ---------------------------------------------------------------------------- */
/* ------------- FUNCTION DEFINTIONS FOR THE STACK TEMPLATE CLASS ------------- */
/* ---------------------------------------------------------------------------- */

/* Constructor for Stack creates a Stack object and initializes values of the member variables */
template <class T>		
Stack<T>::Stack()
{
	// Initialize the top element to a NULL pointer
	top = NULL;

	// Stack size in the beginning is zero
	stackSize = 0;
}


/* Push an element into the stack */
template <class T>
bool Stack<T>::push(T *newData)
{	
	bool status = true;

	// Create a new_element to push into the stack
	Element<T> *newElement = new Element<T>;
	
	// Check for stack overflow
	if(stackSize >= SIZE_LIMIT)
	{
		std::cout << "\nOverflow Error!\n";
		status = false;
		return status;
	}

	// Check if the stack is empty
	if(top == NULL)
	{	
		
		// New element is the only element in the stack
		newElement->prev = NULL;
		
	}
	// If the stack is not empty
	else
	{	
		
		// New element is the top-most element in the stack
		newElement->prev = top;	
	}

	// Initialize the value of the top-most element
	newElement->data = newData;

	// Assign the top-most element to the new element
	top = newElement;	

	// Update the number of elements in the stack
	stackSize = stackSize + 1;

	// Return a 'true' status for a successful push onto the stack
	return status;
}

/* Pop the top element of the stack */
template <class T>
T *Stack<T>::pop()
{
	// Check if stack is empty
	if (top == NULL)
	{
		std::cout << "\nUnderflow Error!\n";
		
		// Return NULL pointer 
		return NULL;
	}

	// If the stack is not empty
	else
	{	
		// Declare temporary element pointer
		Element<T> *tempElement;

		// Declare temporary data 
		T *tempData = new T;

		// Save the top-most data in a temporary variable
		tempData = top->data;

		// Save the top-most element in a temporary pointer
		tempElement = top;

		// Assign the top-most element to the previous element in the stack
		top = top->prev;

		// Delete the temporary pointer
		tempElement = NULL;

		// Update the number of elements in the stack
		stackSize = stackSize - 1;	
		
		// Return the popped element
		return tempData;	
	}

}


/* Returns the value of the top element of the stack */
template <class T>
T *Stack<T>::peek()
{
	// Check if the stack is empty
	if (top == NULL)
	{		
		// Return NULL pointer 
		return NULL;
	}
	// If the stack is not empty
	else
	{
		// Declare variable for data on the top of the stack
		T *topData = new T;
		
		topData = top->data;
		
		// Return pointer to value on the top of the stack
		return topData;
	}
}

/* Returns - 1 if stack is empty and zero if stack is not empty */
template <class T>
bool Stack<T>::isEmpty()
{
	// Check - no elements in the stack
	if (stackSize == 0)
	{
		return true;
	}
	// Stack is not empty
	else
	{
		return false;
	}
}


/* Returns the value for the number of elements in the stack */
template <class T>
int Stack<T>::numElements()
{
	return stackSize;
}


/* Returns the size of the stack*/
template <class T>
int Stack<T>::Size()
{
	return SIZE_LIMIT;
}


/* Free elements in the stack */
template <class T>
void Stack<T>::clearStack()
{
	T *topData;

	while(top!=NULL)
	{
		// Get the top element of the stack
		topData = pop();

		// Free the element
		free(topData);
	}

	stackSize = 0;

}
