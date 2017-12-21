
/*
	The DeshpandeMithunVoterFuntions.cpp source file contains the implementation of 
	function prototypes declared in the DeshpandeMithunVoterHeader.h header file. 
	This file contains the CRUD operations implementations. 
	In here, CRUD has been abbreviated for Create, Read or Report, Update and Donate
	for particular Voter. 

*/

#include "DeshpandeMithunVoterHeader.h"  //  header file having function prototypes

/*
	This functions asks user all the personal information to create new voter account.
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

void create_new_account(string &last_name, string &first_name, int &age, string &street_name, int &street_number, string &town, string &zip_code, float &amount_donated) {


	cout << "Last Name: ";
	cin >> last_name;
	cout << "First Name: ";
	cin >> first_name;
	cout << "Age: ";
	cin >> age;
	cout << "Street Name: ";
	cin >> street_name;
	cout << "House Number: ";
	cin >> street_number;
	cout << "Town: ";
	cin >> town;
	cout << "Zip Code: ";
	cin >> zip_code;
	amount_donated = 0.00;	// donated amount equals to zero while creating new account everytime
	
}

/*
	This function displays the Voters account information.It also displays the amount donated till today with fixed precision digits.
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

 void view_account_detail(string last_name, string first_name, int age, string street_name, int street_number, string town, string zip_code, float amount_donated) {

	cout << "Voter Info" << endl;
     	cout << first_name << " " << last_name << ": age " << age << endl;
	cout << street_number << " " << street_name << endl;
	cout << town <<  ", NY " <<  zip_code << endl;
	cout << "Current Amount Donated: " << "$" << fixed << setprecision(2) << amount_donated << endl; 

} 

/*
	This function reports the amount donated by Voter associated with the last name.
	last_name	:
			User's Last Name
	amount_donated	:
			User's amount donation 

*/
 void report_detail(string last_name, float amount_donated) {

	cout << last_name <<" $" << fixed << setprecision(2) << amount_donated << endl;
}


/*
	This function asks the voter to donate particular amount.
	amount_donated	:
			User's amount donation
*/
void donate_amount(float &amount_donated) {

	float input_amount = 0.00;  // input amount
	cout << "\nEnter Amount to Donate: ";
	cin >> input_amount;
	cout << "$" << fixed << setprecision(2) << input_amount << " donated." << endl; 
	amount_donated = amount_donated + input_amount; // to update recent donation holding previous donations if any  
} 

/*
	This function asks the Voter to update all the information associated with the account except the amount donated.
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

 void update_account_detail(string &last_name, string &first_name, int &age, string &street_name,int &street_number, string &town, string &zip_code) {

	cout << "Last Name: ";
	cin >> last_name;
	cout << "First Name: ";
	cin >> first_name;
	cout << "Age: ";
	cin >> age;
	cout << "Street Name: ";
	cin >> street_name;
	cout << "House Number: ";
	cin >> street_number;
	cout << "Town: ";
	cin >> town;
	cout << "Zip Code: ";
	cin >> zip_code;

}


 
