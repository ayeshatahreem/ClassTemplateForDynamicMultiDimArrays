//C++ does not provide dynamic multidimensional arrays. Develop a class template Array to provide such facility. 
//Note that the array should hold elements of any type, and should be able to have any number of dimensions


#include "dynamicArrays.h"
#include <iostream>
#include <conio.h>						//getch usage
void main()
{
		multiDimensionalArr <char> arr;
		arr.set(5,1,1,"DS");
		arr.set(1,0,0,"DS");
		arr.set(2,0,1,"Assign2");
		arr.set(10,0,1,"Multiarrays");
		cout<<arr.get(10,0,1)<<endl;
		/*
		b.set(1,0,0,1);
		b.set(1,0,1,2);
		b.set(1,0,1,3);
		b.set(1,1,1,4);
		b.set(2,0,1,5);
		b.set(2,0,0,3);
		b.set(3,1,1,10);
		b.set(3,1,0,5);
		b.set(4,0,1,3);
		b.set(4,1,1,9);
		b.set(5,1,1,8);
		b.set(6,0,1,97);
		b.set(7,1,0,8);
		b.set(8,0,0,23);
		b.set(12,1,2,13);
		cout<<b.get(12,1,1)<<endl;
		cout<<b.get(4,1,1)<<endl;
		b.print();
		cout<<endl;
		b.printMatrix();
		cout<<endl;*/
		arr.printLinear();
		cout<<endl;
		arr.printMatrix();
		getch();				//Reads a character directly from the console without buffer, and without echo.
}
