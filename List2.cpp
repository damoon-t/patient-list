#include "List.h"
#include "Patient.h"
#include <cassert>
#include <string>
#include <iostream>
#include <stdio.h>
#include <sstream>

// for testing purposes 
#include "Patient.cpp"
//.....................

using namespace std;


List::List()
{
	elementCount = 0;
	for (int i=0; i<10; i++)
	{
		elements[i]= new Patient [MAX_ELEMENTS]; //we randomely chose to make an initial size of 1 for the start
		elementCountCat[i] = 0; 				// so we can re-allocate memory to each array of patiens individually  
		capacity[i] = MAX_ELEMENTS; // it may be redundant
		elementCount = elementCount + elementCountCat[i];
	}	
}

//
	int  List::getElementCount() const
{
	return elementCount;
}
//Manual constructor, copier
//List::List(const List&)
//{}

// Destructor, 
List::~List() 
{
	for(int i=0; i<10; i++)
		{
			delete[] elements[i]; //it seems that this the only one that needs delete, the rest will be deallocated by default
		}
//	delete[] elements; // I don't know if this is needed or not, actually this causes a warning
}




bool List::insert(const Patient& newElement) // not sorted
{	// this is probably wrong, but assuming it works, read the rest of the logic 



	//elements[0][0] = newElement;

	char col = newElement.getCareCard()[0]; // I don't know how to find the first character of the carecard!!
	//int column = std.convert (col); // I need to convert char to integer
	if (col == '0')
	{

cout << col << "char for col ,  true";
return true;
}
	int colCount = elementCountCat[col];	
	int y = capacity[col];
/*	if ( colCount == y-1)  //if we reach the last empty space allocate memory
	{ 
		capacity[col] = 2* y;
		elements[col]= new Patient [capacity[col]]; // increase the capacity and allocate double the current memory
	}*/
	if(true)//( colCount < capacity[col]) // I know this is redundant 
	{
		elements[col][1] = newElement; //not sorted, place it at the end

		//elementCountCat[0] = elementCountCat[0] + 1;
		return true; 
	}
	return false; 
}
/*   //to be Done by Sunday night

        //char x = toBeRemoved.getCareCard()[0];
	// Description: Remove an element. 
	//    If the removal is successful, true is returned otherwise, false is returned.
	// Postcondition: toBeRemoved is removed, the appropriate elementCount has been decremented.	
	bool List::remove( const Patient& toBeRemoved );
	
	// Description: Remove all elements.
	void List::removeAll()
	{
    elementCount=0;
	}
   
	// Description: Search for target element and returns a pointer to it if found,
	//              otherwise, returns NULL.
	Patient* List::search(const Patient& target)
	{
		int col = int( newElement.getCareCard()[0]); // I don't know how to find the first character of the carecard!!
		int colCount = elementCountCat[col];
		for(int i=0; i<colCount; i++)
		{
			if (elements[col][i] == target)
				return &elements[col][i];
		}
	}
   
	// Description: Prints all n elements stored in List in sort order and does so in O(n).
	void List::printList()
	for()
	{

	}
*/


int main()
{
	List sample = List();

/*	for (int i=0; i<10; i++)
	{
		int x = sample->elementCountCat[i];
		int y  = sample.getElementCount();
		printf("%d %d \n", x, y);
	}*/
	//samole patients
	//Patient p1234567890("1234567890");
    //Patient p2345678901("2345678901");
    //Patient p3456789012("3456789012");
    //Patient p4567890123("4567890123");
    //Patient p5678901234("5678901234");
    Patient abc("0001112223");
    cout << abc.getCareCard();
    //testing insert
    //cout << endl;
    //cout << "Add Patient p2345678901 to List";
 	if(sample.insert(abc))
 	{
 		cout << "sample true" << endl;
 	}


    //testing elementCount
    //cout << "\nThere are now " << sample.getElementCount() << " patients in List." << endl;	
    //sample.printList();
	return 0;
}

