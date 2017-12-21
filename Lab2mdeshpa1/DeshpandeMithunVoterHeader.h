
/*
	The DeshpandeMithunVoterHeader.h header file contains standard header files
   	and function prototype declarations.
	This file has interface declarations to access all Voter's related information.
*/


#include <iostream>  //  header providing input output operations
#include <cstring>   //  header providing functions to manipulate strings
#include <iomanip>   //  header providing parametric manipulators 

using namespace std; //  namespace declaration


/*
	This function is used to create a new account for Voter.   
	last_name 	:
			User's Last Name 
	first_name 	:
			User's First Name
	age 		:
			User's Age
	street_name 	: 
			User's Street Name
	street_number 	:
			User's Street Number
	town 		:
			User's Town
	zip_code 	:
			User's Zip Code
	amount_donated 	:
			User's Amount Donation

*/

void create_new_account(string &last_name, string &first_name, int &age, string &street_name, int &street_number, string &town, string &zip_code, float &amount_donated);

/*
	This function is used to display the whole information of the Voter.
	last_name 	:
			User's Last Name 
	first_name 	:
			User's First Name
	age 		:
			User's Age
	street_name 	: 
			User's Street Name
	street_number 	:
			User's Street Number
	town 		:
			User's Town
	zip_code 	:
			User's Zip Code
	amount_donated 	:
			User's Amount Donation

*/

void view_account_detail(string last_name, string first_name, int age, string street_name, int street_number, string town, string zip_code, float amount_donated);


/*
	This function is used to provide the amount donated associated with the Voters last name.
	last_name	:
			User's Last Name
	amount_donated	:
			User's amount donation 

*/
void report_detail(string last_name, float amount_donated);

/*
	This function is used to ask for an amount to donate by the Voter.
	amount_donated	:
			User's amount donation

*/

void donate_amount(float &amount_donated); 

/*
	This function is used to update all the information of the Voter.
	last_name 	:
			User's Last Name 
	first_name 	:
			User's First Name
	age 		:
			User's Age
	street_name 	: 
			User's Street Name
	street_number 	:
			User's Street Number
	town 		:
			User's Town
	zip_code 	:
			User's Zip Code
*/

void update_account_detail(string &last_name, string &first_name, int &age, string &street_name, int &street_number, string &town, string &zip_code);


