#include <iostream>
#include <fstream>

size_t getFileSize(const char* fileName) 
{
    std::ifstream file(fileName);
    if (file.is_open()) 
    {
        size_t current = file.tellg(); // пази началната позиция на get указателя (за да можем да си я върнем после)
	file.seekg(0, std::ios::end); // мести го в края
	size_t size = file.tellg(); // взема позицията, която вече е в края (това е размерът на файла)
	file.seekg(current, std::ios::beg); // връщаме го в началото на файла

	return size;
    }
    else 
    {
        return -1; // ако файлът не е отворен, връщаме -1 за размер
    }
}
