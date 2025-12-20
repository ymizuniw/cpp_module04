#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main(void) {
  // array of animal. half are dog, another are cat.
  size_t arrSize = 20;
  Animal **arr = new Animal *[arrSize];

  size_t i = 0;
  // delete all animal array element.
  for (; i < arrSize / 2; i++) {
    arr[i] = new Dog();
  }
  for (; i < arrSize; i++) {
    arr[i] = new Cat();
  }
  for (size_t j = 0; j < arrSize; j++)
    arr[j]->makeSound();
#ifdef DEBUG
  // for (size_t l = 0; l < arrSize; l++)
  size_t idx = 5;
  arr[idx]->print_ideas();
#endif
  for (size_t k = 0; k < arrSize; k++)
    delete (arr[k]);
  delete[] arr;
  return (0);
}
