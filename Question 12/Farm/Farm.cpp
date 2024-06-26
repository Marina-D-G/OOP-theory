#include "Farm.h"
#include "AnimalFactory.h"

void Farm::free()
{
  for(size_t i = 0; i < size; i++)
    {
      delete animals[i]; //virtual destructor
    }
  delete[] animals;
}

void Farm::copyFrom(const Farm& other)
{
  animals = new Animal*[other.capacity];
  size = other.size;
  capacity = other.capacity;

  for(size_t i = 0; i < size; i++)
  {
    Animal* cloned = other.animals[i]->clone;
    if(cloned)
      animals[i] = cloned;
  }

void Farm::moveFrom(Farm&& other)
{
  size = other.size;
  capacity = other.capacity;
  other.size = other.capacity = 0;

  animals = other.animals;
  other.animals = nullptr;
}

void Farm::resize()
{
  Animal** newAnimals = new Animal*[capacity*=2];
  for (size_t i = 0; i < size; i++)
  {
    newAnimals[i] = animals[i];
  }
  delete[] animals;
  animals = newAnimals;
}

void Farm::addAnimal(AnimalType animalType)
{
  if (animalsCount == capacity)
    	resize();
  animals[animalsCount++] = animalFactory(animalType);
}

void Farm::addAnimal(const Animal& animal)
{
  if (animalsCount == capacity)
		resize();
	animals[animalsCount++] = animal.clone();
}

Farm::Farm()
{
	capacity = 8;
	size = 0;
	animals = new Animal*[capacity];
}

Farm::Farm(const Farm& other)
{
	copyFrom(other);
}

Farm& Farm::operator=(const Farm& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

Farm::Farm(Farm&& other) noexcept
{
	moveFrom(std::move(other));
}

Farm& Farm::operator=(Farm&& other) noexcept
{
	if (this != &other)
	{
	free();
	moveFrom(std::move(other));
	}
	return *this;
}

Farm::~Farm()
{
	free();
}

void Farm::roarAll() const
{
	for (size_t i = 0; i < animalsCount; i++)
		animals[i]->roar();
}

AnimalType Farm::getTypeByIndex(size_t i) const
{
	if (i > animalsCount)
		throw std::out_of_range("Invalid index");
	return animals[i]->getType();
}
