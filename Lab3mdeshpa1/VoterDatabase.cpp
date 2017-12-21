



#include "VoterDatabase.h"
#include <fstream>

VoterDatabase :: VoterDatabase() 
{	
	current = 0;
	maxsize = 0;
}

void VoterDatabase :: login()
{
	cout << "Hi";
	string username, password;
	cout << "enter user name";
	cin >> username;
	cout << "Enter password";
	cin >> password;
	
	ifstream readile ("input");
	
	readfile >> voter[current].user_id;
	cout << voter[current].user_id;
	if(username == voter[current].user_id) {
	cout << "welcome";
	}	 
}

void VoterDatabase :: setDb(int size)
{

	cout << "size allocation" << size << endl;
	maxsize = size;
	cout << "max sixe is" << maxsize << endl;
	voter = new Voter[maxsize];
}

void VoterDatabase :: create()
{
	cout << "size is " << maxsize << endl;
	if(current >= maxsize) {
		cout << "current size is " << current << endl;
		 cout << "no size to allocate more" << endl;
	} else {
		cout<< "create size" << current;		
	 	voter[current].create();
	}
}

void VoterDatabase :: save()
{
	cout << "save size"  << current;
	voter[current].save();
	limit = current++;
} 

void VoterDatabase :: load()
{
	/*string filenamel
	cout << "Enter name of file" << endl;
	cin >> filename;
	

	ifstream readfile (filename.c_Str());
	string line;

	while(getline(readfile, line))
	{  
	  voter[current].last_name = line;
          cout << voter[current].last_name;		
	  voter[current].first_name = line;
          voter[current].user_id = line;
	  voter[current].password = line;
	  voter[current].street_name = line;
	  voter[current].zip_code = line;
	  voter[current].age = line;
	  voter[current].street_number = line;
	  voter[current].town = line;
	  voter[current].amount_donated = line; 	
	  current++;	  		
	} */

	voter[current].load();
}





