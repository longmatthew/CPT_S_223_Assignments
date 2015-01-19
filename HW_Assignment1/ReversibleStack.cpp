#include "ReversibleStack.h"

ReversibleStack::ReversibleStack()
{
	topNode = NULL;
}

ReversibleStack::~ReversibleStack()
{
	Node *pCur = topNode;
	Node *Next_node = NULL;

	while (pCur != NULL)
	{
		Next_node = pCur->pNext;
		delete pCur;
		pCur = Next_node;
	}

	topNode = NULL;
}

void ReversibleStack::Push(int item)
{
	Node *pMem = NULL;

	pMem = makeNode(item);

	if (pMem != NULL)
	{
		pMem->pNext = topNode;
		topNode = pMem;
	}
}

int ReversibleStack::Pop()
{
	int temp_val = 0;
	Node *tempNode = topNode;

	if (isEmpty())
	{
		cout << "The stack is empty, unable to Pop() from stack." << endl;
	}

	temp_val = topNode->data;
	topNode = topNode->pNext;

	delete tempNode;

	return temp_val;
}

bool ReversibleStack::isEmpty()
{
	if (topNode == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void ReversibleStack::Reverse()
{
	Node *pPrev = NULL;
	Node *pCur = topNode;
	Node *Next_node = NULL;

	while (pCur != NULL)
	{
		Next_node = pCur->pNext;
		pCur->pNext = pPrev;
		pPrev = pCur;
		pCur = Next_node;
	}

	topNode = pPrev;
}

ReversibleStack::Node *ReversibleStack::makeNode(int value)
{
	Node *pMem = NULL;

	pMem = new Node;

	if (pMem == NULL)
	{
		cerr << "Unable to allocate enough memory" << endl;
	}
	else 
	{
		pMem->data = value;
		pMem->pNext = NULL;
	}

	return pMem;
}

/*void ReversibleStack::setTopNode(int value)
{
	topNode->data = value;
	topNode->pNext = NULL;
}

int ReversibleStack::getTopNode_value(void) const
{
	return topNode->data;
}*/
