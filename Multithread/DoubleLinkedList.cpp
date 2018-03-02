#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

// Class Node
class Node
{
	int key;
	Node * left;
	Node * right;
public:
	// Constructors
	Node() : key(0), left(NULL), right(NULL){}
	Node(int keyValue): key(keyValue), left(NULL), right(NULL){}
	Node(Node * node): key(node->key), left(node->left), right(node->right){}

	// Get Set method
	int GetKey()
	{
		return key;
	}
	void SetKey(int key)
	{
		this->key = key;
	}

	Node * GetLeft()
	{
		return left;
	}
	void SetLeft(Node * left)
	{
		this->left = left;
	}

	Node * GetRight()
	{
		return right;
	}
	void SetRight(Node * right)
	{
		this->right = right;
	}

	// destructor
	~Node()
	{
		delete left;
		delete right;
	}
};

typedef Node * pNode;

// Class Double LinkedList
class DoubleLinkedList
{
	pNode head;
public:
	// Constructors
	DoubleLinkedList() : head(NULL){}
	DoubleLinkedList(pNode anotherHead) : head(anotherHead){}
	DoubleLinkedList(DoubleLinkedList * list) : head(list -> head){}

	// Add an element to the right of linkedlist
	void InsertElement(int key)
	{
		pNode newNode = new Node();
		newNode->SetKey(key);

		pNode currNode = head;
		if (!currNode)
		{
			head = newNode;
			return;
		}

		while (!currNode->GetRight())
		{
			currNode = currNode->GetRight();
		}

		currNode->SetRight(newNode);
		newNode->SetLeft(currNode);
	}

	void InsertElement(pNode nextNode)
	{
		pNode currNode = head;
		if (!currNode)
		{
			head = nextNode;
			return;
		}
		while (currNode->GetRight())
		{
			currNode = currNode->GetRight();
		}

		currNode->SetRight(nextNode);
		nextNode->SetLeft(currNode);
	}

	// Delete an element out of the right of linkedlist
	int DeleteElement()
	{
		// list is empty
		if (!head)
		{
			return 0;
		}

		// list have one element
		if (!head->GetRight())
		{
			delete head;
			head = NULL;
			return 1;
		}

		// list have at least two elements
		pNode currNode = head;
		while(currNode->GetRight())
		{
			currNode = currNode->GetRight();
		}
		currNode->GetLeft()->SetRight(NULL);
	}

	// Search an element with key == key
	bool SeachElement(int key)
	{
		pNode currNode = head;
		bool found = false;
		while (currNode)
		{
			if (currNode->GetKey() == key)
			{
				found = true;
				cout << "found!" << endl;
				return 1;
			}
			currNode = currNode->GetRight();
		}
		if (!found)
		{
			cout << "not found!" << endl;
			return 0;
		}

	}

	// Sort this linkedlist using quicksort
	

	// Print list
	void PrintList()
	{
		pNode currNode = head;
		while (currNode)
		{
			cout << currNode->GetKey() << " ";
			currNode = currNode->GetRight();
		}
		cout << endl;
	}

	// Destructor
	~DoubleLinkedList()
	{
		delete head;
	}

};

int main()
{
	cout << "Double Linked List Example.." << endl;
	DoubleLinkedList * list = new DoubleLinkedList();
	cout << "Create node" << endl;
	pNode node1 = new Node(30);
	pNode node2 = new Node(10);
	pNode node3 = new Node(20);
	pNode node4 = new Node(40);
	pNode node5 = new Node(60);
	pNode node6 = new Node(70);

	cout << "Insert elements" << endl;
	list->InsertElement(node1);
	list->InsertElement(node2);
	list->InsertElement(node3);
	list->InsertElement(node4);
	list->InsertElement(node5);
	list->InsertElement(node6);
	list->PrintList();

	cout << "Delete an element" << endl;
	list->DeleteElement();
	list->PrintList();

	cout << "Insert again" << endl;
	list->InsertElement(node6);
	list->PrintList();

	return 0;
}