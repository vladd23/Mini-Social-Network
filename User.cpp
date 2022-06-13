#include "User.h"
#include <iostream>
using namespace std;


//Constructor fara parametrii
User::User() {
	this->idFriends[99] = {};
	this->id = 0;
	this->age = 0;
	this->name = NULL;
	this->nrOfFriends = 0;
}

//Destructor default
User::~User() = default;

//Constructor cu parametrii: id, numeUser si varsta
User::User(int idd,const char* n, int age) {
	this->idFriends[99] = {};
	this->nrOfFriends = 0;
	this->id = idd;
	this->name = new char[strlen(n) + 1];
	strcpy_s(this->name, strlen(n) + 1, n);
	this->age = age;
}

//Returneaza numele userului
char* User::getName() {
	return this->name;
}

//Returneaza varsta userului
int User::getAge() {
	return this->age;
}

//Seteaza o noua varsta pentru user data ca si parametru
void User::setAge(int newAge){
	this->age = newAge;
}

//Seteaza un nou nume pentru user dat ca si parametru
void User::setName(const char* newName) {
	if (this->name) {
		delete[]this->name;
	}
	if (newName == nullptr)
	{
		this->name = nullptr;
	}
	else
	{
		this->name = new char[strlen(newName) + 1];
		strcpy_s(this->name, strlen(newName) + 1, newName);
	}
}

//Returneaza id ul userului
int User::getId() {
	return this->id;
}

//Returneaza numarul de prieteni pe care il are(dimensiunea vectorului idFriends)
int User::getNrOfFriends()
{
	return this->nrOfFriends;
}

//Creste numarul de prieteni cu o unitate
void User::incraseNrOfFriends()
{
	this->nrOfFriends++;
}

//Scade nr de prieteni
void User::decreaseNrOfFriends()
{
	this->nrOfFriends--;
}

//Adauga un id la lista de id uri
void User::addIdToList(int id)
{
	this->idFriends[this->nrOfFriends] = id;
}

void User::delIdFromList(int idDeSters)
{
	for (int i = 0; i < this->nrOfFriends; i++)
		if (this->idFriends[i] == idDeSters)
			for (int j = i; j < this->nrOfFriends; j++)
				this->idFriends[j] = this->idFriends[j + 1];
	this->nrOfFriends--;
}

//Returneaza id ul de pe o pozitie data in vector
int User::idFromPos(int pos)
{
	return this->idFriends[pos];
}

bool User::existIdInList(int idDeCautat)
{
	for (int i = 0; i < this->nrOfFriends; i++)
		if (idFriends[i] == idDeCautat) return true;
	return false;
}

//Operator de asignare dupa un user dat ca si parametru
User &User::operator=(const User& c) {
	this->nrOfFriends = c.nrOfFriends;
	for (int i = 0; i < nrOfFriends; i++)
		this->idFriends[i] = c.idFriends[i];

	this->id = c.id;
	setAge(c.age);
	setName(c.name);
	return* this;
}


//Operator de egalitate, compara varsta numele si id ul a doi useri
//true daca toate sunt egale, false in caz contrar
bool User::operator==(const User& u)
{
	return this->age == u.age && strcmp(this->name, u.name) == 0 && this->id == u.id;
}


//Operator de afisare, foloseste caracteristicile id, nume si varsta pentru a afisa un user
ostream& operator<<(ostream& os, User& user)
{
	os << user.id << ") " <<user.name << ", " << user.age << " ani";
	return os;
}
