#include <iostream>
#include <string>
#include <cctype>
#include "List.h"
#include "Patient.h"


using  namespace std;

void createPatient(List * listofPatients)
{
    string aCareCard = "";
    string aName="";                
    string anAddress="";          
    string aPhone="";
    string anEmail="";
 //   int position = -1;

    // Create a new member profile
    cout << "Please, enter the new Patient's Care Card Number: ";
    // Remove all leading whitespace -> ws
    getline(cin >> ws, aCareCard);

    if (aCareCard.length() != 10 )
        while ( aCareCard.length() != 10)
        {
            cout << "The input does not contain 10 digits, try again." << endl;
            // Create a new member profile
            cout << "Please, enter the new Patient's Care Card Number: ";
            // Remove all leading whitespace -> ws
            getline(cin >> ws, aCareCard);
        }


      //  while ()

    Patient newPatient(aCareCard);

    if(listofPatients->search(newPatient) == NULL)
    {
        // insert the newPatient to the listofPatients
        if ( listofPatients->insert(newPatient) )  // is it the address or the newPatient itself????
        {
           // Report to user
            cout << "Patient: " << newPatient.getCareCard() << " has been successfully added to the list of Patients." << endl;

            cout <<  endl << "Please, enter the new Patient's Name: ";
            getline (cin >> ws, aName);
            newPatient.setName(aName);
            cout << endl << "Please, enter the new Patient's address: ";
            getline(cin >> ws, anAddress);
            newPatient.setAddress(anAddress);
            cout <<  endl << "Please, enter the new Patient's Phone Number: ";
            getline(cin >> ws, aPhone);
            newPatient.setPhone(aPhone);
            cout << endl << "Please, enter the new Patient's E-mail address: ";
            getline(cin >> ws, anEmail);
            newPatient.setEmail(anEmail);

            cout <<  endl << "here are the information youi have entered: " << endl;
            newPatient.printPatient();


            //cout << "You may enter the Patient's information if you wish. Enter 'y' to continue, or 'n' to go back to main menue." << endl;
        }
        else
        {
            cout << newPatient.getCareCard() << " something went wrong! the new Patient was not added" << endl;
        }
    }
}



int main() {
    // Variables declaration
    List* listOfPatients = new List();

    bool done = false;
    char input = 0;

    // Keep doing what the user selects until the user exits
    while (not done)
    {
        // Print menu to user
        cout << "\n----Welcome to PatientsLog!\n" << endl;
        cout << "To create a Patient profile enter: c " << endl;
        cout << "To create a Patient profile enter: s " << endl;
        cout << "To create a Patient profile enter: c " << endl;
        cout << "To create a Patient profile enter: c " << endl;
        cout << "To create a Patient profile enter: c " << endl;
        cout << "To create a Patient profile enter: c " << endl;

        cout << "To exit \t\t\t  enter: x\n" << endl;

        cout << "Your choice: ";
        cin >> input;
        input = tolower(input);
        switch(input) {
            case 'c': createPatient(listOfPatients);
                break;
        switch(input) 

            case 's': createPatient(listOfPatients);
                break;
      //      case ''
          //  case 'n':
    //        case 'i': List::insert(newPatient);
      //          break;

            case 'x': cout << "\n----Bye!\n" << endl; done = true; break;
            default: cout << "Not sure what you mean! Please, try again!" << endl;
        }
    }

    return 0;
}
