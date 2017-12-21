

/*
	The Lab2.cpp source file contains the main function implementation 
	and providing an application interface.
*/

//#include "DeshpandeMithunVoterHeader.h"   // header file providing function prototypes
#include "VoterDatabase.h"
#include <string>
#include <sstream>

// main function
int main(int argc, char **argv) 
{
	
		string command_selection_choice;
		int  var_command_selection_choice;
		string progName(argv[0]);

   		cout << endl << "Argc is an integer containing the number of arguments, " << endl;
   		cout << "including the program name itself. " << endl << endl;
		cout << "This program contains " << argc << " argument(s)." << endl << endl;
   		cout << "You ran this program with " << progName << endl;
   		cout << "The other arguments are: " << endl;

   		for (int i=1; i<argc; i++) 
      			cout << "argv[" << i << "]: " << argv[i] << endl;

   		if (argc > 1) {
      			istringstream buf(argv[1]); // create an input string stream
      			int num1;
      			buf >> num1; // use the extraction operator
      			cout << "argv[1] as an int: " << num1 << endl;
   			VoterDatabase voterDatabase;
 			voterDatabase.setDb(num1);	
		do {

	cout << "\nEnter a Command." << endl;
	cout << "Choose from [\"Login\" \"New\" \"Save\" \"Load\" \"Report\" \"Quit\"]" << endl;
	cout << ": "; 
	cin >> command_selection_choice;

	// check against typos in command 
	//to allow only given commands from the available list
	var_command_selection_choice = command_selection_choice.compare("Login") ? command_selection_choice.compare("New") ? command_selection_choice.compare("Save") ? 
				command_selection_choice.compare("Load") ? command_selection_choice.compare("Report") ? command_selection_choice.compare("Quit") ? 7: 6: 5: 4: 3: 2: 1;

	switch(var_command_selection_choice) 
	{

	 case 6:
		break;
	 case 5:
		// to report amount donated by user
	//	report_detail(last_name, amount_donated); 
		break;
	 case 4:
		// to donate amount
	//	donate_amount(amount_donated);
		voterDatabase.load();
		break;
	 case 3:
		// to showcase or view voter's information
	//	view_account_detail(last_name, first_name, age, street_name, street_number, town, zip_code, amount_donated); 
		voterDatabase.save();
		break;
	 case 2:
		// to update voter's personal information 
	//	update_account_detail(last_name, first_name, age, street_name, street_number, town, zip_code); 
		voterDatabase.create();
		break;
	 case 1:
		 // to create new voter account
		voterDatabase.login();
		break;
	 default:
		 // error message to display against typos for commands
		cout << "Command not recognized. Please try again." << endl; // error message to display against typos for commands
		break;
	}
	
         } while(command_selection_choice!="Quit");
	}

	
	return 0;

} // end of main


