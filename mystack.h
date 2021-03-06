#ifndef MYSTACK_H
#define MYSTACK_H

//***************************************//
//static stack template                  //
//finish all functions                   //
//***************************************//

#include <iostream>
using namespace std;

template <class T>
class MyStack
{
private:
   T *stackArray;  // Pointer to the stack array
   int stackSize;    // The stack size
   int topIndex;		//index of the top element in the stack array

public:
   // Constructor
   MyStack(int);	//pass in an int: tells the maximum size of the stack

   // Copy constructor
   MyStack(const MyStack &);

   //operator= overloading
   MyStack& operator=(const MyStack &);

   // Destructor
   ~MyStack();

   // Stack operations
   void push(T);	//add an item to the stack by passing in a value
   T pop();	//pop a value out by returning the value
   T top();	//return the value at the top position in the stack
   bool isFull() const;	//tell if the statck is full
   bool isEmpty() const;	//tell if the stack is empty
   int size() const;	//tell how many items are in the stack
};


//***********************************************
// Constructor                                  *
// This constructor creates an empty stack. The *
// size parameter is the size of the stack.     *
//***********************************************
template <class T>
MyStack<T>::MyStack(int size) {
   stackArray = new T[size];
   stackSize = size;
   topIndex = -1;
}

//***********************************************
// Copy constructor                             *
//***********************************************
template <class T>
MyStack<T>::MyStack(const MyStack<T> & obj) {
   // Create the stack array.
   if (obj.stackSize > 0)
      stackArray = new T[obj.stackSize];
   else
      stackArray = nullptr;

   // Copy the stackSize attribute.
   stackSize = obj.stackSize;

   // Copy the stack contents.
   for (int count = 0; count < stackSize; count++)
      stackArray[count] = obj.stackArray[count];

   // Set the top of the stack.
   topIndex = obj.topIndex;
}

//***********************************************
// Operator= overloading                        *
//***********************************************
template <class T>
MyStack<T>& MyStack<T>::operator=(const MyStack<T> & obj) {
   // Create the stack array.
   if (obj.stackSize > 0)
      stackArray = new T[obj.stackSize];
   else
      stackArray = nullptr;

   // Copy the stackSize attribute.
   stackSize = obj.stackSize;

   // Copy the stack contents.
   for (int count = 0; count < stackSize; count++)
      stackArray[count] = obj.stackArray[count];

   // Set the top of the stack.
   topIndex = obj.topIndex;

   return *this;
}

//***********************************************
// Destructor                                   *
//***********************************************
template <class T>
MyStack<T>::~MyStack() {
     if (stackArray) {
         delete[] stackArray;
     }
 }

//***********************************************
// Push                                         *
//***********************************************
template <class T>
void MyStack<T>::push(T value) {
   if (isFull()) {
      std::cout << "The stack is full.\n";
   }
   else {
      topIndex++;
      stackArray[topIndex] = value;
   }
}

//***********************************************
// Pop                                          *
//***********************************************
template <class T>
T MyStack<T>::pop() {
   if (isEmpty()) {
      std::cout << "The stack is empty.\n";
   }
   else {
      topIndex--;
   }
   return stackArray[topIndex + 1];
}

//***********************************************
// Top                                          *
//***********************************************
template <class T>
T MyStack<T>::top() {
   return stackArray[topIndex];
}

//***********************************************
// isFull                                       *
//***********************************************
template <class T>
bool MyStack<T>::isFull() const {
    return (topIndex == stackSize - 1);
}

//***********************************************
// isEmpty                                      *
//***********************************************
template <class T>
bool MyStack<T>::isEmpty() const {
   return (topIndex <= -1);
}

//***********************************************
// Size                                         *
//***********************************************
template <class T>
int MyStack<T>::size() const {
   return topIndex + 1;
}

#endif
