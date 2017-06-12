#include "List.h"
#include "Patient.h"
#include <cassert>
#include <string>
#include <iostream>
#include <stdio.h>

// for testing purposes 
#include "Patient.cpp"
//.....................

using namespace std;


List::List()
{
	//elementCount = 0;
	for (int i=0; i<10; i++)
	{
		elements[i]= new Patient [MAX_ELEMENTS]; //we randomely chose to make an initial size of 1 for the start
		elementCountCat[i] = 0; 				// so we can re-allocate memory to each array of patiens individually  
		capacity[i] = MAX_ELEMENTS; // it may be redundant		
	}	
}

int List::getCol(const Patient& newElement)
{
	int col = newElement.getCareCard()[0] - '0';

	return col;
}

//
	int  List::getElementCount() const
{	
	int elementCount=0;
	for(int i=0; i<10; i++)
	{
		elementCount = elementCount + elementCountCat[i];
	}
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
{	
// this is probably wrong, but assuming it works, read the rest of the logic 
//elements[0][0] = newElement;

	int col= getCol(newElement); // to find and covert the first character of the carecard
	int colCount = elementCountCat[col];		
	int y = capacity[col];
	if (colCount >= y-1)  //if we reach the last empty space allocate memory
	{ 
		capacity[col] = 2* y;
		Patient* tempPatient = new Patient [capacity[col]];
		for(int i = 0; i < y; i++){
			tempPatient[i] = elements[col][i];
		}
		delete[] elements[col];
	//	elements[col]=NULL;
		elements[col] = tempPatient;

		//elements[col]= new Patient [capacity[col]]; // increase the capacity and allocate double the current memory
	
	}
	if(colCount < capacity[col]) // I know this is could be redundant 
	{
		int i =0;
		while (i < colCount && !(elements[col][i] > newElement))
			{
				i++;
			}
		int index = i;
					
		for (int k = colCount; k > index; k--) //Not a nested for loop, this moves everything forward
        {
            elements[col][k] = elements[col][k - 1];
        }
		
		elements[col][index] = newElement; //not sorted, places it at the end
		elementCountCat[col]++;
		//elementCount++;
		return true; 
	}
	return false; 
}
  //to be Done by Sunday night

    //char x = toBeRemoved.getCareCard()[0];


	// Description: Remove an element. 
	//    If the removal is successful, true is returned otherwise, false is returned.
	// Postcondition: toBeRemoved is removed, the appropriate elementCount has been decremented.	
	bool List::remove( const Patient& toBeRemoved )
	{
		int col = getCol(target);
		int colCount = elementCountCat[col];
		for(int i=0; i<colCount; i++)
		{
			if (elements[col][i] == target)
			{
				delete elements[col][i];

			}
		}

	}


	
	// Description: Remove all elements.
	void List::removeAll()
	{
    
    	for(int i=0; i<10; i++)
		{
			delete[] elements[i];
			elements[i]=NULL;
			elementCountCat[i]=0;
			capacity[i]=0;
		}
		elementCount=0;
	}
   
	// Description: Search for target element and returns a pointer to it if found,
	//              otherwise, returns NULL.
	Patient* List::search(const Patient& target)
	{
		int col = getCol(target);
		int colCount = elementCountCat[col];
		for(int i=0; i<colCount; i++)
		{
			if (elements[col][i] == target)
				return &elements[col][i];
		}

		return NULL;
	}
  
	// Description: Prints all n elements stored in List in sort order and does so in O(n).
	void List::printList()
	{
		for (int j = 0; j < 10 ; j++)
		{
			if (elementCountCat[j] > 0 )
			{				
				for (int i = 0 ; i < elementCountCat[j]; i++ )
		    	{
		        	elements[j][i].printPatient();
		    	}
	    	}
		}

	}


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
//    cout << "Add Patient p2345678901 to List";
//    sample.insert(p2345678901);

//    cout << "\nThere are now " << sample.getElementCount() << " patients in List." << endl;	
//    sample.printList();

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

	return 0;
}

