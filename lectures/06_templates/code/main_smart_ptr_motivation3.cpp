#include <memory>

void my_func() {
  std::unique_ptr<int> valuePtr(new int(15));
  int x = 45;
  // ...
  if (x == 45)
    return;
  // ...
}

int main() {
  my_func();
  return 0;
}