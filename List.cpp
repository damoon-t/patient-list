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

//List::insert(const Patient& toBeRemoved)
//{

//}




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

