#pragma once
#include "User.h"
#include <iostream>
using namespace std;

class Message {

private:
	struct {
		string text;
		User messageSender;
		User messageReceiver;
	}message; 
		
	 
public:
	Message();
	Message(string, User, User);
	~Message();
	
	string getText();
	User getSenderUser();
	User getReceiverUser();

	friend ostream& operator<<(ostream&, Message&);
	bool operator==(const Message& msg);

};