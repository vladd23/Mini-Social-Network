#pragma once
#include "User.h"
using namespace std;
//Friendship class
class Friendship
{
private:
	struct {
		int idPrietenie;
		User user1;
		User user2;
	} friendship;

public:
	Friendship() = default;
	Friendship(int,User, User);
	~Friendship() = default;

	User getFirstUser();
	User getSecondUser();
	int getId();
	void setFirstUser(User);
	void setSecondUser(User);
	bool existInFriendship(User);

	friend ostream& operator<<(ostream&, Friendship&);
	bool operator==(const Friendship&);



};

