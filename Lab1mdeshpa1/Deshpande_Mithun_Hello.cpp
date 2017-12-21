
/* A Deshpande_Mithun_Hello class having main function */	

#include <stdlib.h> 


#include "Hello_Class.h" // header file 

// main function
int main(int argc, char *argv[]) 
{

	// dynamic object creation
	Hello_Class *my_hello_ptr = new Hello_Class(0);
	my_hello_ptr->print_hello();
	delete(my_hello_ptr); // free memory once object is being used

	Hello_Class my_hello(1); // implicit object 
	my_hello.print_hello(); 

}  // end of main

