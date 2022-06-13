#include "RepositoryEvent.h"

//Functie care adauga un eveniment in arborele binar de cautare
void RepositoryEvent::addEvent(Event& eventParam)
{
	this->root = this->eventTree->insertElement(this->root, eventParam);
	
}

//Functie care sterge un eveniment din arborele binar de cautare
void RepositoryEvent::deleteEvent(Event& ev)
{
	this->root = this->eventTree->deleteElement(this->root, ev);
}

//Functie care afiseaza evenimentele din arborele binar de cautare
void RepositoryEvent::showEvents()
{
	
	this->eventTree->inOrderShow(this->root);
}



