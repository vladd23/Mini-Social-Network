#include "Friendship.h"

//Constructor cu parametrii pe baza de id si 2 utilizatori de tip User
Friendship::Friendship(int id,User firstUser, User secondUser)
{
    this->friendship.idPrietenie = id;
    this->friendship.user1 = firstUser;
    this->friendship.user2 = secondUser;
}

//Returneaza primul user al prieteniei
User Friendship::getFirstUser()
{
    return this->friendship.user1;
}

//Returneaza al doilea user al prieteniei
User Friendship::getSecondUser()
{
    return this->friendship.user2;
}


//Returneaza id ul prieteniei
int Friendship::getId()
{
    return this->friendship.idPrietenie;
}

//Seteaza un nou prim user
void Friendship::setFirstUser(User firstUser)
{
    this->friendship.user1 = firstUser;
}


//Seteaza un nou al doilea user
void Friendship::setSecondUser(User secondUser)
{
    this->friendship.user2 = secondUser;
}

bool Friendship::existInFriendship(User userDeCautat)
{
    if (this->friendship.user1 == userDeCautat || this->friendship.user2 == userDeCautat) return true;
    return false;
}

//Operator de egalitate pe baza de id si cei 2 useri cu o alta prietenie data ca si parametru
//true daca toate sunt egale, false in caz contrar
bool Friendship::operator==(const Friendship& fs)
{
    return this->friendship.idPrietenie == fs.friendship.idPrietenie && this->friendship.user1 == fs.friendship.user1 
        && this->friendship.user2 == fs.friendship.user2;
}

//Operator de afisare pe baza de id si numele celor 2 useri intre care exista prietenia
ostream& operator<<(ostream& os, Friendship& dict)
{
    os << "Prietenie: " << endl;
    os << "  ->id: " << dict.friendship.idPrietenie << endl;
    os << "  ->intre: " << dict.friendship.user1.getName() << " - " << dict.friendship.user2.getName() << endl;
    os << endl;
    return os;
}
