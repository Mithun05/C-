#
# Specifiy the target
all: Deshpande_Mithun_Hello

# Specify the object files that the target depends on
# Also specify the object files needed to create the executable
Deshpande_Mithun_Hello:	Hello_Class.o	Deshpande_Mithun_Hello.o
	g++  Hello_Class.o Deshpande_Mithun_Hello.o  -o Deshpande_Mithun_Hello.exe

# Specify how the object files should be created from source files
Deshpande_Mithun_Hello.o:	Deshpande_Mithun_Hello.cpp Hello_Class.h	
	g++ -c Deshpande_Mithun_Hello.cpp 

# Specify how the object files shoube be created from source files
Hello_Class.o:	Hello_Class.cpp	Hello_Class.h
	g++ -c Hello_Class.cpp 

# Specify the object files and executables that are generated
# and need to be removed to re-compile the whole thing
clean:
	rm -f *.o Deshpande_Mithun_Hello.exe

