#include <iostream>
#include <cstdlib>
using std::cerr;
#include "ProcessFile.h"

bool validateArgs(int,char**);
void usage();

int main(int argc,char* argv[])
{
	if(!validateArgs(argc,argv))
	{
	    usage();
	}

	ProcessFile myFile((string)argv[1]);

	// Open the file
	myFile.open();

    if(strcmp(argv[3],"E") == 0)
    {
        myFile.encrypt(atoi(argv[2]));
    }
    else
    {
        myFile.decrypt(atoi(argv[2]));
    }

	// Write the new file
	myFile.close();
}

bool validateArgs(int count,char* args[])
{
    if (count != 4)
    {
        return false;
    }

    try
    {
        int temp = atoi(args[2]);
    }
    catch(int e)
    {
        return false;
    }

    if(strcmp(args[3],"E") != 0 && strcmp(args[3],"D") != 0)
    {
        return false;
    }

    ProcessFile temp2((string)args[1]);
    if(!temp2.test())
    {
        return false;
    }
    return true;
}

void usage()
{
    cerr << "Usage:\n\nsimpleencryption.exe <filename> <encryption key> <encrypt or decrypt>\n\n";
    cerr << "filename\t\tThe filename to encrypt or decrypt the contents of\n";
    cerr << "encryption key\t\tThis argument must be a number \n";
    cerr << "encrypt or decrypt\tThis argument must be either the character E or D\n";
    exit(-1);
}
