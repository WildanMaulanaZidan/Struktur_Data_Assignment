// WILDAN MAULANA ZIDAN
// 2311102162

#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

int binarySearch(char arr[], int l, int r, char x) {
    while (l <= r) {
        int m = l + (r - l) / 2;

        // Cek apakah x ada di tengah-tengah
        if (arr[m] == x) {
            return m;
        }

        // Jika x lebih besar, maka abaikan bagian kiri
        if (arr[m] < x) {
            l = m + 1;
        }
        // Jika x lebih kecil, maka abaikan bagian kanan
        else {
            r = m - 1;
        }
    }

    return -1;
}

int main() {
    string kalimat;
    char huruf;

    cout << "Masukkan sebuah kalimat: ";
    getline(cin, kalimat);

    cout << "Masukkan huruf yang ingin dicari: ";
    cin >> huruf;

    int n = kalimat.length();
    char arr[n + 1];
    copy(kalimat.begin(), kalimat.end(), arr);
    arr[n] = '\0';

    sort(arr, arr + n);

    int result = binarySearch(arr, 0, n - 1, huruf);

    if (result != -1) {
        cout << "Huruf '" << huruf << "' ditemukan di index " << result << " setelah diurutkan." << endl;
    } else {
        cout << "Huruf '" << huruf << "' tidak ditemukan dalam kalimat." << endl;
    }

    return 0;
}