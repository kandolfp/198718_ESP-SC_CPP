#include <iostream>

struct entry {
  long data;
  entry *next;
  entry *previous;
};

int main() {
  long nEntries = 10; // number entries in list
  entry *previous = NULL;
  for (long i = 0; i < nEntries; ++i) {
    entry *current = new entry;
    current->data = i;
    current->previous = previous;
    if (previous)
      previous->next = current;
    previous = current;
  }
  previous->next = NULL;

  entry *current = previous;

  while (current->previous) {
    std::cout << current->data << std::endl;
    current = current->previous;
  }
  std::cout << current->data << std::endl;

  while (current->next) {
    std::cout << current->data << std::endl;
    current = current->next;
  }
  std::cout << current->data << std::endl;

  return 0;
}