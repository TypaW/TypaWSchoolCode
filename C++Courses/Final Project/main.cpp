#include <iostream>
#include <stdlib.h>
#include <string>
#include "LinkedList.h"
#include "AddressBook.h"

using namespace std;
//The following function prototypes creates the main menu and generates birthday cards. In addition to retriveing and storing User input.
void mainMenu(AddressBook& addresses);
void enterName(AddressBook& addresses);
void deleteName(AddressBook& addresses);
void changeName(AddressBook& addresses);
void generateBirthdayCards(AddressBook& addresses);
void generateAnniversaryCards(AddressBook& addresses);

void resetInput();
//this function starts it all by activating the Main menu
int main()
{
    // Load the address book
    AddressBook addresses;
    addresses.load();

    // Start the mainMenu loop
    mainMenu(addresses);
    return 0;
}

//this is the main menu as requested
void mainMenu(AddressBook& addresses)
{
    // Display main menu
    cout << "------------------Main menu------------------" << endl;
    cout << "[1]: Enter a new name into the address book" << endl;
    cout << "[2]: Delete a name from the address book" << endl;
    cout << "[3]: Change a name or date in the address book" << endl;
    cout << "[4]: Generate birthday cards" << endl;
    cout << "[5]: Generate anniversary cards" << endl;
    cout << "[6]: Save and exit the card program" << endl;
    cout << "[7]: Print address book." << endl;

    // Prompt for user input.
    cout << "Enter code here: ";

    // Cleanup to make sure cin is working before gathering user input
    resetInput();

    int code;
    cin >> code;
    cout << endl;

    // If their input failed, as they entered a word instead of a number
    while (cin.fail())
    {
        // Cleanup to make sure cin is working before gathering user input
        resetInput();

        // Prompts that input failed, trys to recollect input
        cout << "Input failed. Enter code here: ";
        cin >> code;
        cout << endl;
    }

    // Start the corresponding function the code that was entered.
    switch (code)
    {
    case 1:
        cout << "-----------------Enter Name------------------" << endl;
        enterName(addresses);
        break;
    case 2:
        cout << "-----------------Delete Name-----------------" << endl;
        deleteName(addresses);
        break;
    case 3:
        cout << "-----------------Change Name-----------------" << endl;
        changeName(addresses);
        break;
    case 4:
        cout << "---------------Birthday Cards----------------" << endl;
        generateBirthdayCards(addresses);
        break;
    case 5:
        cout << "-------------Anniversary Cards---------------" << endl;
        generateAnniversaryCards(addresses);
        break;
        // Saves and exits the program
    case 6:
        cout << "Now closing..." << endl;
        addresses.save();// Saves the addresses to the text file
        exit(0);// Exits the program
        break;
    case 7:
        cout << "----------------Address List-----------------" << endl;
        addresses.print();
        break;
    default:
        // The default operation will print wrong number.
        cerr << "Sorry, wrong number." << endl;
        break;
    };
    mainMenu(addresses);
}

void enterName(AddressBook& addresses)
{
    // This resets the information before gathering user input
    resetInput();

    // This request the user to input name, address, anniversary date, and birthday
    Address cur;
    cout << "Enter name:";
    getline(cin, cur.name);

    cout << "Enter Address:";
    getline(cin, cur.streetAddress);

    cout << "Enter Anniversary Date(MM/DD/YY):";
    getline(cin, cur.anniversaryDate);

    cout << "Enter Birthday Date(MM/DD/YY):";
    getline(cin, cur.birthdayDate);

    cout << endl;

    // We then add the newly created address to the address book
    addresses.add(cur);
}

void deleteName(AddressBook& addresses)
{
    // This resets the information before gathering user input
    resetInput();

    // Retrieves the requested name to delete
    string name;
    cout << "Enter name to delete: ";
    getline(cin, name);
    cout << endl;

    // Remove it from the address book
    addresses.remove(name);
}

void changeName(AddressBook& addresses)
{
    // This resets the information before gathering user input
    resetInput();

    // Retrieves the requested name to rename
    string name;
    cout << "Enter name to rename: ";
    getline(cin, name);

    // Retrieves the address with the specific name
    Address addressToBeDeleted = addresses.get(name);

    // If the address is NULL and the entered name doesn't exist. This exits the function.
    if (addressToBeDeleted.name == "NULL")
    {
        cerr << "Entered name does not exist!" << endl;
        return;
    }


    // New Address that is being formed
    Address* changeAddress = new Address;
    changeAddress->streetAddress = addressToBeDeleted.streetAddress;
    changeAddress->anniversaryDate = addressToBeDeleted.anniversaryDate;
    changeAddress->birthdayDate = addressToBeDeleted.birthdayDate;

    // Removes the old address
    addresses.remove(name);

    // Retrieves the new name from user
    cout << "Enter new name: ";
    getline(cin, name);
    cout << endl;
    changeAddress->name = name;

    // Adds the new address to the address book
    addresses.add(*changeAddress);
}

void generateBirthdayCards(AddressBook& addresses)
{
    // This resets the information before gathering user input
    resetInput();

    //The following retrieves the date from the user
    string date;
    cout << "Enter date: ";
    cin >> date;

    // Generates the birthday cards for the date
    addresses.generateBirthdayCards(date);
}

//This function does exactly as named
void generateAnniversaryCards(AddressBook& addresses)
{
    // Cleanups up input contained in cin to ensure correct operation before gathering user input
    resetInput();

    // Gets the date
    string date;
    cout << "Enter date: ";
    cin >> date;

    // Generates the anniversary cards for the date
    addresses.generateAnniversaryCards(date);
}

// Cleanups up input contained in cin to ensure correct operation before gathering user input
void resetInput()
{
    // If it's failed, then the program ignores the whole line
    if (cin.fail())
    {
        // Removes any information user entered.
        cin.clear();
    }

    // this If is for ingnoring the next character if it is a newline
    if (cin.peek() == '\n')
    {
        cin.ignore();
    }
}