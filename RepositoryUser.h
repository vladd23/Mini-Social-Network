#pragma once
#include "User.h"
#include "Array.h"
using namespace std;

class RepositoryUser
{
private:
	Array<User> usersList;
	
public:
	RepositoryUser() = default;
	~RepositoryUser() = default;

	void addUser(User&);
	void deleteUser(User);
	void modifyUser(User&, const char*, int);
	void deleteId(User&, User&);
	
	bool existUser(User deCautat);
	bool existId(User, User);

	void addFriendId(User user, User);

	User* getAllUsers();
	int getSize();
};

