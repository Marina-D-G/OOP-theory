#include <iostream>
#include <fstream>

size_t getFileSize(const std::string& fileName) 
{
    std::ifstream file(fileName);
    if (file.is_open()) 
    {
        size_t current = file.tellg();
	      file.seekg(0, std::ios::end);
	      size_t size = file.tellg();
	      file.seekg(current, std::ios::beg);
    }
    else 
    {
        return -1;
    }
}
