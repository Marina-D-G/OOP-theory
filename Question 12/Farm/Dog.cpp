#include "Dog.h"

Dog::Dog() :Animal(Type::DOG){}

void Dog::roar() const
{
  std::cout << "bau bau" << std::endl;
}

Animal* Dog::clone() const
{
  Animal* newDog = new (std::nothrow) Dog(*this); //!!!
  return newDog;
}
