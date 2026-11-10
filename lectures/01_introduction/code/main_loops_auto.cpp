#include <iostream>
#include <vector>

int main() {
  std::vector<int> numbers = {1, 2, 3, 4, 5};

  // Range-based for loop
  for (int num : numbers) {
    std::cout << num << " ";
  }

  // Range-based for loop with auto key word
  for (auto num : numbers) {
    std::cout << num << " ";
  }
}