#include "ProcessFile.h"

ProcessFile::ProcessFile(string fileName)
{
	this->fileName = fileName;
}

// Loads the input file into "contents"
bool ProcessFile::open(void)
{
	long size;
	char* buffer;

	ifstream fin(fileName.c_str());
	if(!fin.is_open())
		return false;

	fin.seekg(0, ios::end);
	size = fin.tellg();
	fin.seekg(0, ios::beg);

	buffer = new char[size];

	fin.read(buffer, size);

	contents = buffer;

	fin.close();

	return true;
}

bool ProcessFile::test()
{
    ifstream fin(fileName.c_str());
	if(!fin.is_open())
		return false;
    else
        fin.close();

    return true;
}

// Encrypts "contents" using the offset
void ProcessFile::encrypt(int offset)
{
	shift(offset);
}

// Decerypts "contents" using the offset
void ProcessFile::decrypt(int offset)
{
	shift(-1 * offset);
}

// Shifts characters over
void ProcessFile::shift(int offset)
{
	// Loop through, character by character
	for(long i=0; i<contents.length(); i++)
	{
		// We actually only want to change printable characters
		if(contents[i] >= ' ' && contents[i] <= '~')
		{
			// Shift and wrap around only the valid characters
			contents[i] = ((contents[i]-32)+offset)%94 + 32;

			// C++ mod accepts negative values, but we don't accept that.
			if(contents[i] < ' ')
				contents[i] += 94;
		}
	}
}

// Writes "contents" to "fileName"
void ProcessFile::close()
{
	ofstream fout (fileName.c_str());
	fout.write(contents.c_str(), contents.length());

	fout.close();
}
