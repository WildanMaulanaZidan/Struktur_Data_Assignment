// WILDAN MAULANA ZIDAN 
// 2311102162

#include <iostream>

using namespace std;

int hitungAngkaEmpat(int data[], int ukuran) {
    int jumlahEmpat = 0;

    for (int i = 0; i < ukuran; ++i) {
        if (data[i] == 4) {
            jumlahEmpat++;
        }
    }

    return jumlahEmpat;
}

int main() {
    int data[] = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4};
    int ukuran = sizeof(data) / sizeof(data[0]);

    int jumlahEmpat = hitungAngkaEmpat(data, ukuran);

    cout << "Jumlah angka 4 dalam array: " << jumlahEmpat << endl;

    return 0;
}
