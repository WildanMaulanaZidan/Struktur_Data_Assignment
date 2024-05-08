// WILDAN MAULANA ZIDAN
// 2311102162

#include <iostream>
#include <stack>
#include <string>
#include <cctype>

using namespace std;

// Menghilangkan karakter non-alfanumerik dari string dan mengonversi huruf menjadi huruf kecil
string prosesString(const string& str) {
    string prosesStr;
    for (char c : str) {
        if (isalnum(c)) {
            prosesStr += tolower(c);
        }
    }
    return prosesStr;
}

// Mengecek apakah sebuah kalimat adalah palindrom atau tidak
bool palindrom(const string& str) {
    string prosesStr = prosesString(str);

    stack<char> charStack;
    int length = prosesStr.length();
    int mid = length / 2;

    // Masukkan setengah pertama karakter ke dalam stack
    for (int i = 0; i < mid; ++i) {
        charStack.push(prosesStr[i]);
    }

    // Jika panjang kalimat ganjil, lewati karakter tengah
    if (length % 2 != 0) {
        mid++;
    }

    // Bandingkan karakter yang tersisa dengan karakter di stack
    for (int i = mid; i < length; ++i) {
        if (charStack.empty() || prosesStr[i] != charStack.top()) {
            return false;
        }
        charStack.pop();
    }

    return true;
}

int main() {
    string kalimat;
    cout << "Masukkan kalimat: ";
    getline(cin, kalimat);

    if (palindrom(kalimat)) {
        cout << "Kalimat tersebut adalah palindrom." << endl;
    } else {
        cout << "Kalimat tersebut bukan palindrom." << endl;
    }

    return 0;
}
