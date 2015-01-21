#include "ReversibleStack.h" // Header inclusion.

// Constructor, will initialize topNode to NULL to create an empty stack.
ReversibleStack::ReversibleStack()
{
	topNode = NULL;
}

// Destructor - although not needed; will delete nodes in a stack object.
ReversibleStack::~ReversibleStack()
{
	// Initialize variables; set topNode to pCur Node to delete later.
	Node *pCur = topNode;
	Node *Next_node = NULL;

	// While the current or top node is not null, delete this node and move to the next.
	// replacing the Next_node with current nodes next.
	while (pCur != NULL)
	{
		Next_node = pCur->pNext; // topNodes next node.
		delete pCur; // Delete topNode.
		pCur = Next_node; // Set topNode to the position of the next node in the stack.
	}

	// Since the list is now empty; topNode will need to be set to NULL to avoid errors.
	topNode = NULL;
}

// Push an item onto the stack.
void ReversibleStack::Push(int item)
{
	// Initialize new Node block.
	Node *pMem = NULL;

	pMem = makeNode(item); // Create the block to be added to the stack.

	// Should their be enough memory allocated we will assign this new node
	// onto the stack.
	if (pMem != NULL)
	{
		pMem->pNext = topNode; // Assign new nodes next to the position of topNode.
		topNode = pMem; // Assign topNode to the location of new Node.
	}
}

// Pop an item off the stack.
int ReversibleStack::Pop()
{
	// Initialize variables and Nodes.
	int temp_val = 0; // Temporary int hold variable.
	Node *tempNode = topNode; // Temporary Node to hold contents from topNode.

	// Defensive Programming; check to see if the stack is already empty before popping.
	//  Display a message if the stack is empty.
	if (isEmpty())
	{
		cout << "The stack is empty, unable to Pop() from stack." << endl;
	}
	else
	{
		temp_val = topNode->data; // Place the item in the top node in the temporary int storage to be returned.
		topNode = topNode->pNext; // Move the position of the topNode to topNode next Node.

		delete tempNode; // Delete the node at topNodes position.
	}

	return temp_val; // Return the temporary int variable.
}

// Determine if the stack is empty.
bool ReversibleStack::isEmpty()
{
	// If not empty return false; otherwise return true.
	if (topNode == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// Reverse the order the stack has been implemented.
void ReversibleStack::Reverse()
{
	// Initialize Nodes; we will need the position of the previous node
	// current node and the next node after current.
	Node *pPrev = NULL;
	Node *pCur = topNode; // Set current node to top node.
	Node *Next_node = NULL;

	// While the stack is not empty, we will swap the elements
	// in the stack.
	while (pCur != NULL)
	{
		Next_node = pCur->pNext; // Set the position of Next_node to topNodes next node.
		pCur->pNext = pPrev; // Break the connect from topNodes next to point to a previous node.
		pPrev = pCur; // Set the position of the previous node to the current node position.
		pCur = Next_node; // Set the position of the current node to the next node position.
	}

	topNode = pPrev; // Set the topNode position to pPrev node; where the beginning of the stack is now.
}

// Helper function to allocate memory.
ReversibleStack::Node *ReversibleStack::makeNode(int value)
{
	// Initialize new Node.
	Node *pMem = NULL;

	pMem = new Node; // Allocate new memory.

	// If the memory was not able to be allocated; send an error message.
	if (pMem == NULL)
	{
		cerr << "Unable to allocate enough memory" << endl;
	}
	else
	{
		// Give data to memory block.
		pMem->data = value;
		pMem->pNext = NULL;
	}

	return pMem; // return the Node.
}

// These functions are not needed.
/*void ReversibleStack::setTopNode(int value)
{
topNode->data = value;
topNode->pNext = NULL;
}

int ReversibleStack::getTopNode_value(void) const
{
return topNode->data;
}*/
