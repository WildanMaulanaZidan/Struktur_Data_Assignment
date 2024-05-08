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
1. pop
   Pop pada stack adalah operasi yang berfokus pada penghapusan elemen.
2. push
   operasi Push justru lebih berfokus pada memasukkan elemen ke dalam stack atau tumpukan.
3. isFull
   Operasi stack yang satu ini adalah untuk mengetahui apakah tumpukan sudah penuh atau belum.
4. isEmpty
   Kebalikan dari isFull, isEmpty merupakan operasi yang digunakan untuk memeriksa apakah tumpukan kosong atau tidak.
5. peek
   operasi Peek atau mengintip adalah operasi yang dilakukan untuk mengetahui data teratas dari tumpukan tanpa harus menghapusnya.

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
Output Guided 1
![Output Guided 1]()

Kode di atas

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
