/*
A queue which uses a doubly-linked list ADT is implemented in this file using template classes
Created by -- Sowmya Gade: sgade@andrew.cmu.edu
*/

#ifndef QUEUE_H_
#define QUEUE_H_

#include <iostream>
#define SIZE_LIMIT 500

// Linked list element of the queue
template <class T>
class Element_Q
{
	public:

		// Pointer to the data in the linked list node
		T *data;

		// Pointer to the previous element in the stack
		Element_Q<T> *prev;

		// Pointer to the next element in the stack
		Element_Q<T> *next;
};

// Queue
template <class T>
class Queue
{
	private:

		// Pointer to the front element of the queue
		Element_Q<T> *front;

		// Pointer to the back element of the queue
		Element_Q<T> *rear;

		// Size of the queue
		int queueSize;

	public:

		// Constructor for Queue 
		// Creates a Queue object and initializes values of the member variables 
		Queue();

		// Enqueue new data into the queue through the back
		bool Enqueue(T *newData);

		// Dequeue the front element of the queue
		T *Dequeue();

		// Returns a pointer to the front of the queue
		T* Front();

		// Returns the maximum size of the queue
		int Size();

		// Returns the number of elements in the queue
		int numElements();

		// Returns 1 if stack is empty and 0 if stack is not empty
		bool isEmpty();

		// Free all elements in the queue
		void clearQueue();

};




/* ---------------------------------------------------------------------------- */
/* ------------- FUNCTION DEFINTIONS FOR THE QUEUE TEMPLATE CLASS ------------- */
/* ---------------------------------------------------------------------------- */



/// Constructor for Queue 
// Creates a Queue object and initializes values of the member variables 
template <class T>
Queue<T>::Queue()
{
	// Initialize the pointer to the front of the queue to NULL 
	front = NULL;

	// Initialize the pointer to the rear of the queue to NULL
	rear = NULL;

	// Set the size of the queue to 0
	queueSize = 0;
}


// Enqueue new data into the queue through the back
template <class T>
bool Queue<T>::Enqueue(T *newData)
{
	bool status = true; 

	// Check if the queue is full
	if (queueSize >= SIZE_LIMIT)
	{
		printf("Queue Overflow! \n");
		status = false;
		return status;
	}
	
	// Create a new element
	Element_Q<T> *newElement = new Element_Q<T>;

	// Check if the new element will be the first element
	if (queueSize == 0)
	{
		// Next element of the first element is NULL
		newElement->next = NULL;

		// Previous element of the first element is NULL
		newElement->prev = NULL;

		// The front of the queue is the new element
		front = newElement;

		// The rear of the queue is the new element
		rear = newElement;
	}
	else
	{
		// The new element is added from the rear
		rear->next = newElement;

		// The current rear has its previous pointer to the new element
		newElement->prev = rear;

		// The next element of the last member of the queue is set to NULL
		newElement->next = NULL;

		// The rear of the queue is updated to be the new element
		rear = newElement;
	}

	// The data of the rear element is updated
	rear->data = newData;

	// The queue size is updated
	queueSize = queueSize + 1;

	return status;
}


// Dequeue the front element of the queue
template <class T>
T *Queue<T>::Dequeue()
{
	// Check if the queue is empty
	if (queueSize == 0)
	{
		printf("Underflow Error! \n");

		return NULL;
	}	

	else
	{
		// Create temporary data
		T *tempData = new T;

		// Initialize the temp data pointer to the front data
		tempData = front->data;

		// Create a temporary element
		Element_Q<T> *tempElement;

		// The temporary element points to the front element
		tempElement = front;

		// Front pointer is moved to the next element in the queue
		front = front->next;
		
		// If the queue has more than one element
		if (front != NULL)
			// The previous pointer of the first element is set to NULL
			front->prev = NULL;

		// The temporary pointer is set to NULL
		tempElement = NULL;

		// The queue size is updated
		queueSize = queueSize - 1;

		// The previous front of the queue is returned
		return tempData;
	}
}

// Returns a pointer to the front of the queue
template <class T>
T *Queue<T>::Front()
{
	// Check if the queue is empty
	if (front == NULL)
	{		
		// Return NULL pointer 
		return NULL;
	}
	// If the queue is not empty
	else
	{
		// Declare variable for data at the front of the queue
		T *frontData = new T;
		
		frontData = front->data;
		
		// Return pointer to value at the front of the queue
		return frontData;
	}
}


// Returns the maximum size of the queue
template <class T>
int Queue<T>::Size()
{
	return SIZE_LIMIT;
}

// Returns the number of elements in the queue
template <class T>
int Queue<T>::numElements()
{
	return queueSize;
}

// Returns 1 if stack is empty and 0 if stack is not empty
template <class T>
bool Queue<T>::isEmpty()
{
	// Check - no elements in the queue
	if (queueSize == 0)
	{
		return true;
	}
	// Queue is not empty
	else
	{
		return false;
	}
}

// Free all elements in the queue
template <class T>
void Queue<T>::clearQueue()
{
	T *frontData;

	while(front != NULL)
	{
		// Get the top element of the stack
		frontData = Dequeue();

		// Free the element
		delete(frontData);
	}

	// Update number of elements
	queueSize = 0;

}

#endif