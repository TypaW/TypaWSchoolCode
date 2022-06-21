#ifndef ADDRESS_H
#define ADDRESS_H

#include <iostream>

class Address
{
public:
    // Creates an Address using these 4 parameters and default values
    Address(std::string name = "Not Entered",
        std::string streetAddress = "Not Entered",
        std::string anniversaryDate = "XX-XX-XXXX",
        std::string birthdayDate = "XX-XX-XXXX");
    virtual ~Address();
    // Let other files print out addresses
    friend std::ostream& operator<<(std::ostream& os, const Address& curAddress);
    std::string name;//this is for the name associated with an address
    std::string streetAddress;//this is the address
    std::string anniversaryDate;//this the date of the entry's anniversary
    std::string birthdayDate;//this the date of the entry's birthday
};

#endif