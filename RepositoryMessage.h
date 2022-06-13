#pragma once
#include "Message.h"
#include "Friendship.h"
#include "User.h"
#include <iostream>
using namespace std;

class RepositoryMessage
{
private:
	Message messages;
public:
	RepositoryMessage() = default;
	RepositoryMessage(Message);
	~RepositoryMessage() = default;

	friend ostream& operator<<(ostream&, Message&);
};

