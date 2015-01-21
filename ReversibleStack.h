#ifndef REVERSIBLESTACK_H // Header guard inclusion.
#define REVERSIBLESTACK_H

// Preprocessor Directives.
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

// Inclusion of the standard library member functions.
using std::getline;
using std::cout;
using std::cin;
using std::cerr;
using std::endl;
using std::ifstream;
using std::string;

// Stack object class.
class ReversibleStack
{
	public:
		ReversibleStack(void); // Constructor
		~ReversibleStack(void); // Destructor

		void Push(int item); // Push an item onto the stack object.
		int Pop(void); // Pop an item off the stack object.
		bool isEmpty(void); // Check to determine if the stack is currently empty.
		void Reverse(void); // Reverse the order of the stack implementation.

		// void setTopNode(int value); - Not necessary for this assignment.
		// int getTopNode_value(void) const; - Not necessary for this assignment.

	private:
		// Self-referential node, will contain our data structure.
		typedef struct node
		{
			int data;
			struct node *pNext; // Pointer to next node.
		}Node;

		Node *makeNode(int value); // Helper function that can only be accessed by the class itself.

		Node *topNode; // Node to the top of the stack.
};

#endif // End of header guard.