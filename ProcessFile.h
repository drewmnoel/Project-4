#include <fstream>
#include <iostream>
#include <cstring>
using namespace std;

class ProcessFile
{
public:
	ProcessFile(std::string);
	bool open();
	bool test();
	void encrypt(int);
	void decrypt(int);
	void close();
private:
	string fileName;
	string contents;
	void shift(int);
};
