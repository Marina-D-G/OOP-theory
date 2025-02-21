#include <iostream>
#include "../Person/Person.h"

class Student : public Person
{
	size_t fn = 0;
public:
	Student() = default;
	Student(const char* name, int age, size_t fn);
	
	size_t getFn() const;
	void setFn(size_t fn);
};
