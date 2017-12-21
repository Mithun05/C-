



#include "Voter.h"

static int limit;

class VoterDatabase
{
	
	private:
	
	int size;	
	int maxsize;
	int current;
	Voter *voter;   	

	public :
	
	VoterDatabase();
	void setDb(int size);
	void login();
	void create();
	void save();
	void load();
	void report();

//	int  getSize();
//	void setSize(int size);

};
