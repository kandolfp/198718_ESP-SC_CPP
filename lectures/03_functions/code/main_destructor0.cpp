class Entry {
  double *_data;

public:
  Entry(double data) : _data() {
    _data = new double;
    _data[0] = data;
  }
};

int main() {
  double *data = new double;
  Entry tmp(*data);
  delete data;
  return 0;
}