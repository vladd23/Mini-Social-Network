#include "Event.h"
#include <iostream>
using namespace std;

//Constructor cu parametrii: id, nume si locatie
Event::Event(int idParam,const char* nameParam, const char* locationParam)
{
	this->id = idParam;
	this->nameEvent = new char[strlen(nameParam) + 1];
	strcpy_s(this->nameEvent, strlen(nameParam) + 1, nameParam);
	this->location = new char[strlen(locationParam) + 1];
	strcpy_s(this->location, strlen(locationParam) + 1, locationParam);
}

//Constructor cu alt eveniment dat ca si parametru, mostenteste caracteristicile parametrului
//date mai sus
Event::Event(const Event& ev)
{
	this->id = ev.id;
	this->nameEvent = new char[strlen(ev.nameEvent) + 1];
	strcpy_s(this->nameEvent, strlen(ev.nameEvent) + 1, ev.nameEvent);
	this->location = new char[strlen(ev.location) + 1];
	strcpy_s(this->location, strlen(ev.location) + 1, ev.location);
}

//Returneaza id ul unui eveniment
int Event::getIdEvent()
{
	return this->id;
}

//Returneaza numele evenimentului
char* Event::getNameEvent()
{
	return this->nameEvent;
}


//Returneaza locatia evenimentului
char* Event::getLocation()
{
	return this->location;
}

//Seteaza un nou id pentru un event
void Event::setIdEvent(int newId)
{
	this->id = newId;
}

//Seteaza un nume nou pt un event
void Event::setNameEvent(const char* nameParam)
{
	if (this->nameEvent) {
		delete[]this-> nameEvent;
	}
	else if (nameParam == nullptr)
	{
		this->nameEvent = nullptr;
	}
	else
	{
		this->nameEvent = new char[strlen(nameParam) + 1];
		strcpy_s(this->nameEvent, strlen(nameParam) + 1, nameParam);
	}
}

//Seteaza o locatie noua pt un event
void Event::setLocation(const char* locationParam)
{
	if (this->location) delete[]this->location;
	else if (locationParam == nullptr) this->location = nullptr;
	else {
		this->location = new char[strlen(locationParam) + 1];
		strcpy_s(this->location, strlen(locationParam) + 1, locationParam);
	}
}

//Comparari de mai mic/mare intre doua evenimente pe baza id-ului
bool Event::operator<(const Event& ev)
{
	return this->id < ev.id;
}

bool Event::operator>(const Event& ev)
{
	return this->id > ev.id;
}

//Operator de egalitate intre 2 eventuri pe baza id ului , numelui si al locatiei
//true daca toate sunt egale, false in caz contrar
bool Event::operator==(const Event& ev)
{
	return this->id == ev.id && strcmp(this->nameEvent, ev.nameEvent) == 0 && strcmp(this->location, ev.location) == 0;
}

//Operator de afisare al unui event pe baza de id , nume si locatie
ostream& operator<<(ostream& os, Event& ev)
{
	os << ev.id << " " << ev.nameEvent << " " << ev.location;
	return os;
}
