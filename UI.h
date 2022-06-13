#pragma once
#include "User.h"
#include "Network.h"
void printOptions();
void menu();
void userOptions();
void friendshipOptions();
void eventOptions();
void messagesOptions();
void addSomeUsers(Network& net);
void addSomeFriendships(Network& net);
void addSomeMessages(Network& net);