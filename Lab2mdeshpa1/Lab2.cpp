

/*
	The Lab2.cpp source file contains the main function implementation 
	and providing an application interface.
*/

#include "DeshpandeMithunVoterHeader.h"   // header file providing function prototypes


// main function
int main() 
{
	
	// choice selection variable to signal user's against wrong command
	string command_selection_choice;   
	int var_command_selection_choice;

	// voters personal information variables
	string last_name;
	string first_name;
	string street_name;
	string town;
	string zip_code;

	int age;
	int street_number;
	
	float amount_donated;
	
	do {

	cout << "\nEnter a Command." << endl;
	cout << "Choose from [\"New\" \"View\" \"Update\" \"Donate\" \"Report\" \"Quit\"]" << endl;
	cout << ": "; 
	cin >> command_selection_choice;

	// check against typos in command 
	//to allow only given commands from the available list
	var_command_selection_choice = command_selection_choice.compare("New") ? command_selection_choice.compare("Update") ? command_selection_choice.compare("View") ? 
				command_selection_choice.compare("Donate") ? command_selection_choice.compare("Report") ? command_selection_choice.compare("Quit") ? 7: 6: 5: 4: 3: 2: 1;

	switch(var_command_selection_choice) 
	{

	 case 6:
		break;
	 case 5:
		// to report amount donated by user
		report_detail(last_name, amount_donated); 
		break;
	 case 4:
		// to donate amount
		donate_amount(amount_donated);
		break;
	 case 3:
		// to showcase or view voter's information
		view_account_detail(last_name, first_name, age, street_name, street_number, town, zip_code, amount_donated); 
		break;
	 case 2:
		// to update voter's personal information 
		update_account_detail(last_name, first_name, age, street_name, street_number, town, zip_code); 
		break;
	 case 1:
		 // to create new voter account
		create_new_account(last_name, first_name, age, street_name, street_number, town, zip_code, amount_donated);
		break;
	 default:
		 // error message to display against typos for commands
		cout << "Command not recognized. Please try again." << endl; // error message to display against typos for commands
		break;
	}

     }while(command_selection_choice!="Quit");
	

	return 0;

} // end of main


