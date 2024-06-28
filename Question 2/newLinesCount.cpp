#include <iostream>
#include <fstream>
#include <assert.h>

const char NEW_LINE_CHAR = '\n';

int getCharCount(std::ifstream& ifs, char ch) 
{
	if (!ifs.is_open()) 
	{
		return -1;
	}

	int count = 0;
	while (true) 
	{
		char current = ifs.get();
		if (ifs.eof()) 
		{
			return count; // ако сме достигнали края на файла, връщаме брояча
		}

		if (current == ch) 
		{
			count++; //ако символа е нашият, увеличаваме брояча
		}
	}
}

int getLinesCount(const char* fileName)
{
	if (!fileName) 
	{
		return -1;
	}

	std::ifstream ifs(fileName);
	if (!ifs.is_open()) 
	{
		return -1;
	}

	return getCharCount(ifs, NEW_LINE_CHAR) + 1; // броят на новите редове е броят на \n символите + 1
}

int main()
{
	std::cout << getLinesCount("file.txt");
}
