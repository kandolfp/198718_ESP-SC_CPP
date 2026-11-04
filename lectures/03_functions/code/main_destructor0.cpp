class Entry {
  double *_data;

public:
  Entry(double data) : _data(NULL) {
    _data = new double[10];
    _data[0] = data;
  }
};

int main() {
  double *data = new double;
  Entry tmp(*data);
  delete data;
  return 0;
}