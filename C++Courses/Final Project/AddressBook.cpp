#include "AddressBook.h"
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>

AddressBook::AddressBook()
{
    //constructor
}

AddressBook::~AddressBook()
{
    //destructor
}

// Prints all of the stored addresses in the address book
void AddressBook::print()
{
    Node* it = head;
    while (it != NULL)
    {
        std::cout << it->val << std::endl;
        it = it->next;
    }
}

// Removes the passed in name
void AddressBook::remove(std::string name)
{
    // start the iterator at the head
    Node* it = head;
    Node* prev = NULL;

    // While our iterator is not null
    while (it != NULL)
    {
        // Gets the current name out of the node
        std::string curName = ((Address)it->val).name;

        // this If detects the current name and nameToBeDeleted are the same
        if (curName == name)
        {
            // this If detects we are at the head, set it's next node to the iterators next value
            if (prev == NULL)
            {
                head = it->next;
                delete it;
            }
            // the Else sets the previous values next value to the iterators next value
            else
            {
                prev->next = it->next;
                delete it;
            }
            // Decreases the length on removal
            length--;
        }
        // Sets the previous node to be the iterator
        prev = it;
        // Sets the iterator to the next value
        it = it->next;
    }
}

// Returns the address at the name passed in, or an address whose name is NULL if the name isn't in the address book
Address AddressBook::get(std::string name)
{
    // Sets the iterator to the head of the linked list
    Node* it = head;

    // While our name isn't found, and we haven't gone through the whole list
    while (it != NULL)
    {
        // Extracts the iterators name
        std::string curName = ((Address)it->val).name;

        // If the iterators name is equal to the wanted name, then the value is found and returned
        if (curName == name)
        {
            return it->val;
        }
        it = it->next;
    }
    // If the address requested wasn't found, then this function returns NULL for the address
    Address nullAdd;
    nullAdd.name = "NULL";
    return nullAdd;
}

// Goes through every address to find the a print out birthday cards with the same date as string passed in
void AddressBook::generateBirthdayCards(std::string date)
{
    // This sorts through every address to find a match
    Node* it = head;
    while (it != NULL)
    {
        //this If function detects if the birthday is equal to the date passed in, then prints the birthday card
        Address curAddress = ((Address)it->val);
        if (date == curAddress.birthdayDate)
        {
            printBirthdayCard(curAddress);
        }
        it = it->next;
    }
}
//this is the output for a birthday card
void AddressBook::printBirthdayCard(Address curAddress)
{
    std::cout << "-------------------------------------" << std::endl;
    std::cout << "Dear " << curAddress.name << "," << std::endl << std::endl;
    std::cout << "Hope your birthday is really wonderful and this coming year is the best yet!" << std::endl;
    std::cout << "Love," << std::endl << std::endl;
    std::cout << "Person" << std::endl;
}

// Goes through every address stored and prints out anniversary cards with the same date as string passed in
void AddressBook::generateAnniversaryCards(std::string date)
{
    // This sorts through every address to find a match
    Node* it = head;
    while (it != NULL)
    {
        // If it's anniversary is equal to the date passed in, print it's anniversary card
        Address curAddress = ((Address)it->val);
        if (date == curAddress.anniversaryDate)
        {
            printAnniversaryCard(curAddress);
        }
        it = it->next;
    }
}

// Adds an entered address to the book along with making sure it is sorted alphabetically
void AddressBook::add(Address newAddress)
{
    // Create a new node with our address
    Node* newNode = new Node;
    newNode->val = newAddress;
    newNode->next = NULL;

    // This IF function detects the head is null, then the head and tail are both put into a new node
    if (head == NULL)
    {
        head = tail = newNode;
    }
    else
    {
        // Create an iterator, and previous iterator
        Node* prev = NULL;
        Node* it = head;

        // Goes through each element
        while (it != NULL)
        {
            // If the current name is greater than the new name,
            std::string curName = ((Address)it->val).name;
            if (curName > newAddress.name)
            {
                // Adds the new node at the last location, then rewires the list
                if (prev == NULL)
                {
                    head = newNode;
                    newNode->next = it;
                }
                else
                {
                    prev->next = newNode;
                    newNode->next = it;
                }
                return;
            }
            else
            {
                // Else we go to the next node
                if (it->next == NULL)
                {
                    it->next = newNode;
                    it = newNode->next;
                }
                else
                {
                    prev = it;
                    it = it->next;
                }

            }

        }
    }
    // Increments the length when an item is added
    length++;
}

//this is the printing of the Anniversary card
void AddressBook::printAnniversaryCard(Address curAddress)
{
    std::cout << "-------------------------------------" << std::endl;
    std::cout << "Dear " << curAddress.name << "," << std::endl << std::endl;
    std::cout << "Hope your anniversary is really wonderful and this coming year is the best yet!" << std::endl;
    std::cout << "Love," << std::endl << std::endl;
    std::cout << "Person" << std::endl;
}

//this loads the address book from a properties file
void AddressBook::load()
{
    // Attempts to open the address file
    std::ifstream in;
    in.open("addresses.properties");

    //this If catches the file if it didn't open, print an error message
    if (!in.good())
    {
        std::cerr << "Cannot open addresses.properties" << std::endl;
        return;
    }

    //this While statement we can read without an error, keep adding addresses to our book
    while (in.good())
    {
        // Creates an new address, then gets all 4 elements
        Address* curAddress = new Address;
        std::string temp;

        getline(in, temp);
        curAddress->name = temp;

        getline(in, temp);
        curAddress->streetAddress = temp;

        getline(in, temp);
        curAddress->anniversaryDate = temp;

        getline(in, temp);
        curAddress->birthdayDate = temp;

        //this If activates our input as long the input is still good after adding those 4 elements,then adds the new address.
        if (in.good())
        {
            add(*curAddress);
        }
    }

    // this closes the file stream
    in.close();
}

// This function saves the address book
void AddressBook::save()
{
    //this opens the properties file for our address book
    std::ofstream out;
    out.open("addresses.properties");

    // If it failed to open, print an error and end.
    if (!out.good())
    {
        std::cerr << "Cannot open addresses.properties" << std::endl;
        return;
    }

    // For every address
    Node* it = head;
    while (it != NULL)
    {
        // Prints it's information to a new line of the text file
        Address curAddress = (Address)it->val;
        out << curAddress.name << std::endl;
        out << curAddress.streetAddress << std::endl;
        out << curAddress.anniversaryDate << std::endl;
        out << curAddress.birthdayDate << std::endl;

        // Goes to the next node
        it = it->next;
    }

    // Closes the outstream
    out.close();
}