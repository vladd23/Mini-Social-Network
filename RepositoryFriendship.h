#pragma once

#include "Friendship.h"
using namespace std;

//Repository Friendship
class RepositoryFriendship
{
private:
	Friendship friendship;
public:
	RepositoryFriendship() = default;
	RepositoryFriendship(Friendship);
	~RepositoryFriendship() = default;

};

