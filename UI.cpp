#include "UI.h"
#include "Array.h"
#include "User.h"
#include "Event.h"
#include "Message.h"
#include "Friendship.h"
#include "Network.h"
#include "ExceptionClass.h"
#include <windows.h>   // WinApi header
#undef max
#include <iostream>
#include <ios>
#include <limits>
using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // 7 alb

void printOptions() {
    userOptions();
    eventOptions();
    friendshipOptions();
    messagesOptions();
    SetConsoleTextAttribute(hConsole, 4);

    cout << endl;
    cout << "0. Iesire" << endl;
    SetConsoleTextAttribute(hConsole, 7);

}

void menu() {
    int optiune;
    Network network;
    printOptions();
    cout << "Dati optiunea: "; cin >> optiune; cout << endl;
    addSomeUsers(network);
    addSomeFriendships(network);
    addSomeMessages(network);

    while (true) {

        switch (optiune) {
        case 1: {
            try {
                int id;
                cout << "Id user: "; cin >> id; cout << endl;
                string nume;
                cout << "Nume user: "; cin >> nume; cout << endl;
                const char* numePointer = nume.c_str();
                int varsta;
                cout << "Varsta user: "; cin >> varsta; cout << endl;
                if (!cin) throw ExceptionClass("Datele nu au fost introduse corespunzator!");
                User userDeAdaugat(id, numePointer, varsta);

                network.addUserService(id, numePointer, varsta);
                cout << "Userul: " << userDeAdaugat << " a fost adaugat" << endl << endl;
                break;
            }
            catch (ExceptionClass& ex) {
                cin.clear(); //goleste buffer
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear out the input buffer
                cout << endl << ex.what() << endl << endl;
                break;
            }
        }
        case 2: {
            User* vectorUser = network.getAllUsers();
            for (int i = 0; i < network.getSizeService(); i++) {
                cout << vectorUser[i] << endl;
            }
            cout << endl << endl;
            break;
        }
        case 3: {
            try {
                int id;
                cout << "Id user: "; cin >> id; cout << endl;
                string nume, numeNou;
                cout << "Nume user de modificat: "; cin >> nume; cout << endl;
                const char* numePointer = nume.c_str();
                int varsta, varstaNoua;
                cout << "Varsta user de modificat: "; cin >> varsta; cout << endl;

                if (!cin) throw ExceptionClass("Datele nu au fost introduse corespunzator!");

                User userDeModificat(id, numePointer, varsta);
                int ok = network.existUserService(userDeModificat);
                if (ok == false) cout << "Userul: " << userDeModificat << " nu exista!" << endl << endl;
                else {
                    cout << "Numele nou: "; cin >> numeNou; cout << endl;
                    const char* numeNouPointer = numeNou.c_str();
                    cout << "Varsta noua: "; cin >> varstaNoua; cout << endl;
                    network.modifyUserService(id, numePointer, varsta, numeNouPointer, varstaNoua);
                    break;
                }

                break;
            }
            catch (ExceptionClass& ex) {
                cin.clear(); //goleste buffer
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear out the input buffer
                cout << endl << ex.what() << endl << endl;
                break;
            }
        }
        case 4: {
            try {
                int id;
                cout << "Id user: "; cin >> id; cout << endl;
                string nume;
                cout << "Nume user de sters: "; cin >> nume; cout << endl;
                const char* numePointer = nume.c_str();
                int varsta;
                cout << "Varsta userului: "; cin >> varsta; cout << endl;

                if (!cin) throw ExceptionClass("Datele nu au fost introduse corespunzator!");

                User userDeSters(id, numePointer, varsta);
                int ok = network.existUserService(userDeSters);
                if (ok == false) cout << "Utilizatorul: " << userDeSters << " nu exista!" << endl << endl;
                else {
                    network.deleteUserService(id, numePointer, varsta);
                    break;
                }
                break;
            }
            catch (ExceptionClass& ex) {
                cin.clear(); //goleste buffer
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear out the input buffer
                cout << endl << ex.what() << endl << endl;
                break;
            }
        }
        case 5: {
            try {
                int id;
                cout << "Dati id event: "; cin >> id; cout << endl;
                string nume;
                cout << "Nume event: "; cin >> nume; cout << endl;
                const char* numePointer = nume.c_str();
                string locatie;
                cout << "Locatie event: "; cin >> locatie; cout << endl;
                const char* locatiePointer = locatie.c_str();

                if (!cin) throw ExceptionClass("Datele nu au fost introduse corespunzator!");

                Event eveniment(id, numePointer, locatiePointer);

                network.addEventService(id, numePointer, locatiePointer);
                cout << "Evenimentul: " << eveniment << " a fost adaugat";
                cout << endl << endl;
                break;
            }
            catch (ExceptionClass& ex) {
                cin.clear(); //goleste buffer
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear out the input buffer
                cout << endl << ex.what() << endl << endl;
                break;
            }
            
        }
        case 6: {
            network.showAllEventsService();
            cout << endl;
            break;
        }
        case 7: {
            try {
                int id;
                cout << "Dati id event: "; cin >> id; cout << endl;
                string nume;
                cout << "Nume event: "; cin >> nume; cout << endl;
                const char* numePointer = nume.c_str();
                string locatie;
                cout << "Locatie event: "; cin >> locatie; cout << endl;
                const char* locatiePointer = locatie.c_str();
                if (!cin) throw ExceptionClass("Datele nu au fost introduse corespunzator!");

                Event eveniment(id, numePointer, locatiePointer);
                network.deleteEventService(id, numePointer, locatiePointer);
                cout << "Evenimentul: " << eveniment << " a fost sters din lista!" << endl << endl;
                break;
           }
            catch (ExceptionClass& ex) {
                cin.clear(); //goleste buffer
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear out the input buffer
                cout << endl << ex.what() << endl << endl;
                break;
            }
        }
        case 8: {
            try {
                int idPrietenie;
                cout << "Id prietenie: "; cin >> idPrietenie; cout << endl;
                string nume1, nume2;

                int id1;
                cout << "Id-ul primului prieten: "; cin >> id1; cout << endl;

                cout << "Numele primului prieten: "; cin >> nume1; cout << endl;
                const char* numePointer1 = nume1.c_str();
                int varsta1, varsta2;
                cout << "Varsta primului prieten: "; cin >> varsta1; cout << endl;
                if (!cin) throw ExceptionClass("Datele nu au fost introduse corespunzator!");


                bool ok1 = false, ok2 = false;

                int id2;
                cout << "Id-ul celui de-al doilea prieten: "; cin >> id2; cout << endl;

                cout << "Numele celui de-al doilea prieten: "; cin >> nume2; cout << endl;
                const char* numePointer2 = nume2.c_str();
                cout << "Varsta celui de-al doilea prieten: "; cin >> varsta2; cout << endl;
                if (!cin) throw ExceptionClass("Datele nu au fost introduse corespunzator!");

                User user1(id1, numePointer1, varsta1);
                User user2(id2, numePointer2, varsta2);
                ok1 = network.existUserService(user1);
                ok2 = network.existUserService(user2);

                if (ok1 == false || ok2 == false) cout << "Unul dintre useri este inexistent, nu se poate realiza prietenia!" << endl << endl;
                else {
                    Friendship frs(idPrietenie, user1, user2);
                    network.addFriendship(frs);
                    break;
                }
                break;
            }
            catch (ExceptionClass& ex) {
                cin.clear(); //goleste buffer
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear out the input buffer
                cout << endl << ex.what() << endl << endl;
                break;
            }

        }
        case 9: {
            network.showUserFriendships();
            break;
        }
        case 10: {
            try {
                int idPrietenie;
                cout << "Id-ul prieteniei pe care doriti sa l stergeti: "; cin >> idPrietenie; cout << endl;
                if (!cin) throw ExceptionClass("Datele nu au fost introduse corespunzator!");

                network.deleteFriendship(idPrietenie);
                break;
           }
            catch (ExceptionClass& ex) {
                cin.clear(); //goleste buffer
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear out the input buffer
                cout << endl << ex.what() << endl << endl;
                break;
            }
        }
        case 11: {
            try {
                string nume1;

                int id1;
                cout << "Id user: "; cin >> id1; cout << endl;

                cout << "Numele: "; cin >> nume1; cout << endl;
                const char* numePointer1 = nume1.c_str();
                int varsta1;
                cout << "Varsta: "; cin >> varsta1; cout << endl;
                if (!cin) throw ExceptionClass("Datele nu au fost introduse corespunzator!");

                User user1(id1, numePointer1, varsta1);
                network.showUserFriends(user1);
                cout << endl;
                break;
           }
            catch (ExceptionClass& ex) {
                cin.clear(); //goleste buffer
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear out the input buffer
                cout << endl << ex.what() << endl << endl;
                break;
            }
        }
        case 12: {
            try {
                
                char mesajChar[250];
                cin.get();
                cout << "Citire mesaj text: "; cin.getline(mesajChar, 250); cout << endl;
                string nume1, nume2;

                int id1;
                cout << "Id user1: "; cin >> id1; cout << endl;

                cout << "Nume user1: "; cin >> nume1; cout << endl;
                const char* numePointer1 = nume1.c_str();
                int varsta1, varsta2;
                cout << "Varsta user1: "; cin >> varsta1; cout << endl;
                if (!cin) throw ExceptionClass("Datele nu au fost introduse corespunzator!");

                User user1(id1, numePointer1, varsta1);

                int id2;
                cout << "Id user2: "; cin >> id2; cout << endl;

                cout << "Nume user2: "; cin >> nume2; cout << endl;
                const char* numePointer2 = nume2.c_str();
                cout << "Varsta user2: "; cin >> varsta2; cout << endl;
                if (!cin) throw ExceptionClass("Datele nu au fost introduse corespunzator!");

                User user2(id2, numePointer2, varsta2);

                bool ok1 = false, ok2 = false;
                ok1 = network.existUserService(user1);
                ok2 = network.existUserService(user2);
                if (ok1 == false || ok2 == false) cout << "Unul dintre useri este inexistent, nu se poate realiza prietenia!" << endl << endl;
                else {
                    Message msg(mesajChar, user1, user2);
                    network.sendMessage(msg);
                    break;
                }
                break;
           }
            catch (ExceptionClass& ex) {
                cin.clear(); //goleste buffer
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear out the input buffer
                cout << endl << ex.what() << endl << endl;
                break;
            }
        }
        case 13: {
            network.showAllMessages();
            break;
        }
        case 14: {
            try {
                string nume1, nume2;
                int id1;
                cout << "Id sender: "; cin >> id1; cout << endl;
                cout << "Nume sender: "; cin >> nume1; cout << endl;
                const char* numePointer1 = nume1.c_str();
                int varsta1, varsta2;
                cout << "Varsta sender: "; cin >> varsta1; cout << endl;
                if (!cin) throw ExceptionClass("Datele nu au fost introduse corespunzator!");

                User user1(id1, numePointer1, varsta1);

                int id2;
                cout << "Id receiver: "; cin >> id2; cout << endl;

                cout << "Nume receiver: "; cin >> nume2; cout << endl;
                const char* numePointer2 = nume2.c_str();
                cout << "Varsta receiver: "; cin >> varsta2; cout << endl;
                if (!cin) throw ExceptionClass("Datele nu au fost introduse corespunzator!");

                User user2(id2, numePointer2, varsta2);

                bool ok1 = false, ok2 = false;
                ok1 = network.existUserService(user1);
                ok2 = network.existUserService(user2);
                if (ok1 == false || ok2 == false) cout << "Unul dintre useri este inexistent, nu se poate realiza stergerea!" << endl << endl;
                else {
                    network.deleteMessage(user1, user2);
                    break;
                }
                break;
            }
            catch (ExceptionClass& ex) {
                cin.clear(); //goleste buffer
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear out the input buffer
                cout << endl << ex.what() << endl << endl;
                break;
            }
        }
       
        
        }
        if (optiune == 0) break;
       
        printOptions();
        cout << endl;
        cout << "Dati optiunea: "; cin >> optiune;cout<< endl;

        
    }
}

