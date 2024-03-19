#include <iostream>
using namespace std;

int main() {
    int size_162;

   cout << "Masukkan ukuran array: ";
   cin >> size_162;

    int array[size_162];

   cout << "Masukkan nilai-nilai array:\n";
    for (int i = 0; i < size_162; ++i) {
       cout << "Nilai untuk elemen ke-" << i << ": ";
       cin >> array[i];
    }

    int max = array[0];
    for (int i = 1; i < size_162; ++i) {
        if (array[i] > max) {
            max = array[i];
        }
    }

    int min = array[0];
    for (int i = 1; i < size_162; ++i) {
        if (array[i] < min) {
            min = array[i];
        }
    }

    double sum = 0;
    for (int i = 0; i < size_162; ++i) {
        sum += array[i];
    }
    double average = sum / size_162;

   cout << "Nilai maksimum: " << max <<endl;
   cout << "Nilai minimum: " << min <<endl;
   cout << "Nilai rata-rata: " << average <<endl;

    return 0;
}
