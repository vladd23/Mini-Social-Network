#pragma once
#include <iostream>
#include "BinaryTree.h"
#include "Event.h"


using namespace std;


class RepositoryEvent
{
private:
	BinaryTree<Event>*eventTree;
	BinaryTree<Event>*root;
	
public:
	RepositoryEvent() = default;
	~RepositoryEvent() = default;

	void addEvent(Event&);
	void deleteEvent(Event&);
	void showEvents();

};

