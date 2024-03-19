#include <iostream>
using namespace std;

int main() {
    const int size_162 = 10;
    int data_162[size_162];

  cout << "Masukkan 10 angka secara berurut: ";
    for (int i = 0; i < size_162; ++i) {
      cin >> data_162[i];
    }

  cout << "Data array: ";
    for (int i = 0; i < size_162; ++i) {
      cout << data_162[i];
        if (i < size_162 - 1) {
          cout << ", ";
        }
    }
  cout << endl;

  cout << "Nomor genap: ";
    for (int i = 0; i < size_162; ++i) {
        if (data_162[i] % 2 == 0) {
          cout << data_162[i];
            if (i < size_162 - 1) {
              cout << ", ";
            }
        }
    }
  cout << endl;

  cout << "Nomor ganjil: ";
    for (int i = 0; i < size_162; ++i) {
        if (data_162[i] % 2 != 0) {
          cout << data_162[i];
            if (i < size_162 - 1) {
              cout << ", ";
            }
        }
    }
  cout << endl;

    return 0;
}
