/*

A doubly-linked list ADT is implemented in this file using template classes

Created by -- Sowmya Gade: sgade@andrew.cmu.edu
*/



#include <iostream>

// Linked list node
template <class T>
class Node
{
	public:
		T *data;

		Node<T> *next;

		Node<T> *prev;
};

// Linked list class
template <class T>
class LinkedList
{
	private:

		// Pointer to the front of the linked list
		Node<T> *front;

		// Pointer to the rear of the linked list
		Node<T> *rear;

		// Length of the linked list
		int length;

		// Recursive quick sort 
		void quickSortRecursive(Node<T> *l, Node<T> *r);

		// Create a list with partition at the pivot value
		Node<T> *partition(Node<T> *l, Node<T> *r);

	public:

		// Constructor for the linked list
		LinkedList();

		// Add a new element to the linked list
		void append(T *new_data);	

		// Swap two elements given by pointers
		void swap(T *a, T *b);		

		// Quick sort interface
		void quickSort();

		// Print all elements of the linked list
		void print();

		// Clear the linked list
		void clear();
};




/* ---------------------------------------------------------------------------------- */
/* ------------- FUNCTION DEFINTIONS FOR THE LINKED LIST TEMPLATE CLASS ------------- */
/* ---------------------------------------------------------------------------------- */


// Constructor for the linked list
template <class T>
LinkedList<T>::LinkedList()
{
	front = NULL;

	rear = NULL;

	length = 0;
}


// Add a new element to the linked list
template <class T>
void LinkedList<T>::append(T *new_data)
{
	Node<T> *newNode = new Node<T>;

	newNode->data = new_data;

	newNode->next = NULL;

	if (front == NULL)
	{
		newNode->prev = NULL;

		front = newNode;

		rear = newNode;
	}
	else
	{
		newNode->prev = rear;

		rear->next = newNode;

		rear = newNode;
	}

	length = length + 1;
}


// Swap two elements given by pointers
template <class T>
void LinkedList<T>::swap(T *a, T *b)
{
	T* temp = new T;
	
	*temp = *a;
	
	*a = *b;
	
	*b = *temp;

	delete temp;

}


// Print all elements of the linked list
template <class T>
void LinkedList<T>::print()
{
	Node<T> *tempNode;

	tempNode = front;

	while(tempNode != NULL)
	{
		std::cout << tempNode->data ;

		tempNode = tempNode->next;
	}

	tempNode = NULL;
}

// Quick sort interface
template <class T>
void LinkedList<T>::quickSort()
{

	// Call the recursive quick sort
	quickSortRecursive(front, rear);	
}


// Recursive quick sort implementation
template <class T>
void LinkedList<T>::quickSortRecursive(Node<T> *l, Node<T> *r)
{
	
	if ((r != NULL) && (l != r) && (l != r->next))
	{
		
		Node<T> *p = partition(l,r);
	
		quickSortRecursive(l, p->prev);
		
		quickSortRecursive(p->next, r);

	}
}


// Create a list with partition at the pivot value
template <class T>
Node<T> *LinkedList<T>::partition(Node<T> *l, Node<T> *r)
{
	// Set pivot element as the first element
	T *pivot = r->data;

	// Create a node with previous element of the left
	Node<T> *l_prev = l->prev;
	
    for (Node<T> *i = l; i != r; i = i->next)
    {
    	// Check if node is 
        if (*(i->data) <= *pivot)
        {
            // Check if previous is the last element
            if (l_prev == NULL)
            {
            	l_prev = l;
            }
            	
            // Go to the next element
            else
            {
            	l_prev = l_prev->next;
            }
 			
 			// Swap the values
            swap((l_prev->data), (i->data));
        }
    }

    // Check if the last element is reached
    if (l_prev == NULL)
    	l_prev = l;
    // Go to the next element
    else
    	l_prev = l_prev->next;

    // Perform a final swap
    swap((l_prev->data), (r->data));


    return l_prev;
}


// Clear all elements in the linked list
template <class T>
void LinkedList<T>::clear()
{
	Node<T> *tempNode;

	// Clear all elements
	while (front != NULL)
	{
		tempNode = front;

		front = front->next;

		delete(tempNode);

		length = length - 1;
	}
}