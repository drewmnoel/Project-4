#include <iostream>
using std::cerr;
#include "ProcessFile.h"

int main(void)
{
	ProcessFile myFile("test.txt");

	// Open the file
	if(!myFile.open())
	{
		cerr << "Failed to open!\n";
		return -11;
	}

	// Encrypt the contents
	//myFile.encrypt(13);

	// Decrypt the contents
	myFile.decrypt(1);

	// Write the new file
	myFile.close();
}