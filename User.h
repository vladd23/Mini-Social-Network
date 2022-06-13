#pragma once
#include <iostream>
#include "Array.h"
using namespace std;

class User {
private:
    int id;
	int age;
	char* name;
    int idFriends[100];
    int nrOfFriends;

public:
	User();
    User(int,const char*, int);
	~User();

    void setName(const char*);
    void setAge(int);
    char* getName();
    int getAge();
    int getId();

    int getNrOfFriends();
    void incraseNrOfFriends();
    void decreaseNrOfFriends();
    void addIdToList(int);
    void delIdFromList(int);
    int idFromPos(int);
    bool existIdInList(int);

    User& operator=(const User&);
    bool operator==(const User&);

    friend ostream& operator<<(ostream&, User&);
};