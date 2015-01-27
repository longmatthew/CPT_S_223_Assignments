#include "HW2BST.h"

using namespace std;

HW2BST::Node::Node(int dataValue)
{
	Data = dataValue;
	Left = Right = NULL;
}

HW2BST::HW2BST(void)
{
	m_root = NULL;
}

HW2BST::~HW2BST(void)
{
	DeleteTree(m_root);
	m_root = NULL;
}

// Should return false if the value already exists in the tree or if memory 
// for a new node could not be allocated.
bool HW2BST::Add(int dataValue)
{
	// You must implement this function
	return AddNode(m_root, dataValue);
}

bool HW2BST::Validate(Node *pMem)
{
	if (pMem)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool HW2BST::AddNode(Node *pMem, int tempValue)
{
	if (pMem == NULL)
	{
		pMem = new Node(tempValue);
		return Validate(pMem);
	}

	if (pMem->Data < tempValue)
	{
		return AddNode(pMem->Left, tempValue);
	}
	else if (pMem->Data > tempValue)
	{
		return AddNode(pMem->Right, tempValue);
	}
	else
	{
		return false;
	}
}

// Returns the number of levels in the tree. A tree with no contents (null root) will have 
// zero levels. A tree with just the root and no children has 1 level. For all other cases 
// the number of levels must be counted. There is a linear-time algorithm for this.
int HW2BST::CountLevels()
{
	// You must implement this function
	return treeHeight(m_root);
}

int HW2BST::treeHeight(Node *pMem)
{
	if (pMem == NULL)
	{
		return 0;
	}

	int left_height = treeHeight(pMem->Left);
	int right_height = treeHeight(pMem->Right);

	return (left_height > right_height) ? left_height + 1 : right_height + 1;
}

void HW2BST::DeleteTree(Node* root)
{
	if (root)
	{
		DeleteTree(root->Left);
		DeleteTree(root->Right);
		delete root;
	}
}

void HW2BST::DisplayContents(Node* node, ostream& outputStream)
{
	if (node)
	{
		DisplayContents(node->Left, outputStream);

		// Display the numerical value for this node
		outputStream << node->Data << " ";

		// Display the entire right subtree
		DisplayContents(node->Right, outputStream);
	}
}

void HW2BST::DisplayContents(ostream& outputStream)
{
	outputStream << "BST Contents: ";
	DisplayContents(m_root, outputStream);
	outputStream << endl;
}

void HW2BST::DisplayLevels(std::ostream& outputStream)
{
	// You must implement this function
}

// Gets the maximum value in the tree. Returns 0 if the tree is empty.
int HW2BST::GetMax()
{
	if (m_root)
	{
		Node* n = m_root;
		while (n->Right)
		{
			n = n->Right;
		}
		return n->Data;
	}
	return 0;
}

bool HW2BST::IsEmpty()
{
	return (NULL == m_root);
}

// Returns true if the value was found and removed, false if it was not found
bool HW2BST::Remove(int dataValue)
{
	// You must implement this function
	return DeleteNode(m_root, dataValue);
}

bool HW2BST::DeleteNode(Node *pMem, int tempValue)
{
	if (pMem == NULL)
	{
		return false;
	}
	else if (tempValue < pMem->Data)
	{
		return DeleteNode(pMem->Left, tempValue);
	}
	else if (tempValue > pMem->Data)
	{
		return DeleteNode(pMem->Right, tempValue);
	}
	else
	{
		if ((pMem->Right == NULL) && (pMem->Left == NULL))
		{
			delete pMem;
			pMem = NULL;
		}
		else if (pMem->Left == NULL)
		{
			Node *pTemp = pMem;
			pMem = pMem->Right;
			delete pTemp;
		}
		else if (pMem->Right == NULL)
		{
			Node *pTemp = pMem;
			pMem = pMem->Left;
			delete pTemp;
		}
		else
		{
			Node *pTemp = findMin(pMem->Right);
			pMem->Data = pTemp->Data;
			return DeleteNode(pMem->Right, pTemp->Data);
		}
		return true;
	}
}

HW2BST::Node *HW2BST::findMin(Node *pMem)
{
	Node *pTemp = pMem;

	while (pTemp->Left != NULL)
	{
		pTemp = pTemp->Left;
	}

	return pTemp;
}
