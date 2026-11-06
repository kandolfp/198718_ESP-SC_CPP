void my_func() {
  int *valuePtr = new int(15);
  int x = 45;
  // ...
  if (x == 45)
    return;
  // ...
  delete valuePtr;
}

int main() {
  my_func();
  return 0;
}