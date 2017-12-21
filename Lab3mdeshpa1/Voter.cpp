



#include "Voter.h"
#include <cstdlib>

Voter::Voter() 
{
	amount_donated = 0.0;
	flag = 0;
	flag2 = 0;
	flag3 = 0;
}


void Voter :: create()
{
	
	cout << "Last Name: ";
	cin >> last_name;
	cout << "First Name: ";
	cin >> first_name;
	cout << "User id: ";
	cin >> user_id;
	cout<< "Password: ";
	cin >> password;
	cout<<"Street Name: ";
	cin >> street_name;
	cout<< "zip code: ";
	cin >> zip_code;
	cout<<"age: ";
	cin >> age;
	cout << "House Number: ";
	cin >> street_number;
	cout << "Town: ";
	cin >> town;
}

void Voter :: save()
{
	ofstream myfile;	
	string filename;
	string filename2;	
	int num;
        if(flag == 0) {
	cout << "Enter file name";
	cin >> filename;
	filenamee = filename;
	myfile.open(filename.c_str(), ios:: out | ios::app);
  	} else {
	  cout << " flag value is" << flag << endl;
	  cout << " file already exits" << endl;
	  cout << "1. overwrite 2. new file" << endl;
	  cin  >> num;
	  myfile.open(filenamee.c_str(), ios::out | ios::app);
	}
	if(myfile.is_open()) {
	cout << "flag value is " << flag << endl;
	flag++; 
	cout << "flag value is " << flag << endl;
	myfile << last_name << endl;
	myfile << first_name << endl;
	myfile << user_id << endl;
	myfile << password << endl;
	myfile << street_name << endl;
	myfile << zip_code << endl;
	myfile << age << endl ;
	myfile << street_number << endl;
	myfile << town << endl;
	myfile << zip_code << endl;
        myfile << amount_donated << endl;
	myfile.close();
 	}
 	else {
		cout << "error" ;
	}
   
}


void Voter::load() {

	string filename;
	cout << "Enter name of file" << endl;
	cin >> filename;
	

	ifstream infile (filename.c_str());
	string line;
 
	  infile >> last_name;
          cout << last_name;		
	  infile >> first_name;
	  cout << first_name;
          infile >> user_id;
	  cout << user_id;
	  infile >> password;
	  cout << password;
	  infile >> street_name;
	  cout << street_name;	
	  infile >> zip_code;
	  cout << zip_code;
	  infile >> age;
	  cout << age;
	  infile >> street_number;
          cout << street_number;
	  infile >> town;
	  cout << town;	
	  infile >> amount_donated; 		 
	  cout << amount_donated; 	

	infile.close();

}
