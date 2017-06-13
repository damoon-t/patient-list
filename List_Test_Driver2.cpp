/*
 * List_Test_Driver2.cpp - Assignment 2
 * 
 * Class Description: Test Driver for List (and Patient) class
 *
 * Modified on: June 12th, 2017
 * Author: Damoon
 */

#include <iostream>
#include <string>
#include <cctype>
#include "Patient.h"
#include "List.h"

using namespace std;

int main()
{
    List sample = List();

/*  for (int i=0; i<10; i++)
    {
        int x = sample->elementCountCat[i];
        int y  = sample.getElementCount();
        printf("%d %d \n", x, y);
    }*/

    //samole patients
    Patient p1234567890("1234567890");
    Patient p2345678901("2345678901");
    Patient p3456789012("3456789012");
    Patient p4567890123("4567890123");
    Patient p5678901234("5678901234");
    Patient p5389012384("5389012384");
    Patient p5489012384("5489012384");
   
    Patient abc("0001112223");
    cout << abc.getCareCard();
    
    //testing insert
    cout << endl;
    cout << "Add Patient p2345678901 to List";
    if(sample.insert(abc))
    {
        cout << "sample true" << endl;
    }


    //testing elementCount
    cout << "\nThere are now " << sample.getElementCount() << " patients in List." << endl; 
    sample.printList();
        cout << endl;

    cout << "Add Patient p2345678901 to List";
    sample.insert(p2345678901);
    cout << "\nThere are now " << sample.getElementCount() << " patients in List." << endl; 
    sample.printList();

    cout << endl;
    cout << "Add Patient p5678901234 to List";
    sample.insert(p5678901234);
    cout << "\nThere are now " << sample.getElementCount() << " patients in List." << endl; 
    sample.printList();
        cout << endl;

    cout << "Add Patient p5389012384 to List";
    sample.insert(p5389012384);
    cout << "\nThere are now " << sample.getElementCount() << " patients in List." << endl; 
    sample.printList();
        cout << endl;

    cout << "Add Patient p5489012384 to List";
    sample.insert(p5489012384);
    cout << "\nThere are now " << sample.getElementCount() << " patients in List." << endl; 
    sample.printList();
        cout << endl;

    cout << "Add Patient p1234567890 to List";
    sample.insert(p1234567890);
    cout << "\nThere are now " << sample.getElementCount() << " patients in List." << endl; 
    sample.printList();
        cout << endl;

    cout << "Add Patient p3456789012 to List";
    sample.insert(p3456789012);
    cout << "\nThere are now " << sample.getElementCount() << " patients in List." << endl; 
    sample.printList();
        cout << endl;    

    cout << "remove Patient p3456789012 to List";
    sample.remove(p3456789012);
    cout << "\nThere are now " << sample.getElementCount() << " patients in List." << endl; 
    sample.printList();
        cout << endl; 

    cout << "remove Patient p5678901234 to List";
    sample.remove(p5678901234);
    cout << "\nThere are now " << sample.getElementCount() << " patients in List." << endl; 
    sample.printList();
        cout << endl; 
    
    cout << "remove Patient abc to List";
    sample.remove(abc);
    cout << "\nThere are now " << sample.getElementCount() << " patients in List." << endl; 
    sample.printList();
        cout << endl; 
    return 0;
}