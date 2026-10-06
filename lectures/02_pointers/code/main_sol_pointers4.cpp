#include <iostream>

int main() {
  int i = 1, j = 2, k = 3;
  int *one = &j, *two = &k, *three = &i;

  int *tmp = one;
  one = three;
  three = two;
  two = tmp;

  std::cout << "one = " << *one << ", two = " << *two << ", three = " << *three;

  return 0;
}