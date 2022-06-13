#pragma once
#include "Array.h"
#include "User.h"
#include "Message.h"
#include "Event.h"
#include "RepositoryFriendship.h"
#include "Friendship.h"
#include "RepositoryUser.h"
#include "RepositoryEvent.h"
#include "RepositoryMessage.h"
#include <iostream>
using namespace std;


class Network
{
private:
	RepositoryUser repoUser;
	RepositoryEvent repoEvent;
	Array<Friendship> friendshipList;
	Array<Message> messagesList;
	
public:
	
	Network() {
		this->repoUser = RepositoryUser();
		this->repoEvent = RepositoryEvent();
	}
	~Network() = default;

	void addUserService(int ,const char* userName, int userAge);
	void deleteUserService(int, const char* userName, int userAge);
	void modifyUserService(int,const char* oldName, int oldAge, const char* newName, int newAge);
	bool existUserService(User userDeCautat);
	void showUserFriends(User);
	User* getAllUsers();
	int getSizeService();

	void addEventService(int, const char*, const char*);
	void showAllEventsService();
	void deleteEventService(int, const char*, const char*);
	char* idInVector(User, int[], int);

	void showUserFriendships();
	void addFriendship(Friendship);
	void deleteFriendship(int id);
	
	void sendMessage(Message);
	void showAllMessages();
	void deleteMessage(User u1, User u2);
};

