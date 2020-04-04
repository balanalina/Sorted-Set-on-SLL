#include "SortedSet.h"
#include"SortedSetIterator.h"


SortedSet::SortedSet(Relation r)
{
	this->r = r;
	this->head = NULL;
}


bool SortedSet::add(TComp e)
{
	if (this->search(e) == true)
		return false;
	if (this->head == NULL)
	{
		Node* currentNode = new Node;
		this->head = currentNode;
		this->head->info = e;
		this->head->next = NULL;
		return true;
	}
	if (this->r(this->head->info, e) == false)
	{
		Node* node = new Node;
		node->next = this->head;
		this->head = node;
		node->info = e;
		return true;
	}
	Node* currentNode = this->head;
	Node* prevNode = NULL;
	while (currentNode != NULL and this->r(currentNode->info, e) == true)
	{
		prevNode = currentNode;
		currentNode = currentNode->next;
	}
	if (currentNode != NULL)
	{
		Node* node = new Node;
		node->next = currentNode;
		prevNode->next = node;
		node->info = e;
		return true;
	}
	else {
		Node* node = new Node;
		prevNode->next = node;
		node->next = NULL;
		node->info = e;
		return true;
	}
}

bool SortedSet::search(TElem elem) const
{
	if (this->head == NULL)
		return false;
	Node* currentNode;
	currentNode = this->head;
	while (currentNode != NULL and currentNode->info != elem)
		currentNode = currentNode->next;
	if(currentNode == NULL)
		return false;
	return true;
}

bool SortedSet::remove(TComp e)
{
	Node* currentNode = this->head;
	Node* prevNode = NULL;
	if (this->search(e) == false)
		return false;
	while (currentNode != NULL and currentNode->info != e)
	{
		prevNode = currentNode;
		currentNode = currentNode->next;
	}
	if (currentNode != NULL and prevNode == NULL)
	{
		this->head = currentNode->next;
		delete currentNode;
	}
	else
	{
		prevNode->next = currentNode->next;
		currentNode->next = NULL;
		delete currentNode;
	}
	return true;
}

bool SortedSet::isEmpty() const
{
	if (this->head == NULL)
		return true;
	return false;
}

int SortedSet::size() const
{
	if (this->isEmpty() == true)
		return 0;
	int n = 0;
	Node* currentNode = this->head;
	while (currentNode != NULL)
	{
		n++;
		currentNode = currentNode->next;
	}
	return n;
}

SortedSet::~SortedSet()
{
	if (this->head != NULL)
	{
		Node* currentNode = this->head->next;
		Node* prevNode = this->head;
		while (currentNode != NULL)
		{
			delete prevNode;
			prevNode = currentNode;
			currentNode = currentNode->next;
		}
	}
}

SortedSetIterator SortedSet::iterator() const
{
	return SortedSetIterator(this->head);
}

