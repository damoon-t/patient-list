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

	for (int i=0; i<10; i++)
	{
		elements[i]= new Patient [MAX_ELEMENTS]; //we randomely chose to make an initial size of 1 for the start
		elementCountCat[i] = 0; 				// so we can re-allocate memory to each array of patiens individually  
		capacity[i] = MAX_ELEMENTS; // it may be redundant
	}
	elementCount =0;
	
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
}


int List::getElementCount() const
{
    return elementCount;
}
int List::getElementCountCat(int i)
{
	return elementCountCat[i];
}

bool insert(const Patient& newElement) // not sorted
{	// this is probably wrong, but assuming it works, read the rest of the logic 
	int col = newElement.getCareCard()[0]; // I don't know how to find the first character of the carecard!!
	int x = elementCountCat[col];	
	int y = capacity[col];
	if ( x == y-1)  //if we reach the last empty space allocate memory
	{ 
		capacity[col] = 2* y;
		elements[i]= new Patient [capacity[col]]; // increase the capacity and allocate double the current memory
	}
	if( x < capacity[col]) // I know this is redundant 
	{
		elements[col][x] = Patient& newElement; //not sorted, place it at the end

		return true; 
	}

	return false; 
}




int main()
{
	List sample = List();
	for (int i=0; i<10; i++){
	int x = sample.getElementCountCat(i);
	int y  = sample.getElementCount();
	printf("%d %d \n", x, y);
}
	return 0;
}

