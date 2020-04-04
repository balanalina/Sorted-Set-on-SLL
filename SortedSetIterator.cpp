#include "SortedSetIterator.h"



SortedSetIterator::SortedSetIterator(Node* head)
{
	this->head = head;
	this->currentElement = head;
}

bool SortedSetIterator::valid()
{
	if (this->currentElement == NULL)
		return false;
	return true;
}


TElem SortedSetIterator::getCurrent()
{
	if (this->currentElement == NULL)
		throw std::exception();
	return this->currentElement->info;
}

void SortedSetIterator::next()
{
	if (this->valid() == true)
		this->currentElement = this->currentElement->next;
	else
		throw std::exception();
}

void SortedSetIterator::first()
{
	this->currentElement = this->head;
}

SortedSetIterator::~SortedSetIterator()
{
}


void SortedSetIterator::jumpForward(int k)
{
	if (k <= 0)
		throw std::exception();
	int n = 0;
	while (this->currentElement != NULL and this->valid() and n<k)
	{
		this->currentElement = this->currentElement->next;
		n++;
	}
	
}