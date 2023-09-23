#ifndef _QUEUE_H_
#define _QUEUE_H_

#include "stack_class.h"
#include <stdexcept>
using namespace std;

template <typename Object>
class Queue {
  private:
	Stack<Object> *stack1, *stack2; //enqueue & dequeue


  public:
	Queue() {
		stack1 = new Stack<Object>();
		stack2 = new Stack<Object>();
	}

	~Queue() {
		delete stack1, stack2;
	}

	bool empty() { return (stack1->empty() && stack2->empty()); }
	
	Object front() { 						// front function
		if (empty()) {
			throw runtime_error("queue is empty.");
		}

		if (stack2->empty()) { 				//if stack2 is empty, move all elements from stack1 to stack2
			while(!stack1->empty()) { 
				stack2->push(stack1->pop()); //push the top element of stack1 to stack2
			}
		}
		return stack2->top(); //return the top element of stack2
	}

	Object get(){ 								// dequeue function
		if (empty()) {
			throw runtime_error("queue is empty.");
		}

		if (stack2->empty()){ 					//if stack2 is empty, move all elements from stack1 to stack2
			while(!stack1->empty()){ 			//while stack1 is not empty
				stack2->push(stack1->pop());	//push the top element of stack1 to stack2
			}
		}
		return stack2->pop(); //pop the top element of stack2
	}

	void put(const Object x) { // enqueue function
		stack1->push(x);
	};
};

#endif
