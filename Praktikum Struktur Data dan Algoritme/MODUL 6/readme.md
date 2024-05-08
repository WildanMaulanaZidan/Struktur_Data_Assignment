# <h1 align="center">LAPORAN PRAKTIKUM MODUL 6 STACK </h1>

## Dasar Teori
### Apa itu Stack

stack adalah salah satu struktur data yang digunakan untuk menyimpan sekumpulan objek ataupun variabel.
karakteristik stack sendiri bersifat LIFO (last in first out). Artinya, data yang terakhir masuk merupakan data yang akan keluar terlebih dahulu.
Seperti halnya tumpukan pada umumnya, misalnya tumpukan buku, yang di atas atau yang terakhir masuk harus dikeluarkan terlebih dahulu untuk mendapatkan buku yang berada di tumpukan bawah.
Sebagai contoh, kamu mempunyai empat buku, yaitu buku matematika, fisika, biologi, dan kimia. Buku matematika kamu masukkan terlebih dahulu, lalu buku selanjutnya fisika, biologi, dan kimia.
Nah, untuk mendapatkan buku fisika, kamu harus mengeluarkan buku kimia dan biologi terlebih dahulu, karena kedua buku tersebut tergolong buku yang terakhir masuk.

### Kelebihan Stack
1. membantu mengelola data dengan metode LIFO
2. secara otomatis membersihkan objek
3. tidak mudah rusak
4. ukuran variabel tidak dapat diubah
5. mengontrol memori secara mandiri
   
### Kekurangan Stack
1. memori stack sangat terbatas
2. ada kemungkinan stack akan meluap atau overflow jika terlalu banyak objek
3. tidak memungkinkan akses acak, karena harus mengeluarkan tumpukan paling atas terlebih dahulu untuk mengakses tumpukan paling bawah

### Jenis-jenis operasi Stack
1. Pop, Pop pada stack adalah operasi yang berfokus pada penghapusan elemen.
2. Push, operasi Push justru lebih berfokus pada memasukkan elemen ke dalam stack atau tumpukan.
3. isFull, Operasi stack yang satu ini adalah untuk mengetahui apakah tumpukan sudah penuh atau belum.
4. isEmpty, Kebalikan dari isFull, isEmpty merupakan operasi yang digunakan untuk memeriksa apakah tumpukan kosong atau tidak.
5. peek, operasi Peek atau mengintip adalah operasi yang dilakukan untuk mengetahui data teratas dari tumpukan tanpa harus menghapusnya[1].

## Guided

### Guided 1

