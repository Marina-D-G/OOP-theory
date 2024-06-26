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
      
