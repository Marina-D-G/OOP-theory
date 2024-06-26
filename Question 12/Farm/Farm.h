#pragma once
#include "Animal.h"

class Farm
{
public:
    Farm();
    Farm(const Farm& other);
    Farm& operator=(const Farm& other);
    Farm(Farm&& other) noexcept;
    Farm& operator=(Farm&& other) noexcept;
    ~Farm();
    
    void roarAll() const;
    void addAnimal(AnimalType animalType);
	  void addAnimal(const Animal& animal);

    AnimalType getTypeByIndex(size_t index) const;

private:
    Animal** animals;

    size_t size;
    size_t capacity;

    void copyFrom(const Farm& other);
    void moveFrom(Farm&& other);
    void free();
    void resize(size_t newCap);
}