``` C++
#include <iostream>
using namespace std;

string arrayBuku[5];
int maksimal = 5, top = 0;
bool isFull() {
    return (top == maksimal);
}

bool isEmpty() {
    return (top == 0);
}

void pushArrayBuku(string data) {
    if (isFull()) {
        cout << "Data telah penuh" << endl;
    } else {
        arrayBuku[top] = data;
        top++;
    }
}

void popArrayBuku() {
    if (isEmpty()) {
        cout << "Tidak ada data yang dihapus" << endl;
    } else {
        arrayBuku[top - 1] = "";
        top--;
    }
}

void peekArrayBuku(int posisi) {
    if (isEmpty()) {
        cout << "Tidak ada data yang bisa dilihat" << endl;
    } else {
        int index = top;
        for (int i = 1; i <= posisi; i++) {
            index--;
        }
        cout << "Posisi ke " << posisi << " adalah " <<
        arrayBuku[index] << endl;
    }
}

int countStack() {
    return top;
}
    void changeArrayBuku(int posisi, string data) {
        if (posisi > top) {
            cout << "Posisi melebihi data yang ada" << endl;
        } else {
            int index = top;
            for (int i = 1; i <= posisi; i++) {
            index--;
        }
        arrayBuku[index] = data;
    }
}

void destroyArraybuku() {
    for (int i = top; i >= 0; i--) {
    arrayBuku[i] = "";
    }
    top = 0;
}
void cetakArrayBuku() {
    if (isEmpty()) {
        cout << "Tidak ada data yang dicetak" << endl;
    } else {
        for (int i = top - 1; i >= 0; i--) {
            cout << arrayBuku[i] << endl;
        }
    }
}

int main() {
pushArrayBuku("Kalkulus");
pushArrayBuku("Struktur Data");
pushArrayBuku("Matematika Diskrit");
pushArrayBuku("Dasar Multimedia");
pushArrayBuku("Inggris");
cetakArrayBuku();
cout << "\n";
cout << "Apakah data stack penuh? " << isFull() << endl;
cout << "Apakah data stack kosong? " << isEmpty() << endl;
peekArrayBuku(2);
popArrayBuku();
cout << "Banyaknya data = " << countStack() << endl;
changeArrayBuku(2, "Bahasa Jerman");
cetakArrayBuku();
cout << "\n";
destroyArraybuku();
cout << "Jumlah data setelah dihapus: " << top << endl;
cetakArrayBuku();
return 0;
}
```
#### Output Guided 1
![Output Guided 1](https://github.com/WildanMaulanaZidan/Struktur_Data_Assignment/blob/main/Praktikum%20Struktur%20Data%20dan%20Algoritme/MODUL%206/GAMBAR%20OUTPUT/Output%20guided1.png)

## Unguided

### Unguided 1
Buatlah program untuk menentukan apakah kalimat tersebut yang diinputkan
dalam program stack adalah palindrom/tidak. Palindrom kalimat yang dibaca dari
depan dan belakang sama. Jelaskan bagaimana cara kerja programnya

contoh:

Kalimat : ini

Kalimat tersebut adalah polindrom

Kalimat : Telkom

Kalimat tersebut adalah bukan polindrom

``` C++
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

```
#### Output Unguided 1
![Output Unguided 1](https://github.com/WildanMaulanaZidan/Struktur_Data_Assignment/blob/main/Praktikum%20Struktur%20Data%20dan%20Algoritme/MODUL%206/GAMBAR%20OUTPUT/Output%20Unguided%201.png)

Kode di atas menggunakan metode stack untuk menentukan apakah suatu pernyataan merupakan palindrom atau bukan. Pertama, program ini menghapus
karakter non-alfanumerik dan mengubah semua huruf menjadi huruf kecil untuk memudahkan perbandingan. Paruh pertama kalimat yang diproses
ditempatkan di tumpukan. Jika panjang kalimatnya ganjil, karakter tengahnya dihilangkan. Karakter yang tersisa dalam kalimat tersebut
kemudian dibandingkan dengan karakter yang diambil dari tumpukan. Jika terdapat perbedaan, maka kalimat tersebut bukan palindrom. Namun, jika
semua karakter cocok, frasa tersebut dianggap palindrom.

### Unguided 2
Buatlah program untuk melakukan pembalikan terhadap kalimat menggunakan
stack dengan minimal 3 kata. Jelaskan output program dan source codenya
beserta operasi/fungsi yang dibuat?

Contoh
Kalimat : Telkom Purwokerto

Hasil : otrekowruP mokleT

``` C++
// WILDAN MAULANA ZIDAN
// 2311102162

#include <iostream>
#include <stack>

using namespace std;

int main() {

  string kalimat;
  stack<char> tumpukan;
  
  cout << endl;
  cout << "Masukkan kalimat (minimal 3 kata): ";
  getline(cin, kalimat);

  if (kalimat.length() < 3) {
    cout << "Kalimat minimal harus 3 kata!" << endl;
    return 1;
  }

  for (char c : kalimat) {
    tumpukan.push(c);
  }

  kalimat = "";
  while (!tumpukan.empty()) {
    kalimat += tumpukan.top();
    tumpukan.pop();
  }

  cout << "Kalimat terbalik: " << kalimat << endl;

  return 0;
}
```
#### Output Unguided 2
![Output Unguided 2](https://github.com/WildanMaulanaZidan/Struktur_Data_Assignment/blob/main/Praktikum%20Struktur%20Data%20dan%20Algoritme/MODUL%206/GAMBAR%20OUTPUT/Output%20Unguided%202.png)

Kode di atas meminta pengguna memasukkan kalimat minimal 3 kata. Program kemudian menggunakan tumpukan untuk menerjemahkan kalimat dan
menampilkannya di layar. Jika kalimat yang dimasukkan kurang dari 3 kata, program memberikan pesan kesalahan dan berhenti. Saat menerjemahkan
sebuah kalimat, program menggunakan struktur data tumpukan untuk menyimpan setiap karakter kalimat masukan dan kemudian mengeluarkan karakter
tersebut dari tumpukan satu per satu untuk membentuk kalimat yang berlawanan. Setelah itu, program menampilkan kalimat terbalik di layar.

## Kesimpulan 
Stack struktur data yang menerapkan prinsip Last In First Out (LIFO), yang memungkinkan elemen baru ditambahkan ke bagian atas
tumpukan dan elemen paling atas dihapus. Karena kecepatan akses berkelanjutan dan kesederhanaannya, tumpukan sering digunakan dalam berbagai
aplikasi, seperti mengevaluasi ekspresi aritmatika, manajemen memori, dan pemeriksaan sintaksis dalam bahasa pemrograman. Meskipun tumpukan
memiliki keunggulan dalam hal efisiensi operasi dorong dan lompat, tumpukan memiliki keterbatasan akses acak dan tidak mendukung pencarian langsung elemen di dalamnya tanpa menghapus elemen di atasnya.

## Referensi
[1]. M. Adieb, "Memahami Stack, Struktur Data yang Mudahkan Programmer Jalankan Tugasnya," Glints, 04 Februari 2021. [Online]. Available: https://glints.com/id/lowongan/stack-adalah/. [Accessed 08 Mei 2024].
