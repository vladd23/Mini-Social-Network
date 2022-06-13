#include "Message.h"
#include <iostream>
#include <utility>
using namespace std;

//Constructor fara parametrii, declaram textul mesajului ca fiind null
Message::Message()
{
	//this->message.text = NULL;
}

//Constructor cu parametrii in functie de textul mesajului, utilizatorul care trimite mesajul si
//utilizatorul care primeste mesajul
Message::Message(string textParam, User sender, User receiver) {
	
	this->message.text = std::move(textParam);
	//this->message.text = new char[strlen(textParam) + 1];
	//strcpy_s(this->message.text, strlen(textParam) + 1, textParam);
	this->message.messageReceiver = receiver;
	this->message.messageSender = sender;
}

//Destructor
Message::~Message() = default;

//Returneaza textul mesajului
string Message::getText() {
	return this->message.text;
}

//Returneaza userul care primeste mesajul
User Message::getReceiverUser() {
	return this->message.messageReceiver;
}

//Operator de egalitate in functie de mesaj si cei 2 useri
//true daca toate sunt egale, false in caz contrar
bool Message::operator==(const Message& msg)
{
	return this->message.text == msg.message.text && 
		this->message.messageReceiver == msg.message.messageReceiver &&
		this->message.messageSender == msg.message.messageSender;
}

//Returneaza userul care trimite mesajul
User Message::getSenderUser() {
	return this->message.messageSender;
}

//Operator de afisare prin textul mesajului si numele celor 2 useri intre care se trimite mesajul
ostream& operator<<(ostream& os, Message& msg)
{
	os << "Mesaj: " << endl;
	os << "  ->text: " << msg.message.text << endl;
	os << "  ->sender: " << msg.message.messageSender.getName() << endl;
	os << "  ->receiver: " << msg.message.messageReceiver.getName() << endl;
	os << endl;
	return os;
}
