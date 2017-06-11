#include "List.h"
#include "Patient.h"
#include <cassert>
#include <string>
#include <iostream>

// for testing purposes 
#include "Patient.cpp"
//.....................

using namespace std;






List::List()
{

	for (int i=0; i<10; i++)
	{
		elements[i]= new Patient [MAX_ELEMENTS]; //we randomely chose to make an initial size of 1 for the start
		elementCountCat[i] = 0; 
		capacity[i] = MAX_ELEMENTS; 
	}
	elementCount =0;
	
}
//Manual constructor, copier
//List::List(const List&)
//{}

// Destructor, 
List::~List() 
{


}


int List::getElementCount() const
{
    return elementCount;
}

List::insert(const Patient& toBeRemoved)
{

}




int main()
{}

