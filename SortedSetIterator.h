#pragma once
#include <stdexcept>
#include"SortedSet.h"
#include"SortedSetIterator.h"


typedef int TElem;

typedef TElem TComp;


class SortedSetIterator
{
private:
	Node* head;
	Node* currentElement;
public:

	//returns the currentElement theta(1)
	TElem getCurrent();

	//constructor theta(1)
	SortedSetIterator(Node* head);

	//there still are elements to be iterated,returns true or false theta(1)
	bool valid();

	//moves the iterator to the next element theta(1)
	void next();

	//moves the iterator to the first element theta(1)
	void first();

	~SortedSetIterator();

	//O(k)
	void jumpForward(int k);
};

