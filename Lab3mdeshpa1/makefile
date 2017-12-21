

#
# Specify the target
all : Voter

# Specify the objects files that target depends on
# Also specify the object files needed to create executable
Voter : Lab2.o VoterDatabase.o Voter.o
	g++ VoterDatabase.o Voter.o Lab2.o -o Voter

Lab2.o: Lab2.cpp Voter.h VoterDatabase.h
	g++ -c Lab2.cpp

# Specify how the object files should be created from source files
VoterDatabase.o : VoterDatabase.cpp VoterDatabase.h
	g++ -c VoterDatabase.cpp

# Specify how the object files should be created from source files
Voter.o : Voter.cpp Voter.h
	g++ -c Voter.cpp

# Specfiy the objects files and executables that are generated 
# and need to be removed to re-compile the whole thing
clean:
	rm -f *.o Voter


