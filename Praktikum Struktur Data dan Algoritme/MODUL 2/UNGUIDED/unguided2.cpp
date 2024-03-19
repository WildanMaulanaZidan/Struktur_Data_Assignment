#include <iostream>
using namespace std;

int main() {
    int size1_162, size2_162, size3_162;

   cout << "Masukkan ukuran elemen array tiga dimensi:\n";
   cout << "Ukuran dimensi pertama: ";
   cin >> size1_162;
   cout << "Ukuran dimensi kedua: ";
   cin >> size2_162;
   cout << "Ukuran dimensi ketiga: ";
   cin >> size3_162;

    int array[size1_162][size2_162][size3_162];

   cout << "Masukkan nilai-nilai elemen array:\n";
    for (int i = 0; i < size1_162; ++i) {
        for (int j = 0; j < size2_162; ++j) {
            for (int k = 0; k < size3_162; ++k) {
               cout << "Nilai untuk elemen [" << i << "][" << j << "][" << k << "]: ";
               cin >> array[i][j][k];
            }
        }
    }

   cout << "Nilai-nilai elemen array:\n";
    for (int i = 0; i < size1_162; ++i) {
        for (int j = 0; j < size2_162; ++j) {
            for (int k = 0; k < size3_162; ++k) {
               cout << "array[" << i << "][" << j << "][" << k << "] = " << array[i][j][k] << "\n";
            }
        }
    }

    return 0;
}