void userOptions()
{
   
    // you can loop k higher to see more color choices
   /* for (int k = 1; k < 255; k++)
    {
        // pick the colorattribute k you want
        SetConsoleTextAttribute(hConsole, k);
        cout << k << " I want to be nice today!" << endl;
    }*/
    SetConsoleTextAttribute(hConsole, 3);
    cout << "1.  Adaugare utilizator" << endl;
    cout << "2.  Afisare utilizatori" << endl;
    cout << "3.  Modificare utilizator" << endl;
    cout << "4.  Stergere utilizator" << endl;
}

void eventOptions()
{
    SetConsoleTextAttribute(hConsole, 10);

    cout << "5.  Adaugare eveniment pe arbore binar" << endl;
    cout << "6.  Afisare evenimente pe arbore binar" << endl;
    cout << "7.  Stergere eveniment din arborele binar" << endl;
}

void messagesOptions()
{
    SetConsoleTextAttribute(hConsole, 5);

    cout << "12. Trimitere mesaj de la un user la altul" << endl;
    cout << "13. Afisarea tuturor mesajelor de pe retea" << endl;
    cout << "14. Stergerea unui mesaj dintre doi useri" << endl;
}

void addSomeUsers(Network& net)
{
    net.addUserService(1, "user1", 20);
    net.addUserService(2, "user2", 20);
    net.addUserService(3, "user3", 20);
    net.addUserService(4, "user4", 20);
    net.addUserService(5, "user5", 20);
    net.addUserService(6, "user6", 20);
    net.addUserService(7, "user7", 20);
    net.addUserService(8, "user8", 20);
    net.addUserService(9, "user9", 20);
    net.addUserService(10, "user10", 20);
    net.addUserService(11, "user11", 20);
    net.addUserService(12, "user12", 20);
    net.addUserService(13, "user13", 20);
    net.addUserService(14, "user14", 20);
    net.addUserService(15, "user15", 20);
    
}

