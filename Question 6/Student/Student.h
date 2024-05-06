#pragma once
class Student
{
	char* name = nullptr;
	int* grades = nullptr;
	size_t gradesCount = 0;

	void copyFrom(const Student& other);
	void free();
public:
	Student(const char* name, const int* grades, size_t gradesCount);
	Student(const Student& other);
	Student& operator=(const Student& other);
	~Student();

	void setName(const char* newName);
	void setGrades(const int* newGrades, size_t newGradesCount);

	const char* getName() const;
	const int* getGrades() const;
	unsigned getGradesCount() const;
};
