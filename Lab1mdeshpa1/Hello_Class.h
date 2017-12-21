
/* Hello_Class header file containing class definition and 
   function interfaces */	

#include <iostream> 

using namespace std;

//Hello_Class class definition
class Hello_Class {
	public:
	      Hello_Class(int);  
	      void print_hello(); // print_hello function to display op string
        private:
	      string output_string; // private data member
};