void addSomeFriendships(Network& net)
{
    User user1(1, "user1", 20);
    User user2(2, "user2", 20);
    User user3(3, "user3", 20);
    User user4(4, "user4", 20);
    User user5(5, "user5", 20);
    User user6(6, "user6", 20);
    User user8(8, "user8", 20);
    User user7(7, "user7", 20);
    User user9(9, "user9", 20);
    User user10(10, "user10", 20);
    User user11(11, "user11", 20);
    User user12(12, "user12", 20);
    User user13(13, "user13", 20);
    User user14(14, "user14", 20);
    User user15(15, "user15", 20);
    
    Friendship fs1(1, user1, user2);
    Friendship fs2(2, user1, user3);
    Friendship fs3(3, user2, user6);
    Friendship fs4(4, user9, user7);
    Friendship fs5(5, user10, user12);
    Friendship fs6(6, user13, user12);
    Friendship fs7(7, user8, user14);
    Friendship fs8(8, user5, user15);
    Friendship fs9(9, user2, user12);
    Friendship fs10(10, user6, user13); 
    Friendship fs11(11, user5, user7);
    Friendship fs12(12, user9, user3);
    Friendship fs13(13, user15, user6);
    Friendship fs14(14, user2, user7);
    Friendship fs15(15, user10, user11);
    Friendship fs16(16, user11, user13);
    Friendship fs17(17, user4, user14);
    Friendship fs18(18, user4, user9);
    Friendship fs19(19, user12, user14);
    Friendship fs20(20, user6, user10);
    Friendship fs21(21, user8, user15);

    net.addFriendship(fs1);
    net.addFriendship(fs2);
    net.addFriendship(fs3);
    net.addFriendship(fs4);
    net.addFriendship(fs5);
    net.addFriendship(fs6);
    net.addFriendship(fs7);
    net.addFriendship(fs8);
    net.addFriendship(fs9);
    net.addFriendship(fs10);
    net.addFriendship(fs11);
    net.addFriendship(fs12);
    net.addFriendship(fs13);
    net.addFriendship(fs14);
    net.addFriendship(fs15);
    net.addFriendship(fs16);
    net.addFriendship(fs17);
    net.addFriendship(fs18);
    net.addFriendship(fs19);
    net.addFriendship(fs20);
    net.addFriendship(fs21);

}

