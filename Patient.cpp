
#include <iostream>
#include "Patient.h"

using namespace std;



Patient::Patient ()
{
    careCard = "0000000000";
    name = "To be entered default";
    address = "To be entered";
    phone = "To be entered";
    email = "To be entered";
}


Patient::Patient(string aCareCard)
{  
    careCard = aCareCard;
    name = "To be entered not default";
    address = "To be entered";
    phone = "To be entered";
    email = "To be entered";
}


string Patient::getName() const
{
    return name;
}

string Patient::getAddress() const
{
    return address;
}

string Patient::getPhone() const
{
    return phone;
}

string Patient::getEmail() const
{
    return careCard;
}

string Patient::getCareCard() const
{
    return careCard;
}
void Patient::setName(const string aName)
{
    name = aName;
}

void Patient::setAddress(const string anAddress)
{
    address = anAddress;
}

void Patient::setPhone(const string aPhone)
{
    phone = aPhone;
}

void Patient::setEmail(const string anEmail)
{
    email = anEmail;
}

bool Patient::operator==(const Patient &rhs) // probably requires a for loop
{
    if(careCard == rhs.getCareCard())
        return true;
    else
        return false;

 /*   for (int i=0; i<10; i++)
    {
        if(careCard[i] == rhs.getcareCard()[i] ) 
        {
            return true;
        }
        else //if (careCard[i] < rhs.careCard[i]) // this was a mistake, it excludes equal carecards
        {
            return false;
        }*/
}

bool Patient::operator>(const Patient &rhs)
{
    if ( careCard > rhs.getCareCard())
        return true;
    else
        return false;


/*    for (int i=0; i<10; i++)
    {
        if(careCard()[i] > rhs.getcareCard()[i] ) 
        {
            return true;
        }
        else 
        {
            return false;
        }

    }*/

}


void Patient::printPatient()
{
    cout << careCard << ", " << "Patient: " << name << ", " << address
         << ", " << phone << ", " << email << endl;
}
