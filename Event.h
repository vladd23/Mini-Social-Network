#pragma once
#include <iostream>
using namespace std;

class Event {

private:
	int id;
	char* nameEvent;
	char* location;

public: 
	Event() = default;
	Event(int, const char*, const char*);
	Event(const Event&);
	~Event() = default;

	int getIdEvent();
	char* getNameEvent();
	char* getLocation();
	void setIdEvent(int);
	void setNameEvent(const char*);
	void setLocation(const char*);

	bool operator<(const Event& ev);
	bool operator>(const Event& ev);
	bool operator==(const Event& ev);
	friend ostream& operator<<(ostream&, Event&);


};