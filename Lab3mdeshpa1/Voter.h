



#include <iostream>
#include <fstream>
#include <string>

using namespace std;
        
	static int flag;
	static int flag2;
	static int flag3;
	static string filenamee;
	static string filenameee;
	static string filenameeee;
class Voter  {

	private:
	string last_name;
	string first_name;
	string user_id;
	string password;
	string street_name;
	string town;
	string zip_code;
//	stateCode state_code;

	int age;
	int street_number;

	float amount_donated;
	
	public:	
//	enum stateCode { NY,PA,NE }; 
	
 	Voter();	
	void create();
	void save();
	void update();
	void passwd();
	void view();
	void donate();
	void report();
	void logout();	
	void load();
	void setflag(int);
	int  getflag();
//	void setState();
//	void getstate();

};




