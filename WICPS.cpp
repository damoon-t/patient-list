#include <iostream>
#include <string>
#include <cctype>
#include "List.h"
#include "Patient.h"


using  namespace std;

void createPatient(List& listOfPatients)
{
    string aCareCard = "";
    string aName="";                
    string anAddress="";          
    string aPhone="";
    string anEmail="";
 //   int position = -1;

    // Create a new Patient profile
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

    Patient newPatient(aCareCard);

    if(listOfPatients.search(newPatient) == NULL)
    {
        // insert the newPatient to the listOfPatients
        if ( listOfPatients.insert(newPatient) )  // is it the address or the newPatient itself????
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

            cout <<  endl << "here are the information you have entered: " << endl;
            newPatient.printPatient();


            //cout << "You may enter the Patient's information if you wish. Enter 'y' to continue, or 'n' to go back to main menue." << endl;
        }
        else
        {
            cout << newPatient.getCareCard() << " something went wrong! the new Patient was not added" << endl;
        }
    }
}

void searchForPatient(List& listOfPatients)
{
    string aCareCard = "";
    // Search for a Patient 
    cout << "Please, enter the Patient's Care Card Number: ";
    // Remove all leading whitespace -> ws
    getline(cin >> ws, aCareCard);

    if (aCareCard.length() != 10 )
        while ( aCareCard.length() != 10)
        {
            cout << "The input does not contain 10 digits, try again." << endl;
            // Create a new member profile
            cout << "Please, enter the Patient's Care Card Number: ";
            // Remove all leading whitespace -> ws
            getline(cin >> ws, aCareCard);
        }

    //creates a temporary patient to
    Patient targetPatient(aCareCard);

    Patient* foundedPatient = listOfPatients.search(targetPatient); 

    if( foundedPatient == NULL) 
    {
        cout << "the patient was not found, you can add the patient to the list.";
    }
    else
    {

        cout << "here are the information of the Patient you are searching for: " << endl;
        foundedPatient->printPatient(); 
    }
}

void removePatient(List &listOfPatients)
{
    string aCareCard = "";
    bool result = false;
        // Search for a Patient 
        cout << "Please, enter the Patient's Care Card Number: ";
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

        //creates a temporary patient to
    Patient toBeRemovedPatient(aCareCard);  

    Patient* foundedPatient = listOfPatients.search(toBeRemovedPatient); 
    if (foundedPatient == NULL)
    {
        cout << "Sorry! The given care card number does not exist in the list of patients. Try again..." << endl;
    }
    else
    {
        result = listOfPatients.remove(toBeRemovedPatient);
    }

    if (result)
    {
        cout << "the patient's profile has been removed successfully from the list of patients." << endl;
    } 
    else
    {
        cout << "something went wrong. the patient has not been removed." << endl;
    }
}

void modifyPatient(List &listOfPatients)
{

    string aCareCard = "";
        string aName="";                
        string anAddress="";          
        string aPhone="";
        string anEmail="";
     //   int position = -1;

        // Create a new Patient profile
        cout << "Please, enter the Patient's Care Card number whose profile needs to be modified: ";
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

        Patient toBeModifiedPatient(aCareCard);

        Patient* toBeModified = listOfPatients.search(toBeModifiedPatient);

        if(toBeModified == NULL)
        {
            cout << toBeModifiedPatient.getCareCard() << " The new Patient is not in the list of Patients, try again..." << endl;
        }

        // insert the newPatient to the listOfPatients
        else
        {
           // Report to user
            cout << "Here are the information linked to the given Care Card number: " << endl;
            toBeModifiedPatient.printPatient();

            cout <<  endl << "Please, enter the Patient's new Name: ";
            getline (cin >> ws, aName);
            toBeModifiedPatient.setName(aName);
            cout << endl << "Please, enter the Patient's new address: ";
            getline(cin >> ws, anAddress);
            toBeModifiedPatient.setAddress(anAddress);
            cout <<  endl << "Please, enter the Patient's new Phone Number: ";
            getline(cin >> ws, aPhone);
            toBeModifiedPatient.setPhone(aPhone);
            cout << endl << "Please, enter the Patient's new E-mail address: ";
            getline(cin >> ws, anEmail);
            toBeModifiedPatient.setEmail(anEmail);

            cout <<  endl << "Here are the information you have entered: " << endl;
            toBeModifiedPatient.printPatient();
        }   

}

void printingPatient(List &listOfPatients)
{
    string aCareCard = "";
    // Search for a Patient 
    cout << "Please, enter the Patient's Care Card Number: ";
    // Remove all leading whitespace -> ws
    getline(cin >> ws, aCareCard);

    if (aCareCard.length() != 10 )
        while ( aCareCard.length() != 10)
        {
            cout << "The input does not contain 10 digits, try again." << endl;
            // Create a new member profile
            cout << "Please, enter the Patient's Care Card Number: ";
            // Remove all leading whitespace -> ws
            getline(cin >> ws, aCareCard);
        }

    //creates a temporary patient to
    Patient toBePrintedPatient(aCareCard);

    Patient* foundedPatient = listOfPatients.search(toBePrintedPatient); 

    if( foundedPatient == NULL) 
    {
        cout << "the patient was not found, you can add the patient to the list.";
    }
    else
    {

        cout << "Here are the information of the Patient you are searching for: " << endl;
        toBePrintedPatient.printPatient(); 
    }

}

void printingAllPatients(List &listOfPatients)
{
    if (listOfPatients.getElementCount() == 0)
    {
        cout << "The list is empty..." << endl;
    }
    else
    {
    cout << "Here is the complete list of patients: " << endl;
    listOfPatients.printList();
    }

}

void removeAllPatients(List &listOfPatients)
{
    char input;
    cout << "Are you sure you want to delete the list of Patients????" << endl;
    cout << "enter 'y' for yes,and 'n' for no:  ";
    cin >> input; 
    input = tolower(input);
    if (input == 'y')
    {
        listOfPatients.removeAll();
        cout << "The list of patients has been removed." << endl;
    }
    else
    {
        cout << "Don't worry, Nothing has been removed." << endl;
    }


}

int main() {
    // Variables declaration
    List listOfPatients = List();

    bool done = false;
    char input = 0;

    // Keep doing what the user selects until the user exits
    while (not done)
    {
        // Print menu to user
        cout << "\n----Welcome to PatientsLog!\n" << endl;
        cout << "To create a Patient profile enter: c " << endl;
        cout << "To search for a Patient profile enter: s " << endl;
        cout << "To remove a Patient profile enter: r " << endl;
        cout << "To modify a Patient profile enter: m " << endl;
        cout << "To print a Patient profile enter: p " << endl;
        cout << "To print all Patient profiles enter: a " << endl;
        cout << "To remove all Patient profiles enter: d " << endl;


        cout << "To exit \t\t\t  enter: x\n" << endl;

        cout << "Your choice: ";
        cin >> input;
        cout << endl;
        input = tolower(input);

        switch(input) {
            case 'c': createPatient(listOfPatients);
                break;

            case 's': searchForPatient(listOfPatients);
                break;

           case 'r': removePatient(listOfPatients);
                break;

           case 'm': modifyPatient(listOfPatients);
                break;

            case 'p': printingPatient(listOfPatients);
                break;

            case 'a': printingAllPatients(listOfPatients);
                break;

            case 'd': removeAllPatients(listOfPatients);
                break;


            case 'x': cout << "\n----Bye!\n" << endl; done = true; break;
            default: cout << "Not sure what you mean! Please, try again!" << endl;
        }
    }

    return 0;
}