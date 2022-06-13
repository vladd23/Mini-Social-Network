#include "RepositoryUser.h"

//Functie care adauga un user la array
void RepositoryUser::addUser(User& user)
{
	this->usersList.addElement(user);
}

//Functie care sterge un user din array
void RepositoryUser::deleteUser(User user)
{
	this->usersList.deleteElement(user);
}

//Functie care modifica un user dat ca parametru, inlocuind numele si varsta cu altele noi
void RepositoryUser::modifyUser(User& user, const char* newName, int newAge)
{
	for(int i = 0; i < this->usersList.getCurrentLength(); i++)
		if (this->usersList.getElemByPos(i) == user) {
			usersList.getElemByPos(i).setAge(newAge);
			usersList.getElemByPos(i).setName(newName);
		}
}

void RepositoryUser::deleteId(User& userDeSters, User& userDeCautat)
{
	userDeCautat.delIdFromList(userDeSters.getId());
}

//Functie care verifica existenta unui user in array
//true in caz afirmativ, fals in caz contrar
bool RepositoryUser::existUser(User deCautat)
{
	User* vectorUseri = this->usersList.getAll();
	for (int i = 0; i < this->usersList.getCurrentLength(); i++)
		if (vectorUseri[i] == deCautat) return true;
	return false;
}

bool RepositoryUser::existId(User userSters, User userDeCautat)
{
	int id = userSters.getId();
	return userDeCautat.existIdInList(id);
}

//Functie care adauga id-ul unui user intr un vector de id-uri cu proprietatea ca cei doi sunt prieteni
void RepositoryUser::addFriendId(User user1, User user2)
{
	User* vectorUseri = this->usersList.getAll();
	for (int i = 0; i < this->usersList.getCurrentLength(); i++)
		if (vectorUseri[i] == user1) {
			vectorUseri[i].addIdToList(user2.getId());
			vectorUseri[i].incraseNrOfFriends();
			
		}
}

//Returneaza un vector dinamic continand toti userii din array
User* RepositoryUser::getAllUsers()
{
	return this->usersList.getAll();
}

//Returneaza numarul de useri din array
int RepositoryUser::getSize()
{
	return this->usersList.getCurrentLength();
}
