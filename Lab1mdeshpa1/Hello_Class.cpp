 
/* Hello_Class class having implementation of member functions
   Hello_Class and print_hello */


#include "Hello_Class.h" // header file

// Constructor memeber function   
Hello_Class::Hello_Class(int i) {
		if(i == 0) {
	   	    output_string = "Hello C++ Data Structures, from Mithun Deshpande!!";
		} else {
	   	    output_string = "Hello Data Structures!";
	        }
}

// Memeber function to display output string
void Hello_Class :: print_hello() {
	     cout<< output_string << endl;
}


