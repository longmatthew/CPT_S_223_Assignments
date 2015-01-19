#ifndef REVERSIBLESTACK_H
#define REVERSIBLESTACK_H

#include <string>
#include <iostream>
#include <fstream>

using std::getline;
using std::cout;
using std::cin;
using std::cerr;
using std::endl;
using std::ifstream;
using std::string;

class ReversibleStack
{
	public:
		ReversibleStack(void);
		~ReversibleStack(void);

		void Push(int item);
		int Pop(void);
		bool isEmpty(void);
		void Reverse(void);

		// void setTopNode(int value); - Not necessary for this assignment.
		// int getTopNode_value(void) const; - Not necessary for this assignment.

	private:
		typedef struct node
		{
			int data;
			struct node *pNext;
		}Node;

		Node *makeNode(int value);

		Node *topNode;
};

#endif