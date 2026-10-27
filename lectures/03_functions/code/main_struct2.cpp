#include <iostream>

struct entry {
  long data;
  entry *next;
  entry *previous;
};

int main() {
  entry *previous = NULL;
  for (long i = 0; i < 10; ++i) {
    entry *current = new entry;
    current->data = i;
    current->previous = previous;
    if (previous)
      previous->next = current;
    previous = current;
  }
  previous->next = NULL;
  return 0;
}