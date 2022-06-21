#include "Address.h"

// This allows the creation of address by being created with name, address, anniversary date, and bday
Address::Address(std::string name, std::string streetAddress, std::string anniversaryDate, std::string birthdayDate)
{
    this->name = name;
    this->streetAddress = streetAddress;
    this->anniversaryDate = anniversaryDate;
    this->birthdayDate = birthdayDate;
}

//destructor
Address::~Address()
{
}

// Can be printed out by an overloaded operator.
std::ostream& operator<<(std::ostream& outStream, const Address& curAddress)
{
    outStream.clear();
    outStream << "Name:             " << curAddress.name << std::endl
        << "Address:          " << curAddress.streetAddress << std::endl
        << "Anniversary Date: " << curAddress.anniversaryDate << std::endl
        << "Birthday Date:    " << curAddress.birthdayDate << std::endl;
    return outStream;
}