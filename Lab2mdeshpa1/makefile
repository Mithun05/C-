

#
# Specify the target
all : Voter

# Specify the objects files that target depends on
# Also specify the object files needed to create executable
Voter : Lab2.o DeshpandeMithunVoterFunctions.o
	g++ Lab2.o DeshpandeMithunVoterFunctions.o -o Voter

# Specify how the object files should be created from source files
DeshpandeMithunVoterFunctions.o : DeshpandeMithunVoterFunctions.cpp DeshpandeMithunVoterHeader.h
	g++ -c DeshpandeMithunVoterFunctions.cpp

# Specify how the object files should be created from source files
Lab2.o : Lab2.cpp DeshpandeMithunVoterHeader.h
	g++ -c Lab2.cpp

# Specfiy the objects files and executables that are generated 
# and need to be removed to re-compile the whole thing
clean:
	rm -f *.o Voter