void addSomeMessages(Network& net)
{
    User user1(1, "user1", 20);
    User user2(2, "user2", 20);
    User user3(3, "user3", 20);
    User user4(4, "user4", 20);
    User user5(5, "user5", 20);
    User user6(6, "user6", 20);
    User user8(8, "user8", 20);
    User user7(7, "user7", 20);
    User user9(9, "user9", 20);
    User user10(10, "user10", 20);
    User user11(11, "user11", 20);
    User user12(12, "user12", 20);
    User user13(13, "user13", 20);
    User user14(14, "user14", 20);
    User user15(15, "user15", 20);

    Message m1("salut ce faci", user1, user2);
    Message m2("bine tu?", user2, user1);
    Message m3("vezi sa cumperi niste mere", user1, user3);
    Message m4("mersi ca mi ai amintit", user3, user1); //6,7,12
    Message m5("am scos eu cainele afara", user2, user6);
    Message m6("bine ok", user6, user2);
    Message m7("am luat un 5 la mate", user2, user7);
    Message m8("se putea si mai bine", user7, user2);
    Message m9("m ai sunat?", user2, user12);
    Message m10("da, din greseala", user12, user2);
    Message m11("mi am uitat ceva la tine", user3, user9);
    Message m12("ti l aduc maine", user9, user3); //9,14
    Message m13("am ajuns acasa", user4, user9);
    Message m14("ma bucur", user9, user4);
    Message m15("la multi ani!", user4, user14);
    Message m16("multumesc", user14, user4);
    Message m17("unde esti?", user5, user7);
    Message m18("la mall", user7, user5);
    Message m19("ti ai facut tema?", user5, user15);
    Message m20("asta voiam sa te intreb si eu", user15, user5);
    Message m21("vii si tu maine?", user6, user10);
    Message m22("da vin", user10, user6);
    Message m23("ce mancam diseara?", user8, user14);
    Message m24("sarmale", user14, user8);
    Message m25("ti ai instalat aplicatia?", user8, user15);
    Message m26("inca nu, mai imediat", user15, user8);
   
    net.sendMessage(m1);
    net.sendMessage(m2);
    net.sendMessage(m3);
    net.sendMessage(m4);
    net.sendMessage(m5);
    net.sendMessage(m6);
    net.sendMessage(m7);
    net.sendMessage(m8);
    net.sendMessage(m9);
    net.sendMessage(m10);
    net.sendMessage(m11);
    net.sendMessage(m12);
    net.sendMessage(m13);
    net.sendMessage(m14);
    net.sendMessage(m15);
    net.sendMessage(m16);
    net.sendMessage(m17);
    net.sendMessage(m18);
    net.sendMessage(m19);
    net.sendMessage(m20);
    net.sendMessage(m21);
    net.sendMessage(m22);
    net.sendMessage(m23);
    net.sendMessage(m24);
    net.sendMessage(m25);
    net.sendMessage(m26);
    

}

void friendshipOptions() {
    SetConsoleTextAttribute(hConsole, 6);

    cout << "8.  Adaugare prietenie" << endl;
    cout << "9.  Afisarea tuturor prieteniilor de pe retea" << endl;
    cout << "10. Stergere prietenie" << endl;
    cout << "11. Afiseaza prieteniile pentru un user" << endl;
}
