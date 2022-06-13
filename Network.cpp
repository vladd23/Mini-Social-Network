#include "Network.h"


//Functie care adauga in retea un user dupa id, nume si varsta
void Network::addUserService(int id,const char* userName, int userAge)
{
	User user(id,userName, userAge);
	this->repoUser.addUser(user);
}

//Functie care sterge din retea un user dupa id, nume si varsta
//Functia elimina si toate prieteniile pe care le are userul respectiv
void Network::deleteUserService(int id,const char* userName, int userAge)
{
	User userToDelete(id,userName, userAge);
	User* vc = this->repoUser.getAllUsers();
	for (int i = 0; i < this->repoUser.getSize(); i++)
	{
		bool exista = this->repoUser.existId(userToDelete, vc[i]);
		if (exista) {
			this->repoUser.deleteId(userToDelete, vc[i]);
		}
	}
	Friendship* fsV = this->friendshipList.getAll();
	for (int i = 0; i < friendshipList.getCurrentLength(); i++)
		while(fsV[i].existInFriendship(userToDelete))
			this->friendshipList.deleteElement(fsV[i]);



	this->repoUser.deleteUser(userToDelete);
}

//Functie care modifica un user din retea dat prin id , nume si varsta
//Se pot modifica numele si varsta 
void Network::modifyUserService(int id, const char* oldName, int oldAge, const char* newName, int newAge)
{
	User user(id, oldName, oldAge);
	this->repoUser.modifyUser(user, newName, newAge);
}

//Functie care verifica existenta unui user in retea
bool Network::existUserService(User userDeCautat)
{
	return this->repoUser.existUser(userDeCautat);
}

//Functie care afiseaza toti prietenii unui user dat ca si parametru
void Network::showUserFriends(User user)
{
	int ids[100] = {}, dim = 0;
	User* vc = repoUser.getAllUsers();
	for (int j = 0; j < repoUser.getSize(); j++)
		if (user == vc[j])
		{
			cout << "Nr de prieteni: " << vc[j].getNrOfFriends() << endl;
			
			for (int i = 0; i < vc[j].getNrOfFriends(); i++)
			{
				int id = vc[j].idFromPos(i);
				ids[dim] = id;
				dim++;
			}
		}
	cout << endl;
	cout << "Prietenii userului: " << endl;
	for (int i = 0; i < this->repoUser.getSize(); i++)
		if (!(vc[i] == user)) {
			if (idInVector(vc[i], ids, dim) != nullptr)
				cout << idInVector(vc[i], ids, dim) << endl;
		}
}


//Functie care returneaza un vector dinamic incluzand toti userii retelei
User* Network::getAllUsers()
{
	return this->repoUser.getAllUsers();
}

//Functie care returneaza numarul de utlizatori aflati in retea
int Network::getSizeService()
{
	return this->repoUser.getSize();
}

//Functie care adauga un eveniment in retea in functie de id, nume si locatie
void Network::addEventService(int idParam, const char* numeParam, const char* locatieParam)
{
	Event eventToAdd(idParam, numeParam, locatieParam);
	
	repoEvent.addEvent(eventToAdd);
	
}

//Functie care afiseaza toate evenimentele inregistrate in retea
void Network::showAllEventsService()
{
	this->repoEvent.showEvents();
}

//Functie care sterge un eveniment din retea dat dupa id, nume, locatie
void Network::deleteEventService(int id, const char* nume, const char* locatie)
{
	Event eventToDelete(id, nume, locatie);
	this->repoEvent.deleteEvent(eventToDelete);
}

//Functie care returneaza numele unui user in cazul in care id ul sau se afla intr u vector de id-uri, null in caz contrar
char* Network::idInVector(User u,int iduri[100], int dim)
{
	for (int i = 0; i < dim; i++)
		if (u.getId() == iduri[i])
			return u.getName();
	return nullptr;
}

//Functie care afiseaza toate prieteniile de pe retea
void Network::showUserFriendships()
{
	Friendship* fsV = this->friendshipList.getAll();
	for (int i = 0; i < friendshipList.getCurrentLength(); i++)
		cout << fsV[i] << endl;
}

//Functie care adauga o prietenie in retea
void Network::addFriendship(Friendship fs)
{
	this->repoUser.addFriendId(fs.getFirstUser(), fs.getSecondUser());
	this->repoUser.addFriendId(fs.getSecondUser(), fs.getFirstUser());

	this->friendshipList.addElement(fs);
	
}

//Functie care sterge o prietenie din retea dupa id
void Network::deleteFriendship(int id)
{
	Friendship* frsVector = this->friendshipList.getAll();
	for (int i = 0; i < this->friendshipList.getCurrentLength(); i++)
		if (frsVector[i].getId() == id)
			this->friendshipList.deleteElement(frsVector[i]);
}

//Functie care adauga un mesaj in retea
void Network::sendMessage(Message msg)
{
	this->messagesList.addElement(msg);
}

//Functie care afiseaza toate mesajele de pe retea
void Network::showAllMessages()
{
	Message* msgVector = this->messagesList.getAll();
	for (int i = 0; i < this->messagesList.getCurrentLength(); i++)
		cout << msgVector[i];
}

//Functie care sterge un mesaj din retea in functie de userii intre care s a trimis mesajul
void Network::deleteMessage(User u1, User u2)
{
	Message* msgVector = this->messagesList.getAll();
	for (int i = 0; i < this->messagesList.getCurrentLength(); i++)
		if (msgVector[i].getSenderUser() == u1 && msgVector[i].getReceiverUser() == u2)
			this->messagesList.deleteElement(msgVector[i]);
}
