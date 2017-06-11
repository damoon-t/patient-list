
#include <iostream>
#include "Patient.h"

using namespace std;



Patient::Patient ()
{
    careCard = "0000000000";
    name = "To be entered";
    address = "To be entered";
    phone = "To be entered";
    email = "To be entered";
}


Patient :: Patient(string aCareCard)
{
    if (aCareCard.size() != 10 )
    {
        careCard = "0000000000";
    }
    else
    {
        careCard = aCareCard;
    }

    name = "To be entered";
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

bool Patient::operator==(const Patient &rhs)
{
    if (careCard == rhs.getCareCard() )
        return true;
    else
        return false;
}

bool Patient::operator>(const Patient& rhs)
{
    for (int i=0; i<10; i++)
    {
        if(careCard[i] > rhs.careCard[i])
        {
            return true;
        }
        else if (careCard[i] < rhs.careCard[i])
        {
            return false;
        }
        /*else if (i ==9 && careCard[i] == rhs.careCard[i])
        {
            return true;
        }*/
    }

}


void Patient::printPatient()
{
    cout << careCard << "," << "Patient: " << name << "," << address
         << "," << phone << "," << email << endl;
}
