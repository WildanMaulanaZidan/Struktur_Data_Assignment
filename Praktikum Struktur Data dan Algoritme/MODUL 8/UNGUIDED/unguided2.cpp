// WILDAN MAULANA ZIDAN
// 2311102162

#include <iostream>
#include <string>

using namespace std;

int hitungVokal(const string& kalimat) {
    int jumlahVokal = 0;
    string vokal = "aeiouAEIOU";

    for (char c : kalimat) {
        if (vokal.find(c) != string::npos) {
            jumlahVokal++;
        }
    }

    return jumlahVokal;
}

int main() {
    string kalimat;

    cout << "Masukkan sebuah kalimat: ";
    getline(cin, kalimat);

    int jumlahVokal = hitungVokal(kalimat);

    cout << "Jumlah huruf vokal dalam kalimat: " << jumlahVokal << endl;

    return 0;
}
