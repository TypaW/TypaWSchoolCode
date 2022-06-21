#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H

#include "LinkedList.h"
#include "Address.h"


class AddressBook : public LinkedList<Address>
{
public:
    AddressBook();//constructor
    virtual ~AddressBook();//destructor
    void print();// Prints the Address Book
    void add(Address curAddress);// Adds an address
    void remove(std::string name);// Removes an address associated with the name passed in
    Address get(std::string name);// Gets an address by passing in the name of that address
    void generateBirthdayCards(std::string date);// Generate bday cards
    void generateAnniversaryCards(std::string date);// Generate anniversary cards
    void load();// Load the address book
    void save();// Save the address book
protected:
private:
    void printBirthdayCard(Address currAdress); //prints the birthday card
    void printAnniversaryCard(Address currAdress);//prints the Anniversary  card
};

#endif