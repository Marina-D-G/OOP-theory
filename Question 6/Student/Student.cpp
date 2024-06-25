#include "Student.h"
#include <cstring>
#pragma warning (disable : 4996)

void Student::copyFrom(const Student& other)
{
	name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);

	grades = new int[other.gradesCount];
	for (int i = 0; i < other.gradesCount; i++)
	{
		grades[i] = other.grades[i];
	}
	
	gradesCount = other.gradesCount;
}

void Student::free()
{
	delete[] name;
	delete[] grades;

	name = nullptr;
	grades = nullptr;
	gradesCount = 0;
}

Student::Student(const char* name, const int* grades, size_t gradesCount)
{
	setName(name);
	setGrades(grades, gradesCount);
}

Student::Student(const Student& other)
{
	copyFrom(other);
}

Student& Student::operator=(const Student& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

Student::~Student()
{
	free();
}

void Student::setName(const char* newName)
{
	if (!newName || newName == name) //setName(getName()) !!!!
		return;
	delete[] name;
	name = new char[strlen(newName) + 1];
	strcpy(name, newName);
}

void Student::setGrades(const int* newGrades, size_t newGradesCount)
{
	if (!newGrades || grades == newGrades)
		return;

	delete[] grades;
	grades = new int[newGradesCount];
	gradesCount = newGradesCount;
	for (int i = 0; i < newGradesCount; i++)
	{
		grades[i] = newGrades[i];
	}
}

const char* Student::getName() const
{
	return name;
}

const int* Student::getGrades() const
{
	return grades;
}

unsigned Student::getGradesCount() const
{
	return gradesCount;
}
