#include <iostream>
#include <memory>

class Child;

class Parent {
public:
  std::XXXX_ptr<Child> child; // Shared or weak pointer of the child?
  ~Parent() { std::cout << "Parent destroyed" << std::endl; }
};

class Child {
public:
  std::XXXX_ptr<Parent> parent; // Shared or weak reference to the parent?
  ~Child() { std::cout << "Child destroyed" << std::endl; }
};

int main() {
  auto parent = std::make_shared<Parent>();
  auto child = std::make_shared<Child>();

  parent->child = child;  // Parent owns the child
  child->parent = parent; // Child observes the parent

  // Both objects will be destroyed when the shared_ptrs go out of scope
  return 0;
}